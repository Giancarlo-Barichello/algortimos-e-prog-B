```cpp
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

typedef struct {
    string telefone;
    string informacoes;
} Registro;


void mostrar(vector<Registro> registros) {
    if (registros.empty()) {
        cout << "Nenhum telefone foi encontrado.\n";
        return;
    }

    cout << "\nTelefones registrados:\n";

    for (int i = 0; i < registros.size(); i++) {
        cout << i + 1 << " - Telefone: " << registros[i].telefone << "\n";
    }

    cout << "  Total de registros: " << registros.size() << "\n";
}


void lerBase(string arquivoDados, vector<Registro>& registros) {
    ifstream arquivo(arquivoDados);

    if (!arquivo) {
        return;
    }

    string telefone, informacoes;
    registros.clear();

    // Realiza a leitura dos registros armazenados, utilizando ';' para separar o telefone das informacoes correspondentes.
    while (getline(arquivo, telefone, ';') && getline(arquivo, informacoes)) {
        if (!telefone.empty() && !informacoes.empty()) {
            Registro novo;
            novo.telefone = telefone;
            novo.informacoes = informacoes;
            registros.push_back(novo);
        }
    }

    arquivo.close();
}


void localizar(const vector<Registro>& registros) {
    string busca;

    cout << "Informe o telefone que deseja localizar: ";
    cin >> busca;

    bool localizado = false;

    for (int i = 0; i < registros.size(); i++) {
        if (busca == registros[i].telefone) {
            cout << "Registro localizado! Telefone: "
                 << registros[i].telefone
                 << " | Informacoes: " << registros[i].informacoes << "\n";

            localizado = true;
            break;
        }
    }

    if (!localizado) {
        cout << "Telefone nao localizado.\n";
    }
}


int main() {
    vector<Registro> registros;
    int escolha;

    string arquivoPrincipal = "telephony_sessions.txt";

    // Importa os dados do arquivo de telefonia e organiza os telefones e suas respectivas informacoes no vetor principal.

    do {
        cout << "MENU PRINCIPAL\n";
        cout << "1 - Exibir telefones\n";
        cout << "2 - Consultar telefone e informacoes da sessao\n";
        cout << "3 - Encerrar programa\n";
        cout << "Escolha: ";

        cin >> escolha;
        cin.ignore();

        lerBase(arquivoPrincipal, registros);

        switch (escolha) {
            case 1:
                // Apresenta todos os telefones existentes no cadastro e informa a quantidade total de registros encontrados.
                mostrar(registros);
                break;

            case 2:
                // Permite informar um telefone para consulta e apresenta os dados da sessao caso exista um registro correspondente.
                localizar(registros);
                break;

            case 3:
                cout << "Sistema encerrado. Obrigado!\n";
                break;

            default:
                cout << "Opcao nao reconhecida!\n";
                break;
        }

    } while (escolha != 3);

    return 1;
}
```
