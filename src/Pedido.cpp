#include "Pedido.hpp"
#include "Produto.hpp"
#include <sstream>

Pedido::Pedido(int id, Cliente* cliente)
    : id(id), cliente(cliente), valorTotal(0.0), status("Pendente") {}

void Pedido::adicionarProduto(Produto* produto, int quantidade) {
    produtos.push_back(produto);
    quantidades.push_back(quantidade);
}

double Pedido::calcularTotal() const {
    double total = 0.0;
    for (std::size_t i = 0; i < produtos.size(); i++) {
        total += produtos[i]->getPreco() * quantidades[i];
    }
    return total;
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
    std::ostringstream resumo;
    resumo << "Pedido " << id << "\n";
    resumo << "Status: " << status << "\n";
    for (std::size_t i = 0; i < produtos.size(); i++) {
        resumo << quantidades[i] << "x " << produtos[i]->getNome()
               << " - R$ " << produtos[i]->getPreco() * quantidades[i] << "\n";
    }
    resumo << "Total: R$ " << calcularTotal() << "\n";
    return resumo.str();
}
