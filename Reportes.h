#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


void menuReportes()
{
    system("cls");
    int opc;
    cout<<"__________________________________"<<endl;
    cout<<"  MENÚ REPORTES "<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"1) Consultas."<<endl;
    cout<<"2) Listados."<<endl;
    cout<<"3) Informes."<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"0) Volver al menú anterior."<<endl;
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
        case 1: menuConsultas();
            break;
        case 2: menuListados();
            break;
        case 3: menuInformes();
            break;
        case 0: return;
            break;
        default: cout<<"Opción inválida."<<endl;
        system("pause");
    }
}


///____________________________________________________________________///


void menuInformes()
{
    int opc;
    while(1)
    {
        system("cls");
        cout<<"_______________________________________"<<endl;
        cout<<"  MENÚ INFORMES"<<endl;
        cout<<"_______________________________________"<<endl<<endl;
        cout<<"1) Progreso"<<endl;
        cout<<"2) La Dieta más usada y por quienes."<<endl;
        cout<<"3) La rutina más utilizada y quienes la usan."<<endl;
        cout<<"4) Mes del año actual con mayor cantidad de inscripciones."<<endl;
        cout<<"_______________________________________"<<endl<<endl;
        cout<<"0) Volver al menú anterior."<<endl;
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
            case 1: informeProgreso();
                break;
            case 2: informeDietaMasUsada();
                break;
            case 3: informeRutinaMasUsada();
                break;
            case 4: informeMesDeAnioActualMayorInsc();
                break;
            case 0: return;
                break;
            default: cout<<"Opción inválida."<<endl;
            system("pause");
        }
    }
}




///____________________________________________________________________///



void menuConsultas()
{
    int opc;
    while(1){
    system("cls");
    cout<<"____________________________________"<<endl;
    cout<<"  MENÚ CONSULTAS"<<endl;
    cout<<"____________________________________"<<endl<<endl;
    cout<<"1) Cliente por DNI."<<endl;
    cout<<"2) Medidas actual de cliente por DNI."<<endl;
    cout<<"3) Mostrar ejercicio por nombre."<<endl;
    cout<<"4) Mostrar rutina por nombre."<<endl;
    cout<<"5) Mostrar dieta por nombre."<<endl;
    cout<<"6) Mostrar clase por ID."<<endl;
    cout<<"7) Mostrar ejercicios por rutinas."<<endl;
    cout<<"____________________________________"<<endl<<endl;
    cout<<"0) Volver al menú anterior."<<endl;
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
        case 1: listarCliente_DNI();
            break;
        case 2: medidaActual_DNI();
            break;
        case 3: mostrarEjercicio();
            break;
        case 4: system("cls");
            char name[30];
            cout<<"Ingrese el nombre de la rutina a mostrar: ";
            cin.ignore();
            cin.getline(name,30,'\n');
            mostrarRutina_nombre(name);
            break;
        case 5: mostrarDieta();
            break;
        case 6: mostrarClase_x_ID();
            break;
        case 7: mostrarEjxIdRutina();
            break;
        case 0: return;
            break;
        default: cout<<"Opción inválida."<<endl;
        system("pause");
    }
}
}


///____________________________________________________________________///


void menuListados()
{
    int opc;
    while(1)
    {
        system("cls");
        cout<<"__________________________________"<<endl;
        cout<<"  MENU LISTADOS"<<endl;
        cout<<"__________________________________"<<endl<<endl;
        cout<<"1) Clientes."<<endl;
        cout<<"2) Ejercicios."<<endl;
        cout<<"3) Rutinas."<<endl;
        cout<<"4) Dietas."<<endl;
        cout<<"5) Clases."<<endl;
        cout<<"__________________________________"<<endl<<endl;
        cout<<"0) Volver el menú anterior."<<endl;
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
            case 1: menuListadosClientes();
                break;
            case 2: menuListadosEjercicios();
                break;
            case 3: menuListadosRutinas();
                break;
            case 4: menuListadosDietas();
                break;
            case 5: menuListadosClases();
                break;
            case 0: return;
                break;
            default: cout<<"Opción inválida."<<endl;
            system("pause");
        }
    }
}


