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
}

std::vector<Produto*> KitRoupas::getProdutos() const {
    return produtos;
}

double KitRoupas::getDesconto() const {
    return desconto;
}

double KitRoupas::getPreco() const {
    return 0.0; 
}
