# User Stories — E-commerce de Roupas e Acessórios do Grupo D

## US01 — Cadastro e perfil do cliente

**Descrição:**  
Como cliente, quero criar e gerenciar meu perfil para realizar compras e receber recomendações personalizadas de produtos e tamanhos.

**Critérios de aceitação:**
- Permitir o cadastro de nome, e-mail e senha.
- Não permitir o cadastro de dois clientes utilizando o mesmo e-mail.
- Permitir o cadastro e a atualização de dados pessoais e endereço de entrega.
- Permitir o cadastro de medidas corporais, como altura, tórax, cintura e quadril.
- Permitir informar a preferência de caimento entre justo, normal e largo.

---

## US02 — Busca e visualização de produtos

**Descrição:**  
Como cliente, quero pesquisar e visualizar roupas e acessórios para encontrar produtos que desejo comprar.

**Critérios de aceitação:**
- Permitir a visualização dos produtos disponíveis na loja.
- Permitir a busca de produtos pelo nome.
- Permitir a filtragem de produtos por categoria.
- Exibir informações como nome, preço, tamanho, material e quantidade disponível.
- Exibir informações sobre a coleção à qual o produto pertence.

---

## US03 — Recomendação de tamanho pelo provador virtual

**Descrição:**  
Como cliente, quero receber uma recomendação de tamanho baseada nas minhas medidas e preferência de caimento para escolher produtos mais adequados ao meu perfil.

**Critérios de aceitação:**
- Permitir comparar as medidas do cliente com a tabela de medidas do produto.
- Considerar a preferência de caimento informada pelo cliente.
- Recomendar um tamanho compatível com as medidas cadastradas.
- Informar quando não houver um tamanho adequado.
- Permitir consultar a recomendação antes de adicionar o produto ao carrinho.

---

## US04 — Carrinho e montagem de kits

**Descrição:**  
Como cliente, quero adicionar produtos ao carrinho e montar kits de roupas e acessórios para organizar minha compra e aproveitar descontos.

**Critérios de aceitação:**
- Permitir adicionar e remover produtos do carrinho.
- Permitir alterar a quantidade de cada produto.
- Permitir criar ou adicionar um conjunto de produtos a um kit.
- Calcular automaticamente o preço do kit considerando o desconto aplicável.
- Impedir a inclusão de produtos cuja quantidade disponível seja insuficiente.

---

## US05 — Finalização e resumo da compra

**Descrição:**  
Como cliente, quero finalizar minha compra e receber um resumo detalhado do pedido para confirmar os produtos adquiridos e consultar informações importantes sobre eles.

**Critérios de aceitação:**
- Permitir selecionar ou informar um endereço de entrega.
- Exibir os produtos, quantidades, preços, descontos e valor total antes da confirmação.
- Registrar o pedido após a confirmação da compra.
- Atualizar o estoque após a realização do pedido.
- Gerar um resumo do pedido em arquivo `.txt`, incluindo as instruções de lavagem e conservação dos produtos.

---

## US06 — Trocas e devoluções

**Descrição:**  
Como cliente, quero solicitar a troca ou devolução de um produto para resolver problemas com minha compra dentro das condições estabelecidas pela loja.

**Critérios de aceitação:**
- Permitir solicitar a troca ou devolução de um item de um pedido.
- Verificar se a solicitação está dentro do prazo permitido pela loja.
- Verificar se o produto é elegível para troca ou devolução.
- Impedir a solicitação quando o produto não atender às regras estabelecidas.
- Informar o motivo da recusa quando uma solicitação não for elegível.

---

## US07 — Gerenciamento de produtos, coleções e descontos

**Descrição:**  
Como administrador, quero cadastrar e gerenciar produtos e coleções para controlar o catálogo e aplicar diferentes políticas de desconto.

**Critérios de aceitação:**
- Permitir cadastrar, alterar e remover produtos.
- Permitir associar produtos a diferentes coleções.
- Permitir definir regras de desconto para cada coleção.
- Aplicar automaticamente o desconto aos produtos elegíveis.
- Exibir o preço original e o preço final quando houver desconto.

---

## US08 — Gerenciamento de estoque e pedidos

**Descrição:**  
Como administrador, quero gerenciar o estoque e os pedidos para controlar a disponibilidade dos produtos e o andamento das vendas.

**Critérios de aceitação:**
- Permitir consultar e atualizar a quantidade de produtos em estoque.
- Impedir que a quantidade disponível fique negativa.
- Permitir consultar os pedidos realizados pelos clientes.
- Permitir atualizar o status dos pedidos.
- Permitir identificar produtos sem estoque.