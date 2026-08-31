#include <stdio.h>

#define MAX_IMOVEIS 100

typedef struct {
    int numeroCasa;
    float consumoKwh;
} Imovel;

int cadastrarImovel(Imovel imoveis[], int total) {
    if (total >= MAX_IMOVEIS) {
        printf("\nLimite máximo de imóveis atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Imóvel ---\n");

    printf("Número da casa: ");
    scanf("%d", &imoveis[total].numeroCasa);

    printf("Consumo (kWh): ");
    scanf("%f", &imoveis[total].consumoKwh);

    total++;
    printf("Imóvel cadastrado com sucesso!\n");

    return total;
}

float calcularMediaConsumo(Imovel imoveis[], int total) {
    if (total == 0) {
        printf("\nNenhum imóvel cadastrado.\n");
        return 0;
    }

    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma += imoveis[i].consumoKwh;
    }

    float media = soma / total;
    printf("\nMédia de consumo geral da rua: %.2f kWh\n", media);

    return media;
}

void listarAcimaDaMedia(Imovel imoveis[], int total) {
    if (total == 0) {
        printf("\nNenhum imóvel cadastrado.\n");
        return;
    }

    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma += imoveis[i].consumoKwh;
    }
    float media = soma / total;

    int encontrou = 0;
    printf("\n--- Imóveis com consumo acima da média (%.2f kWh) ---\n", media);
    for (int i = 0; i < total; i++) {
        if (imoveis[i].consumoKwh > media) {
            printf("Casa: %d | Consumo: %.2f kWh\n",
                   imoveis[i].numeroCasa, imoveis[i].consumoKwh);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum imóvel consome acima da média.\n");
    }
}

int main() {
    Imovel imoveis[MAX_IMOVEIS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar imóvel\n");
        printf("2. Calcular média de consumo geral da rua\n");
        printf("3. Listar imóveis acima da média\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarImovel(imoveis, total);
                break;
            case 2:
                calcularMediaConsumo(imoveis, total);
                break;
            case 3:
                listarAcimaDaMedia(imoveis, total);
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
