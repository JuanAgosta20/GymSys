#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
//Prototipos
Domicilio cargarDomicilio();
bool devuelve_ClientexDNI(const char*, Clientes&);

///____________________________________________________________________///



void menuClientes()
{
    int opc;
    while(1)
    {
        system("cls");
        cout<<"__________________________________"<<endl;
        cout<<"   MENÚ DE CLIENTES"<<endl;
        cout<<"__________________________________"<<endl<<endl;
        cout<<"1) Nuevo Cliente."<<endl;
        cout<<"2) Modificar Cliente."<<endl;
        cout<<"3) Eliminar Cliente."<<endl;
        cout<<"__________________________________"<<endl;
        cout<<"4) Agregar Rutina."<<endl;
        cout<<"__________________________________"<<endl;
        cout<<"5) Cargar Medidas."<<endl;
        cout<<"__________________________________"<<endl;
        cout<<"6) Exportar Clientes a Excel."<<endl;
        cout<<"__________________________________"<<endl<<endl;
        cout<<"0) Volver al Menu Anterior."<<endl;
        cin>>opc;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(200,'\n');
            cout<<"Ingrese la opción en numeros."<<endl;
            cin>>opc;
        }
        switch(opc)
        {
            case 1: cargarCliente();
                break;
            case 2: modificarCliente();
                break;
            case 3: eliminarCliente();
                break;
            case 4: cargarRutina_x_Cliente();
                break;
            case 5: cargarMedidas();
                break;
            case 6: exportarClientesExcel();
                break;
            case 0: return;
                break;
            default: cout<<endl<<"La opción ingresada es inválida."<<endl;
            system("pause");
        }
    }
}


///____________________________________________________________________///



