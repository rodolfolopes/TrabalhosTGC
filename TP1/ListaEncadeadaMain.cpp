//Uso de Listas Encadeadas
#include "ListaEncadeada.h"
#include <iostream>
using namespace std;

int main(){
    LinkedList ll;
    int nElementos,nElementosTirar,elementoPesquisa;
    //Realizar a inclusao de elementos
    cout << "Digite a quantidade de elementos a adicionar:" << endl;
    cin >> nElementos;
    int* vetorElementos = new int[nElementos];
    for(int v = 0;v<nElementos;v++){
        cout << "Digite o próximo elemento:" << endl;
        cin >> vetorElementos[v];
    }
    cout << "Digite um valor a procurar na Lista criada:" << endl;
    cin >> elementoPesquisa;
    if(ll.existeElemento(elementoPesquisa)){
        cout << "Existe o elemento digitado acima na lista." << endl;
    }else{
        cout << "Não existe o elemento digitado acima na lista." << endl;
    }
    cout << "Digite a quantidade de elementos a tirar:" << endl;
    cin >> nElementosTirar;
    return 0;
}