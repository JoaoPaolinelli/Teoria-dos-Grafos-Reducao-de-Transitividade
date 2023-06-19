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
    teste.inserirFim(6);
    teste.inserirFim(7);
    teste.inserirFim(8);
    teste.criaAdjacencia(1,2);
    teste.criaAdjacencia(1,3);
    teste.criaAdjacencia(1,4);
    teste.criaAdjacencia(2,4);
    teste.criaAdjacencia(3,6);
    teste.criaAdjacencia(4,3);
    teste.criaAdjacencia(4,6);
    teste.criaAdjacencia(5,2);
    teste.criaAdjacencia(5,7);
    teste.criaAdjacencia(5,8);
    teste.criaAdjacencia(6,5);
    teste.criaAdjacencia(6,8);
    teste.criaAdjacencia(7,8);
    teste.criaAdjacencia(7,4);
    teste.reducaoTransitividade();    

    return 0;
}