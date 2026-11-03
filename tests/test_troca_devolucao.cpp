#include "doctest.h"
#include "TrocaDevolucao.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"

#include <stdexcept>

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

TEST_CASE("TrocaDevolucao: exige motivo e status preenchidos") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Pedido pedido(100, nullptr);
    CHECK_THROWS_AS(TrocaDevolucao(&pedido, &vestido, ""), std::invalid_argument);
    TrocaDevolucao solicitacao(&pedido, &vestido, "Ficou apertado");
    CHECK_THROWS_AS(solicitacao.atualizarStatus(""), std::invalid_argument);
    CHECK(solicitacao.getStatus() == "Criada");
}

TEST_CASE("TrocaDevolucao: explica o motivo da recusa") {
    Produto vestido(1, "Vestido Floral", "Vestidos", 150.0, "Viscose", "Verao 2026");
    Produto bermuda(2, "Bermuda", "Shorts", 89.90, "Sarja", "Verao 2026");
    Pedido pedido(100, nullptr);
    pedido.adicionarProduto(&vestido, 1);

    TrocaDevolucao naoEntregue(&pedido, &vestido, "Ficou apertado");
    CHECK(naoEntregue.explicarRecusa() ==
          "O pedido ainda nao foi entregue (status: Pendente).");

    pedido.atualizarStatus("Entregue");
    TrocaDevolucao foraDoPedido(&pedido, &bermuda, "Nao gostei");
    CHECK(foraDoPedido.explicarRecusa() == "Este produto nao faz parte do pedido.");

    TrocaDevolucao valida(&pedido, &vestido, "Ficou apertado");
    CHECK(valida.explicarRecusa().empty());

    TrocaDevolucao incompleta(nullptr, &vestido, "Ficou apertado");
    CHECK(incompleta.explicarRecusa() ==
          "A solicitacao precisa de um pedido e de um produto.");
}
