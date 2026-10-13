#include "doctest.h"
#include "Cliente.hpp"
#include "Pedido.hpp"

TEST_CASE("Cliente: construtor armazena os dados de cadastro") {
    Cliente cliente(1, "Ana", "ana@email.com", "senha123");

    CHECK(cliente.getId() == 1);
    CHECK(cliente.getNome() == "Ana");
    CHECK(cliente.getEmail() == "ana@email.com");
}