void menuListadosClases()
{
    int opc;
    while(1)
    {
        system("cls");
        cout<<"__________________________________"<<endl;
        cout<<"  MENÚ LISTADOS CLASES"<<endl;
        cout<<"__________________________________"<<endl<<endl;
        cout<<"1) Clases por duración"<<endl;
        cout<<"2) Clases por horario"<<endl;
        cout<<"__________________________________"<<endl<<endl;
        cout<<"0) Volver al menú anterior."<<endl;
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
            case 1: listarClases(1);
                break;
            case 2: listarClases(2);
                break;
            case 0: return;
                break;
            default: cout<<"Opción inválida."<<endl;
            system("pause");
        }
    }
}


///____________________________________________________________________///



void menuListadosDietas()
{
    int opc;
    while(1)
    {
        system("cls");
        cout<<"_______________________________________"<<endl;
        cout<<"  MENÚ LISTADOS DIETAS"<<endl;
        cout<<"_______________________________________"<<endl<<endl;
        cout<<"1) Dietas en orden alfabético"<<endl;
        cout<<"2) Dietas por cantidad de calorías"<<endl;
        cout<<"3) Dietas por cantidad de carbohidratos"<<endl;
        cout<<"4) Dietas por cantidad de proteínas"<<endl;
        cout<<"5) Dietas por cantidad de grasas"<<endl;
        cout<<"_______________________________________"<<endl<<endl;
        cout<<"0) Volver al menú anterior."<<endl;
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
            case 1: listarDietasxNombre();
                break;
            case 2: listarDietasxVariables(1);
                break;
            case 3: listarDietasxVariables(2);
                break;
            case 4: listarDietasxVariables(3);
                break;
            case 5: listarDietasxVariables(4);
                break;
            case 0: return;
                break;
            default: cout<<"Opción inválida."<<endl;
            system("pause");
        }
    }
}


///____________________________________________________________________///



void menuListadosRutinas()
{
    int opc;
    while(1)
    {
        system("cls");
        cout<<"__________________________________"<<endl;
        cout<<"  MENÚ LISTADOS RUTINAS"<<endl;
        cout<<"__________________________________"<<endl<<endl;
        cout<<"1) Rutinas en orden alfabético."<<endl;
        cout<<"2) Rutinas por cliente."<<endl;
        cout<<"__________________________________"<<endl<<endl;
        cout<<"0) Volver al menú anterior."<<endl;
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
            case 1: listarRutinasxNombre();
                break;
            case 2: listarRutinasxCliente();
                break;
            case 0: return;
                break;
            default: cout<<"Opción inválida."<<endl;
            system("pause");
        }
    }
}


///____________________________________________________________________///



void menuListadosEjercicios()
{
    int opc;
    while(1)
    {
        system("cls");
        cout<<"___________________________________________"<<endl;
        cout<<"  MENÚ LISTADOS EJERCICIOS"<<endl;
        cout<<"___________________________________________"<<endl<<endl;
        cout<<"1) Ejercicios ordenados por grupo muscular."<<endl;
        cout<<"___________________________________________"<<endl<<endl;
        cout<<"0) Volver al menú anterior."<<endl;
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
            case 1: listarEjerciciosOrdxMusculo();
                break;
            case 0: return;
                break;
            default: cout<<"Opción inválida."<<endl;
            system("pause");
        }
    }
}


///____________________________________________________________________///