void cargarCliente()
{
    system("cls");
    Clientes nuevo;
    Fecha aux, act;
    char nombreDieta[30], documento[11], name[25],surname[30], factor[3], obra[30],mail[50], tel[20], sex[2];

    cout<<"Ingrese el número de documento: ";
    cin.ignore();
    cin.getline(documento,11,'\n');
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"EL DOCUMENTO DEBE TENER COMO MÁXIMO 10 CARACTERES."<<endl;
        system("pause");
        return;
    }
    if(strlen(documento)==0)
    {
        cout<<"EL DOCUMENTO NO PUEDE SER UN CAMPO VACIO."<<endl;
        system("pause");
        return;
    }
    if(!buscarDNI_Cliente(documento))
    {nuevo.setDni(documento);}
    else
    {
        cout<<"El DNI ya existe."<<endl;
        system("pause");
        return;
    }
    cout<<"Ingrese el apellido: ";
    cin.getline(surname,30,'\n');
    if(strlen(surname)==0)
    {
        cout<<"EL APELLIDO NO PUEDE SER UN CAMPO VACIO."<<endl;
        system("pause");
        return;
    }
    nuevo.setApellido(surname);

    cout<<"Ingrese el nombre: ";
    cin.getline(name,25,'\n');
    if(strlen(name)==0)
    {
        cout<<"EL NOMBRE NO PUEDE SER UN CAMPO VACIO."<<endl;
        system("pause");
        return;
    }
    nuevo.setNombre(name);

    cout<<"Ingrese el sexo(M,F,X): ";
    cin.getline(sex,2,'\n');
    while(sex[0]!='f' && sex[0]!='F' && sex[0]!='m' && sex[0]!='M' && sex[0]!='x' && sex[0]!='X')
    {
      cout<<"Ingreso incorrecto."<<endl;
      cout<<"Ingrese el sexo(1:M,2:F,3:X): ";
      cin.getline(sex,2,'\n');
    }
    nuevo.setSexo(sex);

    cout<<"DOMICILIO: "<<endl;
    nuevo.setDomicilio(cargarDomicilio());

    cout<<"Ingrese Obra Social: ";
    cin.getline(obra,30,'\n');
    nuevo.setObraSocial(obra);

    cout<<"Ingrese el factor sanguineo: ";
    cin.getline(factor,3,'\n');
    while(strlen(factor)==0)
    {
        cout<<"EL FACTOR SANGUINEO NO PUEDE SER UN CAMPO VACIO."<<endl;
        cout<<"Ingrese el factor sanguineo: ";
        cin.getline(factor,3,'\n');
    }
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"El factor no puede tener mas de 2 caracteres."<<endl;
        cout<<"Ingrese el factor sanguineo: ";
        cin.getline(factor,3,'\n');
        while(strlen(factor)==0)
        {
            cout<<"EL FACTOR SANGUINEO NO PUEDE SER UN CAMPO VACIO."<<endl;
            cout<<"Ingrese el factor sanguineo: ";
            cin.getline(factor,3,'\n');
        }
    }
    nuevo.setFactor(factor);

    cout<<"Ingrese el número de teléfono: ";
    cin.getline(tel,20,'\n');
    while(strlen(tel)==0)
    {
      cout<<"El teléfono no puede ser un campo vacio."<<endl;
      cout<<"Ingrese el número de teléfono: ";
      cin.getline(tel,20,'\n');
    }
    nuevo.setTelefono(tel);

    cout<<"Ingrese el mail: ";
    cin.getline(mail,50,'\n');
    nuevo.setEmail(mail);

    act.fechaActual();
    nuevo.cargarFechaInsc(act);

    cout<<"Ingrese la fecha de nacimiento: "<<endl;
    while( (!aux.setFecha()) || (!(aux.chequearEdad())) )
        {
              cout<<"Ingrese la fecha de nacimiento: "<<endl;
        }
    nuevo.cargarFechaNac(aux);

    cout<<"Ingrese el nombre de la dieta: ";
    cin.ignore();
    cin.getline(nombreDieta,30,'\n');
    if(strlen(nombreDieta)!=0){
    while((!chequearDieta(nombreDieta)) && strlen(nombreDieta)!=0)
        {
          cout<<"El nombre de la dieta no existe."<<endl;
          cout<<"Ingrese el nombre de la dieta: ";
          cin.getline(nombreDieta,30,'\n');

        }
    }
    nuevo.setClienteDieta(nombreDieta);

  if(nuevo.escribirEnDisco())cout<<endl<<"Cliente cargado."<<endl;
      system("pause");
      return;
}



///____________________________________________________________________///



