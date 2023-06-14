#include <iostream>
#include "celula.h"
#include "listaAdjacencia.h"

using namespace std;

// Apenas Teste.

int main(){
    
    ListaAdjacencia teste = ListaAdjacencia();
    teste.inserirFim(1);
    teste.inserirFim(2);
    teste.inserirFim(3);
    teste.inserirFim(4);
    // teste.criaAdjacencia(3,4);
    // teste.criaAdjacencia(4,2);
    // teste.criaAdjacencia(2,1);
    // teste.criaAdjacencia(1,3);
    
    teste.mostrarLista();

    return 0;
}