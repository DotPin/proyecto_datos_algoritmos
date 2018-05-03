#include "equipo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <locale>
#include <sstream>
#include <stdio.h>
#include <string.h>

bool equipo::lectura(){
    char cadena[128];                       //creamos cadena de caracteres para lectura
    string cadena2=" ";                     //creamos una variable de string para guardar buffer del archivo
    string arreglo [8];                     //almacenaremos cada palabra en un arreglo de 8 elementos
       
    ifstream fe("Equipos.csv");             //leemos archivo .csv en variable fe
     
     if(fe.good()){                         //verificamos si el archivo se lelló correctamente
        while (cadena2!=""){
               fe.getline(cadena,128);      //obtenemos las lineas del archivo en la variable cadena
               cadena2=cadena;              //la línea es guardada en el string cadena 2
               if(cadena2!=""){             // evalúa si la línea estaba vacía
                   for(int i=0; i<8;i++){   //realiza la extracción de las palabras de la línea en el arreglo[8] de string
                           arreglo[i]=cadena2.substr(0, cadena2.find(";"));
                           cadena2=cadena2.substr(cadena2.find(";")+1,500);
                   }
                inserta1(arreglo[0],arreglo[1],arreglo[2],arreglo[3],arreglo[4],arreglo[5],arreglo[6],arreglo[7]);              //envía las palabras extraidas al método inserta1 de la clase equipo
               }
        }
     }else {
          cout << "Archivo Equipos.csv no encontrado\n";         //en caso de no haber encontrado el archivo entrega msj
          return false;
     }
     return true;

}

void equipo::inserta1(string a,string b,string c,string d,string e,string f,string g,string h){
     Nodo *nuevo = new Nodo();                          //creamos un nuevo nodo
     Nodo *aux = inicio;                                //creamos un puntero para recorrer lista
     nuevo->siguiente = 0;                              //dejamos el nuevo nodo apuntando ambos lados a nil
     nuevo->anterior = 0;
     
     nuevo->dt[0]=a;                                    //colocamos los datos de la lectura en las posiciones correspondientes del arreglo
     nuevo->dt[1]=b;
     nuevo->dt[2]=c;
     nuevo->dt[3]=d;
     nuevo->dt[4]=e;
     nuevo->dt[5]=f;
     nuevo->dt[6]=g;
     nuevo->dt[7]=h;
     
     if(inicio == final){                               // colocamos el primer dato al inicio
               inicio = nuevo;
               nuevo->anterior = final;
     }else{
           while(aux->siguiente) aux = aux->siguiente;  //luego los demás los colocaremos al final de la lista
           nuevo->anterior = aux;
           aux->siguiente = nuevo;

     }
     aux=0;                                             //al final del ingreso de los datos a la lista eliminamos el puntero
     delete aux;
         
}

void equipo::valores(string e, int a, int b){   // método para ingresar los primeros 5 datos de los pjes Vct;Emp;Drt;Dif;Goles
     ostringstream convert;
     int c=0;
     Nodo *aux = inicio->siguiente;
     while(aux){
         if((aux->dt[1]).compare(0,5,e,0,5) == 0){
                if(a>b){                    // coloca el punto para ganador
                        c = atoi(aux->dt[2].c_str());
                        c = c + 3;
                        convert << c;
                        aux->dt[2] = convert.str();
                        convert.str("");
                }else if(a<b){          // coloca el punto como perdedor
                        c = atoi(aux->dt[4].c_str());
                        c++;
                        convert << c;
                        aux->dt[4] = convert.str();
                        convert.str("");
                }else if(a==b){         // coloca punto para empate
                        c = atoi(aux->dt[3].c_str());
                        c++;
                        convert << c;
                        aux->dt[3] = convert.str();
                        convert.str("");
                }
                c=0;
                convert << ((a-b) + atoi(aux->dt[5].c_str()));       // inserta el punto diferencia de goles
                aux->dt[5] = convert.str();
                convert.str("");
                convert << (a + atoi(aux->dt[6].c_str()));              
                aux->dt[6] = convert.str();        // inserta el numero de goles anotados
                convert.str("");
                cout<<"Registro hecho equipo: "<<e<<"\n";
                break;
         }
         aux = aux->siguiente;
     }
     aux=0;
     delete aux;
     cout<<"\n";
     system("PAUSE");
}



