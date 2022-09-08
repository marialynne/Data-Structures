/*
  ʕ•́ᴥ•̀ʔっ♡
  
  Act_Int_4 - Actividad integradora de grafos
  20/11/2020
  Manuel Camacho Padilla [A01423135]

  ▄▄▀▀█▀▀▄▄
 ▐▄▌ ▀ ▀ ▐▄▌
   █ ▄▄▄ █  ▄▄
   ▄█▄▄▄█▄ ▐  ▌
 ▄█▀█████▐▌ ▀ ▐
 ▀ ▄██▀██▀█▀▄▄▀

*/
#include <iostream>
#include <fstream>
#include "Grafo.h"
using namespace std;

Grafo reading() 
{ 
  /*
    Función: Lectura de datos del archivo.
    
    Complejidad: O(n) 
    Input: Un Archivo.txt
    Output: Un Objeto Grafo 
  */
  Grafo temp_list;
  
  string line;

  ifstream file;
  file.open("bitacora.txt",ios::in);
  if(file.fail())
  { 
    cout << "Error de lectura...";
    exit(1);
  }
  while(getline(file,line))
  {
    temp_list.insertOrder(line);
  }
  return temp_list;
  file.close();
}

int main() 
{
  /*
    Función principal
  */
  Grafo g1 = reading();
  g1.imprime();
  return 0;
}
