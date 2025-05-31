#include <stdio.h>
#include <stdlib.h>
#include "methods/questao5.h"

int main(){
    int opcao;
    do{
        system("cls");
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
        case 5:
            system("cls");
            mainQuestao5();
            break;
        default:
            break;
        }
    }while(opcao != 6);
    return 0;
}