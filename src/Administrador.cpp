#include "Administrador.hpp"
#include "Estoque.hpp"
#include "Produto.hpp"



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

std::vector<Produto*> Administrador::getProdutos() const {
    return produtos;
}

void Administrador::cadastrarProduto(Produto* produto) {
    if (produto == nullptr) {
        return;
    }
    for (Produto* p : produtos) {
        if (p->getId() == produto->getId()) {
            return;
        }
    }
    produtos.push_back(produto);
}

void Administrador::atualizarProduto(Produto* produto) {
    if (produto == nullptr){
return;
}
for (size_t i = 0; i < produtos.size(); i++) {
   if (produtos[i]->getId() == produto->getId()){
   produtos[i] = produto;
   return;
}
}
}

void Administrador::removerProduto(Produto* produto) {
    if (produto == nullptr){
        return;
    }
    for (size_t i = 0; i<produtos.size(); i++){
        if (produtos[i]->getId() == produto->getId()){
            produtos.erase(produtos.begin() + i);
        return;
        }
    }
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
