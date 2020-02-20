#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

//Prototipos
void mostrarPagos(Pagos);


///____________________________________________________________________///



bool Pagos::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_PAGOS,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Pagos)* pos,0);
    fwrite(this,sizeof(Pagos),1,p);
    fclose(p);
    return true;
}

bool Pagos::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_PAGOS,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Pagos)* pos,0);
    fread(this,sizeof(Pagos),1,p);
    fclose(p);
    return true;
}

bool Pagos::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_PAGOS,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Pagos),1,p);
    fclose(p);
    return true;
}


///____________________________________________________________________///



int cantReg_Pagos()
{
    FILE *p;
    int y;
    p=fopen(ARCH_PAGOS, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Pagos);
    fclose(p);
    return y;
}


///____________________________________________________________________///



void cargarPago()
{
    system("cls");
    Pagos nuevo;
    Clientes reg;
    Fecha aux;
    int mes;
    int tipo,forma;
    char doc[11];
    //float mon;
    cin.ignore();
    cout<<"Ingrese el DNI: ";
    cin.getline(doc,11,'\n');
    if(!(buscarDNI_Cliente(doc)))
    {
        cout<<"El DNI no existe."<<endl;
        system("pause");
        return;
    }
    if(!chequearPago(doc)){
    nuevo.setDni(doc);
    cout<<"Ingrese el tipo de pago(1:Mensual, 2:Anual): ";
    cin>>tipo;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el dato en numeros."<<endl;
        cout<<"Ingrese el tipo de pago(1:Mensual, 2:Anual): ";
        cin>>tipo;
    }
    nuevo.setTipoPago(tipo);

    cout<<"Ingrese la forma de pago(1:Efec, 2:Debito, 3:Credito): ";
    cin>>forma;
        while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el dato en numeros."<<endl;
        cout<<"Ingrese la forma de pago(1:Efec, 2:Debito, 3:Credito): ";
        cin>>forma;
    }
    nuevo.setFormaPago(forma);
    aux.fechaActual();
        if(tipo == 1)
    {
        nuevo.setMes(aux.getMes());
        nuevo.setAnio(aux.getAnio());
    }
    else if(tipo == 2)
    {
        mes=aux.getMes()+11;
        if(mes > 12)
        {
            nuevo.setAnio(aux.getAnio()+1);
            nuevo.setMes(aux.getMes());
        }
    }
    nuevo.setFechaPago(aux);
    if(nuevo.escribirEnDisco())cout<<"Pago archivado. "<<endl;
    system("pause");
    return;
    }
    cout<<"El cliente tiene pago el mes en curso."<<endl;
    system("pause");
}



///____________________________________________________________________///


///____________________________________________________________________///
void mostrarPagoxDNI()
{
    system("cls");
    Pagos reg;
    Clientes aux;
    char doc[11];
    bool paso=true, paso2=true;
    cin.ignore();
    cout<<"Ingrese el DNI del cliente: ";
    cin.getline(doc,11,'\n');
    for(int i=0;i<cantReg_Clientes();i++)
    {
        aux.leerDeDisco(i);
        if(0==strcmp(doc,aux.getDni()))
        {
            paso=false;
            cout<<"Nombre y Apellido: "<<aux.getNombre()<<", "<<aux.getApellido()<<endl;
            cout<<"DNI: "<<aux.getDni()<<endl;
            cout<<"==================================="<<endl;
        }
    }
    if(paso)cout<<"No existe cliente con ese DNI."<<endl;
    for(int i=cantReg_Pagos()-1;i>=0;i--)
    {
       reg.leerDeDisco(i);
       if(0==strcmp(doc,reg.getDni()))
       {
           paso2=false;
           mostrarPagos(reg);
           //return;
       }
    }
    if(paso2)cout<<"No existe registros de pagos con ese DNI."<<endl;
    system("pause");
}


///____________________________________________________________________///



void mostrarPagos(Pagos aux)
{
    //system("cls");
    Clientes reg;
    for(int i=0;i<cantReg_Clientes();i++)
    {
        reg.leerDeDisco(i);
        if(0==strcmp(aux.getDni(),reg.getDni()))
        {
            switch(aux.getTipoPago())
            {
                case 1: cout<<"Pago Mensual."<<endl;
                    break;
                case 2: cout<<"Pago Anual. "<<endl;
                    break;
                default: cout<<"Opcion Inválida."<<endl;
                system("pause");
            }
            switch(aux.getFormaPago())
            {
                case 1: cout<<"Forma de pago: Efectivo."<<endl;
                    break;
                case 2: cout<<"Forma de pago: Débito."<<endl;
                    break;
                case 3: cout<<"Forma de pago: Crédito."<<endl;
                    break;
                default: cout<<"Opción inválida."<<endl;
                system("pause");
            }
            //cout<<"Monto: "<<aux.getMonto()<<endl;
            cout<<"Fecha de pago: "<<aux.getFecha().getDia()<<"/"<<aux.getFecha().getMes()<<"/"<<aux.getFecha().getAnio()<<endl;
            cout<<"Pago hasta: "<<aux.getMes()<<"/"<<aux.getAnio()<<endl;
            cout<<"___________________________________"<<endl;
            return;
        }
    }
    cout<<"Error de DNI."<<endl;
    system("pause");
}



///____________________________________________________________________///



void menuPagos()
{
    system("cls");
    int opc;
    cout<<"__________________________________"<<endl;
    cout<<"  MENÚ PAGOS"<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"1) Nuevo Pago."<<endl;
    cout<<"2) Mostrar pagos por DNI."<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"0) Volver al menú anterior."<<endl;
    cin>>opc;
    switch(opc)
    {
        case 1: cargarPago();
            break;
        case 2: mostrarPagoxDNI();
            break;
        case 0: return;
            break;
        default: cout<<"La opción ingresada es inválida."<<endl;
        system("pause");
    }
}


///____________________________________________________________________///



bool chequearPago(char *dni)
{
    Pagos aux;
    Fecha feA;
    for(int i=0; i<cantReg_Pagos(); i++)
    {
        aux.leerDeDisco(i);
        if(0 == strcmp(dni, aux.getDni()))
        {
            feA.fechaActual();

            if(aux.getAnio() > feA.getAnio()) return true;
            if(aux.getAnio()== feA.getAnio() && aux.getMes() >= feA.getMes()) return true;

    }
    }
    return false;
}


#endif // PAGOS_H_INCLUDED
