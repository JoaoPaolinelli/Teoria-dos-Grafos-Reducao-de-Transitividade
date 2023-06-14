#include <iostream>
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
    // cout << teste.pesquisar(1) << endl;
    // cout << teste.pesquisar(2) << endl; 
    // cout << teste.pesquisar(3) << endl;
    // cout << teste.pesquisar(4) << endl;
    teste.criaAdjacencia(3,4);
    teste.criaAdjacencia(4,2);
    teste.criaAdjacencia(2,1);
    teste.criaAdjacencia(1,3);
    teste.mostrarLista();

    return 0;
}