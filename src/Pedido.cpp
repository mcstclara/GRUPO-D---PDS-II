#include "Pedido.hpp"
#include "Produto.hpp"
#include "KitRoupas.hpp"

#include <sstream>
#include <stdexcept>
#include <fstream>

static std::string cuidadosComMaterial(const std::string& material) {
    if (material == "Algodao") {
        return "lavar na maquina com agua fria e secar a sombra.";
    }
    if (material == "Jeans") {
        return "lavar do avesso, sem alvejante, e nao usar secadora.";
    }
    if (material == "La") {
        return "lavar a mao com sabao neutro e secar na horizontal.";
    }
    if (material == "Seda" || material == "Viscose") {
        return "lavar a mao com agua fria, sem torcer.";
    }
    if (material == "Couro") {
        return "limpar com pano umido; nao lavar.";
    }
    return "seguir as instrucoes da etiqueta.";
}

static void escreverCuidados(std::ostream& saida, const Produto* produto) {
    saida << "- " << produto->getNome() << " (" << produto->getMaterial() << "): "
          << cuidadosComMaterial(produto->getMaterial()) << "\n";
}

Pedido::Pedido(int id, Cliente* cliente)
    : id(id), cliente(cliente), valorTotal(0.0), status("Pendente"),
      diasDesdeEntrega(0) {}

void Pedido::adicionarProduto(Produto* produto, int quantidade) {
    if(produto == nullptr){
        throw std::invalid_argument("Produto vazio nao pode entrar no pedido!");
    }
    if (quantidade <= 0){
        throw std::invalid_argument("A quantidade deve ser maior que zero!");
    }
    produtos.push_back(produto);
    quantidades.push_back(quantidade);
}

double Pedido::calcularTotal() const {
    double total = 0.0;
    for (std::size_t i = 0; i < produtos.size(); i++) {
        total += produtos[i]->getPreco() * quantidades[i];
    }
    return total;
}

int Pedido::getId() const {
    return id;
}

Cliente* Pedido::getCliente() const {
    return cliente;
}

std::vector<Produto*> Pedido::getProdutos() const {
    return produtos;
}

std::vector<int> Pedido::getQuantidades() const {
    return quantidades;
}

std::string Pedido::getStatus() const {
    return status;
}

void Pedido::atualizarStatus(const std::string& status) {
    if(status.empty()){
        throw std::invalid_argument("O status do pedido nao pode ser vazio.");
    }
    this->status = status;
}

std::string Pedido::gerarResumo() const {
    std::ostringstream resumo;
    resumo << "Pedido " << id << "\n";
    resumo << "Status: " << status << "\n";
    for (std::size_t i = 0; i < produtos.size(); i++) {
        resumo << quantidades[i] << "x " << produtos[i]->getNome()
               << " - R$ " << produtos[i]->getPreco() * quantidades[i] << "\n";
    }
    resumo << "Total: R$ " << calcularTotal() << "\n";
    return resumo.str();
}

void Pedido::salvarResumo(const std::string& caminho) const {
    std::ofstream arquivo(caminho);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Nao foi possivel criar o arquivo " + caminho + ".");
    }
    arquivo << gerarResumo();
    arquivo << "\nCuidados com as pecas:\n";
    for (Produto* produto : produtos) {
        KitRoupas* kit = dynamic_cast<KitRoupas*>(produto);
        if (kit == nullptr) {
            escreverCuidados(arquivo, produto);
        } else {
            for (Produto* peca : kit->getProdutos()) {
                escreverCuidados(arquivo, peca);
            }
        }
    }
}

void Pedido::registrarDiasDesdeEntrega(int dias) {
    if (dias < 0) {
        throw std::invalid_argument("O numero de dias desde a entrega nao pode ser negativo.");
    }
    diasDesdeEntrega = dias;
}

int Pedido::getDiasDesdeEntrega() const {
    return diasDesdeEntrega;
}
