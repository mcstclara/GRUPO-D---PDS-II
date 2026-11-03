#include <iostream>
#include <string>
#include <vector>

#include "Cliente.hpp"
#include "Entrada.hpp"
#include "Excecoes.hpp"
#include "Loja.hpp"
#include "Menus.hpp"

static Cliente* buscarPorEmail(const Loja& loja, const std::string& email) {
    for (Cliente* cliente : loja.getClientes()) {
        if (cliente->getEmail() == email) {
            return cliente;
        }
    }
    return nullptr;
}

static void criarConta(Loja& loja) {
    std::string nome = lerTexto("Nome: ");
    std::string email = lerTexto("E-mail: ");
    if (buscarPorEmail(loja, email) != nullptr) {
        throw ErroLoja("Ja existe uma conta com o e-mail " + email + ".");
    }
    std::string senha = lerTexto("Senha (pelo menos 6 caracteres): ");
    Cliente* cliente = loja.adicionarCliente(nome, email, senha);
    loja.entrar(cliente);
    std::cout << "\nConta criada! Boas-vindas, " << cliente->getNome() << ".\n";
}

static void entrar(Loja& loja) {
    std::string email = lerTexto("E-mail: ");
    std::string senha = lerTexto("Senha: ");
    Cliente* cliente = buscarPorEmail(loja, email);
    if (cliente == nullptr || !cliente->verificarSenha(senha)) {
        throw AcessoNegado("E-mail ou senha incorretos.");
    }
    loja.entrar(cliente);
    std::cout << "\nOla de novo, " << cliente->getNome() << "!\n";
}

static void menuSemConta(Loja& loja) {
    std::cout << "\n--- Minha conta ---\n"
              << "[1] Criar conta\n"
              << "[2] Entrar\n"
              << "[0] Voltar\n";
    int opcao = lerInteiro("Escolha uma opcao: ", 0, 2);
    if (opcao == 1) {
        criarConta(loja);
    } else if (opcao == 2) {
        entrar(loja);
    }
}

static std::string nomeDaPreferencia(Cliente::PreferenciaCaimento preferencia) {
    switch (preferencia) {
        case Cliente::PreferenciaCaimento::JUSTO:
            return "justo";
        case Cliente::PreferenciaCaimento::NORMAL:
            return "normal";
        case Cliente::PreferenciaCaimento::SOLTO:
            return "solto";
    }
    return "normal";
}

static void verPerfil(const Cliente& cliente) {
    std::cout << "\nNome: " << cliente.getNome()
              << "\nE-mail: " << cliente.getEmail() << "\nEnderecos:";
    std::vector<std::string> enderecos = cliente.getEnderecos();
    if (enderecos.empty()) {
        std::cout << " nenhum";
    }
    std::cout << "\n";
    for (const std::string& endereco : enderecos) {
        std::cout << "  - " << endereco << "\n";
    }
    if (cliente.temMedidas()) {
        std::cout << "Medidas: altura " << cliente.getAltura() << " cm, peso "
                  << cliente.getPeso() << " kg, peito " << cliente.getPeito()
                  << " cm, cintura " << cliente.getCintura() << " cm, quadril "
                  << cliente.getQuadril() << " cm\n";
    } else {
        std::cout << "Medidas: ainda nao cadastradas\n";
    }
    std::cout << "Caimento preferido: " << nomeDaPreferencia(cliente.getPreferencia()) << "\n";
}

static void adicionarEndereco(Cliente& cliente) {
    cliente.adicionarEndereco(lerTexto("Endereco completo: "));
    std::cout << "Endereco adicionado.\n";
}

static void definirMedidas(Cliente& cliente) {
    double altura = lerDecimal("Altura (cm): ", 50.0, 250.0);
    double peso = lerDecimal("Peso (kg): ", 10.0, 300.0);
    double peito = lerDecimal("Peito (cm): ", 30.0, 200.0);
    double cintura = lerDecimal("Cintura (cm): ", 30.0, 200.0);
    double quadril = lerDecimal("Quadril (cm): ", 30.0, 200.0);
    cliente.definirMedidas(altura, peso, peito, cintura, quadril);
    std::cout << "[1] Justo\n[2] Normal\n[3] Solto\n";
    int escolha = lerInteiro("Caimento preferido: ", 1, 3);
    if (escolha == 1) {
        cliente.definirPreferencia(Cliente::PreferenciaCaimento::JUSTO);
    } else if (escolha == 2) {
        cliente.definirPreferencia(Cliente::PreferenciaCaimento::NORMAL);
    } else {
        cliente.definirPreferencia(Cliente::PreferenciaCaimento::SOLTO);
    }
    std::cout << "Medidas salvas.\n";
}

static bool menuComConta(Loja& loja) {
    Cliente& cliente = loja.exigirCliente();
    std::cout << "\n--- Minha conta (" << cliente.getEmail() << ") ---\n"
              << "[1] Ver perfil\n"
              << "[2] Adicionar endereco\n"
              << "[3] Medidas e caimento\n"
              << "[4] Alterar nome, e-mail ou senha\n"
              << "[5] Sair da conta\n"
              << "[0] Voltar\n";
    int opcao = lerInteiro("Escolha uma opcao: ", 0, 5);
    if (opcao == 0) {
        return false;
    }
    if (opcao == 5) {
        loja.sair();
        std::cout << "\nVoce saiu da conta.\n";
        return false;
    }
        if (opcao == 1) {
        verPerfil(cliente);
    } else if (opcao == 2) {
        adicionarEndereco(cliente);
    } else if (opcao == 3) {
        definirMedidas(cliente);
    } else {
        std::cout << "Em construcao.\n";
    }
    return true;
}


void menuConta(Loja& loja) {
    if (loja.getClienteAtual() == nullptr) {
        menuSemConta(loja);
        return;
    }
    bool continuar = true;
    while (continuar) {
        continuar = menuComConta(loja);
    }
}
