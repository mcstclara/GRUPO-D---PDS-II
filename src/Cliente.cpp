#include "Cliente.hpp"

// Esqueleto (stub) criado no C7 para os testes compilarem.
// Os comportamentos reais serão implementados no C8.

Cliente::Cliente(int id,
                 const std::string& nome,
                 const std::string& email,
                 const std::string& senha)
    : id(id), nome(nome), email(email), senha(senha),
      altura(0.0), peso(0.0), peito(0.0), cintura(0.0), quadril(0.0),
      preferencia(PreferenciaCaimento::NORMAL) {}

int Cliente::getId() const {
    return 0; // TODO (C8): implementar
}

std::string Cliente::getNome() const {
    return ""; // TODO (C8): implementar
}

std::string Cliente::getEmail() const {
    return ""; // TODO (C8): implementar
}

void Cliente::atualizarNome(const std::string& nome) {
    // TODO (C8): implementar
}

void Cliente::atualizarEmail(const std::string& email) {
    // TODO (C8): implementar
}

void Cliente::atualizarSenha(const std::string& senha) {
    // TODO (C8): implementar
}

void Cliente::adicionarEndereco(const std::string& endereco) {
    // TODO (C8): implementar
}

std::vector<std::string> Cliente::getEnderecos() const {
    return {}; // TODO (C8): implementar
}

void Cliente::definirMedidas(double altura,
                             double peso,
                             double peito,
                             double cintura,
                             double quadril) {
    // TODO (C8): implementar
}

double Cliente::getAltura() const {
    return -1.0; // TODO (C8): implementar
}

double Cliente::getPeso() const {
    return -1.0; // TODO (C8): implementar
}

double Cliente::getPeito() const {
    return -1.0; // TODO (C8): implementar
}

double Cliente::getCintura() const {
    return -1.0; // TODO (C8): implementar
}

double Cliente::getQuadril() const {
    return -1.0; // TODO (C8): implementar
}

void Cliente::definirPreferencia(PreferenciaCaimento preferencia) {
    // TODO (C8): implementar
}

Cliente::PreferenciaCaimento Cliente::getPreferencia() const {
    return PreferenciaCaimento::JUSTO; // TODO (C8): implementar
}

void Cliente::adicionarPedido(Pedido* pedido) {
    // TODO (C8): implementar
}

std::vector<Pedido*> Cliente::getPedidos() const {
    return {}; // TODO (C8): implementar
}
