#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

void Fecha::fechaActual()
{
{
    time_t fechaHoraSistema;
    struct tm *fechaSistema;
    time(&fechaHoraSistema);
    fechaSistema = localtime(&fechaHoraSistema);
    anio=fechaSistema->tm_year+1900;
    mes=fechaSistema->tm_mon+1;
    dia=fechaSistema->tm_mday;
    }
}
///____________________________________________________________________///



bool Fecha::compararFecha()
{
    Fecha fechaAc;
    fechaAc.fechaActual();
    if(this->anio > fechaAc.anio) return false;
    else if(this->mes > fechaAc.mes && this->anio == fechaAc.anio) return false;
    else if(this->dia > fechaAc.dia && this->mes >= fechaAc.mes) return false;
    else return true;
}


///____________________________________________________________________///



bool Fecha::setFecha()
{
    int a,m,d;
    cout<<"Ingrese el dia: ";
    cin>>d;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el dato en numeros."<<endl;
        cout<<"Ingrese el dia: ";
        cin>>d;
    }
    cout<<"Ingrese el mes: ";
    cin>>m;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el dato en numeros."<<endl;
        cout<<"Ingrese el mes: ";
        cin>>m;
    }
    cout<<"Ingrese el año: ";
    cin>>a;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"Ingrese el dato en numeros."<<endl;
        cout<<"Ingrese el año: ";
        cin>>a;
    }
    if(d<1 || m<1 || a<1)
    {
        cout<<"FECHA INVÁLIDA."<<endl;
        return false;
    }
    if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 ||m == 12) && d < 32)
    {
        setDia(d);
        setMes(m);
        setAnio(a);
        return true;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d < 31)
    {
        setDia(d);
        setMes(m);
        setAnio(a);
        return true;
    }
    else if(esbisiesto(a))
    {
        if (m == 2 && d < 30)
    {
        setDia(d);
        setMes(m);
        setAnio(a);
        return true;
    }
    }
    else if (m == 2 && d < 29)
    {
        setDia(d);
        setMes(m);
        setAnio(a);
        return true;
    }

    cout<<"FECHA INVÁLIDA."<<endl;
    return false;
}


///____________________________________________________________________///



bool Fecha::operator <=(Fecha &f)
{
    if(anio<f.anio){return true;}
    else if(anio>f.anio){return false;}
    else
    {
        if(mes>f.mes){return false;}
        else if(mes<f.mes){return true;}
        else
        {
            if(dia>f.dia){return false;}
            else{return true;}
        }
    }
}

///____________________________________________________________________///



bool Fecha::operator >=(Fecha &f)
{
    if(anio>f.anio){return true;}
    else if(anio<f.anio){return false;}
    else
    {
        if(mes<f.mes){return false;}
        else if(mes>f.mes){return true;}
        else
        {
            if(dia<f.dia){return false;}
            else{return true;}
        }
    }
}

///____________________________________________________________________///



bool Fecha::esbisiesto(int a)
{
  bool bisiesto=false;
  if(a%4==0)
     bisiesto=true;
  if((a%100==0) && (a%400!=0))
           bisiesto=false;
  return bisiesto;
}


///____________________________________________________________________///


void Fecha::MostrarFecha()
{
  cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

///____________________________________________________________________///



void Fecha::MostrarFechaTexto()
{
char mmes[12][10];
  strcpy(mmes[0],"Enero");
  strcpy(mmes[1],"Febrero");
  strcpy(mmes[2],"Marzo");
  strcpy(mmes[3],"Abril");
  strcpy(mmes[4],"Mayo");
  strcpy(mmes[5],"Junio");
  strcpy(mmes[6],"Julio");
  strcpy(mmes[7],"Agosto");
  strcpy(mmes[8],"Septiembre");
  strcpy(mmes[9],"OCtubre");
  strcpy(mmes[10],"Noviembre");
  strcpy(mmes[11],"Diciembre");


  int cantdias=NumeroSerie()-1;//cantidad de días transcurridos desde 01/01/1900
  //El 01/01/1900 fue Lunes
  int numerodia=cantdias%7;

  char mdia[7][10];
  strcpy(mdia[0],"Lunes");
  strcpy(mdia[1],"Martes");
  strcpy(mdia[2],"Miercoles");
  strcpy(mdia[3],"Jueves");
  strcpy(mdia[4],"Viernes");
  strcpy(mdia[5],"Sábado");
  strcpy(mdia[6],"Domingo");

  cout<<endl<<mdia[numerodia]<<" "<<dia<<" de "<<mmes[mes-1]<<" de "<<anio<<endl;
  }

///____________________________________________________________________///



int Fecha::NumeroSerie()
  {
    int cont=0,i;
    for(i=1900;i<anio;i++)
      if(esbisiesto(i)) cont++;
    int vmes[]={31,28,31,30,31,30,31,31,30,31,31,31},suma=0;
    if(esbisiesto(anio)) vmes[1]=29;
    for(int i=0;i<mes-1;i++)  suma+=vmes[i];
    int cantdias=(anio-1900)*365+cont+suma+dia;
    return cantdias;
  }

///____________________________________________________________________///



void Fecha::NumeroSerieaFecha(int ns)
{
  int suma=0, dia_adicional, suma_ant;
  int anio_real=1900;
  while(ns>suma)
    {
    dia_adicional=(esbisiesto(anio_real)?1:0);
    suma_ant=suma;
    suma+=365+dia_adicional;
    anio_real++;
    }
   anio=anio_real-1;
   //Cantidad de días pasados desde anio
  int dias_anio_actual=ns-suma_ant,i=0;
  int vmes[]={31,28,31,30,31,30,31,31,30,31,31,31};
  if(esbisiesto(anio)) vmes[1]=29;
  suma=0;
  while(dias_anio_actual>suma) suma+=vmes[i++];
  mes=i;
  dia=dias_anio_actual-(suma-vmes[i-1]);
 }

 ///____________________________________________________________________///


 bool Fecha::chequearEdad()
 {
     Fecha aux;
     aux.fechaActual();
     if(anio<aux.getAnio()-100){
         cout<<"Es mayor de 100 años."<<endl;
         return false;}
     else if(anio > aux.getAnio()-16){
            cout<<"Es menor de 16 años."<<endl;
            return false;}
     return true;
 }


 void mostrarMes(int mes)
 {
     switch(mes)
     {
         case 1: cout<<"ENERO."<<endl;
         break;
         case 2: cout<<"FEBRERO."<<endl;
         break;
         case 3: cout<<"MARZO."<<endl;
         break;
         case 4: cout<<"ABRIL."<<endl;
         break;
         case 5: cout<<"MAYO."<<endl;
         break;
         case 6: cout<<"JUNIO."<<endl;
         break;
         case 7: cout<<"JULIO."<<endl;
         break;
         case 8: cout<<"AGOSTO."<<endl;
         break;
         case 9: cout<<"SEPTIEMBRE."<<endl;
         break;
         case 10: cout<<"OCTUBRE."<<endl;
         break;
         case 11: cout<<"NOVIEMBRE."<<endl;
         break;
         case 12: cout<<"DICIEMBRE."<<endl;
         break;
         default: cout<<"EL MES PEDIDO ES INCORRECTO."<<endl;
     }
 }
#endif // FECHA_H_INCLUDED
