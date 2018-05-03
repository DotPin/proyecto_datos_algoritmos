#include "partidos.h"
#include "equipo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <locale>
#include <sstream>
#include <stdio.h>
#include <string.h>

void partidos::portada(){
    cout<<"\n\n\n";
    cout << "******************************************************************\n";
    cout << "*           Clasificatorias Mundial Brasil 2014                  *\n";
    cout << "******************************************************************\n";
    cout <<"\n\n\n\n\n\n";
    cout <<"Ingrese la opcion a revisar en clasificatorias\n\n";                   
    cout <<"1) Registrar Partido\n";                                            //listo
    cout <<"2) Ver Tabla General de posiciones\n";                              //listo
    cout <<"3) Ver posiciones por Grupo\n";                                     //listo
    cout <<"4) Ver resultado Partidos Realizados\n";                            //listo
    cout <<"5) Ver resultado Partido Especifico\n";                             //listo
    cout <<"6) Modificar Registro\n";                                           
    cout <<"0) Salir\n";
    cout<<"\n\n\n";

}

void partidos::inserta(string a,string b,string c,string d,string e, string f){
     //método que inserta a una lita llamada partido de 6 parámetros extraidos del archivo Partidos.csv
     Nodo *nuevo = new Nodo();         //crea nodo nuevo para información
     Nodo *aux = inicio;               //crea puntero para recorrer lista doble
     nuevo->siguiente = 0;             // deja apuntando nodo nuevo ambos lados a nil
     nuevo->anterior = 0;
     
     nuevo->prt[0]=a;    //grupo con partido             // cada parámetro recibido desde la función de captura del archivo Partidos.csv
     nuevo->prt[1]=b;    //si partido se jugo o no       // se asigna a cada valor del arreglo formato string para el nodo
     nuevo->prt[2]=c;    //equipo competidor
     nuevo->prt[3]=d;    //goles del equipo compatidor
     nuevo->prt[4]=e;    //equipo contrario
     nuevo->prt[5]=f;    //goles equipo contrario
     
      if(inicio == final){              //el crear el nodo con la información se inserta al inicio
               inicio = nuevo;
               nuevo->anterior = final;
     }else{                            // al haber nodo al principio los va insertando al final
           while(aux->siguiente) aux = aux->siguiente;
           nuevo->anterior = aux;
           aux->siguiente = nuevo;
     }     
}

bool partidos::registra(string q,string e,int a, int b){  //ejecuta método de registro donde toma los 2 paises con los resultados
     ostringstream convert;
     Nodo *aux = inicio;
     while(aux){
                if((aux->prt[2]).compare(0,5,q,0,5) == 0 && (aux->prt[4]).compare(0,5,e,0,5) == 0 ){  //verifica si el partido es el que se organizó
                   if(aux->prt[1]=="F" ){           //verifica si el partido se llevó a cabo
                       cout << "valores encontrados";
                       aux->prt[1] = "V";                  //cambia el valor como partido realizado y procede a incorporar valores de los goles
                       convert << a;
                       aux->prt[3] = convert.str();        //guarda los goles del equipo A
                       convert.str("");
                       convert << b;                       
                       aux->prt[5] = convert.str();        // guarda los goles del equipo B
                       cout<<"\n";
                       system("PAUSE");
                       return true;                        //al realizar los procedimientos retorna verdadero para valores hechos
                   }else {
                         cout << "Partido ya registrado";
                         cout<<"\n\n\n";
                         system("PAUSE");
                         return false;    // retorna falso si el partido si se llevó a cabo
                   }
                }
                aux = aux->siguiente;
     }
     cout << "Partidos no encontrados";
     cout<<"\n\n\n";
     system("PAUSE");
     return false;     // retorna falso si el partido no está organizado
}

void partidos::realizados(){      //método para impresión de partidos realizados
     Nodo * aux = inicio;
     int q=1;
     cout << "Lugar\t"<<"|Equipo1\t"<<"|Goles\t"<<"|Equipo2\t"<<"|Goles\n";     //Imprime el detalle propiedades de valores
     cout << "********************************************************\n\n";
     while(aux){
                if((aux->prt[1]).compare("V")==0){                          //valida si los partidos aparecen como concluidos
                     cout << q++ <<"\t|";                                   //imprime los partidos jugados con sus goles                                                                               
                     for(int h =2;h<6;h++) cout <<aux->prt[h]<<"\t|";
                     cout<<"\n";
                }
                aux = aux->siguiente;
     }
     cout<<"\n\n\n";
     system("PAUSE");
}

