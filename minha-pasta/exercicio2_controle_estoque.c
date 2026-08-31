#include <stdio.h>

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    int quantidade;
    float preco;
} Produto;

int cadastrarProduto(Produto produtos[], int total) {
    if (total >= MAX_PRODUTOS) {
        printf("\nLimite máximo de produtos atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Produto ---\n");

    printf("Código: ");
    scanf("%d", &produtos[total].codigo);

    printf("Quantidade: ");
    scanf("%d", &produtos[total].quantidade);

    printf("Preço: ");
    scanf("%f", &produtos[total].preco);

    total++;
    printf("Produto cadastrado com sucesso!\n");

    return total;
}

void exibirValorTotalEstoque(Produto produtos[], int total) {
    if (total == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    float valorTotal = 0;
    for (int i = 0; i < total; i++) {
        valorTotal += produtos[i].quantidade * produtos[i].preco;
    }

    printf("\nValor total investido no estoque: R$ %.2f\n", valorTotal);
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir valor total investido no estoque\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarProduto(produtos, total);
                break;
            case 2:
                exibirValorTotalEstoque(produtos, total);
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
