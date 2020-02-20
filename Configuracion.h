#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void menuConfiguracion()
{
    int opc;
    while(1){
    system("cls");
    cout<<"__________________________________"<<endl;
    cout<<"\tMenú de configuración"<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"1) Backups."<<endl;
    cout<<"2) Usuarios."<<endl;
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
        case 1: menuBackups();
            break;
        case 2: menuUsuarios();
            break;
        case 0: return;
            break;
        default: cout<<"Opcion invalida."<<endl;
        system("pause");
    }
    }
}


///____________________________________________________________________///



void menuBackups()
{
    int opc;
    Usuario reg;
    while(1)
    {
    system("cls");
    cout<<"__________________________________"<<endl;
    cout<<"Menú Backups"<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"1) Hacer backups."<<endl;
    cout<<"2) Restaurar backups."<<endl;
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
        case 1: system("cls");
            if(reg.comprobarUsuarioAdm()) menuHacerBkp();
            break;
        case 2: system("cls");
            if(reg.comprobarUsuarioAdm()) menuRestBkp();
            break;
        case 0: return;
            break;
        default: cout<<"Opcion inválida."<<endl;
        system("pause");
    }
    }
}


///____________________________________________________________________///



void menuHacerBkp()
{
    int opc;
    while(1){
        system("cls");
    cout<<"________________________________________"<<endl;
    cout<<"\tHacer Backups."<<endl;
    cout<<"________________________________________"<<endl<<endl;
    cout<<"1) Hacer backups de todos los archivos."<<endl;
    cout<<"2) Hacer backup de clientes."<<endl;
    cout<<"3) Hacer backup de usuarios."<<endl;
    cout<<"4) Hacer backup de dietas."<<endl;
    cout<<"5) Hacer backup de ejercicios."<<endl;
    cout<<"6) Hacer backup de rutinas."<<endl;
    cout<<"7) Hacer backup de pagos."<<endl;
    cout<<"8) Hacer backup de clases."<<endl;
    cout<<"9) Hacer backup de inscriptos de clases."<<endl;
    cout<<"10)Hacer backup de medidas."<<endl;
    cout<<"________________________________________"<<endl<<endl;
    cout<<"0)Volver al menú anterior."<<endl;
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
        case 1: system("copy Datos\\clases.dat Backups\\clases.bkp");
                system("copy Datos\\clientes.dat Backups\\clientes.bkp");
                system("copy Datos\\CuposClase.dat Backups\\CuposClase.bkp");
                system("copy Datos\\dietas.dat Backups\\dietas.bkp");
                system("copy Datos\\ejercicios.dat Backups\\ejercicios.bkp");
                system("copy Datos\\Ejercicios_x_Rutinas.dat Backups\\Ejercicios_x_Rutinas.bkp");
                system("copy Datos\\medidas.dat Backups\\medidas.bkp");
                system("copy Datos\\pagos.dat Backups\\pagos.bkp");
                system("copy Datos\\rutinas.dat Backups\\rutinas.bkp");
                system("copy Datos\\Rutinas_x_Clientes.dat Backups\\Rutinas_x_Clientes.bkp");
                system("copy Datos\\usuarios.dat Backups\\usuarios.bkp");
                system("pause");
            break;
        case 2: system("copy Datos\\clientes.dat Backups\\clientes.bkp");
                system("pause");
            break;
        case 3:system("copy Datos\\usuarios.dat Backups\\usuarios.bkp");
                system("pause");
            break;
        case 4: system("copy Datos\\dietas.dat Backups\\dietas.bkp");
                system("pause");
            break;
        case 5: system("copy Datos\\ejercicios.dat Backups\\ejercicios.bkp");
                system("pause");
            break;
        case 6: system("copy Datos\\rutinas.dat Backups\\rutinas.bkp");
                system("copy Datos\\Ejercicios_x_Rutinas.dat Backups\\Ejercicios_x_Rutinas.bkp");
                system("copy Datos\\Rutinas_x_Clientes.dat Backups\\Rutinas_x_Clientes.bkp");
                system("pause");
            break;
        case 7: system("copy Datos\\pagos.dat Backups\\pagos.bkp");
                system("pause");
            break;
        case 8: system("copy Datos\\clases.dat Backups\\clases.bkp");
                system("pause");
            break;
        case 9: system("copy Datos\\CuposClase.dat Backups\\CuposClase.bkp");
                system("pause");
            break;
        case 10: system("copy Datos\\medidas.dat Backups\\medidas.bkp");
                 system("pause");
            break;
        case 0: return;
            break;
        default: cout<<"Opción inválida."<<endl;
        system("pause");
    }
    }
}


///____________________________________________________________________///



