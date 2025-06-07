#include <stdio.h>
#include "questao3.h"

// seguindo o Média = (4 + 8 + 6 + 10 + 2 + 6) / 6 = 36 / 6 = 6
float calcularMedia(int *vetor, int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += *(vetor + i);
    }
    return (float)soma / n;
}

// crie para ficar mais fácil comparar os valores
// se o valor for negativo, retorna o seu valor absoluto
int retornaValor(int x)
{
    return (x < 0) ? -x : x;
}

// testei seguindo o exemplo de reorganização
// se a média = 6, então o vetor reorganizado deve ser: 6, 4, 8, 10, 2, 6
// onde os valores são ordenados pela distância em relação à média, e em caso de empate, pelo valor do elemento
void reorganiza(int *vetor, int n, float media)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int auxI = retornaValor(*(vetor + i) - media);
            int auxJ = retornaValor(*(vetor + j) - media);

            if (auxJ < auxI || (auxJ == auxI && *(vetor + j) < *(vetor + i)))
            {
                int temp = *(vetor + i);
                *(vetor + i) = *(vetor + j);
                *(vetor + j) = temp;
            }
        }
    }
}

int mainQuestao3()
{
    int n;
    int vetor[1000]; // vou definir o tamanho máximo do vetor como 1000

    printf("Valor de n: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000)
    {
        printf("Erro... n deve estar entre 1 e 1000\n");
        return 1; // TODO: nessa situação, o programa deve retornar um código de erro, mas não deve encerrar
    }

    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("elemento %d: ", i + 1);
        scanf("%d", vetor + i);
    }

    float media = calcularMedia(vetor, n);
    reorganiza(vetor, n, media);

    printf("Vetor reorganizado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(vetor + i));
    }
    printf("\n");

    return 0;
}