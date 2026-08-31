#include <stdio.h>

#define MAX_ALUNOS 100

typedef struct {
    int matricula;
    float nota1;
    float nota2;
} Aluno;

int cadastrarAluno(Aluno alunos[], int total) {
    if (total >= MAX_ALUNOS) {
        printf("\nLimite máximo de alunos atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Aluno ---\n");

    printf("Matrícula: ");
    scanf("%d", &alunos[total].matricula);

    printf("Nota 1: ");
    scanf("%f", &alunos[total].nota1);

    printf("Nota 2: ");
    scanf("%f", &alunos[total].nota2);

    total++;
    printf("Aluno cadastrado com sucesso!\n");

    return total;
}

void listarAlunos(Aluno alunos[], int total) {
    if (total == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Alunos ---\n");
    for (int i = 0; i < total; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2) / 2;
        printf("Matrícula: %d | Média: %.2f\n", alunos[i].matricula, media);
    }
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Listar alunos e médias\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarAluno(alunos, total);
                break;
            case 2:
                listarAlunos(alunos, total);
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
