#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RotaOnibus.h"

typedef struct RotaOnibus
{
    char nome_rota[50];
    ListaCidade *prox_cidade;
    struct RotaOnibus *prox;
} ElemR;

typedef struct cidade
{
    char nome[30];
    char descricao[200];
    struct cidade *ant;
    struct cidade *prox;
} ElemC;

struct descritor
{
    struct cidade *inicio;
    struct cidade *final;
    int qtd;
};

Lista *criarLista()
{
    Lista *list = (Lista *)malloc(sizeof(Lista));

    if (list != NULL)
    {
        *list = NULL;
    }
    return list;
}

ListaCidade *criarLista2()
{
    ListaCidade *list = (ListaCidade *)malloc(sizeof(ListaCidade));

    if (list != NULL)
    {
        list->inicio = NULL;
        list->final = NULL;
        list->qtd = 0;
    }
    return list;
}

void cadastrarRota(Lista *list)
{
    system("cls");

    ElemR *no = (ElemR *)malloc(sizeof(ElemR));

    ElemC *curitiba = (ElemC *)malloc(sizeof(ElemC));

    no->prox_cidade = criarLista2();

    printf("Qual o nome da rota? ");
    setbuf(stdin, NULL);
    gets(no->nome_rota);

    strcpy(curitiba->nome, "Curitiba");
    strcpy(curitiba->descricao, "Conhecida por ser a capital ecologica do Brasil");
    curitiba->ant = NULL;
    curitiba->prox = NULL;
    no->prox_cidade->inicio = curitiba;
    no->prox_cidade->final = curitiba;
    no->prox = NULL;

    if ((*list) == NULL)
    {
        no->prox = (*list);
        *list = no;
    }

    else
    {
        ElemR *aux;
        aux = *list;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        no->prox_cidade->inicio = curitiba;
        aux->prox = no;
    }
}

void cadastraPonto(Lista *list, int rotas)
{

    ElemC *cidade = (ElemC *)malloc(sizeof(ElemC));

    ElemR *no = (*list);

    for (int i = 0; i < rotas - 1; i++)
    {
        no = no->prox;
    }
    ElemC *aux;
    int escolha = 0;
    do
    {
        printf("\n1. Cadastrar ponto (paradas)");
        printf("\n2. Concluir cadastro de rota (ao chegar ao destino da rota)");
        printf("\n--> ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            cidade = (ElemC *)malloc(sizeof(ElemC));
            printf("\nQual o nome do ponto? ");
            setbuf(stdin, NULL);
            gets(cidade->nome);
            printf("\nQual a descricao do ponto? ");
            setbuf(stdin, NULL);
            gets(cidade->descricao);
            cidade->prox = NULL;
            aux = no->prox_cidade->final;
            aux->prox = cidade;
            no->prox_cidade->final = cidade;
            cidade->ant = aux;
            system("cls");
            break;

        case 2:
            break;
        }
    } while (escolha != 2);
    system("cls");
}

int excluirRota(Lista *list)
{

    int x = 1;
    char rota[50];

    if (list == NULL)
        return 0;

    ElemR *ant, *no = *list;

    if (no == NULL)
    {
        printf("\n*ERRO! Nao existem rotas cadastradas...\n");
        system("pause;");
        return 0;
    }

    printf("\n- - - - Rotas - - - -\n");
    while (no != NULL)
    {
        printf("- %s\n", no->nome_rota);
        no = no->prox;
    }

    no = *list;
    printf("\nQual rota deseja exluir? ");
    setbuf(stdin, NULL);
    gets(rota);
    x = strcmp(no->nome_rota, rota);
    while (no != NULL && x != 0)
    {
        ant = no;
        x = strcmp(no->nome_rota, rota);
        if (x != 0)
        {
            no = no->prox;
        }
    }

    if (no == NULL)
    {
        printf("\n*ERRO! Rota nao encontrada...\n");
        system("pause;");
        return 0;
    }
    if (no == *list)
        *list = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    printf("\n*Rota excluida com sucesso!\n");
    system("pause;");
    return 1;
}

void imprimeLista(Lista *list)
{

    int escolha, x = 1;
    char rota[50];

    ElemR *no = *list;

    ElemC *cidade;

    if (list == NULL)
        return;

    if (no == NULL)
    {
        printf("\n* Atenção ! Nao existem rotas cadastradas \n");
        system("pause;");
        return;
    }

    printf("\n- - - - Rotas - - - -\n");
    while (no != NULL)
    {
        printf("- %s\n", no->nome_rota);
        no = no->prox;
    }

    no = *list;

    printf("\nQual a rota deseja visitar? ");
    setbuf(stdin, NULL);
    gets(rota);

    while (no != NULL && x != 0)
    {
        x = strcmp(no->nome_rota, rota);
        if (x != 0)
        {
            no = no->prox;
        }
    }

    if (no == NULL)
    {
        printf("\n*ERRO! Rota nao encontrada...\n");
        system("pause;");
        return;
    }
    cidade = no->prox_cidade->inicio;
    do
    {
        system("cls");
        printf("-------------------------------\n");
        printf("Rota: %s\n", no->nome_rota);
        printf("Voce esta em %s!\n", cidade->nome);
        printf("%s\n", cidade->descricao);
        printf("-------------------------------\n");

        if (cidade->prox != NULL)
        {
            printf("\n1. Avancar para a proxima cidade");
        }

        if (cidade->ant != NULL)
        {
            printf("\n2. Voltar para a cidade anterior");
        }
        printf("\n3. Sair da rota\n");
        printf("\n--> ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            if (cidade->prox != NULL)
            {
                cidade = cidade->prox;
            }
            break;
        case 2:
            if (cidade->ant != NULL)
            {
                cidade = cidade->ant;
            }
            break;
        case 3:
            break;
        }
    } while (escolha != 3);
}

void liberarLista(Lista *list)
{
    if (list != NULL)
    {
        ElemR *no;
        while ((*list) != NULL)
        {
            no = *list;
            liberarLista2(no->prox_cidade);
            *list = (*list)->prox;
            free(no);
        }
        free(list);
    }
}

void liberarLista2(ListaCidade *cidade)
{
    ElemC *c;
    while (c != cidade->final)
    {
        c = cidade->inicio;
        cidade->inicio = c->prox;
        free(c);
    }
    free(cidade);
}
