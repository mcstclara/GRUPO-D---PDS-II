#ifndef EXCECOES_HPP
#define EXCECOES_HPP

#include <stdexcept>
#include <string>


/**
 * @brief Classe base dos erros das regras da loja.
 *
 * Representa situações que o programa sabe tratar e explicar
 * para quem está usando, como um produto que não existe.
 */
class ErroLoja : public std::runtime_error {
public:
    /**
     * @brief Construtor da classe ErroLoja.
     *
     * @param mensagem Mensagem que explica o erro.
     */
    explicit ErroLoja(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};


/**
 * @brief Erro lançado quando um produto não está no catálogo.
 */
class ProdutoNaoEncontrado : public ErroLoja {
public:
    /**
     * @brief Construtor da classe ProdutoNaoEncontrado.
     *
     * @param produtoId Identificador do produto procurado.
     */
    explicit ProdutoNaoEncontrado(int produtoId)
        : ErroLoja("Produto " + std::to_string(produtoId) +
                   " nao encontrado no catalogo.") {}
};

/**
 * @brief Erro lançado quando não há unidades suficientes de um produto.
 */
class EstoqueInsuficiente : public ErroLoja {
public:
    /**
     * @brief Construtor da classe EstoqueInsuficiente.
     *
     * @param nomeProduto Nome do produto.
     * @param disponivel Quantidade disponível no estoque.
     */
    EstoqueInsuficiente(const std::string& nomeProduto, int disponivel)
        : ErroLoja("Estoque insuficiente de " + nomeProduto + ": ha " +
                   std::to_string(disponivel) + " unidade(s) disponivel(is).") {}
};

/**
 * @brief Erro lançado quando uma ação exige login ou o login falha.
 */
class AcessoNegado : public ErroLoja {
public:
    /**
     * @brief Construtor da classe AcessoNegado.
     *
     * @param mensagem Mensagem que explica o erro.
     */
    explicit AcessoNegado(const std::string& mensagem)
        : ErroLoja(mensagem) {}
};

/**
 * @brief Erro lançado quando um arquivo de dados não pode ser lido.
 */
class ArquivoInvalido : public ErroLoja {
public:
    /**
     * @brief Construtor da classe ArquivoInvalido.
     *
     * @param mensagem Mensagem que explica o erro.
     */
    explicit ArquivoInvalido(const std::string& mensagem)
        : ErroLoja(mensagem) {}
};

/**
 * @brief Lançada quando a entrada do terminal termina (Ctrl+D ou Ctrl+Z).
 *
 * Não herda de ErroLoja porque não é um erro de regra da loja:
 * indica que o programa deve ser encerrado.
 */
class EntradaEncerrada : public std::runtime_error {
public:
    /**
     * @brief Construtor da classe EntradaEncerrada.
     */
    EntradaEncerrada()
        : std::runtime_error("A entrada do terminal foi encerrada.") {}
};

#endif