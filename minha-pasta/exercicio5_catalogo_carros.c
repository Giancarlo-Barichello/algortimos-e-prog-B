#include <stdio.h>

#define MAX_CARROS 100

typedef struct {
    int codigo;
    int ano;
    float preco;
} Carro;

int cadastrarCarro(Carro carros[], int total) {
    if (total >= MAX_CARROS) {
        printf("\nLimite máximo de carros atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Carro ---\n");

    printf("Código: ");
    scanf("%d", &carros[total].codigo);

    printf("Ano: ");
    scanf("%d", &carros[total].ano);

    printf("Preço: ");
    scanf("%f", &carros[total].preco);

    total++;
    printf("Carro cadastrado com sucesso!\n");

    return total;
}

void buscarPorPreco(Carro carros[], int total) {
    if (total == 0) {
        printf("\nNenhum carro cadastrado.\n");
        return;
    }

    float valorMaximo;
    printf("\nDigite o valor máximo: ");
    scanf("%f", &valorMaximo);

    int encontrou = 0;
    printf("\n--- Carros com preço até R$ %.2f ---\n", valorMaximo);
    for (int i = 0; i < total; i++) {
        if (carros[i].preco <= valorMaximo) {
            printf("Código: %d | Ano: %d | Preço: R$ %.2f\n",
                   carros[i].codigo,
                   carros[i].ano,
                   carros[i].preco);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum carro encontrado dentro desse valor.\n");
    }
}

int main() {
    Carro carros[MAX_CARROS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar carro\n");
        printf("2. Buscar por preço máximo\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarCarro(carros, total);
                break;
            case 2:
                buscarPorPreco(carros, total);
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
