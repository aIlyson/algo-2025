#include "questao4.h"
#include <stdio.h>

int processarMatriz(int **mat, int l, int c){
    int soma = 0;
    // substituir todos os numeros negativos por 0
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(*(*(mat + i) + j) < 0)
            {
                *(*(mat + i) + j) = 0;
            }
        }
    }

    // exibir a matriz modificada
    printf("Matriz modificada:\n");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }

    // depois faz a soma da diagonal principal.
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(i == j)
            {
                soma += *(*(mat + i) + j);
            }
        }
    }
    return soma;
}

int mainQuestao4(){
    int linha0[C], linha1[C], linha2[C];
    int *mat[L] = {linha0, linha1, linha2};

    printf("informe os elementos da matriz\n");
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &*(*(mat + i) + j));
        }
    }
    
    int diagonal = processarMatriz(mat, L, C);
    printf("A soma da diagonal principal: %d", diagonal);
    return 0;
}