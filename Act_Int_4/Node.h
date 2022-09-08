/*
  Act_Int_4 - Actividad integradora de grafos
  20/11/2020
  Manuel Camacho Padilla [A01423135]
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
  private:
    int puerto;
    string ip;
    Node* next;
    vector<string> myVector;
    int fan_out;

  public:
    Node();
    virtual ~Node();
    Node(string, Node*);

    int getPuerto();
    string getIp();
    Node* getNext();
    vector<string> getMyVector();
    int getFan_out();

    void setPuerto(int);
    void setIp(string);
    void setNext(Node*);
    void set_to_myVector(string);
    void setFan_out(int);
};