void menuListadosClientes()
{
    int opc;
    while(1){
    system("cls");
    cout<<"_______________________________________________________"<<endl;
    cout<<"  MENÚ LISTADOS CLIENTES"<<endl;
    cout<<"_______________________________________________________"<<endl<<endl;
    cout<<"1) Clientes ordenados por DNI."<<endl;
    cout<<"2) Clientes ordenados por Apellido."<<endl;
    cout<<"3) Listar clientes por rango de fechas de nacimiento."<<endl;
    cout<<"4) Listar clientes por rango de fechas de inscripción."<<endl;
    cout<<"_______________________________________________________"<<endl<<endl;
    cout<<"0) Volver al menú anterior."<<endl;
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
        case 1: listarClientes_Todos(1);
            break;
        case 2: listarClientes_Todos(2);
            break;
        case 3: listarClientesxRangoDeFechas(0);
            break;
        case 4: listarClientesxRangoDeFechas(1);
            break;
        case 0: return;
            break;
        default: cout<<"Opción inválida."<<endl;
        system("pause");
    }
}
}


///____________________________________________________________________///



void listarClientes_Todos(int opc)

{
    system("cls");
    Clientes *p;
    Clientes aux;
    p=new Clientes[cantReg_Clientes()];
    if(p==NULL)
    {
        cout<<"Error de memoria al cargar los clientes."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Clientes();i++)
    {
        if(aux.leerDeDisco(i))
        {
            p[i]=aux;
        }
    }
    switch(opc)
    {
        case 1:///ORDENAR POR DNI
            for(int j=0; j<cantReg_Clientes();j++)
                {
                    for(int f=j+1;f<cantReg_Clientes();f++)
                    {
                        if(strcmpi(p[j].getDni(),p[f].getDni())>0)
                        {
                            aux=p[f];
                            p[f]=p[j];
                            p[j]=aux;
                        }
                    }
                }
            break;
        case 2:///ORDENAR POR APELLIDO
            for(int j=0; j<cantReg_Clientes();j++)
                {
                    for(int f=j+1;f<cantReg_Clientes();f++)
                    {
                        if(strcmpi(p[j].getApellido(),p[f].getApellido())>0)
                        {
                            aux=p[f];
                            p[f]=p[j];
                            p[j]=aux;
                        }
                    }
                }
                break;

    }
    cout<<left<<setw(4)<<"ID"<<left<<setw(20)<<"APELLIDO"<<left<<setw(15)<<"NOMBRE"<<left<<setw(11)<<"DNI"<<endl<<endl;
    for(int i=0; i<cantReg_Clientes();i++)
    {

        if(p[i].getEstado())cout<<left<<setw(4)<<p[i].getId()<<left<<setw(20)<<p[i].getApellido()<<left<<setw(15)<<p[i].getNombre()<<left<<setw(11)<<p[i].getDni()<<endl;
    }
    cout<<endl;
    system("pause");
    delete p;
}


///____________________________________________________________________///



void listarClientesxRangoDeFechas(int opc)
{
    Fecha minima, maxima;
    Clientes aux;
    system("cls");
    cout<<"Ingrese la fecha mínima."<<endl;
    while(!(minima.setFecha()));
    cout<<"Ingrese la fecha máxima."<<endl;
    while(!(maxima.setFecha()));
    system("cls");
    switch(opc)
    {
    case 0: for(int i=0; i<cantReg_Clientes();i++)
        {
            aux.leerDeDisco(i);
            if(aux.getFechaNac() <= maxima && aux.getFechaNac()>= minima)
            {

                aux.mostrar();
                cout<<"============================================="<<endl;
            }
        }
        break;

    case 1: for(int i=0; i<cantReg_Clientes();i++)
        {
            aux.leerDeDisco(i);
            if(aux.getFechaInsc() <= maxima && aux.getFechaInsc()>= minima)
            {
                cout<<endl;
                aux.mostrar();
                cout<<"============================================="<<endl;
            }
        }

        break;
    }
    system("pause");
}



///____________________________________________________________________///


