#include <stdio.h>

#define MAX_ALUNOS 100

typedef struct {
    int codigo;
    float peso;
    float altura;
} Perfil;

int cadastrarAluno(Perfil alunos[], int total) {
    if (total >= MAX_ALUNOS) {
        printf("\nLimite máximo de alunos atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Aluno ---\n");

    printf("Código: ");
    scanf("%d", &alunos[total].codigo);

    printf("Peso (kg): ");
    scanf("%f", &alunos[total].peso);

    printf("Altura (m): ");
    scanf("%f", &alunos[total].altura);

    total++;
    printf("Aluno cadastrado com sucesso!\n");

    return total;
}

void exibirAlunoMaisAlto(Perfil alunos[], int total) {
    if (total == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    int indiceMaisAlto = 0;
    for (int i = 1; i < total; i++) {
        if (alunos[i].altura > alunos[indiceMaisAlto].altura) {
            indiceMaisAlto = i;
        }
    }

    printf("\n--- Aluno mais alto ---\n");
    printf("Código: %d | Peso: %.2f kg | Altura: %.2f m\n",
           alunos[indiceMaisAlto].codigo,
           alunos[indiceMaisAlto].peso,
           alunos[indiceMaisAlto].altura);
}

int main() {
    Perfil alunos[MAX_ALUNOS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Exibir aluno mais alto\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarAluno(alunos, total);
                break;
            case 2:
                exibirAlunoMaisAlto(alunos, total);
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
