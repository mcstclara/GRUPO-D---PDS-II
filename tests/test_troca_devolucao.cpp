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
