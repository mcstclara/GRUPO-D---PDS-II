#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>

class Pedido;

/**
 * @brief Representa um cliente da loja virtual.
 *
 * Armazena os dados cadastrais, endereços, medidas corporais,
 * preferência de caimento e pedidos realizados pelo cliente.
 */
class Cliente {
public:
    /**
     * @brief Define as preferências de caimento das roupas.
     */
    enum class PreferenciaCaimento {
        JUSTO,
        NORMAL,
        SOLTO
    };

private:
    int id;
    std::string nome;
    std::string email;
    std::string senha;

    std::vector<std::string> enderecos;

    double altura;
    double peso;
    double peito;
    double cintura;
    double quadril;

    PreferenciaCaimento preferencia;

    std::vector<Pedido*> pedidos;

public:
    /**
     * @brief Construtor da classe Cliente.
     *
     * @param id Identificador único do cliente.
     * @param nome Nome do cliente.
     * @param email E-mail utilizado no cadastro.
     * @param senha Senha de acesso à conta.
     */
    Cliente(int id,
            const std::string& nome,
            const std::string& email,
            const std::string& senha);

    /**
     * @brief Retorna o identificador do cliente.
     *
     * @return Identificador do cliente.
     */
    int getId() const;

    /**
     * @brief Retorna o nome do cliente.
     *
     * @return Nome do cliente.
     */
    std::string getNome() const;

    /**
     * @brief Retorna o e-mail do cliente.
     *
     * @return E-mail do cliente.
     */
    std::string getEmail() const;

    /**
     * @brief Atualiza o nome do cliente.
     *
     * @param nome Novo nome do cliente.
     */
    void atualizarNome(const std::string& nome);

    /**
     * @brief Atualiza o e-mail do cliente.
     *
     * @param email Novo e-mail do cliente.
     */
    void atualizarEmail(const std::string& email);

    /**
     * @brief Atualiza a senha do cliente.
     *
     * @param senha Nova senha do cliente.
     */
    void atualizarSenha(const std::string& senha);

    /**
     * @brief Adiciona um endereço à lista de endereços do cliente.
     *
     * @param endereco Endereço a ser adicionado.
     */
    void adicionarEndereco(const std::string& endereco);

    /**
     * @brief Retorna os endereços cadastrados pelo cliente.
     *
     * @return Lista de endereços cadastrados.
     */
    std::vector<std::string> getEnderecos() const;

    /**
     * @brief Define as medidas corporais do cliente.
     *
     * @param altura Altura do cliente.
     * @param peso Peso do cliente.
     * @param peito Medida do peito.
     * @param cintura Medida da cintura.
     * @param quadril Medida do quadril.
     */
    void definirMedidas(double altura,
                        double peso,
                        double peito,
                        double cintura,
                        double quadril);

    /**
     * @brief Retorna a altura do cliente.
     *
     * @return Altura do cliente.
     */
    double getAltura() const;

    /**
     * @brief Retorna o peso do cliente.
     *
     * @return Peso do cliente.
     */
    double getPeso() const;

    /**
     * @brief Retorna a medida do peito do cliente.
     *
     * @return Medida do peito.
     */
    double getPeito() const;

    /**
     * @brief Retorna a medida da cintura do cliente.
     *
     * @return Medida da cintura.
     */
    double getCintura() const;

    /**
     * @brief Retorna a medida do quadril do cliente.
     *
     * @return Medida do quadril.
     */
    double getQuadril() const;

    /**
     * @brief Define a preferência de caimento do cliente.
     *
     * @param preferencia Nova preferência de caimento.
     */
    void definirPreferencia(PreferenciaCaimento preferencia);

    /**
     * @brief Retorna a preferência de caimento do cliente.
     *
     * @return Preferência de caimento cadastrada.
     */
    PreferenciaCaimento getPreferencia() const;

    /**
     * @brief Associa um pedido ao cliente.
     *
     * @param pedido Ponteiro para o pedido a ser associado.
     */
    void adicionarPedido(Pedido* pedido);

    /**
     * @brief Retorna os pedidos associados ao cliente.
     *
     * @return Lista de pedidos do cliente.
     */
    std::vector<Pedido*> getPedidos() const;
};

#endif