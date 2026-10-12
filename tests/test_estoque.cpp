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


TEST_CASE("Estoque: remover unidades disponíveis diminui a quantidade") {
    Estoque estoque;
    estoque.adicionarUnidades(1, 10);

    CHECK(estoque.removerUnidades(1, 4) == true);
    CHECK(estoque.consultarQuantidade(1) == 6);
}

TEST_CASE("Estoque: não permite que a quantidade fique negativa") {
    Estoque estoque;
    estoque.adicionarUnidades(1, 3);

    CHECK(estoque.removerUnidades(1, 5) == false);
    CHECK(estoque.consultarQuantidade(1) == 3);

    CHECK(estoque.removerUnidades(2, 1) == false);
    CHECK(estoque.consultarQuantidade(2) == 0);
}


TEST_CASE("Estoque: verifica se há quantidade suficiente") {
    Estoque estoque;
    estoque.adicionarUnidades(1, 5);

    CHECK(estoque.temQuantidadeSuficiente(1, 5) == true);
    CHECK(estoque.temQuantidadeSuficiente(1, 3) == true);
    CHECK(estoque.temQuantidadeSuficiente(1, 6) == false);
}

TEST_CASE("Estoque: identifica produtos esgotados") {
    Estoque estoque;
    CHECK(estoque.estaEsgotado(1) == true);

    estoque.adicionarUnidades(1, 2);
    CHECK(estoque.estaEsgotado(1) == false);

    estoque.removerUnidades(1, 2);
    CHECK(estoque.estaEsgotado(1) == true);
}
