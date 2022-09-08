/*
Manuel Camacho Padilla [A01423135]
06 / 10 / 2020
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node
{
  private:
    string texto;
    int ip;
    Node* next;

  public:
    Node();
    virtual ~Node();
    Node(string, Node*);

    string getTexto();
    int getIp();
    Node* getNext();
    void setTexto(string);
    void setIp(int);
    void setNext(Node*);
};
