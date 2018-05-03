#ifndef PARTIDOS_H
#define PARTIDOS_H
#include <iostream>
#include <cstdlib>

using namespace std;


class partidos{
      protected:    //se crea clase partidos con objetos protegidos
                class Nodo{
                      public:
                             string prt[6];   //cada nodo tiene un arreglo de string[6] con puntero siguiente y anterior
                             Nodo *siguiente;
                             Nodo *anterior;
                             
                };
                
                Nodo *inicio;     //la lista cuenta con in inicio=0 y final de lista fina=0
                Nodo *final;
                
      public:
             partidos(){inicio=0,final=0;} //método de inicializacion de variables en nil para lista
             void inserta(string a,string b,string c,string d,string e,string f); //inserta todos los valores de los paises
             bool registra(string q,string e,int a, int b); // método de registro de partidos de 2 paises validando si no estan registrados
             void portada();      // método para la muestra de las opciones de ingreso
             void realizados();   // muestra los partidos realizados
             void rslt(string a, string b);  //muestra los resultados de un partido en específico
             bool modifica(string q,string e,int a, int b); //modifica los partidos realizados validando si éstos se jugaron
             void escritura();              //método de escritura(actualización) de los datos al archivo Partidos.cvs
             bool lectura();                //lectura de los datos a procesar en el archivo Partidos.csv
             
	         
	         
};

#endif
