#include <iostream>
#include <string>
#include <vector>

#include "Cliente.hpp"
#include "Entrada.hpp"
#include "Loja.hpp"
#include "Menus.hpp"
#include "Produto.hpp"
#include "ProvadorVirtual.hpp"

void menuProvador(Loja& loja) {
    Cliente& cliente = loja.exigirCliente();
    std::cout << "\n--- Provador virtual ---\n";
    int produtoId = lerInteiro("ID do produto (veja no catalogo): ", 1, 1000000);
    Produto* produto = loja.buscarProduto(produtoId);
    if (produto->getTamanhos().empty()) {
        std::cout << produto->getNome() << " tem tamanho unico.\n";
        return;
    }

    const ProvadorVirtual& provador = loja.getProvador();
    std::string recomendado = provador.recomendarTamanho(cliente, *produto);
    if (recomendado.empty()) {
        std::cout << "Nenhum tamanho de " << produto->getNome()
                  << " e adequado para as suas medidas.\n";
        return;
    }
    std::cout << "Para " << produto->getNome() << ", recomendamos o tamanho "
              << recomendado << ".\n";

    std::vector<std::string> compativeis =
        provador.encontrarTamanhosCompativeis(cliente, *produto);
    std::cout << "Todos os tamanhos que servem:";
    for (const std::string& tamanho : compativeis) {
        std::cout << " " << tamanho;
    }
    std::cout << "\n";
}
