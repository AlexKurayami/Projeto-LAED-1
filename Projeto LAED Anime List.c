/*
 Problema: O programa ajuda o usúario a registrar uma lista de animes, filmes, novelas e seriados assistidos para ter controle de quando episódios ele assistiu.
 Nomes: Alexsandro Bueno, Caio Henrique Paiva
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>

#define MAX_ANIMES 100

struct Anime {
    char nome[50];
    int episodiosAssistidos;
};

int main() {
    struct Anime listaAnimes[MAX_ANIMES];
    int numAnimes = 0;
    char resposta;

    printf("Lista de Animes Assistidos\n\n");

    do {
        printf("Anime: ");
        fgets(listaAnimes[numAnimes].nome, sizeof(listaAnimes[numAnimes].nome), stdin);
        listaAnimes[numAnimes].nome[strcspn(listaAnimes[numAnimes].nome, "\n")] = '\0';

        printf("Episódios Assistidos: ");
        scanf("%d", &listaAnimes[numAnimes].episodiosAssistidos);
        getchar();

        numAnimes++;

        printf("Deseja adicionar outro anime? (S/N): ");
        scanf("%c", &resposta);
        getchar();

        printf("\n");

    } while (resposta == 'S' || resposta == 's');

    // Inicialize a janela de exibição usando o Raylib
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Lista de Animes Assistidos");

    SetTargetFPS(60); // Defina a taxa de quadros por segundo

    while (!WindowShouldClose()) // Loop principal da janela
    {
        BeginDrawing();

        ClearBackground(RAYWHITE); // Limpe o plano de fundo

        // Desenhe os animes na tela usando o Raylib
        for (int i = 0; i < numAnimes; i++) {
            DrawText(TextFormat("Anime: %s", listaAnimes[i].nome), 10, 10 + 20 * i, 20, BLACK);
            DrawText(TextFormat("Episodios Assistidos: %d", listaAnimes[i].episodiosAssistidos), 10, 30 + 20 * i, 20, BLACK);
        }

        EndDrawing();
    }

    CloseWindow(); // Feche a janela ao sair

    return 0;
}
