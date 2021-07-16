#include <stdio.h>
#include <string.h>
#include "RotaOnibus.c"

int main()
{

    Lista *list = criarLista();

    int escolha = 0, rotas = 0, x = 0;

    do
    {
        system("cls");
        printf("\n1. Cadastrar Rota");
        printf("\n2. Excluir Rota");
        printf("\n3. Visitar Rota");
        printf("\n4. Sair");
        scanf("%d", &escolha);

        switch (escolha)
        {

        case 1:
            cadastrarRota(list);
            rotas++;
            cadastraPonto(list, rotas);
            setbuf(stdin, NULL);
            break;

        case 2:
            x = excluirRota(list);
            if (x == 1)
            {
                rotas--;
            }

            break;

        case 3:
            imprimeLista(list);
            break;

        case 4:
            liberarLista(list);
            break;

        default:
            printf("\nOpcao invalida!\n");
            system("pause;");

            system("cls");
        }
    } while (escolha != 4);

    return 0;
}
