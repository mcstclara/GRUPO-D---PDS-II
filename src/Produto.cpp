#include "Produto.hpp"
#include <stdexcept>

Produto::Produto(int id,
                 const std::string& nome,
                 const std::string& categoria,
                 double preco,
                 const std::string& material,
                 const std::string& colecao)
    : id(id), nome(nome), categoria(categoria), preco(preco),
      material(material), colecao(colecao) {
    if (id <= 0) {
        throw std::invalid_argument("O id do produto deve ser maior que zero.");
    }
    if (nome.empty()) {
        throw std::invalid_argument("O nome do produto nao pode ser vazio.");
    }
    if (preco < 0.0) {
        throw std::invalid_argument("O preco do produto nao pode ser negativo.");
    }
}

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
    if (tamanho.empty()) {
        throw std::invalid_argument("O nome do tamanho nao pode ser vazio.");
    }
    if (medidas.size() != 3) {
        throw std::invalid_argument("Informe 3 medidas: peito, cintura e quadril.");
    }
    for (double medida : medidas) {
        if (medida <= 0.0) {
            throw std::invalid_argument("As medidas devem ser maiores que zero.");
        }
    }

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
