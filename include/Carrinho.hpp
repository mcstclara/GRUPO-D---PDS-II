#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <vector>

class Produto;
class Cliente;
class Pedido;

/**
 * @brief Representa o carrinho de compras de um cliente.
 *
 * Armazena os produtos selecionados pelo cliente, suas respectivas
 * quantidades e permite realizar operações relacionadas à compra.
 */

class Carrinho{
private:
    Cliente* cliente;
    std::vector<Produto*> produtos;
    std::vector<int> quantidades;

public:
    /**
     * @brief Construtor da classe Carrinho.
     *
     * @param cliente Cliente ao qual o carrinho pertence.
     */
    explicit Carrinho(Cliente* cliente);

    /**
     * @brief Adiciona um produto ao carrinho.
     *
     * @param produto Produto que será adicionado.
     * @param quantidade Quantidade desejada do produto.
     */
    void adicionarProduto(Produto* produto, int quantidade);

    /**
     * @brief Remove um produto do carrinho.
     *
     * @param produto Produto que será removido.
     */
    void removerProduto(Produto* produto);

    /**
     * @brief Atualiza a quantidade de um produto no carrinho.
     *
     * @param produto Produto cuja quantidade será atualizada.
     * @param quantidade Nova quantidade desejada.
     */
    void atualizarQuantidade(Produto* produto, int quantidade);

    /**
     * @brief Calcula o valor total dos produtos no carrinho.
     *
     * @return Valor total da compra.
     */
    double calcularTotal() const;

    /**
     * @brief Retorna os produtos presentes no carrinho.
     *
     * @return Lista de produtos do carrinho.
     */
    std::vector<Produto*> getProdutos() const;

    /**
     * @brief Retorna as quantidades correspondentes aos produtos.
     *
     * @return Lista de quantidades.
     */
    std::vector<int> getQuantidades() const;    

    /**
     * @brief Finaliza a compra e gera um pedido.
     *
     * @return Ponteiro para o pedido criado.
     */
    Pedido* finalizarCompra();
};

#endif