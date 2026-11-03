#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Carrinho.hpp"
#include "Entrada.hpp"
#include "Estoque.hpp"
#include "Excecoes.hpp"
#include "KitRoupas.hpp"
#include "Loja.hpp"
#include "Menus.hpp"
#include "Produto.hpp"

static std::string paraMinusculas(std::string texto) {
    for (char& letra : texto) {
        letra = static_cast<char>(std::tolower(static_cast<unsigned char>(letra)));
    }
    return texto;
}

static void mostrarProdutos(Loja& loja, const std::vector<Produto*>& produtos) {
    if (produtos.empty()) {
        std::cout << "\nNenhum produto encontrado.\n";
        return;
    }
    std::cout << "\n" << std::left << std::setw(4) << "ID" << std::setw(23) << "Produto"
              << std::setw(12) << "Categoria" << std::setw(14) << "Colecao"
              << std::right << std::setw(9) << "Preco" << std::setw(10) << "Estoque"
              << "\n";
    for (Produto* produto : produtos) {
        int quantidade = loja.getEstoque().consultarQuantidade(produto->getId());
        std::cout << std::left << std::setw(4) << produto->getId()
                  << std::setw(23) << produto->getNome()
                  << std::setw(12) << produto->getCategoria()
                  << std::setw(14) << produto->getColecao()
                  << std::right << std::setw(9) << std::fixed << std::setprecision(2)
                  << produto->getPreco() << std::setw(10);
        if (quantidade == 0) {
            std::cout << "esgotado";
        } else {
            std::cout << quantidade;
        }
        std::cout << "\n    Material: " << produto->getMaterial();
        std::vector<std::string> tamanhos = produto->getTamanhos();
        if (!tamanhos.empty()) {
            std::cout << " | Tamanhos:";
            for (const std::string& tamanho : tamanhos) {
                std::cout << " " << tamanho;
            }
        }
        std::cout << "\n";
    }
}

static void buscarPorNome(Loja& loja) {
    std::string termo = paraMinusculas(lerTexto("Nome ou parte do nome: "));
    std::vector<Produto*> encontrados;
    for (Produto* produto : loja.getCatalogo()) {
        if (paraMinusculas(produto->getNome()).find(termo) != std::string::npos) {
            encontrados.push_back(produto);
        }
    }
    mostrarProdutos(loja, encontrados);
}

void menuCatalogo(Loja& loja) {
    while (true) {
        std::cout << "\n--- Catalogo ---\n"
                  << "[1] Ver todos os produtos\n"
                  << "[2] Buscar por nome\n"
                  << "[3] Filtrar por categoria\n"
                  << "[4] Montar kit com desconto\n"
                  << "[0] Voltar\n";
        int opcao = lerInteiro("Escolha uma opcao: ", 0, 4);
        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            mostrarProdutos(loja, loja.getCatalogo());
        } else if (opcao == 2) {
            buscarPorNome(loja);
        } else {
            std::cout << "Em construcao.\n";
        }
    }
}
