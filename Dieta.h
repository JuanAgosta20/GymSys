#ifndef DIETA_H_INCLUDED
#define DIETA_H_INCLUDED


void menuRyEyD()
{
    int opc;
    while(1){
    system("cls");
    cout<<"_______________________________________"<<endl;
    cout<<"MENÚ RUTINAS, EJERCICIOS Y DIETAS."<<endl;
    cout<<"_______________________________________"<<endl<<endl;
    cout<<"1) Nueva Rutinas."<<endl;
    cout<<"2) Eliminar Rutinas."<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"3) Nuevo ejercicio."<<endl;
    cout<<"4) Eliminar ejercicio."<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"5) Agregar ejercicio a una rutina."<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"6) Nueva dieta."<<endl;
    cout<<"7) Eliminar dieta."<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<"0) Volver al menú anterior."<<endl;
    cin>>opc;
    switch(opc)
    {
        case 1: cargarRutina();
            break;
        case 2: eliminarRutina();
            break;
        case 3: cargarEjercicio();
            break;
        case 4: eliminarEjercicio();
            break;
        case 5: cargarEj_x_Rutina();
            break;
        case 6: cargarDieta();
            break;
        case 7: eliminarDieta();
            break;
        case 0: return;
            break;
        default: cout<<"Opción inválida."<<endl;
        system("pause");

    }
    }

}


///____________________________________________________________________///



bool Dieta::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_DIETAS,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Dieta)* pos,0);
    fwrite(this,sizeof(Dieta),1,p);
    fclose(p);
    return true;
}

bool Dieta::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_DIETAS,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Dieta)* pos,0);
    fread(this,sizeof(Dieta),1,p);
    fclose(p);
    return true;
}

bool Dieta::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_DIETAS,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Dieta),1,p);
    fclose(p);
    return true;
}


///____________________________________________________________________///



void cargarDieta()
{
    system("cls");
    Dieta nueva;
    int cal,c,p,g;
    char n[30];
    cout<<"Ingrese el nombre de la dieta: ";
    cin.ignore();
    cin.getline(n,30,'\n');
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"El nombre no puede tener mas de 30 caracteres."<<endl;
        cout<<"Ingrese el nombre de la dieta: ";
        cin.getline(n,30,'\n');
        while(strlen(n)==0)
        {
            cout<<"EL NOMBRE NO PUEDE SER UN CAMPO VACIO."<<endl;
            cout<<"Ingrese el nombre de la dieta: ";
            cin.getline(n,30,'\n');
        }
    }
    if (chequearDieta(n))
    {
      cout<<"El nombre de la dieta ya existe."<<endl;
      system("pause");
      return;
    }
    nueva.setNombreDieta(n);
    cout<<"Ingrese la cantidad de calorías: ";
    cin>>cal;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingreso incorrecto."<<endl;
        cout<<"Ingrese la cantidad de calorías: ";
        cin>>cal;
    }
    if(cal<1000)
    {
        cout<<"La cantidad de calorías debe ser mayor a 1000."<<endl;
        system("pause");
        return;
    }
    nueva.setCalorias(cal);

    cout<<"Ingrese el porcentaje de carbohidratos: ";
    cin>>c;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingreso incorrecto."<<endl;
        cout<<"Ingrese el porcentaje de carbohidratos: ";
        cin>>c;
    }
    cout<<"Ingrese el porcentaje de proteínas: ";
    cin>>p;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingreso incorrecto."<<endl;
        cout<<"Ingrese el porcentaje de proteínas: ";
        cin>>p;
    }
    cout<<"Ingrese el porcentaje de grasas: ";
    cin>>g;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingreso incorrecto."<<endl;
        cout<<"Ingrese el porcentaje de grasas: ";
        cin>>g;
    }
    if(c<0 || g<0 || p<0)
    {
        cout<<"No puede ingresar pocentajes negativos."<<endl;
        system("pause");
        return;
    }
    while((p+c+g)!=100)
    {
        cout<<"La suma de los porcentajes debe ser 100%."<<endl;
        system("pause");
        cout<<"Ingrese el porcentaje de carbohidratos: ";
        cin>>c;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(200,'\n');
            cout<<"Ingreso incorrecto."<<endl;
            cout<<"Ingrese el porcentaje de carbohidratos: ";
            cin>>c;
        }
        cout<<"Ingrese el porcentaje de proteínas: ";
        cin>>p;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(200,'\n');
            cout<<"Ingreso incorrecto."<<endl;
            cout<<"Ingrese el porcentaje de proteínas: ";
            cin>>p;
        }
        cout<<"Ingrese el porcentaje de grasas: ";
        cin>>g;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(200,'\n');
            cout<<"Ingreso incorrecto."<<endl;
            cout<<"Ingrese el porcentaje de grasas: ";
            cin>>g;
        }
    }
    nueva.setCarbs(c);
    nueva.setProte(p);
    nueva.setGrasa(g);
    if(nueva.escribirEnDisco())cout<<"La Dieta a sido guardada."<<endl;
    else cout<<"Error al guardar."<<endl;
    system("pause");
}



