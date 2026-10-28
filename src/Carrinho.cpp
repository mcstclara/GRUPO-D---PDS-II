#include "Carrinho.hpp"
#include "Produto.hpp"
#include "Cliente.hpp"
#include "Pedido.hpp"

Carrinho::Carrinho(Cliente* cliente) : cliente(cliente) {}

void Carrinho::adicionarProduto(Produto* produto, int quantidade) {
    for (std::size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i] == produto) {
            quantidades[i] += quantidade;
            return;
        }
    }
    produtos.push_back(produto); 
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
    static int proximoId = 1;
    Pedido* pedido = new Pedido(proximoId, cliente);
    proximoId++;
    for (std::size_t i = 0; i < produtos.size(); i++) {
        pedido->adicionarProduto(produtos[i], quantidades[i]);
    }
    if (cliente != nullptr) {
        cliente->adicionarPedido(pedido);
    }
    produtos.clear();
    quantidades.clear();
    return pedido;
}
