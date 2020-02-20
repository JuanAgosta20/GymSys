#ifndef EJERCICIOS_H_INCLUDED
#define EJERCICIOS_H_INCLUDED

void cargarEjercicio()
{
    system("cls");
    Ejercicios nuevo;
    char muscle[20], name[25];
    cin.ignore();
    cout<<"Ingrese el nombre del ejercicio: ";
    cin.getline(name,25,'\n');
    if(strlen(name)==0)
    {
        cout<<"El nombre no puede ser un campo vacío."<<endl;
        system("pause");
        return;
    }
    nuevo.setNombreEjer(name);
    cout<<"Ingrese el nombre del músculo: ";
    cin.getline(muscle,20,'\n');
    if(strlen(muscle)==0)
    {
        cout<<"El nombre del músculo no puede ser un campo vacío."<<endl;
        system("pause");
        return;
    }
    nuevo.setMusculo(muscle);
    if(nuevo.escribirEnDisco())cout<<"Ejercicio guardado."<<endl;
    else cout<<"Error al guardar."<<endl;
    system("pause");
}


///____________________________________________________________________///



void mostrarEjercicio()
{
    system("cls");
    Ejercicios reg;
    char name[25];
    cout<<"Ingrese el nombre del ejercicio: ";
    cin.ignore();
    cin.getline(name,25,'\n');
    if(strlen(name)==0)
    {
        cout<<"El nombre del ejercicio no puede ser un campo vacío."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Ejercicios();i++)
    {
        reg.leerDeDisco(i);
        if(0==strcmpi(name,reg.getNombreEjer()))
        {
            cout<<"ID: "<<reg.getId()<<endl;
            cout<<"Nombre de ejercicio: "<<reg.getNombreEjer()<<endl;
            cout<<"Musculo: "<<reg.getMusculo()<<endl;
            system("pause");
            return;
        }
    }
    cout<<"El ejercicio no existe."<<endl;
    system("pause");
}


///____________________________________________________________________///



bool Ejercicios::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_EJERCICIOS,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Ejercicios)* pos,0);
    fwrite(this,sizeof(Ejercicios),1,p);
    fclose(p);
    return true;
}

bool Ejercicios::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_EJERCICIOS,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Ejercicios)* pos,0);
    fread(this,sizeof(Ejercicios),1,p);
    fclose(p);
    return true;
}

bool Ejercicios::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_EJERCICIOS,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Ejercicios),1,p);
    fclose(p);
    return true;
}


///____________________________________________________________________///

void Ejercicios::mostrar()
{
    cout<<"Nombre del Ejercicio: "<<nombreEjer<<endl;
    cout<<"Musculo: "<<musculo<<endl;
}


int cantReg_Ejercicios()
{
    FILE *p;
    int y;
    p=fopen(ARCH_EJERCICIOS, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Ejercicios);
    fclose(p);
    return y;
}

///____________________________________________________________________///

void eliminarEjercicio()
{
    system("cls");
    int id;
    Ejercicios aux;
    cout<<"Ingrese el ID del ejercicio: ";
    cin>>id;
    while(cin.fail() || id>cantReg_Ejercicios()-1)
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el ID del Ejercicio:";
        cin>>id;
    }
    if(id<=0)
    {
        cout<<"ID inválido."<<endl;
        system("pause");
        return;
    }
    aux.leerDeDisco(id-1);
    aux.setEstado();
    if(aux.modificarEnDisco(id-1))
       {
           cout<<"Ejercicio Eliminado."<<endl;
           system("pause");
           return;
       }
}
#endif // EJERCICIOS_H_INCLUDED
