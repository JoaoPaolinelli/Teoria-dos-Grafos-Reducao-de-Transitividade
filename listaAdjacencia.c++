#include <iostream>
#include <string>
#include <vector>
#include "celula.h"
#include "listaAdjacencia.h"

using namespace std;

// A ideia dessa função é criar uma celula cabeça para a nossa Lista.

ListaAdjacencia::ListaAdjacencia(){
    this->Inicio = new Celula();
    this->Fim = this->Inicio;
    this->InicioAdjacencia = this->FimAdjacencia = nullptr;
}

// Só pra falar que existe mesmo

ListaAdjacencia::~ListaAdjacencia(){

}

// Como vamos trabalhar com grafos não vejo necessidade de inserir elementos em uma ordem, podem ser várias ordens, logo acho o inserir no Fim
// da lista muito mais interessante e simples do que os outros.
// Recebe o vértice deseja para a alocação e coloca no final da lista e inicializa os ponteiros.
// Podemos ver que até o momento os ponteiros de Adjacência ainda não foram inicializados, pelo fato de ainda não existir uma adjacência de fato

void ListaAdjacencia::inserirFim(int vertice){
    this->Fim->prox = new Celula(vertice);
    this->Fim = this->Fim->prox;
}

// Caso seja necessário saber o tamanho do grafo

int ListaAdjacencia::tamanho(){
    int tamanho = 0;
    for (Celula *i = Inicio->prox; i != nullptr; tamanho++,  i = i->prox);
    return tamanho;
}

// pesquisa o vértice na lista, não pesquisa as adjascencias.

bool ListaAdjacencia::pesquisar(int verticePesquisado){
    bool respPesquisa = false;
    for(Celula *i = Inicio->prox; i != nullptr; i = i->prox){
        if(i->vertice == verticePesquisado){
            respPesquisa = true;
            i = Fim;
        }
    }    
    return respPesquisa;
}

// A lógica dessa função pode ser um pouco estranha, mas a ideia é que com i eu tenha a próxima célula
// e com j eu tenha a anterior a celula que contém o vértice que queremos remover.

int ListaAdjacencia::remover(int verticeRemover){
    int verticeRemovido = -1;
    
    Celula *i = Inicio->prox;
    Celula *j = Inicio->prox ;
    while(i->prox != nullptr)
    {
        i = i->prox;
        if(j->prox->vertice == verticeRemover){                              
            Celula *tmp = i;
            i = Fim;
            j->prox = tmp->prox;
            verticeRemovido = tmp->vertice;
            tmp->prox = nullptr;
            delete tmp;
        }else{
            j = j->prox;
        }
    }
    return verticeRemovido;   
}

// Primeiro pesquiso o primeiro vértice do relacionamento (u-v), depois fazemos uma verificação rápida se tem algum vértice, 
// adjacente a ele, que tenha vindo antes, caso tenha, vamos para o fim e inserimos nosso vértice e caso não tenha, insere ali mesmo

void ListaAdjacencia::criaAdjacencia(int vertice_U, int vertice_v){
    Celula *j;
    for (Celula *i = Inicio->prox; i != nullptr; i = i->prox){
        
        if (i->vertice == vertice_U){
            if (i->aresta == nullptr){
                i->aresta = new Celula(vertice_v);
                this->InicioAdjacencia = this->FimAdjacencia = i->aresta;
            }else{
                j = i->aresta;
                while (j != nullptr){
                    if (j->aresta == nullptr){
                        j->aresta = new Celula(vertice_v);
                        this->FimAdjacencia = j->aresta;
                        // cout <<"true" << endl; 
                    }
                    j = FimAdjacencia->aresta;
                }
                i = Fim;
            }
        }
    }
}

// mesma ideia da pesquisa anterior, mas temos 1 for a mais, pois ao mesmo tempo que pesquisamos os vértices
// temos que pesquisar as adjacências 

bool ListaAdjacencia::pesquisarAdjacencia(int vertice_U, int vertice_V){
    bool resultadoPesquisa = false;

    for (Celula *i = Inicio->prox; i != nullptr; i->prox){
        if (i->vertice == vertice_U){
            if (i->aresta == nullptr){
                i = Fim;
            }else{
                for (Celula *j = InicioAdjacencia; j != nullptr; j=j->aresta){
                    if (j->vertice == vertice_V){
                        resultadoPesquisa = true;
                    }
                }
            }
        }
    }

    return resultadoPesquisa;
}

// A lógica é a mesma do remover anterior, mas com a adaptação necessária para percorrer a adjacência e remover.

int ListaAdjacencia::removerAdjacencia(int vertice_U, int vertice_V){
    int verticeRemovido = -1;

    Celula *k = Inicio->prox;
    Celula *i = InicioAdjacencia;
    Celula *j = InicioAdjacencia;

    while (k->prox != nullptr){
        if (i->vertice == vertice_U){
            if (k->aresta == nullptr){
                k = Fim;
            }else{
                while (i->aresta != nullptr){
                    i = i-> aresta;
                    if (j->aresta->vertice == vertice_V){
                        Celula *tmp = i;
                        i = FimAdjacencia;
                        j->aresta = tmp->aresta;
                        verticeRemovido = tmp->vertice;
                        tmp->aresta == nullptr;
                        k = Fim;
                        delete tmp;
                    }else{
                        j = j->aresta;
                    }
                }
            }
        }   
    }
    return verticeRemovido;
}

// Mostrar os elementos dentro da nossa lista e mostrar os relacionamentos de cada vértice.

void ListaAdjacencia::mostrarLista(){
    for(Celula *i = Inicio->prox; i != nullptr; i = i->prox){
        //cout << "Vertice: " << i->vertice << endl;
        for (Celula *j = i->aresta; j != nullptr; j = j->aresta){
            // cout << "U " << i->vertice << " -- V " << j->vertice << endl; 
            cout << i->vertice << "-" << j->vertice << " ";
        }
        cout << endl;
    }
}

vector<int> ListaAdjacencia::DFS(int verticeInicial) {
    // Cria um vetor para marcar os vértices visitados
    vector<bool> visitado(tamanho(), false);
    vector<int> seqVertices;

    // Chama a função auxiliar de busca em profundidade
    DFSUtil(verticeInicial, visitado, seqVertices);

    return seqVertices;
}

void ListaAdjacencia::DFSUtil(int vertice, vector<bool>& visitado, vector<int>& seqVertices) {
    // Marca o vértice como visitado
    //cout << vertice << endl;
    visitado[vertice] = true;
    seqVertices.push_back(vertice);

    // Percorre todas as adjacências do vértice
    for (Celula* i = Inicio->prox; i != nullptr; i = i->prox) {
        if (i->vertice == vertice) {
            // Verifica se há arestas
            Celula* j = i->aresta;
            while (j != nullptr) {
                // Chama a DFS para os vértices adjacentes não visitados
                if (!visitado[j->vertice])
                    DFSUtil(j->vertice, visitado, seqVertices);

                j = j->aresta;
            }
        }
    }
}