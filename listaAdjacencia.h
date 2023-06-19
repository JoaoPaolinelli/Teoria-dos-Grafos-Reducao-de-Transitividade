#ifndef LISTAADJACENCIA_H
#define LISTAADJACENCIA_H
#include <string>
#include "celula.h"



using namespace std;

class ListaAdjacencia{

public:

    Celula *Inicio;
    Celula *Fim;
    Celula *InicioAdjacencia;
    Celula *FimAdjacencia;
    Celula *novoGrafo;

    ListaAdjacencia();
    ~ListaAdjacencia();
    void inserirFim(int vertice);
    int remover(int vertice);
    bool pesquisar(int vertice);
    int tamanho();
    void criaAdjacencia(int vertice, int novoVertice);
    bool pesquisarAdjacencia(int vertice_U, int vertice_V);
    void removerAdjacencia(int vertice_U, int vertice_V);
    void mostrarLista();
    vector<int> DFS(int verticeInicial);
    void DFSUtil(int vertice, vector<bool>& visitado, vector<int>& seqVertices);
    ListaAdjacencia ClonaGrafo(int primeiroVerticeLista);
    void reducaoTransitividade();
    Celula* encontrarCelula(int vertice);
};
#endif // LISTAADJACENCIA_H