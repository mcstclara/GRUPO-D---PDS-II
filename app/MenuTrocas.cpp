#include <iostream>
#include <string>
#include <vector>

#include "Cliente.hpp"
#include "Entrada.hpp"
#include "Excecoes.hpp"
#include "Loja.hpp"
#include "Menus.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"
#include "TrocaDevolucao.hpp"

static std::vector<TrocaDevolucao> solicitacoes;

static Pedido* escolherPedido(Cliente& cliente) {
    std::vector<Pedido*> pedidos = cliente.getPedidos();
    if (pedidos.empty()) {
        throw ErroLoja("Voce ainda nao tem pedidos.");
    }
    std::cout << "\nSeus pedidos:\n";
    for (Pedido* pedido : pedidos) {
        std::cout << "  Pedido " << pedido->getId() << " (" << pedido->getStatus() << ")\n";
    }
    int pedidoId = lerInteiro("Numero do pedido: ", 1, 1000000);
    for (Pedido* pedido : pedidos) {
        if (pedido->getId() == pedidoId) {
            return pedido;
        }
    }
    throw ErroLoja("Pedido " + std::to_string(pedidoId) + " nao encontrado entre os seus.");
}

static void solicitar(Loja& loja) {
    Cliente& cliente = loja.exigirCliente();
    Pedido* pedido = escolherPedido(cliente);
    std::vector<Produto*> produtos = pedido->getProdutos();
    std::cout << "\nItens do pedido " << pedido->getId() << ":\n";
    for (std::size_t i = 0; i < produtos.size(); i++) {
        std::cout << "[" << i + 1 << "] " << produtos[i]->getNome() << "\n";
    }
    int item = lerInteiro("Item: ", 1, static_cast<int>(produtos.size()));
    std::cout << "[1] Troca\n[2] Devolucao\n";
    int tipo = lerInteiro("Tipo: ", 1, 2);
    std::string motivo = lerTexto("Motivo: ");

    TrocaDevolucao solicitacao(pedido, produtos[item - 1], motivo);
    if (tipo == 1) {
        solicitacao.solicitarTroca();
    } else {
        solicitacao.solicitarDevolucao();
    }
    solicitacoes.push_back(solicitacao);
    std::cout << "\nSituacao: " << solicitacao.getStatus() << "\n";
    if (solicitacao.getStatus() == "Recusada") {
        std::cout << "Motivo da recusa: " << solicitacao.explicarRecusa() << "\n";
    }
}

static void verSolicitacoes(Loja& loja) {
    Cliente& cliente = loja.exigirCliente();
    bool encontrou = false;
    for (const TrocaDevolucao& solicitacao : solicitacoes) {
        if (solicitacao.getPedido()->getCliente() == &cliente) {
            encontrou = true;
            std::cout << "Pedido " << solicitacao.getPedido()->getId() << " | "
                      << solicitacao.getProduto()->getNome() << " | "
                      << solicitacao.getStatus() << " | Motivo: "
                      << solicitacao.getMotivo() << "\n";
        }
    }
    if (!encontrou) {
        std::cout << "\nVoce ainda nao fez nenhuma solicitacao.\n";
    }
}

void menuTrocas(Loja& loja) {
    loja.exigirCliente();
    while (true) {
        std::cout << "\n--- Trocas e devolucoes ---\n"
                  << "[1] Solicitar troca ou devolucao\n"
                  << "[2] Ver minhas solicitacoes\n"
                  << "[0] Voltar\n";
        int opcao = lerInteiro("Escolha uma opcao: ", 0, 2);
        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            solicitar(loja);
        } else {
            verSolicitacoes(loja);
        }
    }
}
