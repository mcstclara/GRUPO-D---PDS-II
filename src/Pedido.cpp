#include "Pedido.hpp"

Pedido::Pedido(int id, Cliente* cliente)
    : id(id), cliente(cliente), valorTotal(0.0), status("Pendente") {}

void Pedido::adicionarProduto(Produto* produto, int quantidade) {
    // TODO implementar no C8
}

double Pedido::calcularTotal() const {
    return 0.0; // TODO implementar no C8
}

int Pedido::getId() const {
    return 0; // TODO implementar no C8
}

Cliente* Pedido::getCliente() const {
    return nullptr; // TODO implementar no C8
}

std::vector<Produto*> Pedido::getProdutos() const {
    return {}; // TODO implementar no C8
}

std::vector<int> Pedido::getQuantidades() const {
    return {}; // TODO implementar no C8
}

std::string Pedido::getStatus() const {
    return ""; // TODO implementar no C8
}

void Pedido::atualizarStatus(const std::string& status) {
    // TODO implementar no C8
}

std::string Pedido::gerarResumo() const {
    return ""; // TODO implementar no C8
}
