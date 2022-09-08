/*
Manuel Camacho Padilla [A01423135]
06 / 10 / 2020

1) Abra el archivo de entrada llamado "bitacora.txt".
2) Lea y almacene los datos en una lista ligada simple en el mismo orden en que aparecen en el archivo  (Formato del archivo bitacora.pdf).
3) Muestre todos los elementos de la lista, un elemento por renglón.
4) Ordene la información por ip utilizando únicamente los mismos nodos que ya se tienen en la lista.
5) Muestre todos los elementos de la lista ordenados.
6) Solicite al usuario las ips de inicio y fin y realice una búsqueda.
7) Despliegue los registros correspondientes a esas ips.
8) Almacene en un archivo (bitacoraEnLista.txt) el resultado del ordenamiento.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList reading() // 1 y 2
{ 
  /*
  Función que lee los datos de un archivo de texto y los covertirá en una lista ligada. 
  Input: Un archivo de texto
  Output: Un objeto tipo LinkedList
  */
  LinkedList temp_list;
  string line;
  ifstream file;
  file.open("bitacora2.txt",ios::in);
  if(file.fail())
  { 
    cout << "Error de lectura...";
    exit(1);
  }
  while(getline(file,line))
  {
    temp_list.insertEnd(line);
  }
  return temp_list;
  file.close();
}

int main() 
{
  int start, end;
  LinkedList l1 = reading(); // 1 y 2 
  cout << l1; // 3 
  l1 = l1.ordena(); // 4  
  cout << l1; // 5 
  cout <<  "=====================================================" << endl;
  cout << "\nIserte inicio entre rango entre 1 y 999: ";
  cin >> start;
  cout  << "\nInserte final entre rango entre 1 y 999: ";
  cin >> end;
  cout <<  "=====================================================" << endl;
  l1.printOrdenaIP(start, end); // 6 y 7 
  l1.archivo(); // 8 
  

  return 0;
}
