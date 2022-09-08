/* 
Autor: Manuel Camacho Padilla [A0143135]
Fecha: 13 de septiembre de 2020 

  Porgrama que:
    1) Abra el archivo de entrada llamado "bitacora.txt
    2) Lea y almacene los datos en un vector.
    3) Ordene la información por fecha.
    4) Solicite al usuario las fechas de inicio y fin de búsqueda de información.
    5) Despliegue los registros correspondientes a esas fechas.
    6) Almacene en un archivo el resultado del ordenamiento.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

vector <string> dates;
vector <int> tempSec;
vector <string> out;

void reading(){ 
  /*
  Función que leerá los datos de un archivo de texto e introducirá los datos en un vector de strings. 
    Entrada:
      Un archivo de texto.
    Salida:
      Un vector <string>
  */

  ifstream file;
  file.open("bitacora.txt",ios::in);

  if(file.fail()){ 
    cout << "Error de lectura...";
    exit(1);
  }

  string line; 
  while (getline(file, line,'\n')){ 
    dates.push_back(line);
  }

  file.close(); 
}

int get_month (string name){
  /*
  Función que recibirá un mes y lo intercmabiará por sus segundos acumulados por año. 
    Entrada:
      Un string mes.
    Salida:
      Un int segundos.
  */
  map <string, int> months
  {
      { "Jan", 0 }, // 0
      { "Feb", 2678400 }, 
      { "Mar", 5097600 }, 
      { "Apr", 7776000 }, 
      { "May", 10368000 }, 
      { "Jun", 13046400 }, // 13046400
      { "Jul", 15638400 }, // 15638400
      { "Aug", 18316800 }, // 18316800
      { "Sep", 20995200 }, // 20995200
      { "Oct", 23587200 }, // 23587200
      { "Nov", 26265600 }, // 26265600
      { "Dec", 28857600 } // 28857600
  };

  const auto iter = months.find(name);

  if (iter != months.cend())
      return iter -> second;
  return -1;
}

void orderSec (vector<string> _tempSec){
  /*
  Función que recibirá un vector y llamará a la función de get_month para comvertir los meses en segundos acumulados y sumarlo con los segundos del día, hora, minutos y segundos. E interacturar con un vector temporal para al final ordenarlo con el método de Selección. Dando como resultado el vector con los datos ordenados. 
    Entrada:
      Un vector <string>.
    Salida:
      Un vector <string>
  */

  int temp;
  int _month;

  for(int i=0; i <= dates.size()-1; i++){
    string month = dates[i].substr(0,3); 
    _month = get_month(month);
    int j=7;
    string day = dates[i].substr(4,2);  // 86400 segundos
    if (stoi(day) < 10){ j = 6;}
    string hour = dates[i].substr(j, 2); // 3600 segundos
    string min = dates[i].substr(j+3, 2); // 60
    string sec = dates[i].substr(j+6, 2);  // 1
    temp = _month + stoi(day)*86400 + stoi(hour)*3600 + stoi(min)*60 + stoi(sec);
    tempSec.push_back(temp);
  }
  
  for (int min = 0; min < dates.size() - 1; min++){
    for (int max = min+1; max < dates.size(); max++){
      
      if (tempSec[min] > tempSec[max]){
        swap (tempSec[min], tempSec[max]);
        swap (dates[min], dates[max]);
      }
    }
  }
}

void find (string month_1,int day_1,string month_2,int day_2){
  /*
  Función que encontrará los datos que el usuario está buscando según sus fechas, imprimiendolo en pantalla y generando un nuevo archivo de texto con dichos datos solicitados. 
    Entrada:
      string mes de inicio.
      string mes de fin.
      int día de inicio.
      int día de fin.
    Salida:
      Un archivo de texto.
  */
  cout << "\n" << endl;
  ofstream file;
  file.open("bitacora_busqueda.txt");
  for(int j = 0; j < dates.size()-1; j++){
    int i = get_month(month_1) + day_1*86400;
    int f = get_month(month_2) + day_2*86400;

    if(tempSec[j]>=i && tempSec[j]<=f){
      file << dates[j] << endl;
      cout << dates[j] << endl;
    }
  }
  file.close(); 
  cout << endl << endl;
}

void menu() {
  /*
  Función que le pedirá los datos al usuario para hacer llamado de las funciones  
    Entrada:
    Un archivo de texto.
    Salida:
    Un vector <string>
  */
    int i, day_1, day_2;
    string month_1, month_2;
    do{
      cout << "Menu de busqueda, para proceder digite 1: "; cin >> i;
      if(i==1){
        cout << "\n\tMarque el mes de inicio (Mmm): "; cin >> month_1;
        cout << "\tMarque el día de inicio (D): "; cin >> day_1;
        cout << "\n\tMarque el mes de fin (Mmm): "; cin >> month_2;
        cout << "\tMarque el día de fin (D): "; cin >> day_2;
        if((day_1<=31 && day_1>=1) && (day_2<=31 && day_2>=1) && (month_1.size()==3) && (month_2.size()==3)){
          find(month_1,day_1,month_2,day_2);
        }
        else{cout << "\nDatos incorrectos, intente otra vez.\n" << endl;}
        
      }
      else{
        cout << "\nHasta luego!" << endl;
      }
    } while(i == 1);
}

int main() {
  // Función principal que hace llamado a todas las funciones necesarias 

  reading();
  orderSec(dates);
  menu();

  return 0 ;
}

/* 
Referencias:

  https://www.youtube.com/watch?v=_TYTlsTXk0w
  
  http://decodigo.com/c-plus-plus-crear-archivo-de-texto
  
  http://www.cplusplus.com/reference/string/string/substr/
  
  https://www.ecured.cu/Algoritmo_de_ordenamiento_por_selecci%C3%B3n#:~:text=Algoritmo%20de%20ordenamiento%20por%20Selecci%C3%B3n%20(Selection%20Sort%20en%20ingl%C3%A9s)%3A,as%C3%AD%20sucesivamente%20hasta%20ordenarlo%20todo.

  https://stackoverflow.com/questions/22575190/convert-month-name-into-number-c/22575223

*/