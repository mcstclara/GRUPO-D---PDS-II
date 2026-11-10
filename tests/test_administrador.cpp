#include "doctest.h"
#include "Administrador.hpp"
#include "Estoque.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"

#include <stdexcept>

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


TEST_CASE("Administrador: cadastra produtos no catálogo sem repetir id") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");
    Produto bermuda(2, "Bermuda", "Shorts", 89.90, "Sarja", "Verao 2026");
    CHECK(admin.getProdutos().empty());
    admin.cadastrarProduto(&camiseta);
    admin.cadastrarProduto(&bermuda);
    admin.cadastrarProduto(&camiseta);
    REQUIRE(admin.getProdutos().size() == 2);
    CHECK(admin.getProdutos()[0] == &camiseta);
    CHECK(admin.getProdutos()[1] == &bermuda);
}

TEST_CASE("Administrador: atualiza um produto do catálogo pelo id") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");
    Produto camisetaNova(1, "Camiseta Basica", "Blusas", 49.90, "Algodao", "Verao 2026");
    admin.cadastrarProduto(&camiseta);
    admin.atualizarProduto(&camisetaNova);
    REQUIRE(admin.getProdutos().size() == 1);
    CHECK(admin.getProdutos()[0] == &camisetaNova);
}

TEST_CASE("Administrador: remove um produto do catálogo") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");
    Produto bermuda(2, "Bermuda", "Shorts", 89.90, "Sarja", "Verao 2026");
    admin.cadastrarProduto(&camiseta);
    admin.cadastrarProduto(&bermuda);
    admin.removerProduto(&camiseta);
    REQUIRE(admin.getProdutos().size() == 1);
    CHECK(admin.getProdutos()[0] == &bermuda);
}


TEST_CASE("Administrador: recusa produtos vazios e produtos fora do catálogo") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");
    Produto camiseta(1, "Camiseta Basica", "Blusas", 59.90, "Algodao", "Verao 2026");
    CHECK_THROWS_AS(admin.cadastrarProduto(nullptr), std::invalid_argument);
    CHECK_THROWS_AS(admin.atualizarProduto(&camiseta), std::invalid_argument);
    CHECK_THROWS_AS(admin.removerProduto(&camiseta), std::invalid_argument);
    CHECK_THROWS_AS(admin.atualizarProduto(nullptr), std::invalid_argument);
    CHECK_THROWS_AS(admin.removerProduto(nullptr), std::invalid_argument);
    CHECK(admin.getProdutos().empty());
}

TEST_CASE("Administrador: recusa status desconhecido e ponteiros vazios") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");
    Pedido pedido(100, nullptr);
    CHECK_THROWS_AS(admin.atualizarStatusPedido(&pedido, "Perdido"), std::invalid_argument);
    CHECK(pedido.getStatus() == "Pendente");
    CHECK_THROWS_AS(admin.atualizarStatusPedido(nullptr, "Enviado"), std::invalid_argument);
    CHECK_THROWS_AS(admin.atualizarEstoque(nullptr, 1, 5), std::invalid_argument);
}

TEST_CASE("Administrador: confere a senha de acesso") {
    Administrador admin(1, "Maria", "maria@loja.com", "senha123");

    CHECK(admin.verificarSenha("senha123"));
    CHECK_FALSE(admin.verificarSenha("errada"));
    CHECK_FALSE(admin.verificarSenha(""));
}
