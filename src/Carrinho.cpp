#include "Carrinho.hpp"

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
    // TODO implementar no C8
}

void Carrinho::atualizarQuantidade(Produto* produto, int quantidade) {
    // TODO implementar no C8
}

double Carrinho::calcularTotal() const {
    return 0.0; // TODO implementar no C8
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
