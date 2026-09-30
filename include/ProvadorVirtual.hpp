#ifndef PROVADOR_VIRTUAL_HPP
#define PROVADOR_VIRTUAL_HPP

#include <string>
#include <vector>

class Cliente;
class Produto;

/**
 * @brief Realiza recomendações de tamanho para os clientes.
 *
 * Utiliza as medidas corporais e a preferência de caimento
 * do cliente em conjunto com as medidas disponíveis dos produtos.
 */
class ProvadorVirtual {
public:
    /**
     * @brief Construtor da classe ProvadorVirtual.
     */
    ProvadorVirtual();

    /**
     * @brief Recomenda o tamanho mais adequado para um cliente.
     *
     * @param cliente Cliente que receberá a recomendação.
     * @param produto Produto para o qual o tamanho será recomendado.
     *
     * @return Tamanho recomendado para o cliente.
     */
    std::string recomendarTamanho(
        const Cliente& cliente,
        const Produto& produto) const;

    /**
     * @brief Verifica se um tamanho é compatível com o cliente.
     *
     * @param cliente Cliente que será avaliado.
     * @param produto Produto a ser analisado.
     * @param tamanho Tamanho que será verificado.
     *
     * @return true se o tamanho for compatível e false caso contrário.
     */
    bool tamanhoCompativel(
        const Cliente& cliente,
        const Produto& produto,
        const std::string& tamanho) const;

    /**
     * @brief Encontra os tamanhos compatíveis com o cliente.
     *
     * @param cliente Cliente que será avaliado.
     * @param produto Produto a ser analisado.
     *
     * @return Lista de tamanhos compatíveis.
     */
    std::vector<std::string> encontrarTamanhosCompativeis(
        const Cliente& cliente,
        const Produto& produto) const;
};

#endif