void listarEjerciciosOrdxMusculo()
{
    system("cls");
    Ejercicios *p;
    Ejercicios aux;
    p=new Ejercicios[cantReg_Ejercicios()];
    if(p==NULL)
    {
        cout<<"Error de memoria al cargar los ejercicios."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Ejercicios();i++)
    {
        if(aux.leerDeDisco(i))
        {
            p[i]=aux;
        }
    }
    for(int j=0; j<cantReg_Ejercicios();j++)
        {
            for(int f=j+1;f<cantReg_Ejercicios();f++)
            {
                if(strcmpi(p[j].getMusculo(),p[f].getMusculo())>0)
                {
                    aux=p[f];
                    p[f]=p[j];
                    p[j]=aux;
                }
            }
    }

    cout<<left<<setw(4)<<"ID"<<left<<setw(25)<<"Ejercicio"<<left<<setw(20)<<"Músculo"<<endl<<endl;
    for(int i=0; i<cantReg_Ejercicios();i++)
    {

       if(p[i].getEstado()) cout<<left<<setw(4)<<p[i].getId()<<left<<setw(25)<<p[i].getNombreEjer()<<left<<setw(20)<<p[i].getMusculo()<<endl;
    }
    cout<<endl;
    system("pause");
    delete p;
}


///____________________________________________________________________///


void listarRutinasxNombre()
{
    system("cls");
    Rutina *p;
    Rutina aux;
    p=new Rutina[cantReg_Rutina()];
    if(p==NULL)
    {
        cout<<"Error de memoria al cargar las rutinas."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Rutina();i++)
    {
        if(aux.leerDeDisco(i))
        {
            p[i]=aux;
        }
    }
    for(int j=0; j<cantReg_Rutina();j++)
        {
            for(int f=j+1;f<cantReg_Rutina();f++)
            {
                if(strcmpi(p[j].getNombre(),p[f].getNombre())>0)
                {
                    aux=p[f];
                    p[f]=p[j];
                    p[j]=aux;
                }
            }
    }

    cout<<left<<setw(25)<<"Rutinas:"<<endl;
    cout<<"_______________________"<<endl<<endl;
    for(int i=0; i<cantReg_Rutina();i++)
    {

       if(p[i].getEstado()) cout<<"- "<<left<<setw(25)<<p[i].getNombre()<<"\t"<<"ID: "<<p[i].getId()<<endl;
    }
    cout<<endl;
    system("pause");
    delete p;
}



void listarRutinasxCliente()
{
    system("cls");
    Rutina_x_Cliente *p;
    Rutina_x_Cliente aux;
    Rutina reg;
    Clientes cli;

    p=new Rutina_x_Cliente[cantReg_Rutina_x_Cliente()];
    if(p==NULL)
    {
        cout<<"Error de memoria al cargar las rutinas."<<endl;
        system("pause");
        return;
    }

   for(int i=0; i<cantReg_Rutina_x_Cliente(); i++)
    {
        if(aux.leerDeDisco(i))
        {
            p[i]=aux;
        }
    }

    for(int j=0; j<cantReg_Rutina_x_Cliente();j++)
        {
            for(int f=j+1;f<cantReg_Rutina_x_Cliente();f++)
            {
                if(p[j].getIdRutina()>p[f].getIdRutina())
                {
                    aux=p[f];
                    p[f]=p[j];
                    p[j]=aux;
                }
            }
    }

    //cout<<left<<setw(25)<<"Rutinas"<<endl;
    cout<<left<<setw(12)<<"ID Rutina"<<left<<setw(20)<<"Rutina"<<"\tApellido y Nombre"<<endl;
    cout<<"_____________________________________________________________________"<<endl<<endl;
    for(int i=0; i<cantReg_Rutina_x_Cliente();i++)
    {
        reg.leerDeDisco(p[i].getIdRutina()-1);
        devuelve_ClientexDNI(p[i].getDni(), cli);

       if(p[i].getEstado()) cout<<left<<setw(12)<<p[i].getIdRutina()<<"|"<<left<<setw(20)<<reg.getNombre()<<"|"<<"\t"<<cli.getApellido()<<", "<<cli.getNombre()<<endl;
    }
    cout<<endl;
    system("pause");
    delete p;
}

///____________________________________________________________________///