///____________________________________________________________________///



void mostrarDieta()
{
    system("cls");
    Dieta reg;
    char n[30];
    cout<<"Ingrese el nombre de la dieta a mostrar: ";
    cin.ignore();
    cin.getline(n,30,'\n');
    for(int i=0;i<cantReg_Dietas();i++)
    {
        reg.leerDeDisco(i);
        if(0==strcmpi(n,reg.getNombreDieta()) && reg.getEstado())
        {
            cout<<"ID: "<<reg.getID()<<endl;
            cout<<"Dieta: "<<reg.getNombreDieta()<<endl;
            cout<<"Calorías: "<<reg.getCalorias()<<endl;
            cout<<"Carbohidratos: "<<reg.getCarbs()<<endl;
            cout<<"Proteínas: "<<reg.getProte()<<endl;
            cout<<"Grasa: "<<reg.getGrasa()<<endl;
            system("pause");
            return;
        }
    }
    cout<<"La dieta no existe."<<endl;
    system("pause");
}



///____________________________________________________________________///


void mostrarDieta_RecibeDNI(const char *n)
{
    Dieta reg;
    for(int i=0;i<cantReg_Dietas();i++)
    {
        reg.leerDeDisco(i);
        if(0==strcmpi(n , reg.getNombreDieta()) && reg.getEstado())
        {
            cout<<"Dieta: "<< reg.getNombreDieta()<<endl;
            cout<<"ID: "<<reg.getID()<<"| Calorías: "<<reg.getCalorias()<<"| Carbohidratos: "<<reg.getCarbs()<<"| Proteínas: "<<reg.getProte()<<"| Grasa: "<<reg.getGrasa()<<endl;
            return;
        }
    }
    cout<<"La dieta no existe."<<endl;
    system("pause");
}

///____________________________________________________________________///



int cantReg_Dietas()
{
    FILE *p;
    int y;
    p=fopen(ARCH_DIETAS, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Dieta);
    fclose(p);
    return y;
}



///____________________________________________________________________///


///CLASES

void menuClases()
{
    int opc;
    while(1){
    system("cls");
    cout<<"__________________________________"<<endl;
    cout<<" MENÚ CLASES"<<endl;
    cout<<"__________________________________"<<endl<<endl;
    cout<<"1) Nueva Clase."<<endl;
    cout<<"2) Dar baja de alumno en una clase."<<endl;
    cout<<"3) Dar de alta alumno en una clase."<<endl;
    cout<<"4) Eliminar Clase."<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"0)Volver al menú anterior."<<endl;
    cin>>opc;
    switch(opc)
    {
        case 1: cargarClase();
            break;
        case 2: eliminarCupo_x_Clase();
            break;
        case 3: cargarCupo_x_Clase();
            break;
        case 4: eliminarClase();
            break;
        case 0: return;
            break;
        default: cout<<"Opción invalida."<<endl;
        system("pause");
    }
    }
}



