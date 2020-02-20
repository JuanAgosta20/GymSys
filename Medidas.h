#ifndef MEDIDAS_H_INCLUDED
#define MEDIDAS_H_INCLUDED

//PROTOTIPOS
void mostrarMedidas(Medidas);



///____________________________________________________________________///



void cargarMedidas()
{
    system("cls");
    Medidas nueva;
    float a,p,c,ca,bitri,ante,cuadisq,gemsol,pecho,espalda,graso;
    char doc[11];
    Fecha aux;
    cin.ignore();
    cout<<"Ingrese el dni de la persona a medir: ";
    cin.getline(doc,11,'\n');
    if(strlen(doc)==0)
    {
        cout<<"El DNI no puede ser un campo vacío."<<endl;
        system("pause");
        return;
    }
    if(!(buscarDNI_Cliente(doc)))
    {
        cout<<"El DNI no existe."<<endl;
        system("pause");
        return;
    }
    nueva.setDni(doc);
    cout<<"RECUERDE INGRESAR TODOS LOS DATOS CON NUMEROS."<<endl;
    cout<<"Ingrese la altura: ";
    cin>>a;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(a<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setAltura(a);
    cout<<"Ingrese el peso: ";
    cin>>p;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(p<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setPeso(p);
    cout<<"Ingrese la circunferencia de cintura: ";
    cin>>c;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(c<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setCintura(c);
    cout<<"Ingrese la circunferencia de cadera: ";
    cin>>ca;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(ca<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setCadera(ca);
    cout<<"Ingrese la circunferencia del biceps y el triceps: ";
    cin>>bitri;
    if(bitri<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    nueva.setCircBiTri(bitri);
    cout<<"Ingrese la circunferencia del antebrazo: ";
    cin>>ante;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(ante<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setCircAnte(ante);
    cout<<"Ingrese la circunferencia del cuadriceps y el isquitibial: ";
    cin>>cuadisq;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(cuadisq<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setCircCuadIsq(cuadisq);
    cout<<"Ingrese la circunferencia del gemelo y el soleo: ";
    cin>>gemsol;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(gemsol<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setCircGemSol(gemsol);
    cout<<"Ingrese la circunferencia del pecho: ";
    cin>>pecho;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(pecho<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setCircPecho(pecho);
    cout<<"Ingrese el ancho de espalda: ";
    cin>>espalda;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    if(espalda<1)
    {
        cout<<"Ingrese numeros positivos."<<endl;
        system("pause");
        return;
    }
    nueva.setAnchoEspalda(espalda);
    nueva.setIMC();
    cout<<"Ingrese el porcentaje graso: ";
    cin>>graso;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese los datos en numeros."<<endl;
        system("pause");
        return;
    }
    nueva.setPorcGraso(graso);
    aux.fechaActual();
    nueva.setFechaMed(aux);
    nueva.escribirEnDisco();
}

///____________________________________________________________________///



void medidaActual_DNI()
{
    system("cls");
    Medidas reg;
    char doc[11];
    cin.ignore();
    cout<<"Ingrese el DNI del cliente: ";
    cin.getline(doc,11,'\n');
    if(strlen(doc)==0)
    {
        cout<<"El DNI no puede ser un campo vacío."<<endl;
        system("pause");
        return;
    }
    for(int i=(cantReg_Medidas()-1);i>=0;i--)
    {
       reg.leerDeDisco(i);
       if(0==strcmp(doc,reg.getDni()))
       {
           mostrarMedidas(reg);
           return;
       }
    }
    cout<<"No existe registros de medidas con ese DNI."<<endl;
    system("pause");
}


///____________________________________________________________________///


void mostrarMedidas(Medidas aux)
{
    system("cls");
    Clientes reg;
    for(int i=cantReg_Clientes()-1;i>=0;i--)
    {
        reg.leerDeDisco(i);
        if(0==strcmp(aux.getDni(),reg.getDni()))
        {
            cout<<"Nombre y Apellido: "<<reg.getNombre()<<", "<<reg.getApellido()<<endl;
            cout<<"DNI: "<<aux.getDni()<<endl;
            cout<<"----------------------------"<<endl;
            cout<<"Medidas: "<<endl;
            cout<<"Peso: "<<aux.getPeso()<<endl;
            cout<<"Altura: "<<aux.getAltura()<<endl;
            cout<<"IMC: "<<aux.getIMC()<<endl;
            cout<<"Porcentaje Graso: "<<aux.getPorcGraso()<<"%"<<endl;
            cout<<"Cintura: "<<aux.getCintura()<<endl;
            cout<<"Pecho: "<<aux.getCircPecho()<<endl;
            cout<<"Espalda: "<<aux.getAnchoEspalda()<<endl;
            cout<<"Cadera: "<<aux.getCadera()<<endl;
            cout<<"Biceps-Triceps: "<<aux.getCircBiTri()<<endl;
            cout<<"Antebrazo: "<<aux.getCircAnte()<<endl;
            cout<<"Cuadriceps-Isquiotibial: "<<aux.getCircCuadIsq()<<endl;
            cout<<"Gemelo-Soleo: "<<aux.getCircGemSol()<<endl;
            cout<<"Fecha: "<<aux.getFecha().getDia()<<"/"<<aux.getFecha().getMes()<<"/"<<aux.getFecha().getAnio()<<endl;
            system("pause");
            return;
        }
    }
    cout<<"Error de DNI."<<endl;
    system("pause");
}


///____________________________________________________________________///


void mostrarMedidasComparando(Medidas regIni, Medidas regAct)
{
   {
        cout<<left<<setw(8)<<"MEDIDAS"<<"|"<<left<<setw(3)<<"ID"<<"|"<<left<<setw(6)<<"Altura"<<"|"<<left<<setw(4)<<"Peso"<<"|"<<left<<setw(7)<<"Cintura"<<"|"<<left<<setw(5)<<"BiTri"<<"|"<<
        left<<setw(4)<<"Ante"<<"|"<<left<<setw(7)<<"CuadIsq"<<"|"<<left<<setw(6)<<"GemSol"<<"|"<<left<<setw(5)<<"Pecho"<<"|"<<left<<setw(7)<<"Espalda"<<
        "|"<<left<<setw(7)<<"% Graso"<<"|"<<left<<setw(6)<<"IMC"<<"|"<<left<<setw(10)<<" Fecha"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;

        cout<<left<<setw(8)<<"Inicial"<<"|"<<right<<setw(3)<<regIni.getId()<<"|"<<right<<setw(6)<<regIni.getAltura()<<"|"<<right<<setw(4)<<regIni.getPeso()<<"|"<<right<<setw(7)<<regIni.getCintura()<<"|"<<right<<setw(5)<<regIni.getCircBiTri()<<"|"<<
        right<<setw(4)<<regIni.getCircAnte()<<"|"<<right<<setw(7)<<regIni.getCircCuadIsq()<<"|"<<right<<setw(6)<<regIni.getCircGemSol()<<"|"<<right<<setw(5)<<regIni.getCircPecho()<<"|"<<right<<setw(7)<<regIni.getAnchoEspalda()<<
        "|"<<right<<setw(7)<<regIni.getPorcGraso()<<"|"<<right<<setw(6)<<setprecision(3)<<regIni.getIMC()<<"|"<<right<<" "<<regIni.getFecha().getDia()<<"/"<<regIni.getFecha().getMes()<<"/"<<regIni.getFecha().getAnio()<<endl;

        cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;

        cout<<left<<setw(8)<<"Actual"<<"|"<<right<<setw(3)<<regAct.getId()<<"|"<<right<<setw(6)<<regAct.getAltura()<<"|"<<right<<setw(4)<<regAct.getPeso()<<"|"<<right<<setw(7)<<regAct.getCintura()<<"|"<<right<<setw(5)<<regAct.getCircBiTri()<<"|"<<
        right<<setw(4)<<regAct.getCircAnte()<<"|"<<right<<setw(7)<<regAct.getCircCuadIsq()<<"|"<<right<<setw(6)<<regAct.getCircGemSol()<<"|"<<right<<setw(5)<<regAct.getCircPecho()<<"|"<<right<<setw(7)<<regAct.getAnchoEspalda()<<
        "|"<<right<<setw(7)<<regAct.getPorcGraso()<<"|"<<right<<setw(6)<<setprecision(3)<<regAct.getIMC()<<"|"<<right<<" "<<regAct.getFecha().getDia()<<"/"<<regIni.getFecha().getMes()<<"/"<<regIni.getFecha().getAnio()<<endl;

        cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;

        cout<<left<<setw(8)<<"Progreso"<<"|"<<right<<setw(3)<<regAct.getId()<<"|"<<right<<setw(6)<<(regIni.getAltura()-regAct.getAltura())*-1<<"|"<<right<<setw(4)<<(regIni.getPeso()-regAct.getPeso())*-1<<"|"<<right<<setw(7)<<(regIni.getCintura()-regAct.getCintura())*-1<<"|"<<right<<setw(5)<<(regIni.getCircBiTri()-regAct.getCircBiTri())*-1<<"|"<<
        right<<setw(4)<<(regIni.getCircAnte()-regAct.getCircAnte())*-1<<"|"<<right<<setw(7)<<(regIni.getCircCuadIsq()-regAct.getCircCuadIsq())*-1<<"|"<<right<<setw(6)<<(regIni.getCircGemSol()-regAct.getCircGemSol())*-1<<"|"<<right<<setw(5)<<(regIni.getCircPecho()-regAct.getCircPecho())*-1<<"|"<<right<<setw(7)<<(regIni.getAnchoEspalda()-regAct.getAnchoEspalda())*-1<<
        "|"<<right<<setw(7)<<(regIni.getPorcGraso()-regAct.getPorcGraso())*-1<<"|"<<right<<setw(6)<<setprecision(2)<<(regIni.getIMC()-regAct.getIMC())*-1<<"|"<<right<<" "<<regAct.getFecha().getDia()<<"/"<<regIni.getFecha().getMes()<<"/"<<regIni.getFecha().getAnio()<<endl;



   }
}




///____________________________________________________________________///



bool Medidas::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_MEDIDAS,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Medidas)* pos,0);
    fread(this,sizeof(Medidas),1,p);
    fclose(p);
    return true;
}

bool Medidas::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_MEDIDAS,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Medidas),1,p);
    fclose(p);
    return true;
}


///____________________________________________________________________///



int cantReg_Medidas()
{
    FILE *p;
    int y;
    p=fopen(ARCH_MEDIDAS, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Medidas);
    fclose(p);
    return y;
}

///____________________________________________________________________///

#endif // MEDIDAS_H_INCLUDED
