#include <iostream>
#include "celula.h"
#include "listaAdjacencia.h"

using namespace std;

// Apenas Teste.

int main(){
    
    ListaAdjacencia teste = ListaAdjacencia();
    teste.inserirFim(3);
    teste.inserirFim(2);
    teste.inserirFim(1);
    teste.inserirFim(5);
    cout << "O resultado da pesquisa: " << teste.pesquisar(1) << endl;
    cout << "O resultado da pesquisa: " << teste.remover(1) << endl;
    cout << "O resultado da pesquisa: " << teste.pesquisar(1) << endl;
    return 0;
}