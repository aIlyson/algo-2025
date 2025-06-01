#ifndef QUESTAO_5
#define QUESTAO_5
#include <stdio.h>
#include <string.h>

// Declaration of function
typedef struct
{
    int codigo;
    int quantidade;
    float preco_unitario;
}Produto;

int extrair_Codigo_Arquivo();
// funcao para adiciona os produtos na struct
void addVendidoTotal(float *maisVendido, int *index, float *total);
// Atualizar o arquivo com function
int procesaDados(float *maisVendido, int *index, float *total);
// funcao para buscar o ultimo codigo de produto e depois retorna o codigo + 1 que sera o proximo depois do maior
void adicionaProduto(Produto *p, int *codigo);
// funcao que adiciona os dados no file
void addprodutoFile(int *codigo);
// funcao main
int mainQuestao5();

#endif