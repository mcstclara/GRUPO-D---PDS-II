#include "ProvadorVirtual.hpp"
#include "Cliente.hpp"
#include "Produto.hpp"

static double folgaMinima(Cliente::PreferenciaCaimento preferencia) {
    switch (preferencia) {
        case Cliente::PreferenciaCaimento::JUSTO:
            return 0.0;
        case Cliente::PreferenciaCaimento::NORMAL:
            return 4.0;
        case Cliente::PreferenciaCaimento::SOLTO:
            return 10.0;
    }
    return 0.0;
}

ProvadorVirtual::ProvadorVirtual() {}


std::string ProvadorVirtual::recomendarTamanho(const Cliente& cliente,
                                               const Produto& produto) const {
    return "?"; // TODO (C8): implementar
}

bool ProvadorVirtual::tamanhoCompativel(const Cliente& cliente,
                                        const Produto& produto,
                                        const std::string& tamanho) const {
    std::vector<double> medidas = produto.getMedidas(tamanho);
    if (medidas.size() < 3) {
        return false;
    }
    double folga = folgaMinima(cliente.getPreferencia());
    return medidas[0] - cliente.getPeito() >= folga &&
           medidas[1] - cliente.getCintura() >= folga &&
           medidas[2] - cliente.getQuadril() >= folga;
}

std::vector<std::string> ProvadorVirtual::encontrarTamanhosCompativeis(
    const Cliente& cliente,
    const Produto& produto) const {
    return {}; // TODO (C8): implementar
}
