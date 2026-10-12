#ifndef KIT_ROUPAS_HPP
#define KIT_ROUPAS_HPP

#include "Produto.hpp"
#include <vector>

/**
 * @brief Representa um conjunto de produtos vendido como um kit.
 *
 * Um KitRoupas é um tipo de Produto que reúne outros produtos
 * e pode aplicar um desconto sobre o valor total do conjunto.
 */
class KitRoupas : public Produto {
private:
    std::vector<Produto*> produtos;
    double desconto;

public:
    /**
     * @brief Construtor da classe KitRoupas.
     *
     * O preço base e o material do kit não são informados, pois o
     * preço é calculado a partir dos produtos que o compõem.
     *
     * @param id Identificador único do kit.
     * @param nome Nome do kit.
     * @param categoria Categoria do kit.
     * @param colecao Coleção à qual o kit pertence.
     * @param desconto Percentual de desconto aplicado ao kit (ex.: 10 para 10%).
     */
    KitRoupas(int id,
              const std::string& nome,
              const std::string& categoria,
              const std::string& colecao,
              double desconto);

    /**
     * @brief Adiciona um produto ao kit.
     *
     * @param produto Produto que será adicionado ao kit.
     */
    void adicionarProduto(Produto* produto);

    /**
     * @brief Remove um produto do kit.
     *
     * @param produto Produto que será removido do kit.
     */
    void removerProduto(Produto* produto);

    /**
     * @brief Retorna os produtos que fazem parte do kit.
     *
     * @return Lista de produtos do kit.
     */
    std::vector<Produto*> getProdutos() const;

    /**
     * @brief Retorna o percentual de desconto aplicado ao kit.
     *
     * @return Percentual de desconto.
     */
    double getDesconto() const;

    /**
     * @brief Calcula o preço final do kit.
     *
     * O preço é calculado a partir da soma dos produtos que
     * compõem o kit, aplicando o desconto definido.
     *
     * @return Preço final do kit.
     */
    double getPreco() const override;
};

#endif