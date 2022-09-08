// Manuel Camacho Padilla [A0142315]
// Arbol de estructura de datos (ABB)
#pragma once
#include <iostream>
#include <string>
using namespace std;

class NodeABB
{
  private:
    int data;
    NodeABB* left;
    NodeABB* right;
    string texto;

  public:
    //defualt 
    NodeABB();
    virtual ~NodeABB();
    //new constructor 
    NodeABB(int, NodeABB*, NodeABB*, string);

    // getters
    int getData();
    NodeABB* getLeft();
    NodeABB* getRight();
    string getTexto();

    // setters
    void setData(int);
    void setLeft(NodeABB*);
    void setRight(NodeABB*);
    void setTexto(string);

    //operators
    friend std::ostream& operator << (std::ostream&, NodeABB*);
};
