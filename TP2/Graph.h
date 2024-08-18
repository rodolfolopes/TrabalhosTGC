#include <list>
#include <map>
#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;

class Grafo{
    int numeroVertices;
    map<int,list<int>> listaAdj;//Representação em forma de lista de adjacência
    public:
    Grafo(int num){
        numeroVertices = num;
        if(numeroVertices == 1){
            listaAdj[0].push_back(0);
            listaAdj[0].pop_back();
        }else{
        for(int a = 0;a<numeroVertices;a++){
            for(int b = a+1;b<numeroVertices;b++){
                adicionaAresta(a,b);
            }
        }
         }
    }
    //Adiciona arestas no grafo não direcionado(Aqui representado como os dois sentidos,de a pra b e de b pra a)
    void adicionaAresta(int a,int b){
        listaAdj[a].push_back(b);
        listaAdj[b].push_back(a);
    }
    //Função para mostrar o grafo contido na instância desta classe
    void imprimir()
    {
        cout << "Grafo com número de vértices: " << numeroVertices <<endl;
        
        for (auto a : listaAdj) {
            //Vértice considerado
            cout << a.first << " -> ";
        
            for (auto b : a.second) {
                //Para onde as arestas vão do vértice considerado acima
                cout << b << " ";
            }
            cout << endl;
        }
        
    }
    //Função para achar o número total de subgrafos do grafo desta instância da classe
    int achaSubgrafos(){
        int resp = numeroVertices;
       for(int a = 2;a<=numeroVertices;a++){
        int binomioTop = 1;
        int temp = a;
        while(temp>1){
            binomioTop*= temp;
            temp--;
        }
        int binomioBottom = 1;
        temp = a - 2;
        while(temp>1){
            binomioBottom*= temp;
            temp--;
        }
        int pow2 = (int) pow(2,(binomioTop/binomioBottom)/2);
        int binomioBottom2 = binomioTop;
        binomioTop = 1;
        temp = numeroVertices;
        while(temp>1){
            binomioTop*= temp;
            temp--;
        }
        binomioBottom = 1;
        temp = numeroVertices - a;
        while(temp>1){
            binomioBottom*=temp;
            temp--;
        }
        int multiplier = (binomioTop/binomioBottom)/binomioBottom2;
        resp+= pow2*multiplier;
       }
       return resp;
    }
    
};
