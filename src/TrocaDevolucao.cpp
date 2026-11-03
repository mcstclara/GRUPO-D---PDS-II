#include "TrocaDevolucao.hpp"
#include "Pedido.hpp"

#include <stdexcept>


TrocaDevolucao::TrocaDevolucao(Pedido* pedido,
                               Produto* produto,
                               const std::string& motivo)
        : pedido(pedido), produto(produto), motivo(motivo), status("Criada") {
    if (motivo.empty()) {
        throw std::invalid_argument("Informe o motivo da troca ou devolucao.");
    }
}

bool TrocaDevolucao::verificarElegibilidade() const {
    if (pedido == nullptr || produto == nullptr) {
        return false;
    }
    if (pedido->getStatus() != "Entregue") {
        return false;
    }
    for (Produto* p : pedido->getProdutos()) {
        if (p == produto) {
            return true;
        }
    }
    return false;
}

void TrocaDevolucao::solicitarTroca() {
    if (verificarElegibilidade()) {
        atualizarStatus("Troca solicitada");
    } else {
        atualizarStatus("Recusada");
    }
}

void TrocaDevolucao::solicitarDevolucao() {
    if (verificarElegibilidade()) {
        atualizarStatus("Devolucao solicitada");
    } else {
        atualizarStatus("Recusada");
    }
}

void TrocaDevolucao::cancelarSolicitacao() {
    atualizarStatus("Cancelada");
}

Pedido* TrocaDevolucao::getPedido() const {
    return pedido;
}

Produto* TrocaDevolucao::getProduto() const {
    return produto;
}

std::string TrocaDevolucao::getMotivo() const {
    return motivo;
}

std::string TrocaDevolucao::getStatus() const {
    return status;
}

void TrocaDevolucao::atualizarStatus(const std::string& status) {
    if (status.empty()) {
        throw std::invalid_argument("O status da solicitacao nao pode ser vazio.");
    }
    this->status = status;
}