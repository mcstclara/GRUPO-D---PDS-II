#include "KitRoupas.hpp"


KitRoupas::KitRoupas(int id,
                     const std::string& nome,
                     const std::string& categoria,
                     const std::string& colecao,
                     double desconto)
    : Produto(id, nome, categoria, 0.0, "Variado", colecao),
      desconto(desconto) {}

void KitRoupas::adicionarProduto(Produto* produto) {
}

void KitRoupas::removerProduto(Produto* produto) {
}

std::vector<Produto*> KitRoupas::getProdutos() const {
    return {}; 
}

double KitRoupas::getDesconto() const {
    return 0.0; 
}

double KitRoupas::getPreco() const {
    return 0.0; 
}
