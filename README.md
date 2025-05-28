# Projeto Algoritmos II

Professor: José Denes Lima Araújo

Autores: [Alysson Michel](https://github.com/aIlyson), [Kleber Moura](https://github.com/Kleber232) e [Vinicius Andrade](https://github.com/Vinny00101).

---  

## Questão 1 (2,0 pontos)

Crie um programa que leia 10 números inteiros em um vetor e encontre o **índice do segundo maior elemento**, sem alterar a ordem.

**Protótipo da função:**

```c
void indiceSegundoMaior(int *vetor, int tamanho, int *indice);
````

**Requisitos:**

* Usar apenas aritmética de ponteiros
* Não usar ordenação
* Função `main` deve:

  * Ler os elementos
  * Exibir vetor original
  * Chamar `indiceSegundoMaior`
  * Exibir índice do segundo maior

**Exemplo:**

```
Vetor: 12 7 20 5 20 8 30 3 18 10  
Índice do segundo maior: 2 (Elemento 20)
```

---

## Questão 2 (2,0 pontos)

Sistema acadêmico em C para gerenciar notas de até 100 alunos.

**Dados de cada aluno:**

* Nome (50 caracteres)
* Matrícula (int)
* Número de disciplinas (m)
* Vetor de até 10 disciplinas

**Dados de cada disciplina:**

* Nome (50 caracteres)
* Nota final (float)

**O programa deve:**

* Exibir nome e matrícula do aluno com maior média
* Exibir média geral de todas as notas

**Requisitos:**

* Usar ponteiros em todas as funções
* Acesso por aritmética de ponteiros
* Usar structs e vetores (sem alocação dinâmica)
* Funções:

```c
void cadastrarAlunos(Aluno *alunos, int n);
int encontrarMaiorMedia(Aluno *alunos, int n);
float calcularMediaGeral(Aluno *alunos, int n);
```

**Exemplo de Entrada:**

```
2 alunos
Ana, 123, 2 disciplinas: 9.0, 8.0  
Bruno, 456, 3 disciplinas: 6.0, 5.0, 7.0
```

**Saída:**

```
Aluno com maior média: Ana (Matrícula: 123)  
Média geral: 7.00
```

---

## Questão 3 (2,0 pontos)

Leia `n` números inteiros (n ≤ 1000) e reorganize com base na **proximidade ao valor médio**.

**Requisitos:**

* Usar aritmética de ponteiros
* Função para calcular a média
* Função para reorganizar vetor
* Não usar funções prontas de ordenação ou valor absoluto

**Exemplo de Entrada:**

```
n = 6  
Vetor: 4 8 6 10 2 6  
Média: 6  
```

**Ordenação esperada:**

```
6 6 4 8 2 10
```

---

## Questão 4 (2,0 pontos)

Programa que manipula uma **matriz de inteiros (L x C)** representada como:

```c
int *mat[L];
```

**O programa deve:**

* Ler os elementos
* Substituir negativos por 0
* Somar elementos da diagonal principal

**Função:**

```c
int processarMatriz(int **mat, int l, int c);
```

**Requisitos:**

* Usar `int *mat[L]`
* Acesso por aritmética de ponteiros
* Sem `[]`, exceto para declaração
* Sem alocação dinâmica

**Exemplo de Entrada:**

```
L = 3, C = 3  
Matriz:  
5 -3 7  
-2 4 -1  
6 9 -8
```

**Saída:**

```
Matriz modificada:  
5 0 7  
0 4 0  
6 9 0  
Soma da diagonal: 9
```

---

## Questão 5 (2,0 pontos)

Programa que lê o arquivo `vendas.txt` com formato:

```
[codigo_produto];[quantidade];[preco_unitario]
```

**O programa deve:**

* Calcular total por produto
* Identificar produto mais vendido
* Calcular total geral
* Atualizar o arquivo com:

  * `TOTAL;[valor_total]`
  * `MAIS_VENDIDO;[codigo];[valor]`

**Requisitos:**

* Usar struct
* Validar existência do arquivo
* Manter formato original
* Adicionar as novas linhas no final
* Enviar `vendas.txt` original com o código

**Exemplo de arquivo original:**

```
1001;5;10.50  
1002;3;25.00  
1003;10;7.80
```

**Saída esperada:**

```
Total 1001: R$ 52.50  
Total 1002: R$ 75.00  
Total 1003: R$ 78.00  
Total geral: R$ 205.50  
Mais vendido: 1003 (R$ 78.00)
```

**Arquivo final:**

```
1001;5;10.50  
1002;3;25.00  
1003;10;7.80  
TOTAL;205.50  
MAIS_VENDIDO;1003;78.00