///____________________________________________________________________///

void eliminarClase()
{
    int id;
    Clases aux;
    cin.ignore();
    system("cls");
    cout<<"Ingrese el ID de la clase: ";
    cin>>id;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el ID de la clase: ";
        cin>>id;
    }
    if(id<=0 || id>cantReg_Clases())
    {
        cout<<"ID inválido."<<endl;
        system("pause");
        return;
    }
            aux.leerDeDisco(id-1);
            if(aux.getEstado())
            {
                aux.setEstado();
                if(aux.modificarEnDisco(id-1))
                {
                cout<<"La clase fue eliminada."<<endl;
                system("pause");
                return;
                }
            }
    cout<<"La clase no existe."<<endl;
    system("pause");
}

///____________________________________________________________________///



void cargarClase()
{
    system("cls");
    Clases nueva;
    char nombre[25],profN[25],profA[25], sex[2];
    int cup,dur,hor;
    cin.ignore();

    cout<<"Ingrese el nombre de la clase: ";
    cin.getline(nombre,25,'\n');
    nueva.setNombreClase(nombre);
    if(strlen(nombre)==0)
    {
        cout<<"El nombre de la clase no puede ser un campo vacìo."<<endl;
        system("pause");
        return;
    }
    if(chequearClase(nombre))
    {
        cout<<"Ya existe una clase con ese nombre ¿Desea continuar? (1.Si - 2.No)."<<endl;
        int cont;
        cin>>cont;

        cin.ignore();
        if(cont==2) return;
    }
    cout<<"Ingrese el nombre del Profesor: ";
    cin.getline(profN,25,'\n');
    while(strlen(profN)==0)
    {
        cout<<"Debe cargar el nombre del profesor."<<endl;
        cout<<"Ingrese el nombre del Profesor: ";
        cin.getline(profN,25,'\n');
    }
    nueva.setProfesorNombre(profN);

    cout<<"Ingrese el apellido del Profesor: ";
    cin.getline(profA,25,'\n');
    while(strlen(profA)==0)
    {
        cout<<"Debe cargar el apellido del profesor."<<endl;
        cout<<"Ingrese el apellido del Profesor: ";
        cin.getline(profA,25,'\n');
    }
    nueva.setProfesorApellido(profA);
    cout<<"Ingrese el cupo maximo de la clase: ";
    cin>>cup;
    while(cin.fail())
    {
      cin.clear();
      cin.ignore(200,'\n');
      cout<<"DEBE INGRESAR LA CANTIDAD EN NUMEROS."<<endl;
      cout<<"Ingrese el cupo maximo de la clase: ";
      cin>>cup;
    }
    while(cup<=0)
    {
        cout<<"El cupo debe ser mayor a 0."<<endl;
        cout<<"Ingrese el cupo maximo de la clase: ";
        cin>>cup;
        if(cin.fail())
        {
          cin.clear();
          cin.ignore(200,'\n');
          cout<<"DEBE INGRESAR LA CANTIDAD EN NUMEROS."<<endl;
          cout<<"Ingrese el cupo maximo de la clase: ";
          cin>>cup;
        }
    }
    nueva.setCupo(cup);
    cout<<"Ingrese la duración de la clase en minutos: ";
    cin>>dur;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(200,'\n');
      cout<<"DEBE INGRESAR LA DURACIÓN EN NUMEROS."<<endl;
      cout<<"Ingrese la duración de la clase en minutos: ";
      cin>>dur;
    }
    while(dur<=10)
    {
        cout<<"La clase debe durar más de 10 minutos."<<endl;
        cout<<"Ingrese la duración de la clase en minutos: ";
        cin>>dur;
        if(cin.fail())
        {
           cin.clear();
           cin.ignore(200,'\n');
           cout<<"DEBE INGRESAR LA DURACIÓN EN NUMEROS."<<endl;
           cout<<"Ingrese la duración de la clase en minutos: ";
           cin>>dur;
        }
    }
    nueva.setDuracion(dur);
    cout<<"Ingrese el horario de la clase: ";
    cin>>hor;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(200,'\n');
      cout<<"DEBE INGRESAR EL HORARIO EN NUMEROS."<<endl;
      cout<<"Ingrese el horario de la clase: ";
      cin>>hor;
    }
    while(hor<0 || hor>24)
    {
        cout<<"El horario debe estar dentro de las 24 horas."<<endl;
        cout<<"Ingrese el horario de la clase: ";
        cin>>hor;
        if(cin.fail())
        {
          cin.clear();
          cin.ignore(200,'\n');
          cin.clear();
          cin.ignore(200,'\n');
          cout<<"DEBE INGRESAR EL HORARIO EN NUMEROS."<<endl;
          cout<<"Ingrese el horario de la clase: ";
          cin>>hor;
        }
    }
    nueva.setHorario(hor);
    cout<<"Ingrese para que sexo es la clase(M,F,U): ";
    cin>>sex;
    while(sex[0]!='f' && sex[0]!='F' && sex[0]!='m' && sex[0]!='M' && sex[0]!='u' && sex[0]!='U')
    {
      cin.clear();
      cin.ignore(200,'\n');
      cout<<"Ingreso incorrecto."<<endl;
      cout<<"Ingrese el sexo(M,F,U): ";
      cin.getline(sex,2,'\n');
    }
    nueva.setSexo(sex);
    nueva.escribirEnDisco();

}


