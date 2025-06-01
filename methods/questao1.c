#include <stdio.h>
#include "questao1.h"

void indiceSegundoMaior(int *vet, int tamanho, int *p)
{
    int maior = *(vet);         // equivalente a vet[0]
    int indicemaior = 0;

    // codigo basico pra encontrar o maior
    for (int i = 1; i < tamanho; i++)
    {
        if (*(vet + i) > maior)
        {
            maior = *(vet + i);
            indicemaior = i;
        }
    }

     // Precisamos iniciar a busca pelo segundo maior número com algum valor do vetor(minha ideia inicial era maior=0 porem limita usar numeros negativos)
    // que não seja o próprio maior já encontrado. Para isso, verificamos se o maior
   // estava na posição 0. Se estiver, começamos com a posição 1; caso contrário, com a 0.
    if (indicemaior == 0) {
        maior = *(vet + 1);
        *p = 1;
    } else {
        maior = *(vet);
        *p = 0; //é necessária a atualização de *p pq supondo int vet[5] = {10, 10, 10, 10, 10}; 
                //o segundo loop não encontrará maior e *p não será atualizado imprimindo lixo de memória.

    }

    // Encontra o segundo maior(o continue pula o maior e procura o segundo maior)
    for (int i = 0; i < tamanho; i++)
    {
        if (i == indicemaior)
            continue;

        if (*(vet + i) > maior)
        {
            maior = *(vet + i);
            *p = i;
        }
    }

    printf("Índice do segundo maior elemento: %d (Elemento %d)\n",*p, maior);
}

int mainQuestao1()
{int vet[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o valor (%d/10) do vetor\n",i+1);
        scanf("%d",&vet[i]);
    }
    
    int indice = 0;
    indiceSegundoMaior(vet, 10, &indice);
    return 0;
}
