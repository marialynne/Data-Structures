/*
  Act_Int_5 - Actividad integradora sobre el uso de códigos hash (evidencia competencia)
  30/11/2020
  Manuel Camacho Padilla [A01423135]
*/

#include "Node.h"

// Constructor 
Node::Node(){}

// Destructor 
Node:: ~Node(){}

// Segundo Constructor 
Node::Node(string _web,string _host)
{
  web = _web;
  host = _host;
}

// Getters
string Node::getHost(){
  return host;
}

string Node::getWeb(){
  return web;
}

