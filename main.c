#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Quiz.h"
#include "Consulta.h"

int main()
{
    setlocale(LC_ALL, "");
    Pergunta teste[5];
    carregar_perguntas(teste, "Perguntas.txt");
    int pontAtual = 0;
    int selecaoMenu = 0;
    while (selecaoMenu != 3)
    {
        system("cls");
        printf("\n\n                         BEM-VINDO AO NOSSO QUIZ DE CONHECIMENTOS GERAIS   \n\n");
        printf("\n                                         ----- MENU ----- \n");
        printf("\n\n                    1-Iniciar Quiz     |     2-Checar pontuação     |     3-Sair\n\n\n");
        printf("Selecione uma opção do menu: ");
        scanf("%d", &selecaoMenu);
        if (selecaoMenu == 1)
        {
            Jogador recorde;
            carregar_recorde(&recorde);
            int pontos;
            iniciar_quiz(teste, 5, &pontos);
            if (pontos > recorde.pontuacao){
                 printf("\nNOVO RECORDE!\nDigite seu nome: ");
                 scanf("%s", recorde.nome);
                 recorde.pontuacao = pontos;
                 salvar_recorde(recorde);
            }
            system("cls");
        }
        if (selecaoMenu == 2)
        {
            system("cls");
            Jogador j;
            carregar_recorde(&j);
            printf("\n\n     Consultando Pontuação... \n\n\n");
            printf("Nome: %s\n", j.nome);
            printf("Pontuação: %d\n", j.pontuacao);
            system("pause");
        }
    }
    exit(0);
    return 0;
    
}

