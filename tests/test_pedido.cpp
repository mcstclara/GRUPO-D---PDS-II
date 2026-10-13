#include "doctest.h"
#include "Pedido.hpp"
#include "Produto.hpp"
#include "Cliente.hpp"

TEST_CASE("Pedido: construtor define id, cliente e status inicial") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    Pedido pedido(100, &cliente);

    CHECK(pedido.getId() == 100);
    CHECK(pedido.getCliente() == &cliente);
    CHECK(pedido.getStatus() == "Pendente");
    CHECK(pedido.getProdutos().empty());
}

TEST_CASE("Pedido: atualiza o status") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    Pedido pedido(100, &cliente);

    pedido.atualizarStatus("Enviado");
    CHECK(pedido.getStatus() == "Enviado");
}
