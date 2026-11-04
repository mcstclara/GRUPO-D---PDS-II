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
        } else {
            std::cout << "Em construcao.\n";
        }
    }
}
