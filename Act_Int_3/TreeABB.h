// Manuel Camacho Padilla [A0142315]
// Arbol de estructura de datos (ABB)
#pragma once
#include <iostream>
#include <string>
#include "NodeABB.h"

class TreeABB{
  NodeABB* root;

public:
  //defualt constructors 
  TreeABB();
  ~TreeABB();

  //getters
  NodeABB* getRoot();

  //setters
  void setRoot(NodeABB*);

  //function 
  void insert(int, string);
  void pre_order(NodeABB*);
  void in_order(NodeABB*);
  
  NodeABB* find_b(int);
  NodeABB* previous(NodeABB*);

  void removed(int);
  NodeABB* removed_a(NodeABB*, NodeABB*);
  NodeABB* removed_b(NodeABB*, NodeABB*);
  NodeABB* removed_c(NodeABB*, NodeABB*);
  
};