void listarDietasxNombre()
{

    system("cls");
    Dieta *p;
    Dieta aux;
    p=new Dieta[cantReg_Dietas()];
    if(p==NULL)
    {
        cout<<"Error de memoria al cargar las dietas."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Dietas();i++)
    {
        if(aux.leerDeDisco(i))
        {
            p[i]=aux;
        }
    }
    for(int j=0; j<cantReg_Dietas();j++)
        {
            for(int f=j+1;f<cantReg_Dietas();f++)
            {
                if(strcmpi(p[j].getNombreDieta(),p[f].getNombreDieta())>0)
                {
                    aux=p[f];
                    p[f]=p[j];
                    p[j]=aux;
                }
            }
    }

    cout<<left<<setw(4)<<"ID"<<left<<setw(30)<<"Dieta"<<left<<setw(10)<<"Calorías"<<left<<setw(7)<<"Carbs"<<left<<setw(10)<<"Proteínas"<<left<<setw(7)<<"Grasas"<<endl<<endl;
    for(int i=0; i<cantReg_Dietas();i++)
    {

       if(p[i].getEstado()) cout<<left<<setw(4)<<p[i].getID()<<left<<setw(30)<<p[i].getNombreDieta()<<left<<setw(10)<<p[i].getCalorias()<<left<<setw(7)<<p[i].getCarbs()<<left<<setw(10)<<p[i].getProte()<<left<<setw(7)<<p[i].getGrasa()<<endl;
    }
    cout<<endl;
    system("pause");
    delete p;
}


///____________________________________________________________________///


void listarDietasxVariables(int opc)
{

    system("cls");
    Dieta *p;
    Dieta aux;
    p=new Dieta[cantReg_Dietas()];
    if(p==NULL)
    {
        cout<<"Error de memoria al cargar las dietas."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Dietas();i++)
    {
        if(aux.leerDeDisco(i))
        {
            p[i]=aux;
        }
    }
    switch(opc)
    {
        case 1: for(int j=0; j<cantReg_Dietas();j++)
                {
                    for(int f=j+1;f<cantReg_Dietas();f++)
                    {
                        if(p[j].getCalorias()<p[f].getCalorias())
                        {
                            aux=p[f];
                            p[f]=p[j];
                            p[j]=aux;
                        }
                    }
            }
            break;

        case 2:  for(int j=0; j<cantReg_Dietas();j++)
                {
                    for(int f=j+1;f<cantReg_Dietas();f++)
                    {
                        if(p[j].getCarbs()<p[f].getCarbs())
                        {
                            aux=p[f];
                            p[f]=p[j];
                            p[j]=aux;
                        }
                    }
            }
            break;

        case 3:  for(int j=0; j<cantReg_Dietas();j++)
                {
                    for(int f=j+1;f<cantReg_Dietas();f++)
                    {
                        if(p[j].getProte()<p[f].getProte())
                        {
                            aux=p[f];
                            p[f]=p[j];
                            p[j]=aux;
                        }
                    }
            }
            break;

        case 4:  for(int j=0; j<cantReg_Dietas();j++)
                {
                    for(int f=j+1;f<cantReg_Dietas();f++)
                    {
                        if(p[j].getGrasa()<p[f].getGrasa())
                        {
                            aux=p[f];
                            p[f]=p[j];
                            p[j]=aux;
                        }
                    }
            }
            break;
    }

            cout<<left<<setw(4)<<"ID"<<left<<setw(30)<<"Dieta"<<left<<setw(10)<<"Calorías"<<left<<setw(7)<<"Carbs"<<left<<setw(10)<<"Proteínas"<<left<<setw(7)<<"Grasas"<<endl<<endl;
            for(int i=0; i<cantReg_Dietas();i++)
            {
                if(p[i].getEstado()) cout<<left<<setw(4)<<p[i].getID()<<left<<setw(30)<<p[i].getNombreDieta()<<left<<setw(10)<<p[i].getCalorias()<<left<<setw(7)<<p[i].getCarbs()<<left<<setw(10)<<p[i].getProte()<<left<<setw(7)<<p[i].getGrasa()<<endl;
            }
            cout<<endl;
            system("pause");
            delete p;
}

