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


TEST_CASE("Administrador: atualiza o estoque adicionando unidades") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");
    Estoque estoque;

    admin.atualizarEstoque(&estoque, 10, 20);
    CHECK(estoque.consultarQuantidade(10) == 20);
}

TEST_CASE("Administrador: atualiza o estoque removendo unidades sem ficar negativo") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");
    Estoque estoque;
    estoque.adicionarUnidades(10, 5);

    admin.atualizarEstoque(&estoque, 10, -3);
    CHECK(estoque.consultarQuantidade(10) == 2);

    admin.atualizarEstoque(&estoque, 10, -10);
    CHECK(estoque.consultarQuantidade(10) == 2);
}


TEST_CASE("Administrador: atualiza o status de um pedido") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");
    Pedido pedido(100, nullptr);

    admin.atualizarStatusPedido(&pedido, "Enviado");
    CHECK(pedido.getStatus() == "Enviado");

    admin.atualizarStatusPedido(&pedido, "Entregue");
    CHECK(pedido.getStatus() == "Entregue");
}
