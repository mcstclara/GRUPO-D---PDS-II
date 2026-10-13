#include "doctest.h"
#include "KitRoupas.hpp"

TEST_CASE("KitRoupas: construtor armazena os dados do kit") {
    KitRoupas kit(50, "Kit Praia", "Kits", "Verao 2026", 10.0);

    CHECK(kit.getId() == 50);
    CHECK(kit.getNome() == "Kit Praia");
    CHECK(kit.getCategoria() == "Kits");
    CHECK(kit.getColecao() == "Verao 2026");
    CHECK(kit.getDesconto() == doctest::Approx(10.0));
    CHECK(kit.getProdutos().empty());
}

TEST_CASE("KitRoupas: adiciona e remove produtos do kit") {
    Produto biquini(1, "Biquini", "Praia", 120.0, "Lycra", "Verao 2026");
    Produto saida(2, "Saida de Praia", "Praia", 80.0, "Linho", "Verao 2026");
    KitRoupas kit(50, "Kit Praia", "Kits", "Verao 2026", 10.0);

    kit.adicionarProduto(&biquini);
    kit.adicionarProduto(&saida);
    REQUIRE(kit.getProdutos().size() == 2);
    CHECK(kit.getProdutos()[0] == &biquini);
    CHECK(kit.getProdutos()[1] == &saida);

    kit.removerProduto(&biquini);
    REQUIRE(kit.getProdutos().size() == 1);
    CHECK(kit.getProdutos()[0] == &saida);
}
