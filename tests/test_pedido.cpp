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

TEST_CASE("Pedido: adiciona produtos com suas quantidades") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    Produto calca(1, "Calca Jeans", "Calcas", 150.0, "Jeans", "Inverno 2026");
    Produto blusa(2, "Blusa de Trico", "Blusas", 90.0, "La", "Inverno 2026");
    Pedido pedido(100, &cliente);

    pedido.adicionarProduto(&calca, 1);
    pedido.adicionarProduto(&blusa, 2);

    std::vector<Produto*> produtos = pedido.getProdutos();
    std::vector<int> quantidades = pedido.getQuantidades();
    REQUIRE(produtos.size() == 2);
    REQUIRE(quantidades.size() == 2);
    CHECK(produtos[0] == &calca);
    CHECK(quantidades[0] == 1);
    CHECK(produtos[1] == &blusa);
    CHECK(quantidades[1] == 2);
}

TEST_CASE("Pedido: calcula o valor total") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    Produto calca(1, "Calca Jeans", "Calcas", 150.0, "Jeans", "Inverno 2026");
    Produto blusa(2, "Blusa de Trico", "Blusas", 90.0, "La", "Inverno 2026");
    Pedido pedido(100, &cliente);

    CHECK(pedido.calcularTotal() == doctest::Approx(0.0));

    pedido.adicionarProduto(&calca, 1);
    pedido.adicionarProduto(&blusa, 2);

    CHECK(pedido.calcularTotal() == doctest::Approx(330.0));
}