void partidos::rslt(string a, string b){ // método para mostrar resultado específico de un partido con parámetro par de paises
     Nodo * aux = inicio;
     while(aux){                         //compara si estan organizados y si los paises se enfrentaron 
                if((aux->prt[2]).compare(0,5,a,0,5)==0 && (aux->prt[4]).compare(0,5,b,0,5)==0 && (aux->prt[1]).compare("V")==0){                                                                       
                     cout <<"\n\n";
                     cout <<"Estado\t"<<"|Equipo 1\t"<<"|Goles\t"<<"|Equipo 2\t"<<"|Goles\n"; //imprime el resultado del partido realizado
                     cout << "********************************************************\n\n";
                     cout <<"Jugado\t|";
                     for(int i=2;i<6;i++){
                             cout<<aux->prt[i]<<"\t|"; //<<aux->prt[3]aux->prt[4]<<"\n";
                     }
                }
                aux = aux->siguiente;
     }
     
     cout<<"\n\n\n";
     system("PAUSE");

}

bool partidos::modifica(string q,string e,int a, int b){ // método modifica se asimila al método registra
     ostringstream convert;
     Nodo *aux = inicio;
     while(aux){
                if((aux->prt[2]).compare(0,5,q,0,5) == 0 && (aux->prt[4]).compare(0,5,e,0,5) == 0 ){
                   if(aux->prt[1]=="V" ){           // se módifica en vez de partido no realizado, como realizado para validar
                       cout << "Valores encontrados";
                       convert << a;                       
                       aux->prt[3] = convert.str();        // se cambia los valores de los goles de los 2 equipos comparados
                       convert.str("");
                       convert << b;
                       aux->prt[5] = convert.str();
                       cout<<"\n";
                       system("PAUSE");
                       return true;
                   }else {
                         cout << "Partido no registrado";
                         cout<<"\n\n\n";
                         system("PAUSE");
                         return false;    //en caso de que el partido no esté registrado no modificará enviando un falso
                   }
                }
                aux = aux->siguiente;
     }
     cout << "Partidos no encontrados";
     cout<<"\n\n\n";
     system("PAUSE");
     return false;     //en caso de no encontrar el partido indicará que no está registrado
}

void partidos::escritura(){ //método de escritura al archivo .csv
     ofstream fout("Partidos.csv"); //abrir el fichero Partido.csv
     Nodo *aux = inicio;
     char filename[20];     //crea un arreglo de tipo char con espacio para una palabra
     while(aux){
          for(int i=0;i<5;i++){    //se crea el for para incorporar los datos al nodo con datos de tipo arreglo string[6]
                filename[aux->prt[i].size()]=0;     //se asigna valor 0 al tamaño char de la letra
                memcpy(filename,aux->prt[i].c_str(),aux->prt[i].size());          //de transforma de strign a char 
                fout << filename<<";"; //escribe datos archivo .csv                    
                if(i==4){
                         filename[aux->prt[i+1].size()]=0;
                         memcpy(filename,aux->prt[i+1].c_str(),aux->prt[i+1].size());           
                         fout << filename; //escribe datos archivo .csv
                }
          }
          fout << endl;  //hace un salto de linea en el archivo
          aux = aux->siguiente;
     } 
     fout.close();             //cierra el archivo modificado
     cout << "Datos grabados en: Partidos.csv" << endl;      
     aux=0;                  //puntero se deja en nil
     delete aux;             //se libera puntero
}


bool partidos::lectura(){    //método de lectura de archivo .cvs
    char cadena[128];        //se crea arreglo char tamaño de línea
    string cadena2=" ";      //se crea string para guardar el arreglo de char
    string arreglo [8];      //se crea arreglo para alpacenar pada palabra en cada casilla del string
     
    ifstream acm("Partidos.csv"); //archivo .csv para leer
     
     if(acm.good()){              //pregunta si el archivo se leyó bien
        while (cadena2!=""){      //pregunta si el string es nulo
               acm.getline(cadena,128);      //toma una línea del archivo
               cadena2=cadena;               //se guarda como string
               if(cadena2!=""){              //se pregunta si la línea es vacía
                   for(int i=0; i<5;i++){    // for para rellenar las palabras al arreglo de string
                           arreglo[i]=cadena2.substr(0, cadena2.find(";"));
                           cadena2=cadena2.substr(cadena2.find(";")+1,500);
                   }
                   inserta(arreglo[0],arreglo[1],arreglo[2],arreglo[3],arreglo[4]," "); //se llama método de inserta para ingresar valores a la lista enlazada             
               }
        }
    }else {
          cout << "Archivo Equipos.csv no encontrado\n"; //en caso de no encontrar el archivo de lectura eviará un msj y un falso para su validación
          return false;
    }
    return true;
}





