// Manuel Camacho Padilla [A0142315]
// Arbol de estructura de datos (AVL)
#pragma once
#include <iostream>
#include <string>
using namespace std;

class NodeAVL{
  private:
    int data;
    int fe;
    NodeAVL* left;
    NodeAVL* right;
    string texto;

  public:
    //defualt 
    NodeAVL();
    virtual ~NodeAVL();
    //new constructor 
    NodeAVL(int, int, NodeAVL*, NodeAVL*, string);

    //getters
    int getData();
    int getFe();
    NodeAVL* getLeft();
    NodeAVL* getRight();
    string getTexto();

    //setters
    void setData(int);
    void setFe(int);
    void setLeft(NodeAVL*);
    void setRight(NodeAVL*);
    void setTexto(string);
    
    //operators
    friend std::ostream& operator << (std::ostream&, NodeAVL*);
};



