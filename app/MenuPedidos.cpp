#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Cliente.hpp"
#include "Entrada.hpp"
#include "Excecoes.hpp"
#include "Loja.hpp"
#include "Menus.hpp"
#include "Pedido.hpp"

void menuPedidos(Loja& loja) {
    Cliente& cliente = loja.exigirCliente();
    std::vector<Pedido*> pedidos = cliente.getPedidos();
    if (pedidos.empty()) {
        std::cout << "\nVoce ainda nao fez nenhum pedido.\n";
        return;
    }
    std::cout << "\n--- Meus pedidos ---\n" << std::fixed << std::setprecision(2);
    for (Pedido* pedido : pedidos) {
         std::cout << "Pedido " << pedido->getId() << " | " << pedido->getStatus()
                  << " | R$ " << pedido->calcularTotal();
        if (pedido->getStatus() == "Entregue") {
            std::cout << " | entregue ha " << pedido->getDiasDesdeEntrega() << " dia(s)";
        }
        std::cout << "\n";

    }
    int pedidoId = lerInteiro("Numero do pedido para ver o resumo (0 para voltar): ",
                              0, 1000000);
    if (pedidoId == 0) {
        return;
    }
    for (Pedido* pedido : pedidos) {
        if (pedido->getId() == pedidoId) {
            std::cout << "\n" << pedido->gerarResumo();
            return;
        }
    }
    throw ErroLoja("Pedido " + std::to_string(pedidoId) + " nao encontrado entre os seus.");
}
