# Torre de Hanói - Implementação com Pilhas

Este repositório contém a resolução do problema matemático da Torre de Hanói, implementado na linguagem C++ utilizando a estrutura de dados Pilha (`std::stack`).

## Pontos de Análise e Justificativa

**1. Por que a Pilha é a estrutura de dados naturalmente adequada para modelar as hastes deste problema?**

A Pilha é a estrutura ideal porque as regras do problema da Torre de Hanói seguem estritamente o princípio **LIFO** (*Last-In, First-Out* - Último a entrar, Primeiro a sair)[cite: 5, 8, 9]. [cite_start]De acordo com as regras, apenas o disco que está no topo de uma haste pode ser movimentado por vez[cite: 8, 9]. [cite_start]Em uma estrutura de dados do tipo Pilha, as operações de inserção (`push`) e remoção (`pop`) ocorrem unicamente em uma extremidade (o topo)[cite: 13, 14]. Assim, a Pilha modela com exatidão o comportamento físico do quebra-cabeça, garantindo via código que seja impossível acessar ou mover os discos que estão na base sem antes remover os que estão sobre eles.

**2. Seria possível resolver este problema sem recursão? Se sim, como? Se não, por quê?**

**Sim**, é perfeitamente possível resolver este problema de forma iterativa (usando laços de repetição ao invés de recursão). 

Isso pode ser implementado de duas formas principais:
* **Simulando a Pilha de Execução (Call Stack):** A recursividade funciona nos bastidores porque o sistema gerencia uma pilha interna de chamadas de funções. Para resolver iterativamente, podemos criar e gerenciar nossa própria estrutura de dados Pilha explicitamente dentro de um laço `while`, empilhando os estados do jogo (origem, destino, auxiliar e número de discos) para simular o que o computador faria automaticamente.
* **Através de Padrões Lógicos/Matemáticos:** Existe um algoritmo iterativo clássico para a Torre de Hanói. Ele dita que, se o número total de discos for par, o menor disco sempre se move uma posição para a direita. Se for ímpar, move-se para a esquerda. Nos movimentos intercalados, realiza-se o único movimento válido possível entre as duas hastes que não contêm o menor disco.
