#include <list>
#include <map>
#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;

class Grafo{
    int numeroVertices;
    map<int,list<int>> listaAdj;
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
    int achaSubgrafosRec(){
       return achaSubgrafos(numeroVertices); 
    }
    int achaSubgrafos(int num){
        if(num > 1 ){
            int expoent;
            if(num == 2){
                expoent = 1;
            }else{
                int temp = 1;
                int contador = num;
                while(contador>1){
                    temp *= contador;
                    contador--;
                }
                temp/= 2;
                int temp2 = 1;
                contador = num -2;
                while(contador > 1){
                    temp2 *= contador;
                    contador--;
                }
                expoent = temp/temp2;
            }
            return num * achaSubgrafos(num - 1) + (int) pow(2,expoent);
            
        }else{
            return 1;
        }
        
    }
};
