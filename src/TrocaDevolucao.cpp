#include "TrocaDevolucao.hpp"
#include "Pedido.hpp"

#include <stdexcept>

const int TrocaDevolucao::PRAZO_DIAS = 30;


TrocaDevolucao::TrocaDevolucao(Pedido* pedido,
                               Produto* produto,
                               const std::string& motivo)
        : pedido(pedido), produto(produto), motivo(motivo), status("Criada") {
    if (motivo.empty()) {
        throw std::invalid_argument("Informe o motivo da troca ou devolucao.");
    }
}

std::string TrocaDevolucao::explicarRecusa() const {
    if (pedido == nullptr || produto == nullptr) {
        return "A solicitacao precisa de um pedido e de um produto.";
    }
    if (pedido->getStatus() != "Entregue") {
        return "O pedido ainda nao foi entregue (status: " + pedido->getStatus() + ").";
    }
    for (Produto* p : pedido->getProdutos()) {
        if (p == produto) {
            return "";
        }
    }
    return "Este produto nao faz parte do pedido.";
}

bool TrocaDevolucao::verificarElegibilidade() const {
    return explicarRecusa().empty();
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