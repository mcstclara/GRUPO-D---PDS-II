#include "doctest.h"
#include "Produto.hpp"

#include <stdexcept>


TEST_CASE("Produto: construtor armazena as informações do produto") {
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");

    CHECK(camiseta.getId() == 1);
    CHECK(camiseta.getNome() == "Camiseta Basica");
    CHECK(camiseta.getCategoria() == "Blusas");
    CHECK(camiseta.getPreco() == doctest::Approx(59.90));
    CHECK(camiseta.getMaterial() == "Algodao");
    CHECK(camiseta.getColecao() == "Verao 2026");
}


TEST_CASE("Produto: adiciona e consulta os tamanhos disponíveis") {
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");

    CHECK(camiseta.getTamanhos().empty());
    CHECK(camiseta.temTamanho("P") == false);

    camiseta.adicionarTamanho("P", {88.0, 72.0, 94.0});
    camiseta.adicionarTamanho("M", {96.0, 80.0, 102.0});

    std::vector<std::string> tamanhos = camiseta.getTamanhos();
    REQUIRE(tamanhos.size() == 2);
    CHECK(tamanhos[0] == "P");
    CHECK(tamanhos[1] == "M");

    CHECK(camiseta.temTamanho("P") == true);
    CHECK(camiseta.temTamanho("M") == true);
    CHECK(camiseta.temTamanho("G") == false);
}


TEST_CASE("Produto: retorna as medidas de cada tamanho") {
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");
    camiseta.adicionarTamanho("P", {88.0, 72.0, 94.0});

    std::vector<double> medidasP = camiseta.getMedidas("P");
    REQUIRE(medidasP.size() == 3);
    CHECK(medidasP[0] == doctest::Approx(88.0));
    CHECK(medidasP[1] == doctest::Approx(72.0));
    CHECK(medidasP[2] == doctest::Approx(94.0));
}

TEST_CASE("Produto: tamanho inexistente não tem medidas") {
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");
    camiseta.adicionarTamanho("P", {88.0, 72.0, 94.0});

    CHECK(camiseta.getMedidas("GG").empty());
}

TEST_CASE("Produto: recusa dados inválidos no cadastro") {
    CHECK_THROWS_AS(Produto(0, "Camiseta", "Blusas", 59.90, "Algodao", "Verao 2026"),
                    std::invalid_argument);
    CHECK_THROWS_AS(Produto(1, "", "Blusas", 59.90, "Algodao", "Verao 2026"),
                    std::invalid_argument);
    CHECK_THROWS_AS(Produto(1, "Camiseta", "Blusas", -1.0, "Algodao", "Verao 2026"),
                    std::invalid_argument);
}

TEST_CASE("Produto: recusa tamanhos sem as três medidas") {
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");
    CHECK_THROWS_AS(camiseta.adicionarTamanho("", {88.0, 72.0, 94.0}), std::invalid_argument);
    CHECK_THROWS_AS(camiseta.adicionarTamanho("P", {88.0, 72.0}), std::invalid_argument);
    CHECK_THROWS_AS(camiseta.adicionarTamanho("P", {88.0, -1.0, 94.0}), std::invalid_argument);
    CHECK(camiseta.getTamanhos().empty());
}
