#ifndef EQUIPO_H
#define EQUIPO_H
#include <iostream>
#include <cstdlib>


using namespace std;


class equipo{
      protected:                //se crea clase con objetos protegidos de equipo
                class Nodo{
                      public:             //se crea lista doble enlazada
                             string dt[8];      //arreglo de 8 espacios para cada nodo
                             Nodo *siguiente;   
                             Nodo *anterior;
                };
                
                Nodo *inicio;     //con punteros de nil inicio y final
                Nodo *final;
      public:
	         equipo(){inicio=0,final=0;}
	         void inserta1(string a,string b,string c,string d,string e,string f,string g,string h); //inserta todos los valores de los paises
	         void totales(string a);       //metodo para totalizar despues de editar partidos
	         void orden(){ordenamiento(inicio);}    //redefinición de ordenamiento
	         void ordenamiento(Nodo*);              //método de ordenamiento
	         void orden2(){ordenamiento2(inicio);}
	         void ordenamiento2(Nodo*);
	         void mostrar();                        //imprime listado de nodos
	         void grupos(string a);                         //imprime grupo solicitado a usuario
	         void valores(string e, int a, int b);  //ingresa valores a tabla
	         void escritura();                      //escribe los valores en el .csv
	         bool lectura();                        //lee archivo .csv
};

#endif
