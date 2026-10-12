#include "doctest.h"
#include "Estoque.hpp"

TEST_CASE("Estoque: produto nunca cadastrado tem quantidade zero") {
    Estoque estoque;
    CHECK(estoque.consultarQuantidade(1) == 0);
}

TEST_CASE("Estoque: adicionar unidades aumenta a quantidade") {
    Estoque estoque;
    estoque.adicionarUnidades(1, 10);
    CHECK(estoque.consultarQuantidade(1) == 10);

    estoque.adicionarUnidades(1, 5);
    CHECK(estoque.consultarQuantidade(1) == 15);

    estoque.adicionarUnidades(2, 3);
    CHECK(estoque.consultarQuantidade(2) == 3);
    CHECK(estoque.consultarQuantidade(1) == 15);
}
