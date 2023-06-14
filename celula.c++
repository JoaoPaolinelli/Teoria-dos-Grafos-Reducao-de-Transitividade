
#include <iostream>
#include <string>
#include "celula.h"

using namespace std;

/*-------------- Construtores -----------------*/
Celula::Celula(){
    vertice = -1;
    this->prox = nullptr;
    this->aresta = nullptr;
}

Celula::Celula(int vertice)
{   
    this->vertice = vertice;
    this->prox = nullptr;
    this->aresta = nullptr;
}


// Ideias futuras
Celula::~Celula()
{
    
}
