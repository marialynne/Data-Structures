/*
  Act_Int_4 - Actividad integradora de grafos
  20/11/2020
  Manuel Camacho Padilla [A01423135]
*/
#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class Grafo
{
  private:
    Node* start; 
    int vertice;

  public:
    Grafo();
    virtual ~Grafo();

    // Getter and setter
    Node* getStart();
    int getVertice();
    void setStart(Node*);
    void setVertice(int);

    // Funtions 
    void insertOrder(string);
    void imprime();
};


