#include "KitRoupas.hpp"


KitRoupas::KitRoupas(int id,
                     const std::string& nome,
                     const std::string& categoria,
                     const std::string& colecao,
                     double desconto)
    : Produto(id, nome, categoria, 0.0, "Variado", colecao),
      desconto(desconto) {}

void KitRoupas::adicionarProduto(Produto* produto) {
    if (produto == nullptr) {
        return;
    }
    produtos.push_back(produto);
}

void KitRoupas::removerProduto(Produto* produto) {
    for (std::size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i] == produto) {
            produtos.erase(produtos.begin() + i);
            return;
        }
    }
}

std::vector<Produto*> KitRoupas::getProdutos() const {
    return produtos;
}

double KitRoupas::getDesconto() const {
    return desconto;
}

double KitRoupas::getPreco() const {
    double soma = 0.0;
    for (Produto* produto : produtos) {
        soma += produto->getPreco();
    }
    return soma * (1.0 - desconto / 100.0);
}