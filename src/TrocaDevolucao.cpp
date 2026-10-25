#include "TrocaDevolucao.hpp"


TrocaDevolucao::TrocaDevolucao(Pedido* pedido,
                               Produto* produto,
                               const std::string& motivo)
    : pedido(pedido), produto(produto), motivo(motivo), status("Criada") {}


bool TrocaDevolucao::verificarElegibilidade() const {
    return false;
}

void TrocaDevolucao::solicitarTroca() {
}

void TrocaDevolucao::solicitarDevolucao() {
}

void TrocaDevolucao::cancelarSolicitacao() {
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