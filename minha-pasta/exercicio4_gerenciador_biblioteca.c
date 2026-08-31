#include <stdio.h>

#define MAX_LIVROS 100

typedef struct {
    int codigo;
    int anoPublicacao;
    int quantidadePaginas;
} Livro;

int cadastrarLivro(Livro livros[], int total) {
    if (total >= MAX_LIVROS) {
        printf("\nLimite máximo de livros atingido!\n");
        return total;
    }

    printf("\n--- Cadastro de Livro ---\n");

    printf("Código: ");
    scanf("%d", &livros[total].codigo);

    printf("Ano de publicação: ");
    scanf("%d", &livros[total].anoPublicacao);

    printf("Quantidade de páginas: ");
    scanf("%d", &livros[total].quantidadePaginas);

    total++;
    printf("Livro cadastrado com sucesso!\n");

    return total;
}

void filtrarLivrosApos2020(Livro livros[], int total) {
    if (total == 0) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    int encontrou = 0;
    printf("\n--- Livros publicados após 2020 ---\n");
    for (int i = 0; i < total; i++) {
        if (livros[i].anoPublicacao > 2020) {
            printf("Código: %d | Ano: %d | Páginas: %d\n",
                   livros[i].codigo,
                   livros[i].anoPublicacao,
                   livros[i].quantidadePaginas);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum livro publicado após 2020 encontrado.\n");
    }
}

int main() {
    Livro livros[MAX_LIVROS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar livro\n");
        printf("2. Filtrar livros publicados após 2020\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                total = cadastrarLivro(livros, total);
                break;
            case 2:
                filtrarLivrosApos2020(livros, total);
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
