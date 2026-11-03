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
        } else {
            std::cout << "Em construcao.\n";
        }
    }
}