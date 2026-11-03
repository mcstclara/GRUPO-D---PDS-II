#include "doctest.h"
#include "Cliente.hpp"
#include "Pedido.hpp"

#include <stdexcept>


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

TEST_CASE("Cliente: medidas começam zeradas") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    CHECK(cliente.getAltura() == doctest::Approx(0.0));
    CHECK(cliente.getPeso() == doctest::Approx(0.0));
    CHECK(cliente.getPeito() == doctest::Approx(0.0));
    CHECK(cliente.getCintura() == doctest::Approx(0.0));
    CHECK(cliente.getQuadril() == doctest::Approx(0.0));
}

TEST_CASE("Cliente: define as medidas corporais") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    cliente.definirMedidas(165.0, 60.0, 90.0, 70.0, 96.0);

    CHECK(cliente.getAltura() == doctest::Approx(165.0));
    CHECK(cliente.getPeso() == doctest::Approx(60.0));
    CHECK(cliente.getPeito() == doctest::Approx(90.0));
    CHECK(cliente.getCintura() == doctest::Approx(70.0));
    CHECK(cliente.getQuadril() == doctest::Approx(96.0));
}

TEST_CASE("Cliente: preferência de caimento padrão é NORMAL") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    CHECK(cliente.getPreferencia() == Cliente::PreferenciaCaimento::NORMAL);
}

TEST_CASE("Cliente: altera a preferência de caimento") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    cliente.definirPreferencia(Cliente::PreferenciaCaimento::JUSTO);
    CHECK(cliente.getPreferencia() == Cliente::PreferenciaCaimento::JUSTO);

    cliente.definirPreferencia(Cliente::PreferenciaCaimento::SOLTO);
    CHECK(cliente.getPreferencia() == Cliente::PreferenciaCaimento::SOLTO);
}

TEST_CASE("Cliente: associa pedidos ao cliente") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    CHECK(cliente.getPedidos().empty());

    Pedido pedido1(100, &cliente);
    Pedido pedido2(101, &cliente);
    cliente.adicionarPedido(&pedido1);
    cliente.adicionarPedido(&pedido2);

    std::vector<Pedido*> pedidos = cliente.getPedidos();
    REQUIRE(pedidos.size() == 2);
    CHECK(pedidos[0] == &pedido1);
    CHECK(pedidos[1] == &pedido2);
}

TEST_CASE("Cliente: recusa nome, e-mail e senha inválidos") {
    CHECK_THROWS_AS(Cliente(1, "", "ana@email.com", "senha123"), std::invalid_argument);
    CHECK_THROWS_AS(Cliente(1, "Ana", "anaemail.com", "senha123"), std::invalid_argument);
    CHECK_THROWS_AS(Cliente(1, "Ana", "ana@email", "senha123"), std::invalid_argument);
    CHECK_THROWS_AS(Cliente(1, "Ana", "ana@email.com", "123"), std::invalid_argument);
}

TEST_CASE("Cliente: atualizações inválidas não mudam os dados") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    CHECK_THROWS_AS(cliente.atualizarNome(""), std::invalid_argument);
    CHECK_THROWS_AS(cliente.atualizarEmail("sem-arroba"), std::invalid_argument);
    CHECK_THROWS_AS(cliente.atualizarSenha("abc"), std::invalid_argument);
    CHECK(cliente.getNome() == "Ana");
    CHECK(cliente.getEmail() == "ana@email.com");
}

TEST_CASE("Cliente: recusa medidas e endereço inválidos") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    CHECK(cliente.temMedidas() == false);
    CHECK_THROWS_AS(cliente.definirMedidas(165.0, 60.0, -90.0, 70.0, 96.0),
                    std::invalid_argument);
    CHECK_THROWS_AS(cliente.definirMedidas(0.0, 60.0, 90.0, 70.0, 96.0),
                    std::invalid_argument);
    CHECK(cliente.temMedidas() == false);
    cliente.definirMedidas(165.0, 60.0, 90.0, 70.0, 96.0);
    CHECK(cliente.temMedidas() == true);
    CHECK_THROWS_AS(cliente.adicionarEndereco(""), std::invalid_argument);
    CHECK(cliente.getEnderecos().empty());
}

TEST_CASE("Cliente: confere a senha no login") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");
    CHECK(cliente.verificarSenha("senha123") == true);
    CHECK(cliente.verificarSenha("Senha123") == false);
    CHECK(cliente.verificarSenha("") == false);
    cliente.atualizarSenha("novaSenha456");
    CHECK(cliente.verificarSenha("novaSenha456") == true);
    CHECK(cliente.verificarSenha("senha123") == false);
}
