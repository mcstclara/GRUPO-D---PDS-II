#include <iostream>
#include <stdexcept>

#include "Carrinho.hpp"
#include "Cliente.hpp"
#include "Entrada.hpp"
#include "Excecoes.hpp"
#include "Loja.hpp"
#include "Menus.hpp"

static void mostrarMenuPrincipal(Loja& loja) {
    std::cout << "\n==============================================\n";
    std::cout << "      LOJA GRUPO D - roupas e acessorios\n";
    std::cout << "==============================================\n";
    Cliente* cliente = loja.getClienteAtual();
    if (cliente != nullptr) {
        std::cout << "Ola, " << cliente->getNome() << "! Itens no carrinho: "
                  << loja.getCarrinho().getProdutos().size() << "\n";
    } else {
        std::cout << "Voce ainda nao entrou na sua conta.\n";
    }
    std::cout << "\n[1] Catalogo\n"
              << "[2] Minha conta\n"
              << "[3] Provador virtual\n"
              << "[4] Carrinho\n"
              << "[5] Meus pedidos\n"
              << "[6] Trocas e devolucoes\n"
              << "[7] Area do administrador\n"
              << "[0] Sair\n";
}

static void abrirOpcao(Loja& loja, int opcao) {
    switch (opcao) {
        case 1: menuCatalogo(loja); break;
        case 2: menuConta(loja); break;
        case 3: menuProvador(loja); break;
        case 4: menuCarrinho(loja); break;
        case 5: menuPedidos(loja); break;
        case 6: menuTrocas(loja); break;
        case 7: menuAdministrador(loja); break;
    }
}

int main() {
    Loja loja;
    try {
        loja.carregarProdutos("data/produtos.txt");
    } catch (const ArquivoInvalido& erro) {
        std::cerr << "Nao foi possivel iniciar a loja: " << erro.what() << std::endl;
        return 1;
    }

    try {
        while (true) {
            mostrarMenuPrincipal(loja);
            int opcao = lerInteiro("Escolha uma opcao: ", 0, 7);
            if (opcao == 0) {
                break;
            }
            try {
                abrirOpcao(loja, opcao);
            } catch (const ErroLoja& erro) {
                std::cout << "\n" << erro.what() << "\n";
            } catch (const std::invalid_argument& erro) {
                std::cout << "\nDado invalido: " << erro.what() << "\n";
            } catch (const std::logic_error& erro) {
                std::cout << "\nOperacao nao permitida: " << erro.what() << "\n";
            }
        }
    } catch (const EntradaEncerrada&) {
        std::cout << "\n";
    } catch (const std::exception& erro) {
        std::cerr << "\nErro inesperado: " << erro.what() << std::endl;
        return 1;
    }

    std::cout << "Ate logo!" << std::endl;
    return 0;
}