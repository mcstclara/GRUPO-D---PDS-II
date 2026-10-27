#include "Cliente.hpp"

Cliente::Cliente(int id,
                 const std::string& nome,
                 const std::string& email,
                 const std::string& senha)
    : id(id), nome(nome), email(email), senha(senha),
      altura(0.0), peso(0.0), peito(0.0), cintura(0.0), quadril(0.0),
      preferencia(PreferenciaCaimento::NORMAL) {}

int Cliente::getId() const {
    return id;
}

std::string Cliente::getNome() const {
    return nome;
}

std::string Cliente::getEmail() const {
    return email;
}

void Cliente::atualizarNome(const std::string& nome) {
    this->nome = nome;
}

void Cliente::atualizarEmail(const std::string& email) {
    this->email = email;
}

void Cliente::atualizarSenha(const std::string& senha) {
    this->senha = senha;
}

void Cliente::adicionarEndereco(const std::string& endereco) {
    enderecos.push_back(endereco);
}

std::vector<std::string> Cliente::getEnderecos() const {
    return enderecos;
}

void Cliente::definirMedidas(double altura,
                             double peso,
                             double peito,
                             double cintura,
                             double quadril) {
    this->altura = altura;
    this->peso = peso;
    this->peito = peito;
    this->cintura = cintura;
    this->quadril = quadril;
}

double Cliente::getAltura() const {
    return altura;
}

double Cliente::getPeso() const {
    return peso;
}

double Cliente::getPeito() const {
    return peito;
}

double Cliente::getCintura() const {
    return cintura;
}

double Cliente::getQuadril() const {
    return quadril;
}


void Cliente::definirPreferencia(PreferenciaCaimento preferencia) {
    // TODO (C8): implementar
}

Cliente::PreferenciaCaimento Cliente::getPreferencia() const {
    return preferencia;
}

void Cliente::adicionarPedido(Pedido* pedido) {
    // TODO (C8): implementar
}

std::vector<Pedido*> Cliente::getPedidos() const {
    return {}; // TODO (C8): implementar
}
