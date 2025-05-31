#ifndef QUESTAO_5
#define QUESTAO_5
#include <stdio.h>

// Declaration of function
typedef struct
{
    int codigo;
    int quantidade;
    float preco_unitario;
}Produto;

// Calcular total por produto function

// Identificar produto mais vendido function

// Calcular total geral function

// Atualizar o arquivo com function
int extrair_Codigo_Arquivo();
void adicionaProduto(Produto *p, int *codigo);
int addprodutoFile(int *codigo);
void mainQuestao5();

#endif