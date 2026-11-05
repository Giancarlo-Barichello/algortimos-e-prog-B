```cpp
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    string destino;
    float avaliacao;
} imagem;

bool cadastrar(vector<imagem>& imagens) {
    imagem imagemTMP;

    cout << "Informe o destino: ";
    getline(cin, imagemTMP.destino);

    if (imagemTMP.destino.empty()) {
        cout << "O destino nao pode ficar vazio.\n";
        return false;
    }

    for (int i = 0; i < imagens.size(); i++) {
        if (imagemTMP.destino == imagens[i].destino) {
            cout << "Imagem ja registrada.\n";
            return false;
        }
    }

    cout << "Informe a avaliacao: ";
    while (!(cin >> imagemTMP.avaliacao)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido. Digite uma avaliacao numerica: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    imagens.push_back(imagemTMP);
    cout << "Imagem cadastrada com sucesso.\n";
    return true;
}

void exibir(vector<imagem> imagens) {
    if (imagens.empty()) {
        cout << "Nenhuma imagem registrada.\n";
        return;
    }

    cout << "\nImagens registradas:\n";

    for (int i = 0; i < imagens.size(); i++) {
        cout << i + 1 << " - Destino: " << imagens[i].destino
             << "  Avaliacao: " << imagens[i].avaliacao << "\n";
    }
}

void consultar(const vector<imagem>& imagens) {
    string pesquisa;

    cout << "Informe o destino que deseja consultar: ";
    getline(cin, pesquisa);

    bool localizado = false;

    for (size_t i = 0; i < imagens.size(); i++) {
        if (pesquisa == imagens[i].destino) {
            cout << "Imagem localizada! Destino: "
                 << imagens[i].destino
                 << " | Avaliacao: " << imagens[i].avaliacao << "\n";

            localizado = true;
            break;
        }
    }

    if (!localizado) {
        cout << "Imagem nao localizada.\n";
    }
}

bool excluir(vector<imagem>& imagens) {
    string pesquisa;

    cout << "Informe o destino da imagem que deseja excluir: ";
    getline(cin, pesquisa);

    for (auto it = imagens.begin(); it != imagens.end(); ++it) {
        if (it->destino == pesquisa) {
            imagens.erase(it);
            cout << "Imagem excluida com sucesso.\n";
            return true;
        }
    }

    cout << "Imagem nao encontrada.\n";
    return false;
}

void lerArquivo(string arquivoBase, vector<imagem>& imagens) {
    ifstream arquivo(arquivoBase);

    if (!arquivo) {
        return;
    }

    string destino;
    string avaliacaoTexto;

    while (getline(arquivo, destino, ';') &&
           getline(arquivo, avaliacaoTexto)) {

        if (!destino.empty() && !avaliacaoTexto.empty()) {
            imagem img;
            img.destino = destino;
            img.avaliacao = stof(avaliacaoTexto);
            imagens.push_back(img);
        }
    }

    arquivo.close();
}

void salvarArquivo(const vector<imagem>& imagens, string arquivoBase) {
    ofstream arquivo(arquivoBase);

    if (!arquivo) {
        cout << "Falha ao abrir o arquivo para salvar os dados.\n";
        return;
    }

    for (size_t i = 0; i < imagens.size(); i++) {
        arquivo << imagens[i].destino << ";"
                << imagens[i].avaliacao << "\n";
    }

    arquivo.close();
}

void classificar(vector<imagem>& imagens) {
    imagem auxiliar;
    bool alteracao;

    if (imagens.empty()) return;

    do {
        alteracao = false;

        for (size_t i = 0; i < imagens.size() - 1; i++) {
            if (imagens[i].destino > imagens[i + 1].destino) {
                alteracao = true;

                auxiliar = imagens[i];
                imagens[i] = imagens[i + 1];
                imagens[i + 1] = auxiliar;
            }
        }

    } while (alteracao);
}

int main() {
    vector<imagem> imagens;
    int escolha;

    string arquivoBase = "fotos.txt";

    lerArquivo(arquivoBase, imagens);

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1 - Cadastrar destino\n";
        cout << "2 - Exibir imagens\n";
        cout << "3 - Consultar destinos\n";
        cout << "4 - Excluir imagem\n";
        cout << "5 - Finalizar\n";
        cout << "Selecione uma opcao: ";

        if (!(cin >> escolha)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Informe um numero entre 1 e 5.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (escolha) {
            case 1:
                if (cadastrar(imagens)) {
                    classificar(imagens);
                    salvarArquivo(imagens, arquivoBase);
                }
                break;

            case 2:
                exibir(imagens);
                break;

            case 3:
                consultar(imagens);
                break;

            case 4:
                if (excluir(imagens)) {
                    salvarArquivo(imagens, arquivoBase);
                }
                break;

            case 5:
                cout << "Sistema finalizado.\n";
                break;

            default:
                cout << "Escolha invalida.\n";
        }

    } while (escolha != 5);

    return 0;
}
```
