#include "Administrador.hpp"
#include "Estoque.hpp"
#include "Produto.hpp"
#include <stdexcept>



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
        throw std::invalid_argument("Produto vazio nao pode ser cadastrado.");
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
        throw std::invalid_argument("Produto vazio nao pode ser atualizado.");
    }
    for (size_t i = 0; i < produtos.size(); i++) {
      if (produtos[i]->getId() == produto->getId()){
          produtos[i] = produto;
         return;
        }
    }

    throw std::invalid_argument("O produto " + std::to_string(produto->getId()) + " nao esta no catalogo.");
}

void Administrador::removerProduto(Produto* produto) {
    if (produto == nullptr){
        throw std::invalid_argument("Produto vazio nao pode ser removido.");
    }
    for (size_t i = 0; i<produtos.size(); i++){
        if (produtos[i]->getId() == produto->getId()){
            produtos.erase(produtos.begin() + i);
        return;
        }
    }
    throw std::invalid_argument("O produto " + std::to_string(produto->getId()) + " nao esta no catalogo.");
}


void Administrador::atualizarEstoque(Estoque* estoque, int produtoId, int quantidade) {
    if (estoque == nullptr) {
        throw std::invalid_argument("Estoque vazio.");    
    }
    if (quantidade > 0) {
        estoque->adicionarUnidades(produtoId, quantidade);
    } else {
        estoque->removerUnidades(produtoId, -quantidade);
    }
}

void Administrador::atualizarStatusPedido(Pedido* pedido, const std::string& status) {
    if (pedido == nullptr){
        throw std::invalid_argument("Pedido vazio.");
    }
    
    const std::vector<std::string> permitidos = {
        "Pendente", "Pago", "Enviado", "Entregue", "Cancelado"};
    bool valido = false;

    for (const std::string& permitido : permitidos) {
        if (status == permitido) {
            valido = true;
        }
    }

    if (!valido) {
        throw std::invalid_argument("Status de pedido desconhecido: " + status + ".");
    }    

    if (pedido->getStatus() != status){
        pedido->atualizarStatus(status);
    }
}
