#ifndef CUPO_X_CLASE_H_INCLUDED
#define CUPO_X_CLASE_H_INCLUDED

bool Cupo_x_Clase::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_Cupo_Clase,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Cupo_x_Clase),1,p);
    fclose(p);
    return true;
}

bool Cupo_x_Clase::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_Cupo_Clase,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Cupo_x_Clase)* pos,0);
    fwrite(this,sizeof(Cupo_x_Clase),1,p);
    fclose(p);
    return true;
}

bool Cupo_x_Clase::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_Cupo_Clase,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Cupo_x_Clase)* pos,0);
    fread(this,sizeof(Cupo_x_Clase),1,p);
    fclose(p);
    return true;
}


///____________________________________________________________________///



int cantReg_Cupo_x_Clases()
{
    FILE *p;
    int y;
    p=fopen(ARCH_Cupo_Clase, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Cupo_x_Clase);
    fclose(p);
    return y;

}

///____________________________________________________________________///

void mostrarClases_x_Cliente(char *dni)
{
    Cupo_x_Clase aux;
    Clases reg;
    cout<<"CLASES: "<<endl;
    for(int i=0; i<cantReg_Cupo_x_Clases(); i++)
    {
        aux.leerDeDisco(i);
        if(strcmp(aux.getDni(),dni)==0 && aux.getEstado())
        {
            reg.leerDeDisco(aux.getIdClase()-1);
            cout<<"Nombre: "<<reg.getNombreClase()<<"  ID:"<<reg.getId()<<endl;
        }
    }
}




#endif // CUPO_X_CLASE_H_INCLUDED
