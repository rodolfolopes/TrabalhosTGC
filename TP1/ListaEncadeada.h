//Implementaçao de listas encadeadas
#include <cstddef>
#include <iostream>
#include <ostream>
using namespace std;

//Nó simples,de inteiros
struct Node{
    int data;
    Node* proximo;
};

//Lista Encadeada simples
class LinkedList{

    Node* cabeca;

    public:
    //Construtor
    LinkedList() {
        cabeca = NULL;
    }
    //Funçao para percorrer a lista,até o último elemento,e retornar uma referencia a ele
    Node* percorreLista(){
        Node* temp = cabeca;
        while(temp->proximo){
            temp = temp->proximo;
        }
        return temp;
    }
    //Funçao para inserir novo nó sempre no começo da lista
    void inserirComeco(int valor){
        Node* no = new Node();
        no->data = valor;
        no->proximo = cabeca;
        cabeca = no;
    }
    //Funcao para inserir novo nó sempre no final da lista
    void inserirFim(int valor){
        Node* no = new Node();
        no->data = valor;
        no->proximo = NULL;

        if(!cabeca){
            cabeca = no;
            return;
        }

        Node* temporario = percorreLista();

        temporario->proximo = no;
    }
    //Funcao para inserir n elementos na lista,adicionando ao final
    void inserirNFim(int n,int elementos[]){
        for(int v = 0;v<n;v++){
            inserirFim(elementos[v]);
        }
    }
    //Funçao para deletar do começo da lista
    void removeComeco(){
        if (!cabeca){
            cout << "A lista está vazia." << endl;
            return;
        }
        Node* temporario = cabeca;
        cabeca = cabeca->proximo;
        cout << "Elemento deletado: " << temporario->data << endl;
        delete temporario;
    }
    //Funçao para deletar do fim da lista
    void removeFim(){
        if (!cabeca){
            cout << "A lista está vazia." << endl;
            return;
        }

        if(!cabeca->proximo){
            delete cabeca;
            cabeca = NULL;
            return;
        }

        Node* temporario = cabeca;
        while(temporario->proximo->proximo){
            temporario = temporario->proximo;
        }

        delete temporario->proximo;

        temporario->proximo = NULL;
    }
    //Funçao para percorrer e mostrar toda a lista
    void mostrar(){
        if(!cabeca){
            cout << "A lista está vazia." << endl;
            return;
        }
        Node* temporario = cabeca;
        while(temporario){
            cout << temporario->data << "->";
            temporario = temporario->proximo;
        }
        cout << "Fim da Lista Encadeada" << endl;
    }
    //Funçao para pesquisar a existencia de um valor especifico dentro de nossa lista
    bool existeElemento(int valor){
        if(!cabeca){
            cout << "A lista está vazia." << endl;
            return false;
        }
        Node* temporario = cabeca;
        while(temporario->proximo){
            if(temporario->data == valor){
                return true;
            }
            temporario = temporario->proximo;
        }
        if(temporario->data == valor){
                return true;
            }
        return false;
    }
};