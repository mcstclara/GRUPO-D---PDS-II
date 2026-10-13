#include "doctest.h"
#include "TrocaDevolucao.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"

TEST_CASE("TrocaDevolucao: construtor armazena pedido, produto e motivo") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Pedido pedido(100, nullptr);
    pedido.adicionarProduto(&vestido, 1);

    TrocaDevolucao solicitacao(&pedido, &vestido, "Tamanho errado");

    CHECK(solicitacao.getPedido() == &pedido);
    CHECK(solicitacao.getProduto() == &vestido);
    CHECK(solicitacao.getMotivo() == "Tamanho errado");
    CHECK(solicitacao.getStatus() == "Criada");
}


TEST_CASE("TrocaDevolucao: é elegível quando o pedido foi entregue e contém o produto") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Pedido pedido(100, nullptr);
    pedido.adicionarProduto(&vestido, 1);
    pedido.atualizarStatus("Entregue");

    TrocaDevolucao solicitacao(&pedido, &vestido, "Tamanho errado");
    CHECK(solicitacao.verificarElegibilidade() == true);
}

TEST_CASE("TrocaDevolucao: não é elegível quando o pedido não foi entregue") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Pedido pedido(100, nullptr);
    pedido.adicionarProduto(&vestido, 1);
    pedido.atualizarStatus("Enviado");

    TrocaDevolucao solicitacao(&pedido, &vestido, "Tamanho errado");
    CHECK(solicitacao.verificarElegibilidade() == false);
}

TEST_CASE("TrocaDevolucao: não é elegível quando o produto não está no pedido") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Produto saia(2, "Saia Midi", "Saias", 90.0, "Algodao", "Verao 2026");
    Pedido pedido(100, nullptr);
    pedido.adicionarProduto(&vestido, 1);
    pedido.atualizarStatus("Entregue");

    TrocaDevolucao solicitacao(&pedido, &saia, "Nao gostei");
    CHECK(solicitacao.verificarElegibilidade() == false);
}

TEST_CASE("TrocaDevolucao: solicita troca e devolução quando elegível") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Pedido pedido(100, nullptr);
    pedido.adicionarProduto(&vestido, 1);
    pedido.atualizarStatus("Entregue");

    TrocaDevolucao troca(&pedido, &vestido, "Tamanho errado");
    troca.solicitarTroca();
    CHECK(troca.getStatus() == "Troca solicitada");

    TrocaDevolucao devolucao(&pedido, &vestido, "Defeito");
    devolucao.solicitarDevolucao();
    CHECK(devolucao.getStatus() == "Devolucao solicitada");
}

TEST_CASE("TrocaDevolucao: recusa a solicitação quando não elegível") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Pedido pedido(100, nullptr);
    pedido.adicionarProduto(&vestido, 1);

    TrocaDevolucao solicitacao(&pedido, &vestido, "Tamanho errado");
    solicitacao.solicitarTroca();
    CHECK(solicitacao.getStatus() == "Recusada");
}

TEST_CASE("TrocaDevolucao: cancela uma solicitação") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Pedido pedido(100, nullptr);
    pedido.adicionarProduto(&vestido, 1);
    pedido.atualizarStatus("Entregue");

    TrocaDevolucao solicitacao(&pedido, &vestido, "Tamanho errado");
    solicitacao.solicitarTroca();
    solicitacao.cancelarSolicitacao();
    CHECK(solicitacao.getStatus() == "Cancelada");
}
