#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 100 //definir o tamanho maximo

class Fila {
private:
    int frente, fim, tamanho;
    int *arr;

public:
    Fila() {
        frente = 0;
        fim = -1;
        tamanho = 0;
        arr = new int[MAX_SIZE];
    }

    bool vazia() {
        return tamanho == 0;
    }

    bool cheia() {
        return tamanho == MAX_SIZE;
    }

    int getTamanho(){
        return tamanho;
    }

    int getInicio() {
        if (vazia()) {
            return -1;
        }
        return arr[frente];
    }

    int inserir(int valor) {
        if (cheia()) {
            return -1;
        }

        fim = (fim + 1) % MAX_SIZE;
        arr[fim] = valor;
        tamanho++;
        return valor;

    }

    int remover() {
        if (vazia()) {
            return -1;
        }

        int saida = getInicio();

        frente = (frente + 1) % MAX_SIZE;
        tamanho--;

        return saida;
    }

};

int main() {
    Fila fila;
    int aux, i;


    //mostra que a lista esta vazia
    if (fila.vazia()){
        cout << "Fila vazia\nTamanho: " << fila.getTamanho() << endl;
    }

    //testes
    cout << "Inserir elemento na flia\n";
    for(i=0; i <= MAX_SIZE + 1; i++){
        aux = fila.inserir(i+1);
        //cout << "Inserido valor: " << i << " na fila" << endl;
        if(aux == -1){
            cout << "Fila cheia" << endl;
        }
    }

    cout << "Tamanho: " << fila.getTamanho() << endl;

    //consultar elemento no inicio
    aux = fila.getInicio();
    if(aux == -1){
        cout << "Fila vazia" << endl;
    }else{
        cout << "Elemento no inicio da fila: " << aux << endl;    
    }


    //remover metade da fila
    for(i=0; i <= MAX_SIZE/2; i++ ){  
        int aux = fila.remover();
        if(aux != -1){
            //cout << "Elemento removido: " << aux << endl;                                               
        }else{
            cout << "Fila vazia, nao a o que remover" << endl;
            break;
        }
    }


    //consultar elemento no inicio 
    aux = fila.getInicio();
    if(aux == -1){
        cout << "Fila vazia" << endl;
    }else{
        cout << "Elemento no inicio da fila apos a remocao da mentade: " << aux << endl;    
    }

    //remover da fila o restante da fila
    for(i; i <= MAX_SIZE + 1; i++ ){
        int aux = fila.remover();
        if(aux != -1){
            //cout << "Elemento removido: " << aux << endl;                                               
        }else{
            cout << "Fila vazia, nao a o que remover" << endl;
            break;
        }
    }

    //mostra que a lista esta vazia
    if (fila.vazia()){
        cout << "Fila vazia\nTamanho: " << fila.getTamanho() << endl;
    }

    return 0;
}
