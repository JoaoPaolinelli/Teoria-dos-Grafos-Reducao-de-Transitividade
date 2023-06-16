#include <iostream>
#include <vector>
#include "celula.h"
#include "listaAdjacencia.h"

using namespace std;

// Apenas Teste.

int main(){
    
    // Para ser um grafo não direcionado deve-se criar a adjacência
    // duas vezes u-v e de v-u;

    ListaAdjacencia teste = ListaAdjacencia();
    teste.inserirFim(1);
    teste.inserirFim(2);
    teste.inserirFim(3);
    teste.inserirFim(4);
    teste.criaAdjacencia(3,4);
    teste.criaAdjacencia(4,2);
    teste.criaAdjacencia(2,1);
    teste.criaAdjacencia(1,3);
    // vector<int> testeV = teste.DFS(1);
    // for(int i: testeV){
    //     cout << i << endl;
    // }
    teste.mostrarLista();
    

    return 0;
}