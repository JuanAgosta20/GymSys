#ifndef EJERCICIOS_X_RUTINA_H_INCLUDED
#define EJERCICIOS_X_RUTINA_H_INCLUDED


bool Ejercicios_x_Rutina::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_EjX_Rutina,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Ejercicios_x_Rutina)* pos,0);
    fwrite(this,sizeof(Ejercicios_x_Rutina),1,p);
    fclose(p);
    return true;
}

bool Ejercicios_x_Rutina::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_EjX_Rutina,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Ejercicios_x_Rutina)* pos,0);
    fread(this,sizeof(Ejercicios_x_Rutina),1,p);
    fclose(p);
    return true;
}

bool Ejercicios_x_Rutina::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_EjX_Rutina,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Ejercicios_x_Rutina),1,p);
    fclose(p);
    return true;
}



///____________________________________________________________________///



void cargarEj_x_Rutina()
{
    system("cls");
    Ejercicios_x_Rutina reg;
    int a,idRutina, idEjer;
    cout<<"Ingrese la cantidad de ejercicios a agregar: ";
    cin>>a;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese la cantidad en numeros."<<endl;
        system("pause");
        return;
    }
    if(a<=0)
    {
        cout<<"El número debe ser positivo."<<endl;
        system("pause");
        return;
    }
    bool paso=false;
    do{
    if(paso)cout<<"La rutina no existe."<<endl;
    cout<<"Ingrese el ID de la Rutina: ";
    cin>>idRutina;
    paso=true;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el ID en numeros."<<endl;
        system("pause");
        return;
    }
    }while(!(chequearIdRutina(idRutina)));
    reg.setIdRutina(idRutina);
    paso=false;
        bool paso2=false;
        for(int i=0;i<a;i++){
            do{
                if(paso2)cout<<"El ejercicio no existe."<<endl;
                cout<<"Ingrese el ID del ejercicio:";
                cin>>idEjer;
                paso2=true;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(200,'\n');
                    cout<<"Error de ingreso."<<endl;
                    system("pause");
                    return;
                }
            }while(!(chequearIdEjercico(idEjer)));
            reg.setIdEjercicio(idEjer);
            paso2=false;
            if(reg.escribirEnDisco())
                {
                    cout<<"Ejercicio Guardado en la Rutina."<<endl;
                    system("pause");

                }
    }
}



///____________________________________________________________________///



bool chequearIdRutina(int id)
{
    Rutina aux;
    if(id> cantReg_Rutina() || id==0)return false;
    aux.leerDeDisco(id-1);
    if(aux.getEstado())return true;
    return false;
}



///____________________________________________________________________///



bool chequearIdEjercico(int idEj)
{
    Ejercicios aux;
    if(idEj-1>cantReg_Ejercicios()-1 || idEj==0)return false;
    aux.leerDeDisco(idEj-1);
    if(aux.getEstado())return true;
    return false;
}

///____________________________________________________________________///


void mostrarEjxIdRutina()

{
    system("cls");
    int idRut;
    cout<<"Ingrese el ID de la rutina: ";
    cin>>idRut;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el ID en numeros."<<endl;
        system("pause");
        return;
    }
    Ejercicios_x_Rutina aux;
    Rutina reg;
    Ejercicios ejer;
    reg.leerDeDisco(idRut-1);
    cout<<endl<<reg.getNombre()<<endl;
    cout<<"----------------------------"<<endl;
    for(int i=0; i<cantReg_EjxRut();i++)
    {
        aux.leerDeDisco(i);
        if(aux.getIdRutina() == idRut)
        {
            reg.leerDeDisco(aux.getIdRutina()-1);
            if(reg.getEstado())
            {
                ejer.leerDeDisco(aux.getIdEjercicio()-1);
                ejer.mostrar();
                cout<<endl;
            }
        }
    }
    system("pause");
}




///____________________________________________________________________///



int cantReg_EjxRut()
{
    FILE *p;
    int y;
    p=fopen(ARCH_EjX_Rutina, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Ejercicios_x_Rutina);
    fclose(p);
    return y;

}


#endif // EJERCICIOS_X_RUTINA_H_INCLUDED