void equipo::totales(string q){                         //funcion de totalizar por pais con  datos a editados o modificados con parametro de "pais"
     Nodo *aux = inicio->siguiente;                     // puntero inicio lista para búsqueda
     ostringstream convert;                             // se crea buffer para convertir de entero a string
     int a;                                             //se crea entero para acumular puntos
     while(aux){
          if((aux->dt[1]).compare(0,5,q,0,5) == 0){     //realizamos la comparación si se encuentra el país
             a = atoi(aux->dt[2].c_str()) + atoi(aux->dt[3].c_str()) + atoi(aux->dt[5].c_str()) + atoi(aux->dt[6].c_str()) ;
             if (a<0) a=0;                              //en caso de ser negativos los valores totales los convierte en 0                                                        
             convert << a;                              //buffer asimila valor de la direccion a 
             aux->dt[7] = convert.str();                // se guarda el valor convertiro en string de a en a posición de pts de tabla
             convert.str("");                           // se limpia buffer
             break;                                     //rompemos ciclo en caso de encontrar valores
          }
          aux = aux->siguiente;                         //si no encuentra el país sigue buscando en los nodos
     }
}

void equipo::ordenamiento(Nodo *m){                     // método de ordenamiento de mayor a menor con respecto a  columna pts, con parámetro inicio=0
     orden2();                                          //realizamos método ordenamiento por goles
     int y=0,z=0;                                       // se crean variables de contadores para nodos
     while(m){                                          // se cuentan los nodos
              y++;
              m = m->siguiente;
     }
     Nodo *n;                                          // se crea un segundo puntero
     int swc=1,k=0;
     while(swc!=0){                                    // unicia ciclo ordenamiento
         swc=0;
         k++;
         m = (inicio->siguiente)->siguiente;           //busqueda se realizará con 2 nodos actual y uno previo
         n = inicio->siguiente;
              
         for(int i=0;i<((y-1)-k);i++)
         {
              if(atoi(n->dt[7].c_str()) < atoi((m->dt[7].c_str()))) // se comparan elementos con respecto a columna Pts
              {
                   n->siguiente = m->siguiente;
                   m->siguiente = n;
                   (n->anterior)->siguiente = m;
                   (n->siguiente)->anterior = n;
                   m->anterior = n->anterior;
                   n->anterior = m;
                   m = n->siguiente;
                   swc=1;
                   
              }else{
                    n = m;
                    m = m->siguiente;
              }
         }
     }
     
}

void equipo::ordenamiento2(Nodo *m){                     // método de ordenamiento de mayor a menor con respecto a  columna pts, con parámetro inicio=0
     int y=0,z=0;                                       // se crean variables de contadores para nodos
     while(m){                                          // se cuentan los nodos
              y++;
              m = m->siguiente;
     }
     Nodo *n;                                          // se crea un segundo puntero
     int swc=1,k=0;
     while(swc!=0){                                    // unicia ciclo ordenamiento
         swc=0;
         k++;
         m = (inicio->siguiente)->siguiente;           //busqueda se realizará con 2 nodos actual y uno previo
         n = inicio->siguiente;
              
         for(int i=0;i<((y-1)-k);i++)
         {
              if(atoi(n->dt[6].c_str()) < atoi((m->dt[6].c_str()))) //se realiza comparación con respecto columna Goles
              {
                   n->siguiente = m->siguiente;
                   m->siguiente = n;
                   (n->anterior)->siguiente = m;
                   (n->siguiente)->anterior = n;
                   m->anterior = n->anterior;
                   n->anterior = m;
                   m = n->siguiente;
                   swc=1;
                   
              }else{
                    n = m;
                    m = m->siguiente;
              }
         }
     }
     
}

