#include "questao5.h"
#include "limits.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int extrair_Codigo_Arquivo(){
    FILE *arq = fopen("vendas.txt", "r");
    if(arq == NULL){
        printf("Erro a abrir o arquivo\n");
        return 0;
    }

    Produto p;
    char linha[100];
    int max = 0;

    while (fgets(linha, sizeof(linha), arq))
    {
        if(!(sscanf(linha,"%d;%d;%f", &p.codigo, &p.quantidade, &p.preco_unitario ) == 3)){
            continue;
        }
        if (p.codigo > max) {
            max = p.codigo;
        }
    }
    fclose(arq);
    return max + 1;
}

void addVendidoTotal(float *maisVendido, int *index, float *total)
{
    FILE *arq = fopen("vendas.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char linha[100];
    int opcao;

    if(!arq || !temp)
    {
        printf("Erro a abrir o arquivo\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arq))
    {
        if(strncmp(linha, "TOTAL;", 6) == 0)
        {
            continue;
        }
        if(strncmp(linha, "MAIS_VENDIDO;", 13) == 0)
        {
            continue;
        }

        fputs(linha, temp);
    }
    

    fprintf(temp, "TOTAL;%2.f\n", *total);
    fprintf(temp, "MAIS_VENDIDO;%d;%2.f\n", *index, *maisVendido);

    fclose(arq);
    fclose(temp);

    remove("vendas.txt");
    rename("temp.txt", "vendas.txt");

    do
    {
        printf("Total geral: %f\n", *total);
        printf("Produto mais vendido: %d (R$ %f)\n", *index, *maisVendido);
        printf("Digite 1 para sair:");
        scanf("%d",&opcao);

    }while(opcao != 1);

    *total = 0;
    *index = 0, *maisVendido = 0;
}

int procesaDados(float *maisVendido, int *index, float *total)
{
    FILE *arq = fopen("vendas.txt", "r");
    if(arq == NULL)
    {
        printf("Erro a abrir o arquivo\n");
        return 0;
    }
    
    Produto p;
    char linha[100];
    int opcao;
    int validation = 1;
    float max = 0;
    do
    {
        printf("Processamento concluido:\n");
        while (fgets(linha, sizeof(linha), arq))
        {
            if(!(sscanf(linha, "%d;%d;%f", &p.codigo, &p.quantidade, &p.preco_unitario) == 3))
            {
                continue;
            }

            max = p.quantidade * p.preco_unitario;
            *total += max;

            if(max > *maisVendido)
            {
                *maisVendido = max;
                *index = p.codigo;
            }
            printf("Total produto %d: R$ %2.f\n",p.codigo, max);
        }
        
        if(!(*total && *maisVendido && *index))
        {
            validation = 0;
            printf("Nenhum produto adicionado\n");
        }

        printf("Digite 1 para sair:");
        scanf("%d",&opcao);

    }while(opcao != 1);
    fclose(arq);

    return validation;
}

void adicionaProduto(Produto *p, int *codigo){
    printf("%d",*codigo);
    p->codigo = *codigo;
    printf("Informe a quantidade de produto\n");         
    scanf("%d", &p->quantidade);
    printf("Informe o preco unitario do produto\n");
    scanf("%f",&p->preco_unitario);
    (*codigo)++; 
}

void addprodutoFile(int *codigo){
    FILE *arq = fopen("vendas.txt", "a");
    if(arq == NULL){
        printf("Erro a abrir o arquivo\n");
        return;
    }
    Produto produto;
    adicionaProduto(&produto, codigo);
    fprintf(arq, "%d;%d;%.2f\n", produto.codigo, produto.quantidade, produto.preco_unitario);
    fclose(arq);
    printf("Produto adicionado com sucesso!\n");
}

int mainQuestao5()
{
    int opcao, codigo, index=0;
    float maisVendido=0, total=0;
    codigo = extrair_Codigo_Arquivo();

    do
    {
        system("cls");
        printf("-----------------Menu---------------\n");
        printf("|-----------Informe a opcao----------|\n");
        printf("||\n");
        printf("1-Adiciona Produto---------------<<-\n");
        printf("2-Processar Dados----------------<<-\n");
        printf("3-Sair---------------------------<<-\n");
        printf("\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            addprodutoFile(&codigo);
            break;
        case 2:
            system("cls");
            if(procesaDados(&maisVendido,&index, &total))
            {
                addVendidoTotal(&maisVendido,&index,&total);
            }
            break;
        default:
            break;
        }
    } while (opcao != 3);
    return 0;
}