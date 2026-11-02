#include "doctest.h"
#include "Excecoes.hpp"

TEST_CASE("Excecoes: erros da loja podem ser tratados pela classe base") {
    CHECK_THROWS_AS (throw ProdutoNaoEncontrado(7), ErroLoja);
    CHECK_THROWS_AS (throw EstoqueInsuficiente("meia", 2), ErroLoja);
    CHECK_THROWS_AS (throw AcessoNegado("Usuário inválido"), ErroLoja); 
    CHECK_THROWS_AS (throw ArquivoInvalido("Arquivo muito grande") , ErroLoja);
}