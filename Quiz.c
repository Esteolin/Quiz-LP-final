#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Quiz.h"

int carregar_perguntas(Pergunta quiz[], const char* nome_arquivo) {
    FILE *f = fopen(nome_arquivo, "r");
    if (!f) {
        printf("\nErro ao abrir arquivo %s\n", nome_arquivo);
        return 0;
    }
    char linha[256];
        for (int i = 0;i < 5;i++)
        {
                fgets(linha, sizeof(linha), f);
                linha[strcspn(linha, "\n")] ='\0';
                strcpy(quiz[i].enunciado, linha);
                for (int k = 0;k < 5;k++)
                {
                    fgets(linha,sizeof(linha), f);
                    linha[strcspn(linha, "\n")] = '\0';
                    strcpy(quiz[i].opcoes[k], linha);
                }
                fgets(linha, sizeof(linha), f);
                quiz[i].resposta_correta = atoi(linha);
                fgets(linha, sizeof(linha), f);
        }
    fclose(f);
    return 5;
};

void iniciar_quiz(Pergunta quiz[], int total_perguntas) {
    setlocale(LC_ALL, "");
    int resposta;
    for (int i = 0; i < total_perguntas;i++)
    {
        system("cls");
        printf("\n--- PERGUNTA NUMERO %d ---\n", i+1);
        printf("    %s", quiz[i].enunciado);
        for(int j = 0;j < 5;j++)
        {
            printf("\n%s", quiz[i].opcoes[j]);
        }
        printf("\n");
        printf("\nDigite o numero da resposta correta(1-5): ");
        scanf("%d", &resposta);
        if (resposta != quiz[i].resposta_correta)
        {
            system("cls");
            printf("\n\n      Não foi dessa vez!! Tente na próxima pergunta!\n\n");
            system("pause");
        }
        else
        {
            system("cls");
            printf("\n\n     Bom!!! Vamos seguir para a próxima\n\n");
            system("pause");
        }
    }
};

