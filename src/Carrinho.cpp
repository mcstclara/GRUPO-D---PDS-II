#include "Carrinho.hpp"
#include "Produto.hpp"

Carrinho::Carrinho(Cliente* cliente) : cliente(cliente) {}

void Carrinho::adicionarProduto(Produto* produto, int quantidade) {
    for (std::size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i] == produto) {
            quantidades[i] += quantidade;
            return;
        }
    }
    quantidades.push_back(quantidade);
}

void Carrinho::removerProduto(Produto* produto) {
    for (std::size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i] == produto) {
            produtos.erase(produtos.begin() + i);
            quantidades.erase(quantidades.begin() + i);
            return;
        }
    }
}

void Carrinho::atualizarQuantidade(Produto* produto, int quantidade) {
    for (std::size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i] == produto) {
            quantidades[i] = quantidade;
            return;
        }
    }
}

double Carrinho::calcularTotal() const {
    double total = 0.0;
    for (std::size_t i = 0; i < produtos.size(); i++) {
        total += produtos[i]->getPreco() * quantidades[i];
    }
    return total;
}

std::vector<Produto*> Carrinho::getProdutos() const {
    return produtos;
}

std::vector<int> Carrinho::getQuantidades() const {
    return quantidades;
}


Pedido* Carrinho::finalizarCompra() {
    return nullptr; // TODO implementar no C8
}
