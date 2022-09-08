/*
  Act_Int_5 - Actividad integradora sobre el uso de códigos hash (evidencia competencia)
  30/11/2020
  Manuel Camacho Padilla [A01423135]
*/

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Node
{
  private:
    string host;
    string web;

  public:
    Node();
    ~Node();
    Node(string, string);
    
    // Getters
    string getHost();
    string getWeb();
};
