/*
Manuel Camacho Padilla [A01423135]
06 / 10 / 2020
*/

#include <iostream>
#include "Node.h"
using namespace std;
 
Node::Node()
{
  texto = "";
  ip = 0;
	next = nullptr;
}

Node:: ~Node(){}

Node::Node(string _texto, Node* node)
{
	texto = _texto;
	next = node;
//////////////////////////////////////////////////////////
//    Esta parte de logica me ayudo Brando Alberto      //
//////////////////////////////////////////////////////////
  int j = 1;
  char separador = ' ';
  string iP;
  for (size_t p = 0, q = 0; p != texto.npos; p = q)
  {
    if (j < 4)
    {
        texto.substr(p + (p != 0), (q = texto.find(separador, p + 1)) - p - (p != 0));
    }
    else if (j == 4) {
        iP = texto.substr(p + (p != 0), (q = texto.find(separador, p + 1)) - p - (p != 0));
        break;
    }
    j++;
  }

  j = 1;
  separador = '.';
  size_t p = 0, q = 0;
  ip = atoi((iP.substr(p + (p != 0), (q = iP.find(separador, p + 1)) - p - (p != 0))).c_str());
///////////////////////////////////////////////////////////

}

// Getters
string Node::getTexto() 
{
  return texto;
}
int Node::getIp() 
{
  return ip;
}
Node* Node::getNext()
{
	return next;
}

// Setters
void Node::setTexto(string _texto) 
{
  texto = _texto;
}
void Node::setIp(int _ip) 
{
  ip = _ip;
}
void Node::setNext(Node* _node)
{
	next = _node;
}

