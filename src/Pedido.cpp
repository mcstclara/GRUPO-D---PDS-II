#include "Pedido.hpp"

Pedido::Pedido(int id, Cliente* cliente)
    : id(id), cliente(cliente), valorTotal(0.0), status("Pendente") {}

void Pedido::adicionarProduto(Produto* produto, int quantidade) {
    produtos.push_back(produto);
    quantidades.push_back(quantidade);
}

double Pedido::calcularTotal() const {
    return 0.0; // TODO implementar no C8
}

int Pedido::getId() const {
    return id;
}

Cliente* Pedido::getCliente() const {
    return cliente;
}

std::vector<Produto*> Pedido::getProdutos() const {
    return produtos;
}

std::vector<int> Pedido::getQuantidades() const {
    return quantidades;
}

std::string Pedido::getStatus() const {
    return status;
}

void Pedido::atualizarStatus(const std::string& status) {
    this->status = status;
}

std::string Pedido::gerarResumo() const {
    return ""; // TODO implementar no C8
}
