#ifndef QUIZ_H
#define QUIZ_H

#define MAX_PERGUNTAS 20

typedef struct {
    char enunciado[200];
    char opcoes[5][100];
    int resposta_correta;
} Pergunta;

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

int carregar_perguntas(Pergunta quiz[], const char* nome_arquivo);
void menu();
void iniciar_quiz(Pergunta quiz[], int total_perguntas);
void carregar_recorde(Jogador *recordista);
void salvar_recorde(Jogador recordista);

#endif

