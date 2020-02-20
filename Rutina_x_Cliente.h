#ifndef RUTINA_X_CLIENTE_H_INCLUDED
#define RUTINA_X_CLIENTE_H_INCLUDED


bool Rutina_x_Cliente::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_Rut_x_Cli,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Rutina_x_Cliente)* pos,0);
    fwrite(this,sizeof(Rutina_x_Cliente),1,p);
    fclose(p);
    return true;
}

bool Rutina_x_Cliente::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_Rut_x_Cli,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Rutina_x_Cliente)* pos,0);
    fread(this,sizeof(Rutina_x_Cliente),1,p);
    fclose(p);
    return true;
}

bool Rutina_x_Cliente::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_Rut_x_Cli,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Rutina_x_Cliente),1,p);
    fclose(p);
    return true;
}



///____________________________________________________________________///



void cargarRutina_x_Cliente()
{
    system("cls");
    Rutina_x_Cliente reg;
    int idRutina;
    char dni[11];
    do{
    cout<<"Ingrese el ID de Rutina: ";
    cin>>idRutina;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el ID en numeros."<<endl;
        system("pause");
        return;
    }
    reg.setIdRutina(idRutina);
    }while(!(chequearIdRutina(reg.getIdRutina())));
        do{
            cin.ignore();
            cout<<"Ingrese el DNI del cliente:";
            cin.getline(dni,11,'\n');
            reg.setDni(dni);
        }while(!(buscarDNI_Cliente(reg.getDni())));
        if(reg.escribirEnDisco())
                {
                    cout<<"Rutina Guardada en el Cliente."<<endl;
                    system("pause");

                }
}



///____________________________________________________________________///


int cantReg_Rutina_x_Cliente()
{
    FILE *p;
    int y;
    p=fopen(ARCH_Rut_x_Cli, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Rutina_x_Cliente);
    fclose(p);
    return y;
}



void mostrarRutinasxCliente(char *dni)
{
    Rutina_x_Cliente aux;
    for(int i=0; i<cantReg_Rutina_x_Cliente(); i++)
    {
        aux.leerDeDisco(i);
        if(0== strcmp(dni,aux.getDni()) && aux.getEstado())
        {
            mostrarRutina_ID(aux.getIdRutina());

        }
    }
}

#endif // RUTINA_X_CLIENTE_H_INCLUDED
