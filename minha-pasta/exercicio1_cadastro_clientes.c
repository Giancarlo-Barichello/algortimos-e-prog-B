#include <stdio.h>

#define MAX_CLIENTES 100

typedef struct {
    int codigo;
    int idade;
    char telefone[20];
} Cliente;

int cadastrarCliente(Cliente clientes[], int total) {
    if (total >= MAX_CLIENTES) {
        printf("\nLimite máximo de clientes atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Cliente ---\n");

    printf("Código: ");
    scanf("%d", &clientes[total].codigo);

    printf("Idade: ");
    scanf("%d", &clientes[total].idade);

    printf("Telefone: ");
    scanf(" %19[^\n]", clientes[total].telefone);

    total++;
    printf("Cliente cadastrado com sucesso!\n");

    return total;
}

void listarClientes(Cliente clientes[], int total) {
    if (total == 0) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < total; i++) {
        printf("Código: %d | Idade: %d | Telefone: %s\n",
               clientes[i].codigo,
               clientes[i].idade,
               clientes[i].telefone);
    }
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar todos os clientes\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarCliente(clientes, total);
                break;
            case 2:
                listarClientes(clientes, total);
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

