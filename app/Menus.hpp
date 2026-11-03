#ifndef MENUS_HPP
#define MENUS_HPP

class Loja;

/**
 * @brief Catálogo: ver, buscar, filtrar e montar kits (US02 e US04).
 *
 * @param loja Dados da loja.
 */
void menuCatalogo(Loja& loja);

/**
 * @brief Conta do cliente: criar, entrar, perfil e medidas (US01).
 *
 * @param loja Dados da loja.
 */
void menuConta(Loja& loja);

/**
 * @brief Provador virtual: recomendação de tamanho (US03).
 *
 * @param loja Dados da loja.
 */
void menuProvador(Loja& loja);

/**
 * @brief Carrinho e finalização da compra (US04 e US05).
 *
 * @param loja Dados da loja.
 */
void menuCarrinho(Loja& loja);

/**
 * @brief Pedidos do cliente (US05).
 *
 * @param loja Dados da loja.
 */
void menuPedidos(Loja& loja);

/**
 * @brief Trocas e devoluções (US06).
 *
 * @param loja Dados da loja.
 */
void menuTrocas(Loja& loja);

/**
 * @brief Área do administrador: estoque, pedidos e produtos (US07 e US08).
 *
 * @param loja Dados da loja.
 */
void menuAdministrador(Loja& loja);

#endif