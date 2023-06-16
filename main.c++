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
    teste.inserirFim(5);
    teste.criaAdjacencia(3,4);
    teste.criaAdjacencia(4,2);
    teste.criaAdjacencia(2,1);
    teste.criaAdjacencia(1,3);
    teste.criaAdjacencia(3,2);
    teste.criaAdjacencia(3,5);


    /*Quem for modificar o código da uma olhada no criaAdjacencia bugou legal*/
    /*Mil perdões por isso e tmj*/ //caio


    cout << "Fecho transitivo de cada vertice" << endl;
    for(int i = 1; i <= 4; i++){    
        vector<int> testeV = teste.DFS(i);
        for (const auto& numero : testeV) {
            cout << numero << " " ;
        }
        cout << endl;
    }

    cout << "Grafo" << endl;
    teste.mostrarLista();
    

    return 0;
}