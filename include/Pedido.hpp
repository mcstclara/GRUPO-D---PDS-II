#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <vector>
#include <string>

class Produto;
class Cliente;

/**
 * @brief Representa um pedido realizado por um cliente.
 *
 * Armazena os produtos, quantidades, valor total e informações
 * relacionadas ao estado do pedido.
 */

class Pedido {
private: 
    int id; 
    Cliente* cliente; 

    std::vector<Produto*> produtos; 
    std::vector<int> quantidades; 

    double valorTotal;
    std::string status; 

public: 

  /**
     * @brief Construtor da classe Pedido.
     *
     * @param id Identificador único do pedido.
     * @param cliente Cliente responsável pelo pedido.
     */

Pedido(int id, Cliente* cliente);


    /**
     * @brief Adiciona um produto ao pedido.
     *
     * @param produto Produto que será adicionado.
     * @param quantidade Quantidade do produto.
     */

void adicionarProduto(Produto * produto, int quantidade);

 /**
     * @brief Calcula o valor total do pedido.
     *
     * @return Valor total do pedido.
     */

double calcularTotal() const; 

 /**
     * @brief Retorna o identificador do pedido.
     *
     * @return Identificador do pedido.
     */

int getId() const; 

 /**
     * @brief Retorna o cliente associado ao pedido.
     *
     * @return Ponteiro para o cliente.
     */

Cliente* getCliente() const;

/**
     * @brief Retorna os produtos do pedido.
     *
     * @return Lista de produtos.
     */

std::vector<Produto*> getProdutos() const; 

 /**
     * @brief Retorna as quantidades dos produtos.
     *
     * @return Lista de quantidades.
     */

std::vector<int> getQuantidades() const; 

 /**
     * @brief Retorna o status atual do pedido.
     *
     * @return Status do pedido.
     */

std::string getStatus() const; 

 /**
     * @brief Atualiza o status do pedido.
     *
     * @param status Novo status do pedido.
     */

void atualizarStatus(const std::string& status); 

 /**
     * @brief Gera um resumo do pedido.
     *
     * O resumo pode incluir informações sobre os produtos,
     * quantidades, valor total e status.
     *
     * @return Texto contendo o resumo do pedido.
     */

std::string gerarResumo() const; 

};


#endif