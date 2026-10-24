#include "Produto.hpp"

Produto::Produto(int id,
                 const std::string& nome,
                 const std::string& categoria,
                 double preco,
                 const std::string& material,
                 const std::string& colecao)
    : id(id), nome(nome), categoria(categoria), preco(preco),
      material(material), colecao(colecao) {}

int Produto::getId() const {
    return id;
}

std::string Produto::getNome() const {
    return nome;
}

std::string Produto::getCategoria() const {
    return categoria;
}

double Produto::getPreco() const {
    return preco;
}

std::string Produto::getMaterial() const {
    return material;
}

std::string Produto::getColecao() const {
    return colecao;
}

void Produto::adicionarTamanho(const std::string& tamanho,
                               const std::vector<double>& medidas) {
    if (medidasPorTamanho.count(tamanho) == 0) {
        tamanhos.push_back(tamanho);
    }
    medidasPorTamanho[tamanho] = medidas;
}

std::vector<std::string> Produto::getTamanhos() const {
    return tamanhos;
}

std::vector<double> Produto::getMedidas(const std::string& tamanho) const {
    auto it = medidasPorTamanho.find(tamanho);
    if (it == medidasPorTamanho.end()) {
        return {};
    }
    return it->second;
}

bool Produto::temTamanho(const std::string& tamanho) const {
    return medidasPorTamanho.count(tamanho) > 0;
}
