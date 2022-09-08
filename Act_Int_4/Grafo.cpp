/*
  Act_Int_4 - Actividad integradora de grafos
  20/11/2020
  Manuel Camacho Padilla [A01423135]
*/
#include "Grafo.h"
using namespace std;

// Constructor 
Grafo::Grafo()
{
	start = nullptr;
  vertice = 0;
}

// Destructor 
Grafo::~Grafo(){}

// Getters
Node* Grafo::getStart()
{
	return start;
}
int Grafo::getVertice(){
  return vertice;
}

//Setters
void Grafo::setStart(Node* _start)
{
	start = _start;
}
void Grafo::setVertice(int _vertice){
  vertice = _vertice;
}

// Funtions
void Grafo::insertOrder(string texto)
{
  /*
    Función: Realiza la lista de adyacencia de forma descendente segun el puerto.

    Complejidad: O(n^2) 
    Input: Un valor STRING
    Output: Nada
  */
  Node* nuevo = new Node(texto,nullptr);
  Node* i = start;
  while(i != nullptr)
  {
    if(i->getPuerto() == nuevo->getPuerto())
    {
      i->set_to_myVector(texto);
      i->setFan_out(i->getFan_out() + 1);
      return;
    }
    i = i->getNext();
  }
  delete i;
  setVertice(getVertice() + 1);
  if (start == nullptr) {
    start = nuevo;
  }
  else {
    Node* aux1 = start;
    Node* aux2 = start; 
    // La condición determina si será descendente o ascendente 
    while (aux2 != nullptr && nuevo->getPuerto() < aux2->getPuerto()) 
    {
      aux1 = aux2;
      aux2 = aux2->getNext();
    }
    if (aux1 == aux2) {
      nuevo->setNext(start);
      start = nuevo;
    }
    else if (aux2 == nullptr)
    {
      aux1->setNext(nuevo);
    }
    else 
    {
      nuevo->setNext(aux2);
      aux1->setNext(nuevo);
    }
  }
}

void Grafo::imprime()
{
  /*
    Función: Despliega los datos en forma descendente segun el puerto. Y determina el fan-out con mayor grado e imprime el vertice.
    
    Complejidad: O(n^2) 
    Input: Nada
    Output: Nada
  */
  Node* i = start;
  int puerto=0, fo=0;
  while(i != nullptr)
  {
    cout << "\n\nPuerto: " <<  i->getPuerto() << "\tFan out: " << i->getFan_out() << "\n\n";
    vector<string> itr = i->getMyVector();
    for(int k = 0; k < itr.size(); k++)
    {
      cout <<"\t\t<< "<< itr[k] <<" >>"<<endl;
    }
    if(i->getFan_out() > fo)
    {
      fo = i->getFan_out();
      puerto = i->getPuerto();
    }
    i = i->getNext();
  }
  cout << "\n\nEl puerto con mayor Fan-out es \"" << puerto << "\" \nCon grado de: " << fo <<"\nVeritice total: " << getVertice() << endl;
}


