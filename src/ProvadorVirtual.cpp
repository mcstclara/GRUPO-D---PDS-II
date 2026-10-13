#include "ProvadorVirtual.hpp"

// Esqueleto (stub) criado no C7 para os testes compilarem.
// Os comportamentos reais serão implementados no C8.

ProvadorVirtual::ProvadorVirtual() {}

std::string ProvadorVirtual::recomendarTamanho(const Cliente& cliente,
                                               const Produto& produto) const {
    return "?"; // TODO (C8): implementar
}

bool ProvadorVirtual::tamanhoCompativel(const Cliente& cliente,
                                        const Produto& produto,
                                        const std::string& tamanho) const {
    return false; // TODO (C8): implementar
}

std::vector<std::string> ProvadorVirtual::encontrarTamanhosCompativeis(
    const Cliente& cliente,
    const Produto& produto) const {
    return {}; // TODO (C8): implementar
}
