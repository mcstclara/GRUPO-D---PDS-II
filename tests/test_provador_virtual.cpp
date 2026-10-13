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

TEST_CASE("ProvadorVirtual: encontra todos os tamanhos compatíveis") {
    ProvadorVirtual provador;
    Produto camiseta = criarCamiseta();

    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    cliente.definirMedidas(165.0, 60.0, 90.0, 74.0, 96.0);
    cliente.definirPreferencia(Cliente::PreferenciaCaimento::NORMAL);

    std::vector<std::string> compativeis =
        provador.encontrarTamanhosCompativeis(cliente, camiseta);
    REQUIRE(compativeis.size() == 2);
    CHECK(compativeis[0] == "M");
    CHECK(compativeis[1] == "G");
}

TEST_CASE("ProvadorVirtual: recomenda o menor tamanho compatível") {
    ProvadorVirtual provador;
    Produto camiseta = criarCamiseta();

    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    cliente.definirMedidas(165.0, 60.0, 90.0, 74.0, 96.0);
    cliente.definirPreferencia(Cliente::PreferenciaCaimento::NORMAL);

    CHECK(provador.recomendarTamanho(cliente, camiseta) == "M");
}

TEST_CASE("ProvadorVirtual: a preferência de caimento muda a recomendação") {
    ProvadorVirtual provador;
    Produto camiseta = criarCamiseta();

    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    cliente.definirMedidas(165.0, 60.0, 86.0, 70.0, 92.0);

    cliente.definirPreferencia(Cliente::PreferenciaCaimento::JUSTO);
    CHECK(provador.recomendarTamanho(cliente, camiseta) == "P");

    cliente.definirPreferencia(Cliente::PreferenciaCaimento::NORMAL);
    CHECK(provador.recomendarTamanho(cliente, camiseta) == "M");

    cliente.definirPreferencia(Cliente::PreferenciaCaimento::SOLTO);
    CHECK(provador.recomendarTamanho(cliente, camiseta) == "M");
}

TEST_CASE("ProvadorVirtual: informa quando não há tamanho adequado") {
    ProvadorVirtual provador;
    Produto camiseta = criarCamiseta();

    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    cliente.definirMedidas(185.0, 95.0, 110.0, 95.0, 115.0);
    cliente.definirPreferencia(Cliente::PreferenciaCaimento::NORMAL);

    CHECK(provador.encontrarTamanhosCompativeis(cliente, camiseta).empty());
    CHECK(provador.recomendarTamanho(cliente, camiseta) == "");
}
