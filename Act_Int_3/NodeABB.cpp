// Manuel Camacho Padilla [A0142315]
// Arbol de estructura de datos (ABB)
#include <iostream>
#include "NodeABB.h"
using namespace std;
 
NodeABB::NodeABB()
{
  data = 0;
  left = nullptr;
  right = nullptr;
  texto = "";
}

NodeABB:: ~NodeABB(){}

NodeABB::NodeABB(int _data, NodeABB* _left, NodeABB* _right, string _texto)
{
  data = _data;
  left = _left;
  right = _right;
	texto = _texto;

}

// Getters
int NodeABB::getData(){
  return data;
}
NodeABB* NodeABB::getLeft(){
  return left;
}
NodeABB* NodeABB::getRight(){
  return right;
}
string NodeABB::getTexto() {
  return texto;
}

// Setters
void NodeABB::setData(int _data){
  data = _data;
}
void NodeABB::setLeft(NodeABB* _left){
  left = _left;
}
void NodeABB::setRight(NodeABB* _right){
  right = _right;
}
void NodeABB::setTexto(string _texto) {
  texto = _texto;
}

//operators
std::ostream& operator  << (std::ostream& out, NodeABB* n){
  //out << "\tIP: " << n->getData() << "\n";
  out << n->getTexto() << "\n";
  return out;
}

