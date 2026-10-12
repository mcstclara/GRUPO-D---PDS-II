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
    return 0; 
}

std::string Produto::getNome() const {
    return ""; 
}

std::string Produto::getCategoria() const {
    return ""; 
}

double Produto::getPreco() const {
    return 0.0; 
}

std::string Produto::getMaterial() const {
    return ""; 
}

std::string Produto::getColecao() const {
    return ""; 
}

void Produto::adicionarTamanho(const std::string& tamanho,
                               const std::vector<double>& medidas) {
}

std::vector<std::string> Produto::getTamanhos() const {
    return {}; 
}

std::vector<double> Produto::getMedidas(const std::string& tamanho) const {
    return {}; 
}

bool Produto::temTamanho(const std::string& tamanho) const {
    return false;
}