///____________________________________________________________________///



void cargarCupo_x_Clase()

{
    system("cls");
    char dni[11];
    int id;
    Clases aux;
    Cupo_x_Clase nuevo, reg;
    cin.ignore();
    cout<<"Ingrese el DNI del cliente: ";
    cin.getline(dni,11,'\n');
    if(buscarDNI_Cliente(dni))  nuevo.setDni(dni);
    else
    {
        cout<<"No existe cliente con ese DNI."<<endl;
        system("pause");
        return;
    }
    cout<<"Ingrese el ID de la Clase: ";
    cin>>id;
    while(cin.fail())
    {
      cin.clear();
      cin.ignore(200,'\n');
      cout<<"DEBE INGRESAR EL ID EN NUMEROS."<<endl;
      cout<<"Ingrese el ID de la Clase: ";
      cin>>id;
    }
    if(id>0 && id <= cantReg_Clases()) nuevo.setIdClase(id);
    else
    {
        cout<<"No existe clase con ese ID."<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantReg_Cupo_x_Clases();i++)
    {
        reg.leerDeDisco(i);
        if(reg.getIdClase()==id && 0==strcmp(reg.getDni(), dni) && reg.getEstado())
        {
            cout<<"El alumno ya esta inscripto."<<endl;
            system("pause");
            return;
        }
    }
    aux.leerDeDisco(id-1);
    if(chequearCupo(id))
    {
        if(nuevo.escribirEnDisco())cout<<"Cliente anotado."<<endl;
    }
    else cout<<"No hay cupo disponible."<<endl;
    system("pause");

}



///____________________________________________________________________///



void eliminarCupo_x_Clase()
{
    system("cls");
    Cupo_x_Clase aux;
    char dni[11];
    int id;
    Clases reg;
    cin.ignore();
    cout<<"Ingrese el DNI del cliente: ";
    cin.getline(dni,11,'\n');
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(200,'\n');
      cout<<"EL DNI DEBE TENER MÁXIMO 10 CARACTERES."<<endl;
      system("pause");
      return;
    }
    cout<<"Ingrese el ID de la clase: ";
    cin>>id;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(200,'\n');
      cout<<"DEBE INGRESAR EL ID EN NUMEROS."<<endl;
      system("pause");
      return;
      if(id<=0 || id>cantReg_Clases())
      {
          cout<<"ID inválido."<<endl;
          system("pause");
          return;
      }
    }
    for(int i=0;i<cantReg_Cupo_x_Clases();i++)
    {
        aux.leerDeDisco(i);
        if(id == aux.getIdClase() && 0==strcmpi(dni,aux.getDni()))
        {
            aux.setEstado();
            if(aux.modificarEnDisco(i))
            {
                cout<<"Alumno dado de baja de la clase."<<endl;
                system("pause");
                return;
            }
        }
    }
    cout<<"El alumno no esta anotado a la clase, o la clase no existe."<<endl;
    system("pause");
}


