/*
  Act_Int_4 - Actividad integradora de grafos
  20/11/2020
  Manuel Camacho Padilla [A01423135]
*/
#include "Node.h"
using namespace std;
 
// Constructor 
Node::Node()
{ 
  puerto = 0;
  ip = "";
	next = nullptr;
  fan_out = 1;
}

// Destructor 
Node:: ~Node(){}

int obtenerPuerto(string iP)
{
  /*
    Función: Obtiene el puerto de una IP.
    
    Complejidad: O(n) 
    Input: Un valor STRING
    Output: Un valor INT
  */
  int pos = iP.find(":");
  string ip = (iP.substr(pos + 1));
  return stoi(ip);
}

string obtenerIP(string texto)
{
  /*
    Función: Obtiene la IP de una linea de texto.
    
    Complejidad: O(n) 
    Input: Un valor STRING
    Output: Un valor STRING
  */
  int ip,j = 1;
  char separador = ' ';
  string iP;
  for (size_t p = 0, q = 0; p != texto.npos; p = q){
    if (j < 4)
    {
      texto.substr(p + (p != 0), (q = texto.find(separador, p + 1)) - p - (p != 0));
    }
    else if (j == 4)
    {
      iP = texto.substr(p + (p != 0), (q = texto.find(separador, p + 1)) - p - (p != 0));
      break;
    }
    j++;
  }
  return iP;
}

// Segundo Constructor 
Node::Node(string texto, Node* node)
{
  puerto = obtenerPuerto(obtenerIP(texto));
  ip = obtenerIP(texto);
	next = node; 
  myVector.push_back(ip);
  fan_out = 1;
}

// Getters
int Node::getPuerto() 
{
  return puerto;
}
string Node::getIp() 
{
  return ip;
}
Node* Node::getNext()
{
	return next;
}
vector<string> Node::getMyVector()
{
  return myVector;
}
int Node::getFan_out(){
  return fan_out;
}

// Setters
void Node::setPuerto(int _puerto) 
{
  puerto = _puerto;
}
void Node::setIp(string _ip) 
{
  ip = _ip;
}
void Node::setNext(Node* _node)
{
	next = _node;
}
void Node::set_to_myVector(string p)
{
  myVector.push_back(obtenerIP(p));
}
void Node::setFan_out(int _fan_out){
  fan_out = _fan_out;
}