///____________________________________________________________________///




void listarClases(int opc)
{

    system("cls");
    Clases *p;
    Clases aux;
    p=new Clases[cantReg_Clases()];
    if(p==NULL)
    {
        cout<<"Error de memoria al cargar las clases."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Clases();i++)
    {
        if(aux.leerDeDisco(i))
        {
            p[i]=aux;
        }
    }
    switch(opc)
    {
        case 1: for(int j=0; j<cantReg_Clases();j++)
                {
                    for(int f=j+1;f<cantReg_Clases();f++)
                    {
                        if(p[j].getDuracion()<p[f].getDuracion())
                        {
                            aux=p[f];
                            p[f]=p[j];
                            p[j]=aux;
                        }
                    }
            }
            break;

        case 2:  for(int j=0; j<cantReg_Clases();j++)
                {
                    for(int f=j+1;f<cantReg_Clases();f++)
                    {
                        if(p[j].getHorario()<p[f].getHorario())
                        {
                            aux=p[f];
                            p[f]=p[j];
                            p[j]=aux;
                        }
                    }
            }
            break;
    }

            cout<<left<<setw(4)<<"ID"<<left<<setw(25)<<"Clase"<<left<<setw(5)<<"Sexo"<<left<<setw(10)<<"Duración"<<left<<setw(10)<<"Horario"<<left<<setw(25)<<"Apellido Prof."<<endl<<endl;
            for(int i=0; i<cantReg_Clases();i++)
            {

                if(p[i].getEstado())
                {
                   cout<<left<<setw(4)<<p[i].getId()<<left<<setw(25)<<p[i].getNombreClase()<<left<<setw(5)<<p[i].getSexo()<<left<<setw(10)<<p[i].getDuracion()<<left<<setw(10)<<p[i].getHorario()<<left<<setw(25)<<p[i].getProfesorApellido()<<endl;
                }
            }
            cout<<endl;
            system("pause");
            delete p;

}



///____________________________________________________________________///




void informeProgreso()
{
    system("cls");
    char dni[11];
    Medidas regIni, regAct;
    Clientes aux;
    cin.ignore();
    cout<<"Ingrese el DNI del cliente: ";
    cin.getline(dni,11,'\n');
    for(int i=(cantReg_Medidas()-1);i>=0;i--)
    {
       regAct.leerDeDisco(i);
       if(0==strcmp(dni,regAct.getDni()) && regAct.getEstado())
       {
           for(int j=0;j<cantReg_Medidas();j++)
           {
               regIni.leerDeDisco(j);
               if(0==strcmp(dni,regIni.getDni()) && regIni.getEstado())
               {
                   if(devuelve_ClientexDNI(regIni.getDni(), aux)){
                   system("cls");
                   cout<<"Cliente: "<< aux.getApellido()<<", "<<aux.getNombre()<<endl;

                   cout<<"Fecha de Inscripción: ";
                   aux.getFechaInsc().MostrarFechaTexto();
                   cout<<endl;


                   mostrarMedidasComparando(regIni, regAct);
                   cout<<endl<<endl;

                   if(strlen(aux.getClienteDieta()) == 0) cout<<"Dieta: El cliente no tiene dieta asignada."<<endl;
                   else mostrarDieta_RecibeDNI(aux.getClienteDieta());
                   cout<<endl;

                   mostrarRutinasxCliente(aux.getDni());
                   cout<<endl<<endl;
                   mostrarClases_x_Cliente(aux.getDni());




                   cout<<endl<<endl;
                   system("pause");
                   return;
                        }
               }
           }
       }
    }
    cout<<"No existe registros de medidas con ese DNI."<<endl;
    system("pause");
}


///____________________________________________________________________///

