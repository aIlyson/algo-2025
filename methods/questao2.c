#include "questao2.h"
#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_DISCIPLINAS 10
#define TAM_NOME 51

typedef struct {
    char nome[TAM_NOME];
    float nota;
} Disciplina;

typedef struct {
    char nome[TAM_NOME];
    int matricula;
    int numDisciplinas;
    Disciplina disciplinas[MAX_DISCIPLINAS];
} Aluno;

// Função para cadastrar todos os alunos
void cadastrarAlunos(Aluno *alunos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Aluno %d:\n", i + 1);
        
        printf("Nome: ");
        scanf(" %[^\n]", (alunos + i)->nome);
        
        printf("Matrícula: ");
        scanf("%d", &(alunos + i)->matricula);
        
        printf("Número de disciplinas: ");
        scanf("%d", &(alunos + i)->numDisciplinas);
        
        for (int j = 0; j < (alunos + i)->numDisciplinas; j++) {
            printf("Disciplina %d - Nome: ", j + 1);
            scanf(" %[^\n]", ((alunos + i)->disciplinas + j)->nome);
            
            printf("Nota: ");
            scanf("%f", &(((alunos + i)->disciplinas + j)->nota));
        }
    }
}

// Função para encontrar o índice do aluno com a maior média
int encontrarMaiorMedia(Aluno *alunos, int n) {
    int indiceMaior = 0;
    float maiorMedia = 0.0;

    for (int i = 0; i < n; i++) {
        float soma = 0.0;
        for (int j = 0; j < (alunos + i)->numDisciplinas; j++) {
            soma += ((alunos + i)->disciplinas + j)->nota;
        }
        float media = soma / (alunos + i)->numDisciplinas;

        if (media > maiorMedia || i == 0) {
            maiorMedia = media;
            indiceMaior = i;
        }
    }

    return indiceMaior;
}

// Função para calcular a média geral de todas as notas
float calcularMediaGeral(Aluno *alunos, int n) {
    float somaTotal = 0.0;
    int totalNotas = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (alunos + i)->numDisciplinas; j++) {
            somaTotal += ((alunos + i)->disciplinas + j)->nota;
            totalNotas++;
        }
    }

    return (totalNotas > 0) ? (somaTotal / totalNotas) : 0.0;
}

int mainQuestao2() {
    Aluno alunos[MAX_ALUNOS];
    int n;

    printf("Número de alunos: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_ALUNOS) {
        printf("Número de alunos inválido!\n");
        return 1;
    }

    cadastrarAlunos(alunos, n);

    int indiceMaior = encontrarMaiorMedia(alunos, n);
    float mediaGeral = calcularMediaGeral(alunos, n);

    printf("\nAluno com maior média: %s (Matrícula: %d)\n",
           (alunos + indiceMaior)->nome,
           (alunos + indiceMaior)->matricula);

    printf("Média geral de todas as notas: %.2f\n", mediaGeral);

    return 0;
}
