#ifndef TROCA_DEVOLUCAO_HPP
#define TROCA_DEVOLUCAO_HPP

#include <string>

class Pedido;
class Produto;

/**
 * @brief Representa uma solicitação de troca ou devolução.
 *
 * Controla informações relacionadas ao pedido, produto,
 * motivo da solicitação e situação da troca ou devolução.
 */
class TrocaDevolucao {
private:
    Pedido* pedido;
    Produto* produto;

    std::string motivo;
    std::string status;

public:
    /**
     * @brief Construtor da classe TrocaDevolucao.
     *
     * @param pedido Pedido relacionado à solicitação.
     * @param produto Produto que será trocado ou devolvido.
     * @param motivo Motivo da solicitação.
     */
    TrocaDevolucao(Pedido* pedido,
                   Produto* produto,
                   const std::string& motivo);

    /**
     * @brief Verifica se o produto pode ser trocado ou devolvido.
     *
     * @return true se a solicitação for elegível e false caso contrário.
     */
    bool verificarElegibilidade() const;

    /**
     * @brief Solicita uma troca do produto.
     */
    void solicitarTroca();

    /**
     * @brief Solicita a devolução do produto.
     */
    void solicitarDevolucao();

    /**
     * @brief Cancela a solicitação de troca ou devolução.
     */
    void cancelarSolicitacao();

    /**
     * @brief Retorna o pedido relacionado à solicitação.
     *
     * @return Ponteiro para o pedido.
     */
    Pedido* getPedido() const;

    /**
     * @brief Retorna o produto relacionado à solicitação.
     *
     * @return Ponteiro para o produto.
     */
    Produto* getProduto() const;

    /**
     * @brief Retorna o motivo da solicitação.
     *
     * @return Motivo informado pelo cliente.
     */
    std::string getMotivo() const;

    /**
     * @brief Retorna o status da solicitação.
     *
     * @return Status atual da solicitação.
     */
    std::string getStatus() const;

    /**
     * @brief Atualiza o status da solicitação.
     *
     * @param status Novo status da solicitação.
     */
    void atualizarStatus(const std::string& status);
};

#endif