///____________________________________________________________________///



bool chequearCupo(int id)
{
    Clases aux;
    aux.leerDeDisco(id-1);
    if(aux.getCupo() > cantInscriptosClase(id-1)) return true;
    else return false;

}


///____________________________________________________________________///



void mostrarClase_x_ID()
{
    system("cls");
    int id;
    Clases reg;
    cin.ignore();
    cout<<"Ingrese el ID de la clase: ";
    cin>>id;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(200,'\n');
      cout<<"DEBE INGRESAR EL ID EN NUMEROS."<<endl;
      system("pause");
      return;
    }
    if(reg.leerDeDisco(id-1)){
        if(reg.getEstado())
        {
            system("cls");
            cout<<"Nombre: "<<reg.getNombreClase()<<endl;
            cout<<"Nombre del Profesor/a: "<<reg.getProfesorNombre()<<endl;
            cout<<"Apellido del Profesor/a: "<<reg.getProfesorApellido()<<endl;
            cout<<"Horario: "<<reg.getHorario()<<endl;
            cout<<"Duración: "<<reg.getDuracion()<<endl;
            cout<<"Sexo: "<<reg.getSexo()<<endl;
            cout<<"Cuenta con un cupo de "<<reg.getCupo()<<" personas."<<endl;
            cout<<"Cantidad de inscriptos actualmete: "<<cantInscriptosClase(id)<<endl;
            system("pause");
            return;
        }
    }
    cout<<"No existe una clase con ese ID."<<endl;
    system("pause");
}



///____________________________________________________________________///

int cantInscriptosClase(int id)
{
    int cont=0;
    Cupo_x_Clase aux;
    for(int i=0;i<cantReg_Cupo_x_Clases();i++)
    {
        aux.leerDeDisco(i);
        if(aux.getIdClase() == id && aux.getEstado()) cont++;
    }
    return cont;
}


///____________________________________________________________________///

bool Clases::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_CLASES,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Clases),1,p);
    fclose(p);
    return true;
}

bool Clases::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_CLASES,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Clases)* pos,0);
    fwrite(this,sizeof(Clases),1,p);
    fclose(p);
    return true;
}

bool Clases::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_CLASES,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Clases)* pos,0);
    fread(this,sizeof(Clases),1,p);
    fclose(p);
    return true;
}



///____________________________________________________________________///



int cantReg_Clases()
{
    FILE *p;
    int y;
    p=fopen(ARCH_CLASES, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Clases);
    fclose(p);
    return y;

}


///____________________________________________________________________///

bool chequearDieta(char *nombreDieta)
{
    Dieta dieta_reg;
    for(int i=0; i<cantReg_Dietas();i++){
    dieta_reg.leerDeDisco(i);
    if(0==strcmpi(nombreDieta,dieta_reg.getNombreDieta()) && dieta_reg.getEstado())
    {
        return true;
    }
    }
    return false;
}


///____________________________________________________________________///


bool chequearClase(char *nombreClase)
{
    Clases reg;
    for(int i=0; i<cantReg_Clases();i++){
    reg.leerDeDisco(i);
    if(0==strcmpi(nombreClase,reg.getNombreClase()) && reg.getEstado())
    {
        return true;
    }
    }
    return false;
}




void eliminarDieta()
{
    system("cls");
    int id;
    Dieta aux;
    cout<<"Ingrese el ID de la dieta: ";
    cin>>id;
    while(cin.fail() || id-1>cantReg_Dietas()-1)
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
           cout<<"Dieta Eliminada."<<endl;
           system("pause");
           return;
       }
}
#endif // DIETA_H_INCLUDED
