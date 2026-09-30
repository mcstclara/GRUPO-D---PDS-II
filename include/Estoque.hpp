#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <map>

/**
 * @brief Gerencia as quantidades disponíveis dos produtos.
 *
 * Controla a quantidade de unidades de cada produto em estoque
 * e impede operações que resultem em quantidade negativa.
 */
class Estoque {
private:
    std::map<int, int> quantidades;

public:
    /**
     * @brief Construtor da classe Estoque.
     */
    Estoque();

    /**
     * @brief Consulta a quantidade disponível de um produto.
     *
     * @param produtoId Identificador do produto.
     *
     * @return Quantidade disponível do produto.
     */
    int consultarQuantidade(int produtoId) const;

    /**
     * @brief Adiciona unidades de um produto ao estoque.
     *
     * @param produtoId Identificador do produto.
     * @param quantidade Quantidade de unidades adicionadas.
     */
    void adicionarUnidades(
        int produtoId,
        int quantidade);

    /**
     * @brief Remove unidades de um produto do estoque.
     *
     * @param produtoId Identificador do produto.
     * @param quantidade Quantidade de unidades removidas.
     *
     * @return true se a remoção for realizada e false caso
     * a quantidade solicitada não esteja disponível.
     */
    bool removerUnidades(
        int produtoId,
        int quantidade);

    /**
     * @brief Verifica se há quantidade suficiente de um produto.
     *
     * @param produtoId Identificador do produto.
     * @param quantidade Quantidade necessária.
     *
     * @return true se houver quantidade suficiente e false caso contrário.
     */
    bool temQuantidadeSuficiente(
        int produtoId,
        int quantidade) const;

    /**
     * @brief Verifica se um produto está esgotado.
     *
     * @param produtoId Identificador do produto.
     *
     * @return true se não houver unidades disponíveis e false caso contrário.
     */
    bool estaEsgotado(
        int produtoId) const;
};

#endif