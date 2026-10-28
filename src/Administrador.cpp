#include "Administrador.hpp"
#include "Estoque.hpp"



Administrador::Administrador(int id,
                             const std::string& nome,
                             const std::string& email,
                             const std::string& senha)
    : id(id), nome(nome), email(email), senha(senha) {}

int Administrador::getId() const {
    return id;
}

std::string Administrador::getNome() const {
    return nome;
}

std::string Administrador::getEmail() const {
    return email;
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
    if (estoque == nullptr) {
        return;
    }
    if (quantidade > 0) {
        estoque->adicionarUnidades(produtoId, quantidade);
    } else {
        estoque->removerUnidades(produtoId, -quantidade);
    }
}

void Administrador::atualizarStatusPedido(Pedido* pedido, const std::string& status) {
    if (pedido == nullptr){
        return; 
    }
    if (pedido->getStatus() != status){
        pedido->atualizarStatus(status);
    }
}
