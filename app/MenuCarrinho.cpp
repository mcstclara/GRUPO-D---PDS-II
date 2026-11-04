#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>

#include "Carrinho.hpp"
#include "Cliente.hpp"
#include "Entrada.hpp"
#include "Estoque.hpp"
#include "Excecoes.hpp"
#include "KitRoupas.hpp"
#include "Loja.hpp"
#include "Menus.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"

static void mostrarCarrinho(const Carrinho& carrinho) {
    if (carrinho.estaVazio()) {
        std::cout << "\nSeu carrinho esta vazio.\n";
        return;
    }
    std::vector<Produto*> produtos = carrinho.getProdutos();
    std::vector<int> quantidades = carrinho.getQuantidades();
    std::cout << "\n" << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < produtos.size(); i++) {
        std::cout << "[" << i + 1 << "] " << std::left << std::setw(22)
                  << produtos[i]->getNome() << quantidades[i] << " x R$ "
                  << produtos[i]->getPreco() << " = R$ "
                  << produtos[i]->getPreco() * quantidades[i] << "\n";
    }
    std::cout << "Total: R$ " << carrinho.calcularTotal() << "\n";
}

static int quantidadeNoCarrinho(const Carrinho& carrinho, const Produto* produto) {
    std::vector<Produto*> produtos = carrinho.getProdutos();
    std::vector<int> quantidades = carrinho.getQuantidades();
    for (std::size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i] == produto) {
            return quantidades[i];
        }
    }
    return 0;
}

static void adicionar(Loja& loja, Carrinho& carrinho) {
    int produtoId = lerInteiro("ID do produto: ", 1, 1000000);
    Produto* produto = loja.buscarProduto(produtoId);
    int quantidade = lerInteiro("Quantidade: ", 1, 99);
    int total = quantidadeNoCarrinho(carrinho, produto) + quantidade;
    if (!loja.getEstoque().temQuantidadeSuficiente(produtoId, total)) {
        throw EstoqueInsuficiente(produto->getNome(),
                                  loja.getEstoque().consultarQuantidade(produtoId));
    }
    carrinho.adicionarProduto(produto, quantidade);
    std::cout << quantidade << "x " << produto->getNome() << " no carrinho.\n";
}

static Produto* escolherItem(const Carrinho& carrinho) {
    if (carrinho.estaVazio()) {
        throw ErroLoja("Seu carrinho esta vazio.");
    }
    std::vector<Produto*> produtos = carrinho.getProdutos();
    int item = lerInteiro("Numero do item: ", 1, static_cast<int>(produtos.size()));
    return produtos[item - 1];
}

static void remover(Carrinho& carrinho) {
    Produto* produto = escolherItem(carrinho);
    carrinho.removerProduto(produto);
    std::cout << produto->getNome() << " saiu do carrinho.\n";
}

static void alterarQuantidade(Loja& loja, Carrinho& carrinho) {
    Produto* produto = escolherItem(carrinho);
    int quantidade = lerInteiro("Nova quantidade: ", 1, 99);
    bool ehKit = dynamic_cast<KitRoupas*>(produto) != nullptr;
    if (!ehKit && !loja.getEstoque().temQuantidadeSuficiente(produto->getId(), quantidade)) {
        throw EstoqueInsuficiente(produto->getNome(),
                                  loja.getEstoque().consultarQuantidade(produto->getId()));
    }
    carrinho.atualizarQuantidade(produto, quantidade);
    std::cout << "Quantidade atualizada.\n";
}
static std::map<Produto*, int> pecasNecessarias(const Carrinho& carrinho) {
    std::map<Produto*, int> pecas;
    std::vector<Produto*> produtos = carrinho.getProdutos();
    std::vector<int> quantidades = carrinho.getQuantidades();
    for (std::size_t i = 0; i < produtos.size(); i++) {
        KitRoupas* kit = dynamic_cast<KitRoupas*>(produtos[i]);
        if (kit == nullptr) {
            pecas[produtos[i]] += quantidades[i];
        } else {
            for (Produto* peca : kit->getProdutos()) {
                pecas[peca] += quantidades[i];
            }
        }
    }
    return pecas;
}

static std::string escolherEndereco(Cliente& cliente) {
    std::vector<std::string> enderecos = cliente.getEnderecos();
    if (!enderecos.empty()) {
        std::cout << "\nEnderecos cadastrados:\n";
        for (std::size_t i = 0; i < enderecos.size(); i++) {
            std::cout << "[" << i + 1 << "] " << enderecos[i] << "\n";
        }
        std::cout << "[0] Usar um endereco novo\n";
        int escolha = lerInteiro("Endereco de entrega: ", 0,
                                 static_cast<int>(enderecos.size()));
        if (escolha > 0) {
            return enderecos[escolha - 1];
        }
    }
    std::string endereco = lerTexto("Endereco de entrega: ");
    cliente.adicionarEndereco(endereco);
    return endereco;
}

static void finalizarCompra(Loja& loja, Carrinho& carrinho) {
    if (carrinho.estaVazio()) {
        throw ErroLoja("Seu carrinho esta vazio.");
    }
    Cliente& cliente = loja.exigirCliente();
    std::map<Produto*, int> pecas = pecasNecessarias(carrinho);
    for (const auto& peca : pecas) {
        if (!loja.getEstoque().temQuantidadeSuficiente(peca.first->getId(), peca.second)) {
            throw EstoqueInsuficiente(peca.first->getNome(),
                                      loja.getEstoque().consultarQuantidade(peca.first->getId()));
        }
    }

    std::string endereco = escolherEndereco(cliente);
    std::cout << "\nResumo da compra:";
    mostrarCarrinho(carrinho);
    std::cout << "Entrega em: " << endereco << "\n";
    if (!lerSimNao("Confirmar a compra?")) {
        std::cout << "Compra nao confirmada. Os itens continuam no carrinho.\n";
        return;
    }

    Pedido* pedido = carrinho.finalizarCompra();
    loja.registrarPedido(pedido);
    for (const auto& peca : pecas) {
        loja.getEstoque().removerUnidades(peca.first->getId(), peca.second);
    }
    std::string arquivo = "pedido_" + std::to_string(pedido->getId()) + ".txt";
    try {
        pedido->salvarResumo(arquivo);
        std::cout << "\nPedido " << pedido->getId() << " registrado! Resumo salvo em "
                  << arquivo << ".\n";
    } catch (const std::runtime_error& erro) {
        std::cout << "\nPedido " << pedido->getId()
                  << " registrado, mas o resumo nao foi salvo: " << erro.what() << "\n";
    }
}

void menuCarrinho(Loja& loja) {
    Carrinho& carrinho = loja.getCarrinho();
    while (true) {
        mostrarCarrinho(carrinho);
        std::cout << "\n--- Carrinho ---\n"
                  << "[1] Adicionar produto\n"
                  << "[2] Remover item\n"
                  << "[3] Alterar quantidade\n"
                  << "[4] Finalizar compra\n"
                  << "[0] Voltar\n";
        int opcao = lerInteiro("Escolha uma opcao: ", 0, 4);
        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            adicionar(loja, carrinho);
        } else if (opcao == 2) {
            remover(carrinho);
        } else if (opcao == 3) {
            alterarQuantidade(loja, carrinho);
        } else {
            finalizarCompra(loja, carrinho);
        }
    }
}