void informeDietaMasUsada()
{
    system("cls");
    int *cont;
    int mayor;
    cont= new int[cantReg_Dietas()];
    ponerVec0_INT(cont, cantReg_Dietas());
    Dieta reg;
    Clientes aux;
    if(cont==NULL)
    {
        cout<<"Error de memoria al asignar dietas."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Clientes();i++)
    {
        aux.leerDeDisco(i);
        for(int f=0; f<cantReg_Dietas(); f++){
        reg.leerDeDisco(f);
        if(aux.getEstado() && reg.getEstado() && 0==strcmpi(reg.getNombreDieta(),aux.getClienteDieta())) cont[reg.getID()-1]++;
        }
    }
    mayor=buscarMayor(cont, cantReg_Dietas());
    delete cont;
    reg.leerDeDisco(mayor);
    cout<<"La dieta mas usada es: "<<reg.getNombreDieta()<<endl;
    cout<<"ID: "<<reg.getID()<<endl;
    cout<<"Los clientes que la utilizan son: "<<endl;
    for(int j=0; j<cantReg_Clientes(); j++)
    {
        aux.leerDeDisco(j);
        if(0==strcmpi(aux.getClienteDieta(),reg.getNombreDieta()) && aux.getEstado()) cout<<left<<setw(30)<<aux.getApellido()<<", "<<left<<setw(25)<<aux.getNombre()<<"\tDNI:"<<left<<setw(11)<<aux.getDni()<<endl;
    }
    cout<<endl;
    system("pause");
}



///____________________________________________________________________///



void informeRutinaMasUsada()
{
    system("cls");
    int *cont;
    int mayor;
    cont= new int[cantReg_Rutina()];
    ponerVec0_INT(cont, cantReg_Rutina());
    Rutina reg;
    Rutina_x_Cliente aux;
    Clientes cli;
    if(cont==NULL)
    {
        cout<<"Error de memoria al asignar dietas."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Rutina_x_Cliente();i++)
    {
        aux.leerDeDisco(i);
        for(int f=0; f<cantReg_Rutina(); f++){
        reg.leerDeDisco(f);
        if(aux.getEstado() && reg.getEstado() && reg.getId()==aux.getIdRutina()) cont[reg.getId()-1]++;
        }
    }
    mayor=buscarMayor(cont, cantReg_Rutina());
    delete cont;
    reg.leerDeDisco(mayor);
    cout<<"La Rutina mas usada es: "<<reg.getNombre()<<endl;
    cout<<"ID: "<<reg.getId()<<endl;
    cout<<"Los clientes que la utilizan son: "<<endl;
    for(int j=0; j<cantReg_Rutina_x_Cliente(); j++)
    {
        aux.leerDeDisco(j);
        if(reg.getId()== aux.getIdRutina() && aux.getEstado()){
            devuelve_ClientexDNI(aux.getDni(), cli);
            cout<<left<<setw(30)<<cli.getApellido()<<", "<<left<<setw(25)<<cli.getNombre()<<"\tDNI:"<<left<<setw(11)<<cli.getDni()<<endl;
        }
    }
    cout<<endl;
    system("pause");
}



///____________________________________________________________________///


void informeMesDeAnioActualMayorInsc()
{
    system("cls");
    int v[12]={0};
    Clientes cli;
    Fecha fec;
    fec.fechaActual();
    int mayor;
    for(int i=0; i<cantReg_Clientes();i++)
    {
        cli.leerDeDisco(i);
        if(cli.getFechaInsc().getAnio()== fec.getAnio()) v[cli.getFechaInsc().getMes()-1]++;
    }
    mayor = buscarMayor(v,12);
    cout<<"EN EL AÑO ACTUAL:"<<endl;
    cout<<endl<<"EL MES DE MAYOR RECAUDACIÓN ES:";
    mostrarMes(mayor+1);
    cout<<"CON "<<v[mayor]<<" INSCRIPTOS."<<endl;
    cout<<endl;
    system("pause");
}


#endif // REPORTES_H_INCLUDED
