#ifndef ENTRADA_HPP
#define ENTRADA_HPP

#include <string>

/**
 * @brief Lê uma linha de texto não vazia digitada no terminal.
 *
 * @param pergunta Texto mostrado antes da leitura.
 * @return Texto digitado.
 * @throws EntradaEncerrada se a entrada do terminal terminar.
 */
std::string lerTexto  (const std::string& pergunta);

/**
 * @brief Lê um número inteiro dentro de um intervalo.
 *
 * @param pergunta Texto mostrado antes da leitura.
 * @param min Menor valor aceito.
 * @param max Maior valor aceito.
 * @return Número digitado.
 * @throws EntradaEncerrada se a entrada do terminal terminar.
 */
int lerInteiro(const std::string& pergunta , int min, int max);

/**
 * @brief Lê um número decimal dentro de um intervalo (aceita vírgula ou ponto).
 *
 * @param pergunta Texto mostrado antes da leitura.
 * @param min Menor valor aceito.
 * @param max Maior valor aceito.
 * @return Número digitado.
 * @throws EntradaEncerrada se a entrada do terminal terminar.
 */
double lerDecimal(const std::string& pergunta, double min, double max);

/**
 * @brief Faz uma pergunta de sim ou não.
 *
 * @param pergunta Texto mostrado antes da leitura.
 * @return true para "s" e false para "n".
 * @throws EntradaEncerrada se a entrada do terminal terminar.
 */
bool lerSimNao(const std::string& pergunta);


#endif