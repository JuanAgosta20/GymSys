#ifndef RUTINA_H_INCLUDED
#define RUTINA_H_INCLUDED

bool Rutina::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_RUTINAS,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Rutina)* pos,0);
    if(fwrite(this,sizeof(Rutina),1,p))
    {
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

bool Rutina::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_RUTINAS,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Rutina)* pos,0);
    fread(this,sizeof(Rutina),1,p);
    fclose(p);
    return true;
}

bool Rutina::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_RUTINAS,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Rutina),1,p);
    fclose(p);
    return true;
}

///____________________________________________________________________///



void cargarRutina()
{
    system("cls");
    Rutina nueva;
    char name[30];
    while(1){
    cout<<"Ingrese el nombre de la rutina: ";
    cin.ignore();
    cin.getline(name,30,'\n');
    nueva.setNombre(name);
    if(!(nueva.chequearRutina())){
    nueva.setId();
    if(nueva.escribirEnDisco())cout<<"Rutina Guardada"<<endl;
    system("pause");
    return;
    }
    cout<<"El nombre de la rutina ya existe."<<endl;
    }
}


///____________________________________________________________________///



bool Rutina::chequearRutina()
{
    Rutina aux;
    for(int i=0;i<cantReg_Rutina();i++)
    {
        if(aux.leerDeDisco(i)){
        if(0==strcmp(aux.getNombre(),nombre))
        {
            return true;
        }
        }
        else return false;
    }
    return false;
}


///____________________________________________________________________///



void mostrarRutina_nombre(char *name)
{
    system("cls");
    Rutina reg;
    for(int i=0;i<cantReg_Rutina();i++)
    {
        reg.leerDeDisco(i);
        if(0==strcmp(name,reg.getNombre()) && reg.getEstado())
        {
            cout<<"Nombre de rutina: "<<reg.getNombre()<<endl;
            cout<<"ID: "<<reg.getId()<<endl;
            system("pause");
            return;
        }
    }
    cout<<"La rutina no existe."<<endl;
    system("pause");
}


///____________________________________________________________________///


void mostrarRutina_ID(int id)
{
    Rutina reg;
    reg.leerDeDisco(id-1);
        if(reg.getEstado())
        {
            cout<<"Nombre de rutina: "<<reg.getNombre()<<endl;
            cout<<"ID: "<<reg.getId()<<endl;
            return;
        }
    cout<<"La rutina no existe."<<endl;
    system("pause");
}


///____________________________________________________________________///



int cantReg_Rutina()
{
    FILE *p;
    int y;
    p=fopen(ARCH_RUTINAS, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Rutina);
    fclose(p);
    return y;

}


///____________________________________________________________________///

bool chequearRutina(char *nombreRutina)
{
    Rutina rutina_reg;
    for(int i=0; i<cantReg_Rutina();i++){
    rutina_reg.leerDeDisco(i);
    if(0==strcmpi(nombreRutina,rutina_reg.getNombre()))
    {
        return true;
    }
    }
    return false;
}


///____________________________________________________________________///

void eliminarRutina()
{
    system("cls");
    int id;
    Rutina aux;
    cout<<"Ingrese el ID de la Rutina:";
    cin>>id;
    while(cin.fail() || id-1>cantReg_Rutina()-1)
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el ID de la Rutina:";
        cin>>id;
    }
    if(id<=0){
        cout<<"ID inválido."<<endl;
        system("pause");
        return;
    }
    aux.leerDeDisco(id-1);
    aux.setEstado();
    if(aux.modificarEnDisco(id-1))
       {
           cout<<"Rutina Eliminada."<<endl;
           system("pause");
           return;
       }
}


#endif // RUTINA_H_INCLUDED
