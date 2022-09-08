/*
Manuel Camacho Padilla [A01423135]
06 / 10 / 2020
*/

#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList
{
  private:
    Node* start; 

  public:
    LinkedList();
    virtual ~LinkedList();

    // Getter and setter
    Node* getStart();
    void setStart(Node*);

    // Funtions 
    void insertStart(string);
    void insertEnd(string);
    bool searchNode(string);
    void insertOrder(string,int);
    void archivo();
    void printOrdenaIP(int, int); // LinkedList
    LinkedList ordena();
    void print();

    // Operator overloading
    friend ostream& operator<< (ostream& out, LinkedList& n);

};


