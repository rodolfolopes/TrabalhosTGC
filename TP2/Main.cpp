#include "Graph.h"

int main(){
    int nUsuario;
    cout << "Digite o número de vértices do grafo completo desejado:(inteiro maior que zero)" << endl;
    do{
        cin >> nUsuario;
    }while(nUsuario<=0);//Validação simples do dado inserido
    Grafo g(nUsuario);
    g.imprimir();
    cout <<"O número de subgrafos do grafo acima é: " << g.achaSubgrafos() << endl;
    return 0;
}