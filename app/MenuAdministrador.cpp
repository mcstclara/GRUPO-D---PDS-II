#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Administrador.hpp"
#include "Cliente.hpp"
#include "Entrada.hpp"
#include "Estoque.hpp"
#include "Excecoes.hpp"
#include "Loja.hpp"
#include "Menus.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"

static void verEstoque(Loja& loja) {
    std::cout << "\n" << std::left << std::setw(5) << "ID"
              << std::setw(26) << "Produto" << "Quantidade\n";
    for (Produto* produto : loja.getCatalogo()) {
        int quantidade = loja.getEstoque().consultarQuantidade(produto->getId());
        std::cout << std::left << std::setw(5) << produto->getId()
                  << std::setw(26) << produto->getNome() << quantidade;
        if (loja.getEstoque().estaEsgotado(produto->getId())) {
            std::cout << "  <- sem estoque";
        }
        std::cout << "\n";
    }
}

static void atualizarEstoque(Loja& loja) {
    int produtoId = lerInteiro("ID do produto: ", 1, 1000000);
    Produto* produto = loja.buscarProduto(produtoId);
    std::cout << "Digite um numero positivo para entrada e negativo para saida.\n";
    int quantidade = lerInteiro("Quantidade: ", -1000, 1000);
    int antes = loja.getEstoque().consultarQuantidade(produtoId);
    loja.getAdministrador().atualizarEstoque(&loja.getEstoque(), produtoId, quantidade);
    int depois = loja.getEstoque().consultarQuantidade(produtoId);
    if (antes == depois) {
        std::cout << "Nao ha unidades suficientes para essa saida. O estoque continua com "
                  << antes << ".\n";
    } else {
        std::cout << produto->getNome() << ": " << antes << " -> " << depois
                  << " unidade(s).\n";
    }
}

static void verPedidos(Loja& loja) {
    std::vector<Pedido*> pedidos = loja.getPedidos();
    if (pedidos.empty()) {
        std::cout << "\nNenhum pedido foi feito ainda.\n";
        return;
    }
    std::cout << "\n" << std::left << std::setw(8) << "Pedido" << std::setw(20)
              << "Cliente" << std::setw(12) << "Status" << "Total\n";
    for (Pedido* pedido : pedidos) {
        std::string nome = "-";
        if (pedido->getCliente() != nullptr) {
            nome = pedido->getCliente()->getNome();
        }
        std::cout << std::left << std::setw(8) << pedido->getId()
                  << std::setw(20) << nome << std::setw(12) << pedido->getStatus()
                  << "R$ " << std::fixed << std::setprecision(2)
                  << pedido->calcularTotal() << "\n";
    }
}

static Pedido* buscarPedido(Loja& loja, int pedidoId) {
    for (Pedido* pedido : loja.getPedidos()) {
        if (pedido->getId() == pedidoId) {
            return pedido;
        }
    }
    throw ErroLoja("Pedido " + std::to_string(pedidoId) + " nao encontrado.");
}

static void atualizarStatus(Loja& loja) {
    int pedidoId = lerInteiro("Numero do pedido: ", 1, 1000000);
    Pedido* pedido = buscarPedido(loja, pedidoId);
    const std::vector<std::string> opcoes = {
        "Pendente", "Pago", "Enviado", "Entregue", "Cancelado"};
    for (std::size_t i = 0; i < opcoes.size(); i++) {
        std::cout << "[" << i + 1 << "] " << opcoes[i] << "\n";
    }
    int escolha = lerInteiro("Novo status: ", 1, static_cast<int>(opcoes.size()));
    loja.getAdministrador().atualizarStatusPedido(pedido, opcoes[escolha - 1]);
    std::cout << "Pedido " << pedidoId << " agora esta: " << pedido->getStatus() << ".\n";
}

void menuAdministrador(Loja& loja) {

    while (true) {
        std::cout << "\n--- Area do administrador ---\n"
                  << "[1] Ver estoque\n"
                  << "[2] Atualizar estoque\n"
                  << "[3] Ver pedidos\n"
                  << "[4] Atualizar status de um pedido\n"
                  << "[5] Cadastrar produto\n"
                  << "[0] Voltar\n";
        int opcao = lerInteiro("Escolha uma opcao: ", 0, 5);
        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            verEstoque(loja);
                } else if (opcao == 2) {
            atualizarEstoque(loja);
        } else if (opcao == 3) {
            verPedidos(loja);
        } else if (opcao == 4) {
            atualizarStatus(loja);
        } else {
            std::cout << "Em construcao.\n";
        }
    }
}