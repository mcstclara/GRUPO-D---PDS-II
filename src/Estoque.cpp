#include "Estoque.hpp"

// Esqueleto (stub) criado no C7 para os testes compilarem.
// Os comportamentos reais serão implementados no C8.

Estoque::Estoque() {}

int Estoque::consultarQuantidade(int produtoId) const {
    return 0; // TODO (C8): implementar
}

void Estoque::adicionarUnidades(int produtoId, int quantidade) {
    // TODO (C8): implementar
}

bool Estoque::removerUnidades(int produtoId, int quantidade) {
    return false; // TODO (C8): implementar
}

bool Estoque::temQuantidadeSuficiente(int produtoId, int quantidade) const {
    return false; // TODO (C8): implementar
}

bool Estoque::estaEsgotado(int produtoId) const {
    return false; // TODO (C8): implementar
}
