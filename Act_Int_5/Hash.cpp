/*
  Act_Int_5 - Actividad integradora sobre el uso de códigos hash (evidencia competencia)
  30/11/2020
  Manuel Camacho Padilla [A01423135]
*/

#include "Hash.h"

// Constructor
Hash::Hash(){
}

// Destructor 
Hash::~Hash(){}

// Functions
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
  int i = iP.find(":");
  string m;
  m = iP.substr(0,i);
  return m;
}

string webI (string m){
  /*
    Función: Obtiene el identificador Web de una ip.
    Complejidad: O(n) 
    Input: Un valor STRING
    Output: Un valor STRING
  */
  int i = m.find(".");
  string copia = m.substr(i + 1);
  string j = m.substr(0,i+1); 
  i = m.find(".");
  i = copia.find(".");
  string copia2 = copia.substr(0,i);
  string ip = j+copia2;
  return ip;
}

string hostI (string m){
  /*
    Función: Obtiene el identificador Host de una ip.
    Complejidad: O(n) 
    Input: Un valor STRING
    Output: Un valor STRING
  */
  int i = m.find(".");
  m = m.substr(i + 1);
  i = m.find(".");
  m = m.substr(i + 1);
  return m;
}

int hashKey(string plate){
  /*
    Función: Crear llaves 
    Entrada: Un identificador host
    Salida: Un entero 
    Complejidad: O(k)
  */
  int index,i,e,l,m,r,q,w,o,d,k,g,a;
  string aux = plate, aux2 = plate, aux3 = plate;
  aux3 = aux3.substr(0,1);
  m = stoi(aux3);
  k = m;
  m *= 397;
  l = plate.length();
  g = l*59;
  o = l;
  l *= 409;
  e = aux.find(".");
  aux = aux.substr(0,i);
  i = aux.length();
  i += stoi(aux);
  w = i;
  i *= 7;
  aux2 = aux2.substr(e + 1);
  e = aux2.length();
  d = e;
  e *= 3;
  e += stoi(aux2);
  r = 97;
  q = 47;
  index = i+e+l+m+r+q+w+o+d+k+l;
  return index;
}

void Hash::table(vector<string> v){
  /*
    Función: Crea la tabla hash dentro de un vector de vectores
    Entrada: Un vector
    Salida: Nada 
    Complejidad: O(n)
  */
  int key;
  Node node;
  for(int i = 0; i < v.size(); i++){
    key = hashKey(hostI(v[i]));
    node = Node(webI(v[i]), hostI(v[i]));
    if(myVector[key].size() == 0){
      myVector[key].push_back(node);
    } else{
      colisiones++;
      myVector[key].push_back(node);
    }
  }    
}

void Hash::read(){
  /*
    Función: Lee los datos de un archivo y genera un vectir de IPs
    Entrada: Un archivo de texto
    Salida: Nada
    Complejidad: O(n)
  */
  ifstream file;
  file.open("bitacora.txt",ios::in);
  if(file.fail()){
    cout << "Error de lectura..." << endl;
    exit(1);
  }
  vector <string> v;
  string line;
  string m;
  while (getline(file,line)) {
    m = obtenerIP(line); 
    v.push_back(obtenerIP(line));
    contador++;
  }
  myVector.resize(contador);
  file.close();
  table(v);
}

void Hash::print(){
  /*
    Función: Imprimir la tabla Hash
    Entrada: Ninguna
    Salida: Ninguna
    Complejidad: O(n^2)
  */
  int n = 1;
  for(int i = 0; i < contador; i++){
    if(myVector[i].size() == 1){
      cout << n << ". Llave: " << i << endl;
      cout << "\t  Web: " <<  myVector[i][0].getWeb() << endl << endl;
      n++;
    }
    else if(myVector[i].size() > 1){
      cout << n << ". Llave: " << i << endl;
      for(int j = 0; j < myVector[i].size(); j++){
        cout << "\t  Web: " <<  myVector[i][j].getWeb() << endl;
      }
      cout << endl;
      n++;    
    }
  }
  cout << "Numero de colisiones: " << colisiones << endl;
  cout << "Cantidad de datos almacenados: " << contador << endl;
  cout << "Porcentaje de colisiones: " << (colisiones*100)/contador << "%" << endl;
}