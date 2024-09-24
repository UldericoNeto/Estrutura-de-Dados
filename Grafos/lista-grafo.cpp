#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

class Grafo {
private:
    int tamanho;
    vector<vector<int>> matrizAdj;
    vector<vector<int>> listaAdj;

public:
    Grafo(const string& nomeArquivo) {
        lerArquivo(nomeArquivo);
    }

    int getTamanho() const {
        return tamanho;
    }

    void lerArquivo(const string& nomeArquivo) {
        ifstream inputFile(nomeArquivo);

        if (!inputFile) {
            cerr << "Erro ao abrir o arquivo!" << endl;
            exit(1);
        }

        inputFile >> tamanho;

        matrizAdj.resize(tamanho, vector<int>(tamanho));
        listaAdj.resize(tamanho);

        for (int i = 0; i < tamanho; ++i) {
            for (int j = 0; j < tamanho; ++j) {
                int valor;
                inputFile >> valor;
                matrizAdj[i][j] = valor;
                if(valor != 0){
                listaAdj[i].push_back(j);
                }
            }
        }

        inputFile.close();
    }

    void exibirMatrizAdjacencia() {
        cout << "Matriz de Adjacencia:" << endl;
        for (int i = 0; i < tamanho; ++i) {
            for (int j = 0; j < tamanho; ++j) {
                cout << matrizAdj[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void exibirListaAdjacencia() {
        cout << "Lista de Adjacencia:" << endl;
        for (int i = 0; i < tamanho; ++i) {
            cout << "Vertice " << i << ":";
            for (int j : listaAdj[i]) {
                cout << " -> " << j;
            }
            cout << endl;
        }
        cout << endl;
    }

    void exibirCaminho(vector<int>& anterior, int fim){
        vector<int> caminho;
        for (int i = fim; i != -1; i = anterior[i]) {
            caminho.push_back(i);
        }
        reverse(caminho.begin(), caminho.end());
        
        for (int i = 0; i < caminho.size(); ++i) {
            if (i != 0){ 
                cout << " -> ";
            }                
            cout << caminho[i];
        }
        cout << "\n";

    }

    void metodoBFS(int inicio, int fim){
        vector<bool> visitado(tamanho, false);
        vector<int> anterior(tamanho, -1);
        queue<int> fila;

        visitado[inicio] = true;
        fila.push(inicio);

        while (!fila.empty()){
            int atual = fila.front();
            fila.pop();

            if(atual == fim){
                cout << "Caminho: " << endl;
                exibirCaminho(anterior, fim);
                return;
            }

            for(int adj : listaAdj[atual]){
                if(!visitado[adj]){
                    visitado[adj] = true;
                    anterior[adj] = atual;
                    fila.push(adj);
                }
            }
        
        }
        cout << "Nao a caminho de: " << inicio << " ate " << fim <<". :(" << endl;
    }

    void metodoDFS(int inicio){
        vector<bool> visitado(tamanho, false);
        stack<int> pilha;

        pilha.push(inicio);

        while (!pilha.empty()) {
            int atual = pilha.top();
            pilha.pop();

            if (!visitado[atual]) {
                cout << atual << " ";
                visitado[atual] = true;
            }

            for (int adj : listaAdj[atual]) {
                if (!visitado[adj]) {
                    pilha.push(adj);
                }
            }
        }
        cout << "\n";
    }


};

int main() {
    string arq;
    int num1 = 0, num2 =0;

    cout << "Escolha entra as seguintes opcoes de matrizes:\n[1] - 4x4\t [2] - 10x10\n[3] - 50x50\t [4] - 177x177\n";
    cin >> num1;

    switch (num1){
    case 1:
        arq = "testes/pcv4.txt";
        break;
    case 2:
        arq = "testes/pcv10.txt";
        break;
    case 3:
        arq = "testes/pcv50.txt";
        break;
    case 4:
        arq = "testes/pcv177.txt";
        break;
    default:
        cout << "Numero incorreto. Finalizando o programa\n";
        return 0;
    }

    Grafo matriz(arq);
    int j = matriz.getTamanho();

    cout << "Matriz do tipo: " << j << "x" << j << "\n\n";

    matriz.exibirMatrizAdjacencia();

    matriz.exibirListaAdjacencia();

    cout << "Escolhas 2 numeros entre 0 e " << j-1 << " para a execucao do BFS.\nNumero 1: ";
    cin >> num1;
    cout << "Numero 2: ";
    cin >> num2;

    matriz.metodoBFS(num1, num2);

    cout << "Escolha 1 numero ate " << j-1 << " para a execucao do DFS.\nNumero: ";
    cin >> num1;

    matriz.metodoDFS(num1);

    return 0;
}
