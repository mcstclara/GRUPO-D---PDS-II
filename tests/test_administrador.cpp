#include "doctest.h"
#include "Administrador.hpp"
#include "Estoque.hpp"
#include "Pedido.hpp"

TEST_CASE("Administrador: construtor armazena os dados") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");

    CHECK(admin.getId() == 1);
    CHECK(admin.getNome() == "Maria");
    CHECK(admin.getEmail() == "maria@loja.com");
}
