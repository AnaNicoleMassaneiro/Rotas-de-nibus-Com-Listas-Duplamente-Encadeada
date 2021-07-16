#  Rotas de ônibus com lista duplamente encadeada

Objetivo: Implementar uma Lista de Rotas de Ônibus utilizando Listas Duplamente Encadeadas.

- Este programa deverá gerenciar um conjunto de listas de rotas/linhas de uma companhia
de ônibus intermunicipal do Estado do Paraná;
- Todas as rotas iniciam em Curitiba;
- Cada rota possui um nome que a identifica de forma única, dado pelo destino. Ex: "Campo
Largo“;
- Cada rota possui a lista de todas as cidades por onde o ônibus passa, para ir de Curitiba
ao destino;
- A rota de ônibus, ao retornar, passa pelos mesmos lugares. Portanto, pode ser
representada por uma lista duplamente encadeada;
- O usuário deve poder escolher uma rota e poder navegar por ela, indo de cidade em
cidade e voltando para a cidade anterior, usando para tanto as teclas de seta à esquerda e
seta à direita ou 1- Ir para próxima cidade; 2 – Voltar para a ciadde anterior;
- Cada nodo representando uma cidade possui, além do nome, um texto descrevendo
alguma característica desta cidade. Ex.: "Lá encontram-se as melhores porcelanas". Este
texto é mostrado quando se visita um nodo.
- Implemente o programa de rotas como uma lista de listas;
- A lista que contém todas as rotas pode ser uma lista encadeada ou uma lista estática em
vetor em vetor;
- Cada lista que representa uma rota deve ser uma lista duplamente encadeada;
- Aplicar o conceito de nó descritor na lista duplamente encadeada.
- Menu de Entrada:
1. Cadastrar Rota
2. Excluir Rota
3. Visitar Rota
4. Sair
