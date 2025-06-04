#include <stdio.h>
#include <stdlib.h>
#include "methods/questao1.h"
#include "methods/questao3.h"
#include "methods/questao5.h"

// lembra que vamos usar o limpar a tela no Ubuntu dele tmb
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
        printf("*----------------------------------*\n");
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
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            clearScreen();
            mainQuestao1();
            break;

        case 3:
            clearScreen();
            mainQuestao3();
            break;

        case 5:
            clearScreen();
            mainQuestao5();
            break;
        default:
            break;
        }
    } while (opcao != 6);
    return 0;
}