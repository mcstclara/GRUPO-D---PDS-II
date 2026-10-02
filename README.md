# GRUPO D — Trabalho de PDS II

## Integrantes

- Ana Luísa Milhomem Martins
- Cecília Formigli Noblat
- Clara Moreira Costa
- Isabela Vilarino de Paula

---

## Sobre o projeto:

O projeto consiste em uma plataforma de E-Commerce, voltada para a venda de roupas e acessórios.

O sistema possui como objetivo reproduzir as principais operações básicas envolvidas em uma loja virtual, contemplando desde o cadastro e consulta de produtos até a realização de compras, gerenciamento de estoque, coleções, descontos e processos de troca e devolução. 

Entretanto, como a compra de roupas e acessórios em plataformas digitais ainda envolve desafios relacionados à combinação de produtos, definição do tamanho adequado, organização da compra e gerenciamento dos valores, a plataforma também contará com funcionalidades que atraiam mais o público consumidor. Visando aprimorar a experiência de compra virtual e aproximá-la da assertividade proporcionada pelas compras presenciais, o sistema contará com as funções de montagem de kits de desconto e conferência de medidas adequadas por um provador virtual.

A motivação do grupo veio do descontentamento com plataformas de E-commerce no ramo, que, por muitas vezes, não contam com ferramentas de extrema utilidade para a escolha das peças, tornando as compras presenciais mais funcionais, apesar do deslocamento. Assim, pensamos em uma plataforma que aproximaria a experiência virtual da presencial, entregando maior praticidade e adesão dos clientes.

---

## Objetivo

Desenvolver um sistema de comércio eletrônico de roupas e acessórios que permita:

- cadastrar e gerenciar clientes;
- consultar produtos;
- pesquisar e filtrar produtos;
- recomendar tamanhos com base nas medidas do cliente;
- adicionar produtos ao carrinho;
- montar kits de produtos com descontos;
- finalizar compras;
- consultar pedidos;
- gerenciar estoque;
- gerenciar produtos e coleções;
- aplicar políticas de desconto;
- solicitar trocas e devoluções.

---

## Funcionalidades

### Para clientes:

- Cadastro e gerenciamento de perfil;
- Cadastro de endereço;
- Cadastro de medidas corporais;
- Definição de preferência de caimento;
- Busca e visualização de produtos;
- Recomendação de tamanho pelo provador virtual;
- Adição e remoção de produtos do carrinho;
- Alteração da quantidade de produtos;
- Montagem de kits;
- Aplicação de descontos;
- Finalização de pedidos;
- Consulta do resumo da compra;
- Solicitação de trocas e devoluções.

### Para administradores:

- Cadastro de produtos;
- Atualização de produtos;
- Remoção de produtos;
- Gerenciamento de coleções;
- Definição de políticas de desconto;
- Consulta e atualização do estoque;
- Consulta de pedidos;
- Atualização do status dos pedidos;
- Consulta de solicitações de troca e devolução.

---

## Modelagem

O sistema é estruturado a partir de classes que representam os principais elementos do domínio.

As principais classes definidas nesta etapa são:

- `Cliente`
- `Produto`
- `Estoque`
- `ProvadorVirtual`
- `Carrinho`
- `KitRoupas`
- `Pedido`
- `Administrador`
- `TrocaDevolucao`

As especificações das funcionalidades do sistema estão descritas nas User Stories disponíveis no diretório `design/`.