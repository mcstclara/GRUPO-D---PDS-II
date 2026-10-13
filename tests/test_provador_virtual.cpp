#include "doctest.h"
#include "ProvadorVirtual.hpp"
#include "Cliente.hpp"
#include "Produto.hpp"

static Produto criarCamiseta() {
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");
    camiseta.adicionarTamanho("P", {88.0, 72.0, 94.0});
    camiseta.adicionarTamanho("M", {96.0, 80.0, 102.0});
    camiseta.adicionarTamanho("G", {104.0, 88.0, 110.0});
    return camiseta;
}

TEST_CASE("ProvadorVirtual: verifica se um tamanho é compatível") {
    ProvadorVirtual provador;
    Produto camiseta = criarCamiseta();

    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    cliente.definirMedidas(165.0, 60.0, 90.0, 74.0, 96.0);
    cliente.definirPreferencia(Cliente::PreferenciaCaimento::NORMAL);

    CHECK(provador.tamanhoCompativel(cliente, camiseta, "M") == true);
    CHECK(provador.tamanhoCompativel(cliente, camiseta, "P") == false);
    CHECK(provador.tamanhoCompativel(cliente, camiseta, "GG") == false);
}