void modificarCliente()
{
    char documento[11];
    Clientes aux;
    Fecha auxFecha;
    char documento2[11], name[25],surname[30], sex[2], nombreDieta[30];
    int opc;
    system("cls");
    cout<<"Ingrese el DNI del cliente que desea modificar: "<<endl;
    cin.ignore();
    cin.getline(documento,11,'\n');
    for(int i=0; i<cantReg_Clientes();i++)
    {
        aux.leerDeDisco(i);
        if(0==strcmp(aux.getDni(),documento))
        {
            while(1){
            system("cls");
            cout<<"Que desea modificar: "<<endl;
            cout<<"1)Nombre."<<endl;
            cout<<"2)Apellido."<<endl;
            cout<<"3)DNI."<<endl;
            cout<<"4)Sexo."<<endl;
            cout<<"5)Fecha de nacimiento."<<endl;
            cout<<"6)Dieta."<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"0)Volver al menú anterior."<<endl;
            cin>>opc;
            system("cls");
            cin.ignore();
            switch(opc)
            {
                case 1: cout<<"Ingrese el nuevo nombre: ";
                        cin.getline(name,25,'\n');
                        while(strlen(name)==0)
                            {
                                cout<<"EL NOMBRE NO PUEDE SER UN CAMPO VACIO."<<endl;
                                system("pause");
                                cout<<"Ingrese el nuevo nombre: ";
                                cin.getline(name,25,'\n');
                            }
                        aux.setNombre(name);
                        if(aux.modificarEnDisco(i))cout<<"Cliente Modificado."<<endl;
                        system("pause");
                        break;

                case 2: cout<<"Ingrese el nuevo apellido: ";
                        cin.getline(surname,30,'\n');
                        aux.setApellido(surname);
                        while(strlen(surname)==0)
                            {
                                cout<<"EL APELLIDO NO PUEDE SER UN CAMPO VACIO."<<endl;
                                system("pause");
                                cout<<"Ingrese el nuevo nombre: ";
                                cin.getline(name,25,'\n');
                                return;
                            }
                        if(aux.modificarEnDisco(i))cout<<"Cliente Modificado."<<endl;
                        system("pause");
                        break;

                case 3: cout<<"Ingrese el nuevo DNI: ";
                        cin.getline(documento2,11,'\n');
                            while(strlen(documento2)==0)
                                {
                                    cout<<"EL DOCUMENTO NO PUEDE SER UN CAMPO VACIO."<<endl;
                                    system("pause");
                                    cout<<"Ingrese el nuevo DNI: ";
                                    cin.getline(documento2,11,'\n');
                                }
                        aux.setDni(documento2);
                        if(aux.modificarEnDisco(i))cout<<"Cliente Modificado."<<endl;
                        system("pause");
                        break;

                case 4: cout<<"Ingrese el nuevo sexo(M,F,X): ";
                        cin.getline(sex,2,'\n');
                        while(sex[0]!='n' && sex[0]!='N' && sex[0]!='m' && sex[0]!='M' && sex[0]!='x' && sex[0]!='X')
                        {
                          cout<<"Ingreso incorrecto."<<endl;
                          cout<<"Ingrese el sexo(1:M,2:F,3:X): ";
                          cin.getline(sex,2,'\n');
                        }
                        aux.setSexo(sex);
                        if(aux.modificarEnDisco(i))cout<<"Cliente Modificado."<<endl;
                        system("pause");
                        break;

                case 5: cout<<"Ingrese la fecha de nacimiento: "<<endl;
                        while(!(auxFecha.setFecha()))
                            {
                                  cout<<"Ingrese la fecha de nacimiento: "<<endl;
                            }
                        aux.cargarFechaNac(auxFecha);
                        if(aux.modificarEnDisco(i))cout<<"Cliente Modificado."<<endl;
                        system("pause");
                        break;

                case 6: cout<<"Ingrese el nombre de la dieta: ";
                        //cin.ignore();
                        cin.getline(nombreDieta,30,'\n');
                        if(strlen(nombreDieta)!=0){
                        while(!chequearDieta(nombreDieta))
                            {
                              cout<<"El nombre de la dieta no existe."<<endl;
                              cout<<"Ingrese el nombre de la dieta: ";
                              cin.getline(nombreDieta,30,'\n');

                            }
                        }
                        aux.setClienteDieta(nombreDieta);
                        if(aux.modificarEnDisco(i))cout<<"Cliente Modificado."<<endl;
                        system("pause");
                        break;

                case 0: return;
                        break;
                default: cout<<"Opcion invalida."<<endl;
                system("pause");
            }
            }
        }
    }
    cout<<"El DNI ingresado no existe."<<endl;
    system("pause");
}


///____________________________________________________________________///



void eliminarCliente()
{
    char documento[11];
    Clientes aux;
    system("cls");
    cout<<"Ingrese el DNI del cliente que desea eliminar: "<<endl;
    cin.ignore();
    cin.getline(documento,11,'\n');
    if(strlen(documento)==0)
    {
        cout<<"El documento no puede ser un campo vacío."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Clientes();i++)
    {
        aux.leerDeDisco(i);
        if(0==strcmp(aux.getDni(),documento))
        {
            aux.setEstado();
            if(aux.modificarEnDisco(i))
            {
                cout<<"Cliente eliminado"<<endl;
                system("pause");
                return;
            }
        }
}
cout<<"El DNI ingresado no existe."<<endl;
system("pause");
}


