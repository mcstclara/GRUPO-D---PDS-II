#include "KitRoupas.hpp"
#include <stdexcept>


KitRoupas::KitRoupas(int id,
                     const std::string& nome,
                     const std::string& categoria,
                     const std::string& colecao,
                     double desconto)
        : Produto(id, nome, categoria, 0.0, "Variado", colecao),
          desconto(desconto) {
           if (desconto < 0.0 || desconto > 100.0) {
           throw std::invalid_argument("O desconto do kit deve estar entre 0 e 100%.");
           }
        }


void KitRoupas::adicionarProduto(Produto* produto) {
    if (produto == nullptr) {
        throw std::invalid_argument("Produto vazio nao pode entrar no kit.");
    }
    if (produto == this) {
        throw std::invalid_argument("Um kit nao pode conter a si mesmo.");
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