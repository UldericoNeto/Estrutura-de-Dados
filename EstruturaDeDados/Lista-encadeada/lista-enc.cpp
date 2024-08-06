#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prox;   

    Node(int valor) {
        data = valor;
        prox = NULL;
    }
};


class ListaEncadeada {
private:
    Node* head;   //ponteiro para o primeiro no da lista

public:
    //criar uma lista vazia
    ListaEncadeada(){
        head = NULL;
    }

    //limpa a memoria
    ~ListaEncadeada() {
        while (head != NULL) {
            Node* temp = head;
            head = head->prox;
            delete temp;
        }
    }

    //verificar se ta vazia
    bool vazia() const {
        return head == NULL;
    }

    //obter o tamanho
    int getTamanho() const {
        int cont = 0;
        Node* atual = head;
        while (atual != NULL) {
            cont++;
            atual = atual->prox;
        }
        return cont;
    }

    //obter o valor do elemento de uma determinada posicao
    int getElemento(int posicao) const {
        Node* atual = head;
        int tam = getTamanho();
        if (posicao <= tam){
            for (int i = 1; i < posicao; ++i) {
            atual = atual->prox;
        }

        return atual->data;
        }else {
            return -1;
        }
    }

    //alterar o valor do elemento de uma determinada posicao
    void altElemento(int posicao, int valor) {
        Node* atual = head;
        for (int i = 1; i < posicao; ++i) {
            atual = atual->prox;
        }
        atual->data = valor;
    }

    //inserir um elemento
    void inserir(int posicao, int valor) {
        Node* pro = new Node(valor);
        if (posicao == 1) {
            pro->prox = head;
            head = pro;
        } else {
            Node* atual = head;
            for (int i = 1; i < posicao - 1; ++i) {
                atual = atual->prox;
            }
            pro->prox = atual->prox;
            atual->prox = pro;
        }
    }

    //remover um elemento 
    int remove(int posicao) {
        int removi = getElemento(posicao);
        Node* temp = head;

        if (posicao == 1) {
            head = head->prox;
        } else {
            Node* atual = head;
            for (int i = 1; i < posicao - 1; i++) {
                atual = atual->prox;
            }
            temp = atual->prox;
            atual->prox = temp->prox;
            delete atual;
        }
        delete temp;
        return removi;
    }

};

int main(){
    ListaEncadeada lista;

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


    return 0;
}