#include "doctest.h"
#include "Cliente.hpp"
#include "Pedido.hpp"

TEST_CASE("Cliente: construtor armazena os dados de cadastro") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    CHECK(cliente.getId() == 1);
    CHECK(cliente.getNome() == "Ana");
    CHECK(cliente.getEmail() == "ana@email.com");
}

TEST_CASE("Cliente: atualiza nome e e-mail") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    cliente.atualizarNome("Ana Luisa");
    CHECK(cliente.getNome() == "Ana Luisa");

    cliente.atualizarEmail("analuisa@email.com");
    CHECK(cliente.getEmail() == "analuisa@email.com");

    cliente.atualizarSenha("novaSenha456");
    CHECK(cliente.getNome() == "Ana Luisa");
    CHECK(cliente.getEmail() == "analuisa@email.com");
}

TEST_CASE("Cliente: cadastra endereços de entrega") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    CHECK(cliente.getEnderecos().empty());

    cliente.adicionarEndereco("Av. Antonio Carlos, 6627 - Belo Horizonte");
    cliente.adicionarEndereco("Rua da Bahia, 100 - Belo Horizonte");

    std::vector<std::string> enderecos = cliente.getEnderecos();
    REQUIRE(enderecos.size() == 2);
    CHECK(enderecos[0] == "Av. Antonio Carlos, 6627 - Belo Horizonte");
    CHECK(enderecos[1] == "Rua da Bahia, 100 - Belo Horizonte");
}

