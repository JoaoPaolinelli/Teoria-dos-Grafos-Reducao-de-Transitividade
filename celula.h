#ifndef CELULA_H
#define CELULA_H
#include <string> 

using namespace std;

class Celula
{
public:
   
    int vertice;
    Celula *prox;
    Celula *aresta;
    //construtores
    Celula();
    Celula(int vertice);
    //Destrutor
    ~Celula();

};
#endif //CELULA_H