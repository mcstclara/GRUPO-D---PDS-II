#include <string>
#include <iostream>
#include <stdexcept>

#include "Entrada.hpp"
#include "Excecoes.hpp"

std::string lerTexto(const std::string& pergunta) {
    while (true) {
        std::cout << pergunta;
        std::string linha;
        if (!std::getline(std::cin, linha)) {
            throw EntradaEncerrada();
        }
        if (!linha.empty()) {
            return linha;
        }
        std::cout << "O texto nao pode ser vazio\n";
    }
}

int lerInteiro(const std::string& pergunta, int min, int max) {
    while (true) {
        std::string linha = lerTexto(pergunta);
        try {
            int valor = std::stoi(linha); ;
            if (valor>=min && valor<=max) {
                return valor;
            }
        } catch (const std::invalid_argument&) {
        } catch (const std::out_of_range&) {
        }
        std::cout << "Digite um numero entre "<<min<<" e "<<max<<"\n";
    }
}

double lerDecimal(const std::string& pergunta, double min, double max) {
    while (true) {
        std::string linha = lerTexto(pergunta);
        for (std::size_t i = 0; i < linha.size(); i++) {
            if (linha[i] == ',') {
                linha[i] = '.';
            }
        }
        try {
            double valor = std::stod(linha);
            if (valor >= min && valor <= max) {
                return valor;
            }
        } catch (const std::invalid_argument&) {
        } catch (const std::out_of_range&) {
        }
        std::cout << "Digite um numero entre " << min << " e " << max
                  << " (pode usar virgula ou ponto)\n";
    }
}

bool lerSimNao(const std::string& pergunta) {
    while (true) {
        std::string resposta = lerTexto(pergunta + " (s/n): ");
        if (resposta == "s" || resposta == "S") {
            return true;
        }
        if (resposta == "n" || resposta == "N") {
            return false;
        }
        std::cout << "Responda s ou n\n";
    }
}