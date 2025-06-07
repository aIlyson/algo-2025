#ifndef QUESTAO_5
#define QUESTAO_5
#include <stdio.h>
#include <string.h>

void clearScreen5();

// Declaration of function
typedef struct
{
    int codigo;
    int quantidade;
    float preco_unitario;
}Produto;

int extrair_Codigo_Arquivo();
void addVendidoTotal(float *maisVendido, int *index, float *total);
int procesaDados(float *maisVendido, int *index, float *total);
void adicionaProduto(Produto *p, int *codigo);
void addprodutoFile(int *codigo);
int mainQuestao5();

#endif