void menuRestBkp()
{
    int opc;
    while(1){
            system("cls");
    cout<<"_____________________________________________"<<endl;
    cout<<"Restaurar Backups."<<endl;
    cout<<"_____________________________________________"<<endl<<endl;
    cout<<"1) Restaurar backups de todos los archivos."<<endl;
    cout<<"2) Restaurar backup de clientes."<<endl;
    cout<<"3) Restaurar backup de usuarios."<<endl;
    cout<<"4) Restaurar backup de dietas."<<endl;
    cout<<"5) Restaurar backup de ejercicios."<<endl;
    cout<<"6) Restaurar backup de rutinas."<<endl;
    cout<<"7) Restaurar backup de pagos."<<endl;
    cout<<"8) Restaurar backup de clases."<<endl;
    cout<<"9) Restaurar backup de inscriptos de clases."<<endl;
    cout<<"10)Restaurar backup de medidas."<<endl;
    cout<<"_____________________________________________"<<endl<<endl;
    cout<<"0)Volver al menú anterior."<<endl;
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
        case 1: system("copy Backups\\clases.bkp Datos\\clases.dat");
                system("copy Backups\\clientes.bkp Datos\\clientes.dat");
                system("copy Backups\\CuposClase.bkp Datos\\CuposClase.dat");
                system("copy Backups\\dietas.bkp Datos\\dietas.dat");
                system("copy Backups\\ejercicios.bkp Datos\\ejercicios.dat");
                system("copy Backups\\Ejercicios_x_Rutinas.bkp Datos\\Ejercicios_x_Rutinas.dat");
                system("copy Backups\\medidas.bkp Datos\\medidas.dat");
                system("copy Backups\\pagos.bkp Datos\\pagos.dat");
                system("copy Backups\\rutinas.bkp Datos\\rutinas.dat");
                system("copy Backups\\Rutinas_x_Clientes.bkp Datos\\Rutinas_x_Clientes.dat");
                system("copy Backups\\usuarios.bkp Datos\\usuarios.dat");
                system("pause");
            break;
        case 2: system("copy Backups\\clientes.bkp Datos\\clientes.dat");
                system("pause");
            break;
        case 3:system("copy Backups\\usuarios.bkp Datos\\usuarios.dat");
                system("pause");
            break;
        case 4: system("copy Backups\\dietas.bkp Datos\\dietas.dat");
                system("pause");
            break;
        case 5: system("copy Backups\\ejercicios.bkp Datos\\ejercicios.dat");
                system("pause");
            break;
        case 6: system("copy Backups\\rutinas.bkp Datos\\rutinas.dat");
                system("copy Backups\\Ejercicios_x_Rutinas.bkp Datos\\Ejercicios_x_Rutinas.dat");
                system("copy Backups\\Rutinas_x_Clientes.bkp Datos\\Rutinas_x_Clientes.dat");
                system("pause");
            break;
        case 7: system("copy Backups\\pagos.bkp Datos\\pagos.dat");
                system("pause");
            break;
        case 8: system("copy Backups\\clases.bkp Datos\\clases.dat");
                system("pause");
            break;
        case 9: system("copy Backups\\CuposClase.bkp Datos\\CuposClase.dat");
                system("pause");
            break;
        case 10: system("copy Backups\\medidas.bkp Datos\\medidas.dat");
                 system("pause");
            break;
        case 0: return;
            break;
        default: cout<<"Opción inválida."<<endl;
        system("pause");
    }
    }
}


///____________________________________________________________________///



void exportarClientesExcel()
{
    ofstream excel("CLIENTES_EXCEL.csv");
    Clientes aux;

    excel<<"DNI;"<<"APELLIDO;"<<"NOMBRE;"<<"TELÉFONO;"<<"SEXO;"<<"CALLE y NÚMERO;"<<"LOCALIDAD;"<<"PROVINCIA;"<<"PAIS;"<<"MAIL;"<<"OBRA_SOCIAL;"<<"FACTOR_SANG;"<<"FECHA_NAC;"<<"FECHA_INSC;"<<"DIETA;"<<endl;
    for(int i=0; i<cantReg_Clientes();i++)
    {
        if(aux.leerDeDisco(i))
        excel<<aux.getDni()<<";"<<aux.getApellido()<<";"<<aux.getNombre()<<";"<<aux.getTelefono()<<";"<<aux.getSexo()<<";"<<aux.getDomicilio().getCalle()<<" "<<aux.getDomicilio().getNCalle()<<";"<<aux.getDomicilio().getLocalidad()<<";"
        <<aux.getDomicilio().getProvincia()<<";"<<aux.getDomicilio().getPais()<<";"<<aux.getEmail()<<";"<<aux.getObraSocial()<<";"<<aux.getFactor()<<";"<<aux.getFechaNac().getDia()<<"/"<<aux.getFechaNac().getMes()<<"/"<<aux.getFechaNac().getAnio()<<";"
        <<aux.getFechaInsc().getDia()<<"/"<<aux.getFechaInsc().getMes()<<"/"<<aux.getFechaInsc().getAnio()<<";"<<aux.getClienteDieta()<<";"<<endl;

    }
    excel.close();
    cout<<"Listado Exportado."<<endl;
    system("pause");

}

///____________________________________________________________________///



void menuUsuarios()
{
    int opc;
    while(1)
    {
    system("cls");
    cout<<"_____________________________________"<<endl;
    cout<<"\tMenú Usuarios"<<endl;
    cout<<"_____________________________________"<<endl<<endl;
    cout<<"1) Nuevo usuario."<<endl;
    cout<<"2) Listar los usuarios."<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"3) Dar permisos de administrador."<<endl;
    cout<<"4) Quitar permisos de administrador."<<endl;
    cout<<"_____________________________________"<<endl<<endl;
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
        case 1: crear_usuario();
            break;
        case 2: listarUsuarios();
            break;
        case 3: darPermisoAdministrador();
            break;
        case 4: quitarPermisoAdministrador();
            break;
        case 0: return;
            break;
        default: cout<<"Opcion inválida."<<endl;
        system("pause");
    }
    }
}

#endif // CONFIGURACION_H_INCLUDED
