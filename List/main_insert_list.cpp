#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
#include <chrono>  
#include<stdlib.h>
#include <list> 
using namespace std;

int main() {
  const string nfichero="english3.txt";
  char cadena[80];
  string palabra;
  ifstream fichero;
  fichero.open(nfichero.c_str());

  list<string> lista; 
  
  if(!fichero.fail()){
    //fichero.getline(cadena, 80, ' ');
    //cout<<cadena<<endl;
    ofstream archivo;
    archivo.open("tiempo_insert_list.txt",ios::out);
    while(!fichero.eof()){
      auto start = chrono::high_resolution_clock::now(); //Tiempo start

      fichero.getline(cadena, ' '); //lee los datos
      //cout<<"Cadena es: "<<cadena<<endl;
      lista.push_back(cadena); //inserta el dato en list

      auto end = chrono::high_resolution_clock::now(); //tiempo end
      double time_taken =  //calcula tiempo
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
      time_taken *= 1e-9;  
      //setprecision(9); //aproximacion
      //cout << "Time taken by program is : "<<fixed<<time_taken<<setprecision(9)<<endl; 
      archivo<<fixed<<time_taken<<setprecision(9); //guardo el tiempo en tiempo.txt
      archivo<<'\n';
    }
    archivo.close();
    fichero.close();
  }
}