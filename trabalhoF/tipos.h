#include <iostream>
#include <string>


using namespace std;

typedef struct{
   string local;
    int nota;
    
} fotos;


#include <sstream>
#include <fstream>

int contarNumero(int numero, int vetor[], int quantidade) {
    int contador = 0;
    
    for (int i = 0; i < quantidade; i++) {
        if (vetor[i] == numero) {
            contador++;
        }
    }
    
    return contador;
}
// Retorna true se o número for par, e false se for ímpar
bool ehPar(int numero) {
    return (numero % 2 == 0);
}

bool inserirLista(string nome, string listaNomes[], int *quantidadeNomes, int tamanho) {
    if (*quantidadeNomes == tamanho) {
        return false; //lista lotada
    }

    bool encontrou = false;
    int i;
    for (i = 0; i < *quantidadeNomes; i++) {
        if (nome == listaNomes[i]) {
            encontrou = true;
            break;
        }
    }

    if (encontrou) { //se encontrou o nome, retorna falso pq nao conseguiu inserir
        return false;
    }

    *quantidadeNomes = *quantidadeNomes + 1;
    listaNomes[*quantidadeNomes] = nome;

    //ordenar a lista de nomes
    //...

    return true; //consegui inserir na lista
}

void exibirListaNomes(string listaNomes[], int quantidadeNomes) {
    for (int i = 0; i < quantidadeNomes; i++) {
        cout << listaNomes[i] << endl;
    }
}

int conectarBase(string listaNomes[], string nomeBaseDados, int tamanho) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeBaseDados); 

    string linha;
    int quantidadeNomes = 0;
    while (!procuradorArquivo.eof() && quantidadeNomes < tamanho) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
        listaNomes[quantidadeNomes] = linha; //a linha tem um nome completo
        quantidadeNomes++;
	}
  
    procuradorArquivo.close();

    return quantidadeNomes;
}


int contarVogais(string frase) {
    int totalVogais = 0;

    for (int i = 0; i < frase.size(); i++) {
        //cout << frase[i] << endl;
        if (frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U' || 
            frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u'){
                totalVogais+=1; //totalVogais++;
        }
    }

    return totalVogais;
}

string trocarCaracter(string frase, char letra) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letra)) {
            frase[i] = '@';
        }
    }
    return frase;
}

string trocarCaracterOrigemDestino(string frase, char letraOrigem, char letraDestino) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letraOrigem)) {
            frase[i] = letraDestino;
        }
    }
    return frase;
}

int contarPalavras(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;
    
    // Enquanto houver palavras na frase
    while (stream >> palavra) {
        cout << palavra << endl;
        contagem++;
    }
    
    return contagem;
}

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool existeArquivo(string nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 
    
    if (procuradorArquivo) { //caso arquivo exista
        procuradorArquivo.close();
        return true;
    } 
    return false; //caso arquivo nao exista
}

string copiarArquivo2String(string nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    string resposta = "";
    string linha;
    while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		resposta = resposta + linha + "\n";
	}
  
    procuradorArquivo.close();

    return resposta;
}





#include <cstdlib>
#include <time.h>
#include <string.h>

void popular(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; //forcando a saida do metodo
    }
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibir(string frase, int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; //forcando a saida do metodo
    }
    cout << frase << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << endl;
    }
}

void menorElemento(int vetor[], int quantidade, int tamanho) {
    int menor = vetor[0];

    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; //forcando a saida do metodo
    }

    for (int i = 1; i < quantidade; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    cout << "Menor elemento.... " << menor << endl;

}

void escreverSeValida(int dia, int mes, int ano) {
    //meses com 31: 1, 3, 5, 7, 8, 10, 12
    //meses com 30: 2, 4, 6, 9, 11

    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}

void escreverSeValida2(string data) {
    //meses com 31: 1, 3, 5, 7, 8, 10, 12
    //meses com 30: 2, 4, 6, 9, 11

    //data = 01/09/2025
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));
    
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}

bool verificarDataValida(string data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        return false;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        return false;
    } else if (dia > 29 && mes == 2) {
        return false;
    } else {
        return true;
    }
}

int contaLetras(string nome, string letra) {
    int quantidade = 0;
    for (int i = 0; i < nome.size(); i++) {
        if (nome[i] == letra[0]) {
            quantidade++;
        }
    }
    return quantidade;
}

#include <fstream>


void exibirQuantasPalavrasArquivo(string palavra, string nomeArquivo) {
    ifstream arquivo;
    int contador = 0;
    string palavraAtual;
    arquivo.open(nomeArquivo);

    while (arquivo >> palavraAtual) {
        if (palavraAtual == palavra) {
            contador++;            
        }
    }
    cout << "Quantidade de " << palavra << " localizadas no arquivo: " << contador << endl;

    arquivo.close();
}

int contarQuantasPalavrasArquivo(string palavra, string nomeArquivo) {
    ifstream arquivo;
    int contador = 0;
    string palavraAtual;
    arquivo.open(nomeArquivo);

    while (arquivo >> palavraAtual) {
        if (palavraAtual == palavra) {
            contador++;            
        }
    }
    
    arquivo.close();
    return contador;
}
