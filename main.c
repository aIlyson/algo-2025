#include <stdio.h>
#include <stdlib.h>
#include "methods/questao1.h"
#include "methods/questao2.h"
#include "methods/questao3.h"
#include "methods/questao4.h"
#include "methods/questao5.h"

// lembra que precisamos limpar a tela tanto no Windows quanto no Linux/Ubuntu
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    int opcao;

    do
    {
        clearScreen();
        printf("*------------------------------------*\n");
        printf("*------------Menu Questoes-----------*\n");
        printf("|-----------Informe a opcao----------|\n");
        printf("|____________________________________|\n");
        printf("*1-Questao 1----------------------<<-*\n");
        printf("*2-Questao 2----------------------<<-*\n");
        printf("*3-Questao 3----------------------<<-*\n");
        printf("*4-Questao 4----------------------<<-*\n");
        printf("*5-Questao 5----------------------<<-*\n");
        printf("*6-Sair---------------------------<<-*\n");
        printf("*____________________________________*\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        clearScreen(); // tirei o clearScreen() do switch para evitar limpar a tela antes de mostrar o resultado da questao

        switch (opcao)
        {
        case 1:
            mainQuestao1();
            break;

        case 2:
            mainQuestao2();
            break;

        case 3:
            mainQuestao3();
            break;

        case 4:
            mainQuestao4();
            break;

        case 5:
            mainQuestao5();
            break;

        case 6:
            printf("Saindo...\n");
            break;

        default:
            printf("Erro... digite uma opcao valida\n");
            break;
        }

        if (opcao != 6)
        {
            printf("\nAperte ENTER para voltar ao menu...");
            getchar(); // necessario para que o programa aguarde o usuário pressionar ENTER
            getchar();
        }

    } while (opcao != 6);

    return 0;
}