///____________________________________________________________________///



int cantReg_Clientes()
{
    FILE *p;
    int y;
    p=fopen(ARCH_CLIENTES, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Clientes);
    fclose(p);
    return y;
}


///____________________________________________________________________///



void listarCliente_DNI()
{
    system("cls");
    Clientes aux;
    char documento[11];
    cout<<"Ingrese el DNI del cliente."<<endl;
    cin.ignore();
    cin.getline(documento,11,'\n');
    if(strlen(documento)==0)
    {
        cout<<"EL DOCUMENTO NO PUEDE SER UN CAMPO VACIO."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Clientes();i++)
    {
        aux.leerDeDisco(i);
        if(0==strcmp(aux.getDni(),documento) && aux.getEstado()){
            aux.mostrar();
            system("pause");
            return;
        }
    }
    cout<<"El DNI ingresado no existe."<<endl;
    system("pause");
}


///____________________________________________________________________///



void Clientes::mostrar()
{
    Rutina_x_Cliente aux;
    Rutina reg;
    cout<<"ID: "<<id<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Apellido y Nombres: "<<apellido<<", "<<nombre<<endl;
    cout<<"Teléfono: "<<telefono<<endl;
    cout<<"Mail: "<<email<<endl;
    cout<<"Fecha de nacimiento: "<<fechaNac.getDia()<<"/"<<fechaNac.getMes()<<"/"<<fechaNac.getAnio()<<endl;
    cout<<"Fecha de inscripción: "<<fechaInscripcion.getDia()<<"/"<<fechaInscripcion.getMes()<<"/"<<fechaInscripcion.getAnio()<<endl;
    cout<<"Domicilio: "<<domicilioActual.getCalle()<<", "<<domicilioActual.getNCalle()<<", "<<domicilioActual.getDepto()<<endl;
    cout<<"Pais: "<<domicilioActual.getLocalidad()<<","<<domicilioActual.getProvincia()<<", "<<domicilioActual.getPais()<<endl;
    cout<<"Factor Sanguineo: "<<factorSanguineo<<endl;
    cout<<"Obra Social: "<<obraSocial<<endl;
    cout<<"Dieta: "<<dietaActual<<endl;
    cout<<"Rutinas: ";
    for(int i=0; i<cantReg_Rutina_x_Cliente(); i++)
    {
        aux.leerDeDisco(i);
        if(strcmp(dni,aux.getDni()) == 0)
        {
            reg.leerDeDisco(aux.getIdRutina()-1);
            if(reg.getEstado()) cout<<reg.getNombre()<<endl;
        }
    }
}



///____________________________________________________________________///



bool Clientes::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_CLIENTES,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Clientes)* pos,0);
    fwrite(this,sizeof(Clientes),1,p);
    fclose(p);
    return true;
}

bool Clientes::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_CLIENTES,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Clientes)* pos,0);
    fread(this,sizeof(Clientes),1,p);
    fclose(p);
    return true;
}

bool Clientes::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_CLIENTES,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Clientes),1,p);
    fclose(p);
    return true;
}


///____________________________________________________________________///



bool buscarDNI_Cliente(const char *doc)
{
    Clientes aux;
    for(int i=0; i<cantReg_Clientes();i++)
    {
        aux.leerDeDisco(i);
        if(0==strcmp(doc,aux.getDni()) && aux.getEstado())return true;
    }
    return false;
}

///____________________________________________________________________///

bool devuelve_ClientexDNI(const char *doc, Clientes &reg)
{
    Clientes aux;
    for(int i=0; i<cantReg_Clientes();i++)
    {
        aux.leerDeDisco(i);
        if(0==strcmp(doc,aux.getDni()) && aux.getEstado()){ reg=aux;
        return true;}
    }
    return false;
}

#endif // CLIENTES_H_INCLUDED
