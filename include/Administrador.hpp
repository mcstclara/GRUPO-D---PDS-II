#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include <string>

#include "Pedido.hpp"

class Produto;
class Estoque;

/**
 * @brief Representa um administrador da loja virtual.
 *
 * Permite realizar operações de gerenciamento de produtos,
 * estoque e pedidos.
 */
class Administrador {
private:
    int id;
    std::string nome;
    std::string email;
    std::string senha;

public:
    /**
     * @brief Construtor da classe Administrador.
     *
     * @param id Identificador único do administrador.
     * @param nome Nome do administrador.
     * @param email E-mail utilizado no cadastro.
     * @param senha Senha de acesso.
     */
    Administrador(int id,
                  const std::string& nome,
                  const std::string& email,
                  const std::string& senha);

    /**
     * @brief Retorna o identificador do administrador.
     *
     * @return Identificador do administrador.
     */
    int getId() const;

    /**
     * @brief Retorna o nome do administrador.
     *
     * @return Nome do administrador.
     */
    std::string getNome() const;

    /**
     * @brief Retorna o e-mail do administrador.
     *
     * @return E-mail do administrador.
     */
    std::string getEmail() const;

    /**
     * @brief Cadastra um produto na loja.
     *
     * @param produto Produto que será cadastrado.
     */
    void cadastrarProduto(
        Produto* produto);

    /**
     * @brief Atualiza as informações de um produto.
     *
     * @param produto Produto que será atualizado.
     */
    void atualizarProduto(
        Produto* produto);

    /**
     * @brief Remove um produto da loja.
     *
     * @param produto Produto que será removido.
     */
    void removerProduto(
        Produto* produto);

    /**
     * @brief Atualiza a quantidade de um produto no estoque.
     *
     * @param estoque Estoque que será atualizado.
     * @param produtoId Identificador do produto.
     * @param quantidade Quantidade a ser adicionada ou removida.
     */
    void atualizarEstoque(
        Estoque* estoque,
        int produtoId,
        int quantidade);

    /**
     * @brief Atualiza o status de um pedido.
     *
     * @param pedido Pedido que terá seu status atualizado.
     * @param status Novo status do pedido.
     */
    void atualizarStatusPedido(
        Pedido* pedido,
        const std::string& status);
};

#endif