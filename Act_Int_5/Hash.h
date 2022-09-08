/*
  Act_Int_5 - Actividad integradora sobre el uso de códigos hash (evidencia competencia)
  30/11/2020
  Manuel Camacho Padilla [A01423135]
*/

#pragma once
#include "Node.h"
#include <fstream>
#include <vector>
#include <string>

class Hash{
  private:
    vector<vector<Node>> myVector;
    int contador = 0;
    int colisiones = 0;

  public:
    Hash();
    ~Hash();

    // Functions 
    void table(vector<string>);
    void read();
    void print();
};