void equipo::mostrar(){                         //método para mostrar la lista gral ordenada de pjes
     int k=1;
     Nodo *aux = inicio;
     for(int i=0;i<8;i++){
            cout << aux->dt[i] <<"\t|";         // imprime los datos del primer nodo
     }
     cout << "\n";
     cout <<"-------------------------------------------------------------------------\n";
     aux = aux->siguiente;                      // posiciona puntero desde la segunda ubicación                                          
     while(aux){
            cout << k++ <<"\t|";
            for(int i=1;i<8;i++){
                    cout << aux->dt[i] <<"\t|"; //empieza a imprimir los datos de todos los nodos empezando del 2°
            }
            cout << "\n";
            aux = aux->siguiente;
     }
     aux=0;
     delete aux;
     cout<<"\n\n\n";
     system("PAUSE");
}

void equipo::grupos(string gr){           //método de impresión ordenada por grupos
     string p [] = {"Brasil","Croacia","Mexico","Camerun","Espana","Holanda","Chile","Australia","Colombia","Grecia","C._de_Marfil","Japon.","Uruguay","Costa_Rica","Inglaterra","Italia","Suiza","Ecuador","Francia","Honduras","Argentina","Bosnia","Iran.","Nigeria","Alemania","Portugal","Ghana","Estados_Unidos","Belgica","Arjelia","Rusia","Corea_del_Sur"};
     string g[] = {"A","B","C","D","E","F","G","H"};          
     bool z = true;
     int i = 0;
     while(z && i<8){
              if(0 != gr.compare(g[i])) i++;
              else z = false;
     }
     if(!z){
            Nodo *aux = inicio->siguiente; //puntero al segundo nodo
            Nodo *pete = inicio;
            int c = 0;
            cout<<"********Grupo "<<gr<<"********\n";   //imprime titulo grupo a
            for(int r=0;r<8;r++){
                    cout << pete->dt[r] <<"\t|";       //imprime detalles de pjes
            }
            cout<<"\n";
            cout <<"-------------------------------------------------------------------------\n";
            while(aux){                               //recorre todos los nodos de la lista para su impresión
                for(int j=(i*4);j<(4+(i*4));j++){
                    if((aux->dt[1]).compare(0,5,p[j],0,5) == 0){  // compara los strings para revisar similitudes 
                          cout<<c+1<<"\t|";                                                  
                          for(int i=1;i<8;i++) cout<<aux->dt[i]<<"\t|";                      // imprime los pjes de todos los paises
                          c++;
                          cout<<"\n";
                    }
                }
                if(c==4) break;        //en caso de encontrar los 4 paises rompe el ciclo de busqueda
                else aux = aux->siguiente;
            }
            aux = 0;
            delete aux;
     }else cout<<"Grupo no valido\n";
     cout<<"\n\n\n";
     system("PAUSE");
}

void equipo::escritura(){
     ofstream fout("Equipos.csv"); //abrir el fichero el cual se leyó
     Nodo *aux = inicio;
     char filename[20];            //se crea variable char para cada palabra a exrtaer
     while(aux){       // se comienza a recorrer el arreglo
          for(int i=0;i<7;i++){
                filename[aux->dt[i].size()]=0;   
                memcpy(filename,aux->dt[i].c_str(),aux->dt[i].size());    //transforma de string a char cada palabra extraida de los datos de los nodos       
                fout << filename<<";"; //escribe datos archivo .csv
                if(i==6){              //escribe el último dato de columna sin ; para la proxima lectura
                         filename[aux->dt[i+1].size()]=0;
                         memcpy(filename,aux->dt[i+1].c_str(),aux->dt[i+1].size());           
                         fout << filename; //escribe datos archivo .csv 
                }
          }
          fout << endl; //salto del linea en ecritura
          aux = aux->siguiente;
     }
     fout.close();             //cierra archivo
     cout << "Datos grabados en: Equipos.csv" << endl;
     aux=0;  //puntero se deja en nil
     delete aux;              //libera espacio  
                
}




