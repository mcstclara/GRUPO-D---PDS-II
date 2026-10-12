#include "doctest.h"
#include "Produto.hpp"

TEST_CASE("Produto: construtor armazena as informações do produto") {
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");

    CHECK(camiseta.getId() == 1);
    CHECK(camiseta.getNome() == "Camiseta Basica");
    CHECK(camiseta.getCategoria() == "Blusas");
    CHECK(camiseta.getPreco() == doctest::Approx(59.90));
    CHECK(camiseta.getMaterial() == "Algodao");
    CHECK(camiseta.getColecao() == "Verao 2026");
}
