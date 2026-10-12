#include "Administrador.hpp"

// Esqueleto (stub) criado no C7 para os testes compilarem.
// Os comportamentos reais serão implementados no C8.

Administrador::Administrador(int id,
                             const std::string& nome,
                             const std::string& email,
                             const std::string& senha)
    : id(id), nome(nome), email(email), senha(senha) {}

int Administrador::getId() const {
    return 0; // TODO (C8): implementar
}

std::string Administrador::getNome() const {
    return ""; // TODO (C8): implementar
}

std::string Administrador::getEmail() const {
    return ""; // TODO (C8): implementar
}

void Administrador::cadastrarProduto(Produto* produto) {
    // TODO (C8): implementar
}

void Administrador::atualizarProduto(Produto* produto) {
    // TODO (C8): implementar
}

void Administrador::removerProduto(Produto* produto) {
    // TODO (C8): implementar
}

void Administrador::atualizarEstoque(Estoque* estoque, int produtoId, int quantidade) {
    // TODO (C8): implementar
}

void Administrador::atualizarStatusPedido(Pedido* pedido, const std::string& status) {
    // TODO (C8): implementar
}
