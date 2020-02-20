#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

Domicilio cargarDomicilio()
{
    Domicilio nuevo;
    char street[40], dep[3],loc[40], p[30], country[30];
    int numero;
    //cin.ignore();
    cout<<"Ingrese la calle: ";
    cin.getline(street,40,'\n');
    while(strlen(street)==0)
    {
      cout<<"La calle no puede ser un campo vacío."<<endl;
      cout<<"Ingrese la calle: ";
      cin.getline(street,40,'\n');

    }
    nuevo.setCalle(street);
    cout<<"Ingrese el numero: ";
    cin>>numero;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingreso incorrecto."<<endl;
        cout<<"Ingrese el numero: ";
        cin>>numero;
    }
    nuevo.setNCalle(numero);
    cin.ignore();
    cout<<"Ingrese el numero o letra del departamento: ";
    cin.getline(dep,3,'\n');
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingreso incorrecto(2 caracteres máximo)."<<endl;
        cout<<"Ingrese el numero letra del departamento: ";
        cin.getline(dep,3,'\n');
    }
    nuevo.setDepto(dep);
    cout<<"Ingrese la localidad: ";
    cin.getline(loc,40,'\n');
    while(strlen(loc)==0)
    {
        cout<<"La localidad no puede ser un campo vacío."<<endl;
        cout<<"Ingrese la localidad: ";
        cin.getline(loc,40,'\n');
    }
    nuevo.setLocalidad(loc);
    cout<<"Ingrese la provincia: ";
    cin.getline(p,30,'\n');
    nuevo.setProvincia(p);
    cout<<"Ingrese el pais: ";
    cin.getline(country,30,'\n');
    nuevo.setPais(country);
    return nuevo;
}

///____________________________________________________________________///


#endif // DOMICILIO_H_INCLUDED
