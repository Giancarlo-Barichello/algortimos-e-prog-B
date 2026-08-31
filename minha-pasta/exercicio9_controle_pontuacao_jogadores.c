#include <stdio.h>

#define MAX_JOGADORES 100

typedef struct {
    int idJogador;
    int pontos;
} Jogador;

int cadastrarJogador(Jogador jogadores[], int total) {
    if (total >= MAX_JOGADORES) {
        printf("\nLimite máximo de jogadores atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Jogador ---\n");

    printf("ID do jogador: ");
    scanf("%d", &jogadores[total].idJogador);

    printf("Pontos: ");
    scanf("%d", &jogadores[total].pontos);

    total++;
    printf("Jogador cadastrado com sucesso!\n");

    return total;
}

void buscarJogadorPorId(Jogador jogadores[], int total) {
    if (total == 0) {
        printf("\nNenhum jogador cadastrado.\n");
        return;
    }

    int id;
    printf("\nDigite o ID do jogador: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (jogadores[i].idJogador == id) {
            printf("Jogador encontrado! ID: %d | Pontos: %d\n",
                   jogadores[i].idJogador, jogadores[i].pontos);
            return;
        }
    }

    printf("Jogador com ID %d não encontrado.\n", id);
}

int main() {
    Jogador jogadores[MAX_JOGADORES];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar jogador\n");
        printf("2. Buscar jogador por ID\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarJogador(jogadores, total);
                break;
            case 2:
                buscarJogadorPorId(jogadores, total);
                break;
            case 3:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
