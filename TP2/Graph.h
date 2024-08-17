#include <list>
#include <map>
#include <iostream>
#include <ostream>
using namespace std;

class Grafo{
    int numeroVertices;
    map<int,list<int>> listaAdj;
    public:
    Grafo(int num){
        numeroVertices = num;

        for(int a = 0;a<numeroVertices;a++){
            for(int b = a+1;b<numeroVertices;b++){
                adicionaAresta(a,b);
            }
        }
    }
    void adicionaAresta(int a,int b){
        listaAdj[a].push_back(b);
        listaAdj[b].push_back(a);
    }
    void imprimir()
    {
        cout << "Grafo com número de vértices: " << numeroVertices <<endl;

        for (auto a : listaAdj) {
            
            cout << a.first << " -> ";
        
            for (auto b : a.second) {
                
                cout << b << " ";
            }
            cout << endl;
        }
    }
};
