#include "Graph.h"

int main(){
    int nUsuario;
    cout << "Digite o número de vértices do grafo completo desejado:(inteiro maior que zero)" << endl;
    do{
        cin >> nUsuario;
    }while(nUsuario<=0);
    Grafo g(nUsuario);
    g.imprimir();
    cout <<"O número de subgrafos do grafo acima é: " << g.achaSubgrafosRec() << endl;
    return 0;
}