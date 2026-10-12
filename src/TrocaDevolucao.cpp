#include "TrocaDevolucao.hpp"


TrocaDevolucao::TrocaDevolucao(Pedido* pedido,
                               Produto* produto,
                               const std::string& motivo)
    : pedido(pedido), produto(produto), motivo(motivo), status("") {}

bool TrocaDevolucao::verificarElegibilidade() const {
    return false;
}

void TrocaDevolucao::solicitarTroca() {r
}

void TrocaDevolucao::solicitarDevolucao() {
}

void TrocaDevolucao::cancelarSolicitacao() {
}

Pedido* TrocaDevolucao::getPedido() const {
    return nullptr;
}

Produto* TrocaDevolucao::getProduto() const {
    return nullptr;
}

std::string TrocaDevolucao::getMotivo() const {
    return "";
}

std::string TrocaDevolucao::getStatus() const {
    return "";
}

void TrocaDevolucao::atualizarStatus(const std::string& status) {
}
