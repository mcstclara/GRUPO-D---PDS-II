#include "Estoque.hpp"

Estoque::Estoque() {}

int Estoque::consultarQuantidade(int produtoId) const {
    auto it = quantidades.find(produtoId);
    if (it == quantidades.end()) {
        return 0;
    }
    return it->second;
}

void Estoque::adicionarUnidades(int produtoId, int quantidade) {
    quantidades[produtoId] += quantidade;
}

bool Estoque::removerUnidades(int produtoId, int quantidade) {
    if (consultarQuantidade(produtoId) < quantidade) {
        return false;
    }
    quantidades[produtoId] -= quantidade;
    return true;
}


bool Estoque::temQuantidadeSuficiente(int produtoId, int quantidade) const {
    return false; // TODO (C8): implementar
}

bool Estoque::estaEsgotado(int produtoId) const {
    return false; // TODO (C8): implementar
}
