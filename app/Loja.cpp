#include "Loja.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Carrinho.hpp"
#include "Cliente.hpp"
#include "Excecoes.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"

static std::vector<std::string> separar(const std::string& texto, char separador) {
    std::vector<std::string> partes;
    std::stringstream fluxo(texto);
    std::string parte;
    while (std::getline(fluxo, parte, separador)) {
        partes.push_back(parte);
    }
    return partes;
}

static int paraInteiro(const std::string& texto, const std::string& campo) {
    try {
        std::size_t lidos = 0;
        int valor = std::stoi(texto, &lidos);
        if (lidos == texto.size()) {
            return valor;
        }
    } catch (const std::logic_error&) {
    }
    throw std::invalid_argument(campo + " invalido: \"" + texto + "\"");
}

static double paraDecimal(const std::string& texto, const std::string& campo) {
    try {
        std::size_t lidos = 0;
        double valor = std::stod(texto, &lidos);
        if (lidos == texto.size()) {
            return valor;
        }
    } catch (const std::logic_error&) {
    }
    throw std::invalid_argument(campo + " invalido: \"" + texto + "\"");
}

Loja::Loja()
    : administrador(1, "Administrador", "admin@lojagrupod.com", "admin123"),
      clienteAtual(nullptr), carrinho(nullptr),
      proximoIdProduto(1), proximoIdCliente(1) {}

Loja::~Loja() {
    delete carrinho;
    for (Pedido* pedido : pedidos) {
        delete pedido;
    }
    for (Cliente* cliente : clientes) {
        delete cliente;
    }
    for (Produto* produto : produtos) {
        delete produto;
    }
}

void Loja::adicionarProduto(Produto* produto, int quantidade) {
    if (produto == nullptr) {
        throw std::invalid_argument("produto vazio");
    }
    produtos.push_back(produto);
    for (Produto* existente : administrador.getProdutos()) {
        if (existente->getId() == produto->getId()) {
            throw std::invalid_argument("ja existe um produto com o id " +
                                        std::to_string(produto->getId()));
        }
    }
    administrador.cadastrarProduto(produto);
    if (quantidade > 0) {
        estoque.adicionarUnidades(produto->getId(), quantidade);
    }
    if (produto->getId() >= proximoIdProduto) {
        proximoIdProduto = produto->getId() + 1;
    }
}

void Loja::guardarProduto(Produto* produto) {
    if (produto == nullptr) {
        throw std::invalid_argument("produto vazio");
    }
    produtos.push_back(produto);
    if (produto->getId() >= proximoIdProduto) {
        proximoIdProduto = produto->getId() + 1;
    }
}

int Loja::gerarIdProduto() {
    return proximoIdProduto++;
}

std::vector<Produto*> Loja::getCatalogo() const {
    return administrador.getProdutos();
}

Estoque& Loja::getEstoque() {
    return estoque;
}

Administrador& Loja::getAdministrador() {
    return administrador;
}

const ProvadorVirtual& Loja::getProvador() const {
    return provador;
}

Cliente* Loja::adicionarCliente(const std::string& nome,
                                const std::string& email,
                                const std::string& senha) {
    Cliente* cliente = new Cliente(proximoIdCliente, nome, email, senha);
    clientes.push_back(cliente);
    proximoIdCliente++;
    return cliente;
}

std::vector<Cliente*> Loja::getClientes() const {
    return clientes;
}

void Loja::entrar(Cliente* cliente) {
    if (cliente == nullptr) {
        throw std::invalid_argument("cliente vazio");
    }
    delete carrinho;
    clienteAtual = cliente;
    carrinho = new Carrinho(cliente);
}

void Loja::sair() {
    delete carrinho;
    carrinho = nullptr;
    clienteAtual = nullptr;
}

Cliente* Loja::getClienteAtual() const {
    return clienteAtual;
}

Carrinho& Loja::getCarrinho() {
    exigirCliente();
    return *carrinho;
}

void Loja::registrarPedido(Pedido* pedido) {
    if (pedido == nullptr) {
        throw std::invalid_argument("pedido vazio");
    }
    pedidos.push_back(pedido);
}

std::vector<Pedido*> Loja::getPedidos() const {
    return pedidos;
}

Produto* Loja::buscarProduto(int produtoId) const {
    std::vector<Produto*>produtosCatalogo = getCatalogo();
    for (size_t i = 0; i < produtosCatalogo.size(); i++) {
        if (produtosCatalogo[i]->getId() == produtoId){
            return produtosCatalogo[i];
        }
    }

    throw ProdutoNaoEncontrado(produtoId);

}

Cliente& Loja::exigirCliente() const {
    if (getClienteAtual() == nullptr){
        throw AcessoNegado("Entre na sua conta primeiro");
    }
    else {
        return *getClienteAtual();
    }
}

void Loja::carregarProdutos(const std::string& caminho) {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        throw ArquivoInvalido("Nao foi possivel abrir o arquivo " + caminho + ".");
    }
    std::string linha;
    int numeroLinha = 0;
    while (std::getline(arquivo, linha)) {
        numeroLinha++;
        if (!linha.empty() && linha[linha.size() - 1] == '\r') {
            linha.erase(linha.size() - 1);
        }
        if (linha.empty() || linha[0] == '#') {
            continue;
        }
        try {
            std::vector<std::string> campos = separar(linha, ';');
            if (campos.size() != 8) {
                throw std::invalid_argument("esperados 8 campos separados por ';'");
            }
            int id = paraInteiro(campos[0], "id");
            double preco = paraDecimal(campos[3], "preco");
            int quantidade = paraInteiro(campos[6], "quantidade");
            if (quantidade < 0) {
                throw std::invalid_argument("a quantidade nao pode ser negativa");
            }
            Produto* produto = new Produto(id, campos[1], campos[2], preco,
                                           campos[4], campos[5]);
            adicionarProduto(produto, quantidade);
            if (campos[7] == "-") {
                continue;
            }
            for (const std::string& tamanho : separar(campos[7], '|')) {
                std::vector<std::string> partes = separar(tamanho, '=');
                if (partes.size() != 2) {
                    throw std::invalid_argument("tamanho invalido: \"" + tamanho + "\"");
                }
                std::vector<double> medidas;
                for (const std::string& medida : separar(partes[1], ',')) {
                    medidas.push_back(paraDecimal(medida, "medida"));
                }
                produto->adicionarTamanho(partes[0], medidas);
            }
        } catch (const std::invalid_argument& erro) {
            throw ArquivoInvalido(caminho + ", linha " + std::to_string(numeroLinha) +
                                  ": " + erro.what());
        }
    }
}