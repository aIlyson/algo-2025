#ifndef QUESTAO2_H
#define QUESTAO2_H

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


void cadastrarAlunos(Aluno *alunos, int n);
int encontrarMaiorMedia(Aluno *alunos, int n);
float calcularMediaGeral(Aluno *alunos, int n);
int mainQuestao2();

#endif 
