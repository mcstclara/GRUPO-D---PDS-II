#ifndef LOJA_HPP
#define LOJA_HPP

#include <string>
#include <vector>

#include "Administrador.hpp"
#include "Estoque.hpp"
#include "ProvadorVirtual.hpp"

class Produto;
class Cliente;
class Carrinho;
class Pedido;

/**
 * @brief Reúne os dados da loja usados pela interface do terminal.
 *
 * Guarda o catálogo (por meio do Administrador), o estoque, os clientes,
 * os pedidos e o cliente que está usando o programa. A Loja é dona da
 * memória de todos os objetos que guarda e os apaga no destrutor.
 */
class Loja {
private:
    Administrador administrador;
    Estoque estoque;
    ProvadorVirtual provador;
    std::vector<Produto*> produtos;
    std::vector<Cliente*> clientes;
    std::vector<Pedido*> pedidos;
    Cliente* clienteAtual;
    Carrinho* carrinho;
    int proximoIdProduto;
    int proximoIdCliente;

public:
    /**
     * @brief Construtor da classe Loja, com catálogo e estoque vazios.
     */
    Loja();

    /**
     * @brief Destrutor: apaga produtos, clientes, pedidos e o carrinho.
     */
    ~Loja();

    Loja(const Loja&) = delete;
    Loja& operator=(const Loja&) = delete;

    /**
     * @brief Lê o catálogo inicial de um arquivo de texto.
     *
     * Cada linha tem o formato
     * id;nome;categoria;preco;material;colecao;quantidade;tamanhos.
     * Linhas vazias ou começadas por # são ignoradas.
     *
     * @param caminho Caminho do arquivo.
     * @throws ArquivoInvalido se o arquivo não abrir ou tiver uma linha inválida.
     */
    void carregarProdutos(const std::string& caminho);

    /**
     * @brief Cadastra um produto no catálogo e no estoque.
     *
     * A Loja passa a ser dona do produto.
     *
     * @param produto Produto criado com new.
     * @param quantidade Unidades iniciais no estoque.
     * @throws std::invalid_argument se o produto for vazio ou o id já existir.
     */
    void adicionarProduto(Produto* produto, int quantidade);

    /**
     * @brief Guarda um produto que não entra no catálogo (por exemplo, um kit).
     *
     * @param produto Produto criado com new.
     * @throws std::invalid_argument se o produto for vazio.
     */
    void guardarProduto(Produto* produto);

    /**
     * @brief Gera um id ainda não usado para um novo produto.
     *
     * @return Novo identificador.
     */
    int gerarIdProduto();

    /**
     * @brief Procura um produto do catálogo pelo id.
     *
     * @param produtoId Identificador do produto.
     * @return Ponteiro para o produto encontrado.
     * @throws ProdutoNaoEncontrado se o id não estiver no catálogo.
     */
    Produto* buscarProduto(int produtoId) const;

    /**
     * @brief Retorna os produtos do catálogo.
     *
     * @return Lista de produtos cadastrados pelo administrador.
     */
    std::vector<Produto*> getCatalogo() const;

    /**
     * @brief Retorna o estoque da loja.
     *
     * @return Referência para o estoque.
     */
    Estoque& getEstoque();

    /**
     * @brief Retorna o administrador da loja.
     *
     * @return Referência para o administrador.
     */
    Administrador& getAdministrador();

    /**
     * @brief Retorna o provador virtual.
     *
     * @return Referência para o provador.
     */
    const ProvadorVirtual& getProvador() const;

    /**
     * @brief Cria e guarda um novo cliente.
     *
     * @param nome Nome do cliente.
     * @param email E-mail do cliente.
     * @param senha Senha do cliente.
     * @return Ponteiro para o cliente criado.
     * @throws std::invalid_argument se os dados forem inválidos.
     */
    Cliente* adicionarCliente(const std::string& nome,
                              const std::string& email,
                              const std::string& senha);

    /**
     * @brief Retorna os clientes cadastrados.
     *
     * @return Lista de clientes.
     */
    std::vector<Cliente*> getClientes() const;

    /**
     * @brief Define o cliente que está usando o programa e cria o carrinho dele.
     *
     * @param cliente Cliente que entrou na conta.
     * @throws std::invalid_argument se o cliente for vazio.
     */
    void entrar(Cliente* cliente);

    /**
     * @brief Sai da conta atual e descarta o carrinho.
     */
    void sair();

    /**
     * @brief Retorna o cliente que está usando o programa.
     *
     * @return Ponteiro para o cliente, ou nullptr se ninguém entrou.
     */
    Cliente* getClienteAtual() const;

    /**
     * @brief Retorna o cliente atual, exigindo que alguém tenha entrado.
     *
     * @return Referência para o cliente atual.
     * @throws AcessoNegado se ninguém entrou na conta.
     */
    Cliente& exigirCliente() const;

    /**
     * @brief Retorna o carrinho do cliente atual.
     *
     * @return Referência para o carrinho.
     * @throws AcessoNegado se ninguém entrou na conta.
     */
    Carrinho& getCarrinho();

    /**
     * @brief Guarda um pedido finalizado. A Loja passa a ser dona dele.
     *
     * @param pedido Pedido criado pelo carrinho.
     * @throws std::invalid_argument se o pedido for vazio.
     */
    void registrarPedido(Pedido* pedido);

    /**
     * @brief Retorna todos os pedidos da loja.
     *
     * @return Lista de pedidos.
     */
    std::vector<Pedido*> getPedidos() const;
};

#endif