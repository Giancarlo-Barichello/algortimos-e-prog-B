#include <stdio.h>

#define MAX_FUNCIONARIOS 100

typedef struct {
    int codigo;
    int idade;
    float salario;
} Funcionario;

int cadastrarFuncionario(Funcionario funcionarios[], int total) {
    if (total >= MAX_FUNCIONARIOS) {
        printf("\nLimite máximo de funcionários atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Funcionário ---\n");

    printf("Código: ");
    scanf("%d", &funcionarios[total].codigo);

    printf("Idade: ");
    scanf("%d", &funcionarios[total].idade);

    printf("Salário: ");
    scanf("%f", &funcionarios[total].salario);

    total++;
    printf("Funcionário cadastrado com sucesso!\n");

    return total;
}

void contarFuncionariosFiltro(Funcionario funcionarios[], int total) {
    if (total == 0) {
        printf("\nNenhum funcionário cadastrado.\n");
        return;
    }

    int contador = 0;
    printf("\n--- Funcionários com mais de 40 anos e salário acima de R$ 5000,00 ---\n");
    for (int i = 0; i < total; i++) {
        if (funcionarios[i].idade > 40 && funcionarios[i].salario > 5000.0) {
            printf("Código: %d | Idade: %d | Salário: R$ %.2f\n",
                   funcionarios[i].codigo,
                   funcionarios[i].idade,
                   funcionarios[i].salario);
            contador++;
        }
    }

    printf("\nTotal de funcionários que atendem aos critérios: %d\n", contador);
}

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar funcionário\n");
        printf("2. Contar funcionários (idade > 40 e salário > R$ 5000,00)\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarFuncionario(funcionarios, total);
                break;
            case 2:
                contarFuncionariosFiltro(funcionarios, total);
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
