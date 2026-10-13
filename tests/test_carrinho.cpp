#include "doctest.h"
#include "Carrinho.hpp"
#include "Cliente.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"

TEST_CASE("Carrinho: começa vazio") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    Carrinho carrinho(&cliente);

    CHECK(carrinho.getProdutos().empty());
    CHECK(carrinho.calcularTotal() == doctest::Approx(0.0));
}

TEST_CASE("Carrinho: adiciona produtos e calcula o total") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    Produto tenis(1, "Tenis Casual", "Calcados", 200.0, "Couro", "Basicos");
    Produto meia(2, "Meia", "Acessorios", 15.0, "Algodao", "Basicos");
    Carrinho carrinho(&cliente);

    carrinho.adicionarProduto(&tenis, 1);
    carrinho.adicionarProduto(&meia, 3);

    REQUIRE(carrinho.getProdutos().size() == 2);
    REQUIRE(carrinho.getQuantidades().size() == 2);
    CHECK(carrinho.getProdutos()[0] == &tenis);
    CHECK(carrinho.getQuantidades()[1] == 3);

    CHECK(carrinho.calcularTotal() == doctest::Approx(245.0));
}

TEST_CASE("Carrinho: adicionar o mesmo produto soma as quantidades") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    Produto meia(2, "Meia", "Acessorios", 15.0, "Algodao", "Basicos");
    Carrinho carrinho(&cliente);

    carrinho.adicionarProduto(&meia, 2);
    carrinho.adicionarProduto(&meia, 1);

    REQUIRE(carrinho.getProdutos().size() == 1);
    CHECK(carrinho.getQuantidades()[0] == 3);
}
