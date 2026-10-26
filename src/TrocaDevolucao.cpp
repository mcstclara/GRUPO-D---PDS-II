#include "TrocaDevolucao.hpp"
#include "Pedido.hpp"


TrocaDevolucao::TrocaDevolucao(Pedido* pedido,
                               Produto* produto,
                               const std::string& motivo)
    : pedido(pedido), produto(produto), motivo(motivo), status("Criada") {}


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
    this->status = status;
}