/*
Manuel Camacho Padilla [A01423135]
06 / 10 / 2020
*/

#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	start = nullptr;
}

LinkedList::~LinkedList(){}

// Getter
Node* LinkedList::getStart()
{
	return start;
}

//Setter
void LinkedList::setStart(Node* _start)
{
	start = _start;
}

// Funtions
void LinkedList::insertEnd(string n)
{
  /*
  Funcion que inserta el ultimo dato de una lista 
  Input: Valor entero 
  Output: Nada
  */
	Node* neu = new Node(n, nullptr);
	if (start == nullptr)
  {
		start = neu;
	}
	else
  {
		Node* before = start;
		Node* aux = start;
		while (aux != nullptr)
    {
			before = aux;
			aux = aux->getNext();
		}
		before->setNext(neu);
	}
}

void LinkedList::insertOrder(string t1, int i)
{
  /*
  Funcion que inserta un dato en una lista 
  Input: Valor entero 
  Output: Nada
  */
  Node* nuevo = new Node(t1,nullptr);
  if (start == nullptr) {
    start = nuevo;
  }
  else {
    Node* aux1 = start;
    Node* aux2 = start;
    while (aux2 != nullptr && i > aux2->getIp()) 
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

ostream& operator<< (ostream& out, LinkedList& n) // 3, 5 y 7
{
  /*
  Funcion sobrecarga (<<) que imprime una lista
  Input: ostream& out, lista LinkedList
  Output: ostream& out
  */
  out << "\n\n\n=========== Contenido de la lista ligada ===========\n\n";
  if(n.start == nullptr)
  {
    out << "\n\n\nLista vacia..." << endl;
    return out;
  }
  Node* m = n.start;
	while (m != nullptr){
		out << m->getTexto() << endl;
		m = m->getNext();
	}
  return out;
}

void LinkedList::archivo() // 8 
{
  /*
  Funcion que crea un archivo de texto con los datos solicitados 
  Input: Nada
  Output: Un archivo de texto
  */
  Node* n = start;
  ofstream archivo("Resultado_Busqueda.txt");

  while(n != nullptr)
  {
    archivo << n->getTexto() << endl;
    n = n->getNext();
  }
}

LinkedList LinkedList::ordena() // 4
{
  /*
  Funcion que ordena una lista con los IPs solicitados 
  Input: Nada
  Output: Un objeto tipo LinkedList
  */
  LinkedList temp_list;
  Node* n = start;
  if(n==nullptr)
  {
    cout << "\n\n\nLista vacia..." << endl;
    return temp_list;
  }
  while(n != nullptr){
    temp_list.insertOrder(n->getTexto(),n->getIp());
    n = n->getNext();
  }
  return temp_list;
}

void LinkedList::printOrdenaIP(int _start, int _end) // 6
{
  /*
  Función que hace llamado de la función insertOrder para ordenar la lista. 
  Input: Dos valores enteros
  Output: Un objeto tipo LinkedList
  */
  LinkedList temp_list;
  Node* n = start;
  if(n==nullptr)
  {
    cout << "\n\n\nLista vacia..." << endl;
  }
  while(n != nullptr){ 
    if(n->getIp() >= _start && n->getIp() <= _end)
    {
        cout << n->getTexto() << endl;
    }
    n = n->getNext();
  }
}
