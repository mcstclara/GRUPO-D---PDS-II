#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>
#include <vector>
#include <map>

/**
 * @brief Representa um produto disponível na loja.
 *
 * Armazena informações como nome, categoria, preço, material,
 * coleção, tamanhos disponíveis e medidas correspondentes.
 */
class Produto {
private:
    int id;
    std::string nome;
    std::string categoria;
    double preco;
    std::string material;
    std::string colecao;

    std::vector<std::string> tamanhos;

    std::map<std::string, std::vector<double>> medidasPorTamanho;

public:
    /**
     * @brief Construtor da classe Produto.
     *
     * @param id Identificador único do produto.
     * @param nome Nome do produto.
     * @param categoria Categoria do produto.
     * @param preco Preço do produto.
     * @param material Material do produto.
     * @param colecao Coleção à qual o produto pertence.
     */
    Produto(int id,
            const std::string& nome,
            const std::string& categoria,
            double preco,
            const std::string& material,
            const std::string& colecao);

    /**
     * @brief Destrutor virtual da classe Produto.
     */
    virtual ~Produto() = default;

    /**
     * @brief Retorna o identificador do produto.
     *
     * @return Identificador do produto.
     */
    int getId() const;

    /**
     * @brief Retorna o nome do produto.
     *
     * @return Nome do produto.
     */
    std::string getNome() const;

    /**
     * @brief Retorna a categoria do produto.
     *
     * @return Categoria do produto.
     */
    std::string getCategoria() const;

    /**
     * @brief Retorna o preço do produto.
     *
     * O método é virtual para permitir que classes derivadas,
     * como KitRoupas, implementem seu próprio cálculo de preço.
     *
     * @return Preço do produto.
     */
    virtual double getPreco() const;

    /**
     * @brief Retorna o material do produto.
     *
     * @return Material do produto.
     */
    std::string getMaterial() const;

    /**
     * @brief Retorna a coleção do produto.
     *
     * @return Coleção do produto.
     */
    std::string getColecao() const;

    /**
     * @brief Adiciona um tamanho e suas medidas ao produto.
     *
     * @param tamanho Tamanho que será adicionado.
     * @param medidas Medidas correspondentes ao tamanho.
     */
    void adicionarTamanho(
        const std::string& tamanho,
        const std::vector<double>& medidas);

    /**
     * @brief Retorna os tamanhos disponíveis para o produto.
     *
     * @return Lista de tamanhos disponíveis.
     */
    std::vector<std::string> getTamanhos() const;

    /**
     * @brief Retorna as medidas associadas a um tamanho.
     *
     * @param tamanho Tamanho cujas medidas serão consultadas.
     *
     * @return Lista de medidas correspondentes ao tamanho.
     */
    std::vector<double> getMedidas(
        const std::string& tamanho) const;

    /**
     * @brief Verifica se o produto possui determinado tamanho.
     *
     * @param tamanho Tamanho que será verificado.
     *
     * @return true se o tamanho estiver disponível e false caso contrário.
     */
    bool temTamanho(
        const std::string& tamanho) const;
};

#endif