#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <locale>
#include <sstream>
#include "equipo.h"
#include "partidos.h"

using namespace std;

int main(int argc, char *argv[]){
    
    equipo *a1 = new equipo();   //se crea constructor de equipo
    partidos *a2 = new partidos();    //se crea constructor partido
    
    bool q;  //se crean boleanos para validacion de lectura
    bool o;
    
        
    q = a1->lectura();  //se validan las lecturas de los archivos
    o = a2->lectura();
        
    if(!(q && o)) cout << "Archivos Inexistentes\n";
        
    while(q && o){
        a2->portada(); //se llama a partidos método portada
        string a;
        do{            // se pide interacción a usuario para solicitud de opciones
            cout << "ingrese la opcion a revisar: \n";
            cin >> a;
            if(a=="1" || a=="2" || a=="3" || a=="4" || a=="5" || a=="6" || a=="0") q=false;
            else cout <<"Entrada no valida, intente nuevamente \n";
        }while(q);
        q = true;
        a1->orden();  //llama a equipo método redefinido ordenamiento
        cout<<"\n\n\n";
        switch (atoi(a.c_str())){      // se transforma variable string para uso del case en int
               case 1: {               // primera instancia para caso 1
                            cout<<"\n\n\n";
                            string b,a;
                            int y,z;
                            cout << "Ingrese los equipos que jugaron con sus resultados en el siguiente orden con espacio\n";
                            cout << "Ejemplo: 'equipo1' 'goles equipo1' 'equipo2' 'goles equipo2'\n";
                            cin >>a>>y>>b>>z;
                            q = a2->registra(a,b,y,z);  //se realiza el registro de un partido validado
                            if(q){                      // si el partido no se ha desarrollado continua
                                  a1->valores(a,y,z);   // guarda los resultados en tabla
                                  a1->valores(b,z,y);
                                  a1->totales(a);       //calcula los totales del equipo A jugado
                                  a1->totales(b);       //calcula los totales del equipo B jugado
                                  a1->orden();          //ordena tabla
                                  
                            }else{
                                  cout<<"no se procesó registro\n"; // si no se encuentra registrado el partido no lo registra
                                  q = true; 
                            }
                       
                       }
               break;
               
               case 2: cout<<"\n\n\n";
                       a1->mostrar(); //muestra tabla de posiciones ordenada
               break;
               
               case 3: {
                       cout<<"\n\n\n";
                       string a;
                       cout << "Ingrese el Grupo que desea revisar 'A','B','C','D','E','F','G','H':  ";
                       cin >> a ;
                       cout<<"\n";
                       a1->grupos(a);  //muestra tabla de posicion a grupo deseado
                       }
               break;
               
               case 4: cout<<"\n\n\n";
                       a2->realizados();        // muestra partidos realizados
               break;
               
               case 5: {cout<<"\n\n\n";
                       cout<<"Ingrese resultado de partido a revisar:\n";
                       cout<<"Ejemplo: China Colombia\n";
                       string y,z;
                       cin >>y>>z;
                       a2->rslt(y,z);        //busca resultados de un partido en específico
                       cout<<"\n\n\n";
                       }
               break;
               
               case 6: {    cout<<"\n\n\n";
                            string b;a;
                            int y,z;
                            cout << "Ingrese los equipos que jugaron a MODIFICAR con sus resultados en el siguiente orden con espacio\n";
                            cout << "Ejemplo: 'equipo1' 'goles equipo1' 'equipo2' 'goles equipo2'\n";
                            cin >>a>>y>>b>>z;
                            q = a2->modifica(a,b,y,z);  //para modificar pide los datos para ser validados
                            if(q){
                                  a1->valores(a,y,z);   //al estar el equipo registrado ingresa valores a tabla
                                  a1->valores(b,z,y);
                                  a1->totales(a);       //totaliza datos de los equipos modificados
                                  a1->totales(b);
                                  a1->orden();          // ordena tabla de mayor a menor
                                  
                            }else{
                                  cout<<"no se procesó registro\n";     //en caso de no estar equipo registrado no modificará datos
                                  q = true;
                            }
                       
                       }
               break;
               
               case 0: {
                        q=false;  // opcion de salida del programa
                        a1->escritura();    //hace el método para la escritura del archivo Equipo.csv
                        cout<<"primera escritura\n";
                        a2->escritura();            //hace el método de escritura para el archivo Partidos.csv
                        cout<<"Segunda escritura\n";        
                       }
               
               default:break;
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
