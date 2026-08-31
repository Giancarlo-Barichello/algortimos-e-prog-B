#include <stdio.h>

#define MAX_CONTAS 100

typedef struct {
    int numeroConta;
    float saldo;
} Conta;

int cadastrarConta(Conta contas[], int total) {
    if (total >= MAX_CONTAS) {
        printf("\nLimite máximo de contas atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Conta ---\n");

    printf("Número da conta: ");
    scanf("%d", &contas[total].numeroConta);

    printf("Saldo inicial: ");
    scanf("%f", &contas[total].saldo);

    total++;
    printf("Conta cadastrada com sucesso!\n");

    return total;
}

void depositar(Conta contas[], int total) {
    if (total == 0) {
        printf("\nNenhuma conta cadastrada.\n");
        return;
    }

    int indice;
    float valor;

    printf("\n--- Depósito ---\n");
    printf("Digite a posição (índice) da conta (0 a %d): ", total - 1);
    scanf("%d", &indice);

    if (indice < 0 || indice >= total) {
        printf("Índice inválido!\n");
        return;
    }

    printf("Valor a depositar: ");
    scanf("%f", &valor);

    contas[indice].saldo += valor;
    printf("Depósito realizado com sucesso! Novo saldo: R$ %.2f\n", contas[indice].saldo);
}

void mostrarContas(Conta contas[], int total) {
    if (total == 0) {
        printf("\nNenhuma conta cadastrada.\n");
        return;
    }

    printf("\n--- Lista de Contas ---\n");
    for (int i = 0; i < total; i++) {
        printf("[%d] Número: %d | Saldo: R$ %.2f\n",
               i, contas[i].numeroConta, contas[i].saldo);
    }
}

int main() {
    Conta contas[MAX_CONTAS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar conta\n");
        printf("2. Depositar\n");
        printf("3. Mostrar todas as contas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarConta(contas, total);
                break;
            case 2:
                depositar(contas, total);
                break;
            case 3:
                mostrarContas(contas, total);
                break;
            case 4:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
