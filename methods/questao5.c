#include "questao5.h"
#include "limits.h"
#include <stdlib.h>
#include <stdio.h>


int extrair_Codigo_Arquivo(){
    FILE *arq = fopen("vendas.txt", "r");
    if(arq == NULL){
        printf("Erro a abrir o arquivo\n");
        return 1;
    }

    char linha[100];
    int max = 0, codigo, quantidade;
    float preco_unitario;

    while (fgets(linha, sizeof(linha), arq))
    {
        if(sscanf(linha,"%d;%d;%f", &codigo, &quantidade, &preco_unitario ) == 3){
            printf("%d", codigo);
            if (codigo > max) {
                max = codigo;
            }
        }
    }
    return max;
}
// implementation of function
void adicionaProduto(Produto *p, int *codigo){
    p->codigo = *codigo;
    printf("Informe a quantidade de produto\n");         
    scanf("%d", &p->quantidade);
    printf("Informe o preco unitario do produto\n");
    scanf("%f",&p->preco_unitario);
    (*codigo)++;
}

int addprodutoFile(int *codigo){
    FILE *arq = fopen("vendas.txt", "a");
    if(arq == NULL){
        printf("Erro a abrir o arquivo\n");
        return 1;
    }
    (*codigo)++;
    Produto produto;
    adicionaProduto(&produto, codigo);

    fprintf(arq, "%d;%d;%.2f\n", produto.codigo, produto.quantidade, produto.preco_unitario);
    fclose(arq);
    printf("Produto adicionado com sucesso!\n");

    return 0;
}

void mainQuestao5(){
    int opcao, codigo;
    codigo = extrair_Codigo_Arquivo();

    do
    {
        system("cls");
        printf("*-----------------Menu---------------*\n");
        printf("|-----------Informe a opcao----------|\n");
        printf("|____________________________________|\n");
        printf("*1-Adiciona Produto---------------<<-*\n");
        printf("*2-Sair---------------------------<<-*\n");
        printf("*____________________________________*\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            addprodutoFile(&codigo);
            break;
        
        default:
            break;
        }
    } while (opcao != 2);
}