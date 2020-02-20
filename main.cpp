#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <clocale>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
#include "Funciones Globales.h"
#include "Clases.h"
#include "Usuarios.h"
#include "Fecha.h"
#include "Dieta.h"
#include "Clientes.h"
#include "Medidas.h"
#include "Ejercicios.h"
#include "Rutina.h"
#include "Ejercicios_x_Rutina.h"
#include "Pagos.h"
#include "Configuracion.h"
#include "Reportes.h"
#include "Domicilio.h"
#include "Cupo_x_Clase.h"
#include "Rutina_x_Cliente.h"




int main()
{
    SetConsoleTitle("GymSys");
    setlocale(LC_ALL, "spanish");
    //system("color FC");
    //escribir en la cmd "color z" para ver todos los colores.
    //system("mode con: cols=140 lines=40");
    //Barra de Carga
    int segundos=2;
    for(int i=0; i<=21; i++)
        cout <<endl;
    cout << "\t\t\t\t  GYMSYS: CARGANDO..."<<endl;

    for(int j=0; j<=79; j++)
    {
        cout << "_";
    }
    cout<<endl;
    for(int i=0; i<=79; i++)
    {
        cout<<char(45);
        Sleep(segundos*1000/80);
    }
    //
    int opc;
    system("cls");
    cout<<endl<<"\t\t"<<" GYMSYS"<<endl;
    //cout<<endl<<"\t\tBIENVENIDO"<<endl;
    cout<<endl<<endl<<endl<<endl;
    system("pause");
    while(!(cantReg_Usuarios()))
    {
        crear_usuarioAdm();
    }
    while(!(ingresar_usuario()))
    {

    }
    while(1){
    system("cls");
    cout<<"__________________________________"<<endl;
    cout<<"\tMENÚ PRINCIPAL"<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"1) Clientes."<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"2) Rutinas ,Ejercicios y Dietas."<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"3) Pagos."<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"4) Clases."<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"5) Reportes."<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"6) Configuracion."<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"0) Salir."<<endl;
    cin>>opc;
    switch(opc)
    {
        case 1: menuClientes();
            break;
        case 2: menuRyEyD();
            break;
        case 3: menuPagos();
            break;
        case 4: menuClases();
            break;
        case 5: menuReportes();
            break;
        case 6: menuConfiguracion();
            break;
        case 0: return 0;
            break;
        default: cout<<endl<<"La opcion ingresada no es válida."<<endl;
        system("pause");
    }
    }

    return 0;
}
