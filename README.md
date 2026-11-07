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
- gerenciar o catálogo de produtos, organizados em coleções;
- solicitar trocas e devoluções dentro do prazo.

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
- Montagem de kits com desconto automático;
- Finalização de pedidos;
- Consulta do resumo da compra;
- Solicitação de trocas e devoluções.

### Para administradores:

- Cadastro de produtos, com coleção e tabela de medidas;
- Alteração do preço dos produtos;
- Remoção de produtos do catálogo;
- Consulta e atualização do estoque;
- Consulta de pedidos;
- Atualização do status dos pedidos, com o registro da entrega.

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

---

## Como compilar e testar

O projeto usa **C++11**, **Make** e o framework de testes **doctest** (já incluído em `tests/doctest.h`). Os comandos abaixo devem ser executados na raiz do repositório, em um terminal Linux, WSL ou Git Bash.

| Comando | O que faz |
|---|---|
| `make` | Compila as classes de `src/` e o programa da loja (`build/loja`) |
| `make run` | Compila e abre o programa da loja no terminal |
| `make test` | Compila e executa todos os testes de unidade de `tests/` |
| `make coverage` | Recompila com instrumentação, executa os testes e mostra a cobertura do código com o gcovr (relatório em `build/cobertura/index.html`) |
| `make clean` | Apaga os arquivos gerados na compilação |

Para o `make coverage`, é necessário instalar o gcovr: `pip install gcovr`.

---

## Como usar o programa

Na raiz do repositório, rode `make run` (no Windows, `mingw32-make run` no Git Bash). O programa lê o catálogo inicial de `data/produtos.txt` e abre o menu principal:

- **Catálogo:** ver os produtos, buscar por nome, filtrar por categoria e montar kits com desconto.
- **Minha conta:** criar conta, entrar, cadastrar endereço, medidas e preferência de caimento.
- **Provador virtual:** recomendação de tamanho a partir das medidas.
- **Carrinho:** adicionar, remover, alterar quantidades e finalizar a compra. A compra gera o arquivo `pedido_N.txt` com o resumo e os cuidados com as peças.
- **Meus pedidos** e **Trocas e devoluções**.
- **Área do administrador:** estoque, pedidos e seus status (ao marcar um pedido como entregue, informa-se há quantos dias foi a entrega), cadastro, remoção e alteração de preço de produtos.


O arquivo `data/produtos.txt` tem um produto por linha, no formato `id;nome;categoria;preco;material;colecao;quantidade;tamanhos`. Cada tamanho é escrito como `TAMANHO=peito,cintura,quadril`, e os tamanhos são separados por `|`.

### Regras da loja

- **Kits:** com 2 peças, 10% de desconto; com 3 ou mais, 15%.
- **Trocas e devoluções:** só para pedidos com status "Entregue", para produtos que fazem parte do pedido e em até 30 dias depois da entrega (`TrocaDevolucao::PRAZO_DIAS`). Quando a solicitação é recusada, o programa mostra o motivo.
- **Estoque:** a quantidade nunca fica negativa, e não é possível comprar mais unidades do que as disponíveis.

### Programação defensiva e exceções (C9)

- As classes de `src/` validam os dados recebidos e lançam `std::invalid_argument` ou `std::logic_error` quando algo é inválido.
- Os erros das regras da loja usam a hierarquia de `include/Excecoes.hpp` (`ErroLoja` e suas classes filhas).
- A interface (pasta `app/`) lê todas as entradas com as funções de `app/Entrada.hpp`, que repetem a pergunta até o valor ser válido.
- O `main` trata as exceções, então um erro de digitação mostra uma mensagem em vez de fechar o programa.