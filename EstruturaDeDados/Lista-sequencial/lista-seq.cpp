#include <iostream>

using namespace std;

class ListaSequencial {
private:
    int *arr;
    int max_tam;
    int tam;

public:
    ListaSequencial() {
        max_tam = 10;
        arr = new int[max_tam];
        tam = 0;
    }

    ~ListaSequencial() {
        delete[] arr;
    }

    bool vazia() {
        return tam == 0;
    }

    bool cheia() {
        return tam == max_tam;
    }

    int getTamanho() {
        return tam;
    }

    //retornar o elemento
    int getElemento(int pos) {
        if (pos >= 1 && pos <= tam) {
            return arr[pos - 1];
        } else {
            return -1;
        }
    }

    void altElemento(int pos, int valor) {
        if (pos >= 1 && pos <= tam) {
            arr[pos - 1] = valor;
        } else {
            cout << "****Posicao invalida!****\nElemento " << valor << " nao inserido na posicao " << pos << endl;
        }
    }

    void inserir(int pos, int valor) {
        if (pos >= 1 && pos <= tam + 1 && !cheia()) {
            for (int i = tam; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = valor;
            tam++;
        } else {
            cout << "****Posicao invalida!****\nElemento " << valor << " nao inserido na posicao " << pos << endl;
        }
    }

    int remove(int pos) {
        int remov = getElemento(pos);
        if (pos >= 1 && pos <= tam) {
            for (int i = pos - 1; i < tam - 1; i++) {
                arr[i] = arr[i + 1];
            }
            tam--;
        } else {
            cout << "*******Posicao invalida para remocao*******\n";
        }
        //retorna o valor removido
        return remov;
    }
};


int main(){
    ListaSequencial lista;

    //mostrar que a lista esta vazia
    if( lista.vazia() ){
        cout << "Lista vazia\nTamanho: " << lista.getTamanho() << endl;
    }


    //inserir na lista
    cout << "Inserir elementos na lista\n";
    lista.inserir(1, 13);
    lista.inserir(2, 31);
    lista.inserir(3, 22);
    lista.inserir(4, 33);
    lista.inserir(5, 331);
    lista.inserir(17, 22);


    //exibir o tamanho da lista no inicio
    cout << "Tamanho: " <<lista.getTamanho() << endl;

    //exibir lista
    cout << "Elementos da lista: ";
    for (int i = 1; i <= (lista.getTamanho()); ++i) {
        cout << lista.getElemento(i) << " ";
    }
    cout << endl;


    //procurar elemento
    int proc = lista.getElemento(10);

    if (proc != -1)
    {
        cout << "Elemento da posicao 10: " << proc << endl;
    }else
    {
        cout << "Posicao nao encontrada\n";
    }
    

    //alterar elemento da lista
    cout << "Elemento: " <<lista.getElemento(3);
    lista.altElemento(3, 131);
    cout << " alterado para: "<<lista.getElemento(3) << endl;


    //remover elemento
    int elementoRemovido = lista.remove(1);
    if (elementoRemovido != -1)
    {
        cout << "Elemento removido: " << elementoRemovido << endl;
        cout << "Tamanho atual da lista: " << lista.getTamanho() << endl;
    }
    

    //exibir lista
    cout << "Elementos da lista: ";
    for (int i = 1; i <= (lista.getTamanho()); ++i) {
        cout << lista.getElemento(i) << " ";
    }
    cout << endl;


    //testa se a lista esta cheia
    if (lista.cheia())
    {
        cout << "Lista cheia\n";
    }else{
        cout << "Lista nao esta cheia\n";
    }


    return 0;
}