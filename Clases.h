#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

using namespace std;
/*ACLARACIONES

SEXO: 1=MASC 2=FEM 3=VACIO;
DIFICULTAD: 1=FACIL 2=MEDIA 3=DIFICIL 4=CON SEGUIMIENTO;
INTENSIDAD DE TRABAJO: 1=SIN MOVILIDAD 2=ALGO DE MOVILIDAD 3=CON ESFUERZO;



*/
///____________________________________________________________________///


const char ARCH_CLIENTES[25]="Datos/clientes.dat", ARCH_EJERCICIOS[25]="Datos/ejercicios.dat",ARCH_RUTINAS[25]="Datos/rutinas.dat";
const char ARCH_DIETAS[25]="Datos/dietas.dat", ARCH_USUARIOS[25]="Datos/usuarios.dat",ARCH_CLASES[25]="Datos/clases.dat";
const char ARCH_PAGOS[25]="Datos/pagos.dat", ARCH_EjX_Rutina[40]="Datos/Ejercicios_x_Rutinas.dat";
const char ARCH_MEDIDAS[25]="Datos/medidas.dat", ARCH_Cupo_Clase[25]="Datos/CuposClase.dat", ARCH_Rut_x_Cli[30]="Datos/Rutinas_x_Clientes.dat";

///____________________________________________________________________///


///FECHA
class Fecha
{
    private:
        int dia,mes,anio;
    public:
        Fecha(){}
        void setDia(int d){dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        void fechaActual();
        bool compararFecha();
        bool setFecha();
        bool operator<= (Fecha &f);
        bool operator>= (Fecha &f);
        void NumeroSerieaFecha(int);
        int NumeroSerie();
        void MostrarFechaTexto();
        bool esbisiesto(int);
        void MostrarFecha();
        bool chequearEdad();


};


///____________________________________________________________________///


///DOMICILIO
class Domicilio
{
    private:
        char calle[40], depto[3],localidad[40], prov[30], pais[30];
        int nCalle;
    public:
        void setCalle(char *street){strcpy(calle,street);}
        void setDepto(char *dep){strcpy(depto,dep);}
        void setLocalidad(char *loc){strcpy(localidad,loc);}
        void setProvincia(char *provincia){strcpy(prov,provincia);}
        void setPais(char *country){strcpy(pais,country);}
        void setNCalle(int n){nCalle=n;}
        char* getCalle(){return calle;}
        char* getDepto(){return depto;}
        char* getLocalidad(){return localidad;}
        char* getProvincia(){return prov;}
        char* getPais(){return pais;}
        int getNCalle(){return nCalle;}
};


///____________________________________________________________________///


///DIETA
class Dieta
{
    private:
        int carbs,prote,grasa,calorias, id;
        char nombreDieta[30];
        bool estado;

    public:
        Dieta(){
            strcpy(nombreDieta,"SIN DIETA");
            carbs=0;
            prote=0;
            grasa=0;
            calorias=0;
            id=cantReg_Dietas()+1;
            estado=true;
            }
        void setCarbs(int c){carbs=c;}
        void setProte(int p){prote=p;}
        void setGrasa(int g){grasa=g;}
        void setCalorias(int cal){calorias=cal;}
        void setNombreDieta(char *n){strcpy(nombreDieta,n);}
        int getCarbs(){return carbs;}
        int getProte(){return prote;}
        int getGrasa(){return grasa;}
        int getCalorias(){return calorias;}
        char* getNombreDieta(){return nombreDieta;}
        bool escribirEnDisco();
        bool leerDeDisco(int);
        bool modificarEnDisco(int);
        bool getEstado(){return estado;}
        void setEstado(){estado=false;}
        int getID(){return id;}

};


///____________________________________________________________________///


///MEDIDAS
class Medidas
{
    private:
        char dni[11];
        float altura,peso,cintura,cadera,circBiTri,circAnte,circCuadIsq,circGemSol,circPecho,anchoEspalda;
        float imc,porcGraso;
        Fecha fechaMedida;
        int id;
        bool estado;

    public:
        Medidas(){estado=true;
        id=cantReg_Medidas()+1;}
        void setDni(char *doc){strcpy(dni,doc);}
        void setAltura(float a){altura=a;}
        void setPeso(float p){peso=p;}
        void setCintura(float c){cintura=c;}
        void setCadera(float ca){cadera=ca;}
        void setCircBiTri(float bitri){circBiTri=bitri;}
        void setCircAnte(float ante){circAnte=ante;}
        void setCircCuadIsq(float cuadisq){circCuadIsq=cuadisq;}
        void setCircGemSol(float gemsol){circGemSol=gemsol;}
        void setCircPecho(float pecho){circPecho=pecho;}
        void setAnchoEspalda(float espalda){anchoEspalda=espalda;}
        void setIMC(){imc=peso/((altura/100)*(altura/100));}
        void setPorcGraso(float graso){porcGraso=graso;}
        void setFechaMed(Fecha f){fechaMedida=f;}
        char* getDni(){return dni;}
        float getAltura(){return altura;}
        float getPeso(){return peso;}
        float getCintura(){return cintura;}
        float getCadera(){return cadera;}
        float getCircBiTri(){return circBiTri;}
        float getCircAnte(){return circAnte;}
        float getCircCuadIsq(){return circCuadIsq;}
        float getCircGemSol(){return circGemSol;}
        float getCircPecho(){return circPecho;}
        float getAnchoEspalda(){return anchoEspalda;}
        float getIMC(){return imc;}
        float getPorcGraso(){return porcGraso;}
        Fecha getFecha(){return fechaMedida;}
        bool escribirEnDisco();
        bool leerDeDisco(int);
        int getId(){return id;}
        bool getEstado(){return estado;}

};


///____________________________________________________________________///


///EJERCICIOS
class Ejercicios
{
    private:
        char nombreEjer[25],musculo[20];
        int  id;
        bool estado;

    public:
        Ejercicios(){estado=true;
        id=cantReg_Ejercicios()+1;}
        void setNombreEjer(char *name){strcpy(nombreEjer,name);}
        void setMusculo(char *muscle){strcpy(musculo,muscle);}
        char* getNombreEjer(){return nombreEjer;}
        char* getMusculo(){return musculo;}
        bool getEstado(){return estado;}
        bool modificarEnDisco(int);
        bool leerDeDisco(int);
        bool escribirEnDisco();
        void mostrar();
        int getId(){return id;}
        void setEstado(){estado=false;}
};


///____________________________________________________________________///



///CLASES
class Clases
{
    private:
        char nombreClase[25], profesorNombre[25],profesorApellido[25], sexo[2];
        int cupo, duracion, horario, id;
        bool estado;
    public:
        Clases(){estado=true;
        id=cantReg_Clases()+1;}
        void setNombreClase(char *name){strcpy(nombreClase,name);}
        void setProfesorNombre(char *profname){strcpy(profesorNombre,profname);}
        void setProfesorApellido(char *profapell){strcpy(profesorApellido,profapell);}
        void setDuracion(int dur){duracion=dur;}
        void setHorario(int hora){horario=hora;}
        void setSexo(char *sex){strcpy(sexo,sex);}
        void setCupo(int cup){cupo=cup;}
        void setEstado(){estado=false;}
        char* getNombreClase(){return nombreClase;}
        char* getProfesorNombre(){return profesorNombre;}
        char* getProfesorApellido(){return profesorApellido;}
        int getDuracion(){return duracion;}
        int getHorario(){return horario;}
        char* getSexo(){return sexo;}
        int getCupo(){return cupo;}
        bool modificarEnDisco(int);
        bool leerDeDisco(int);
        bool escribirEnDisco();
        bool getEstado(){return estado;}
        int getId(){return id;}
};


///____________________________________________________________________///



///CUPO POR CLASE
class Cupo_x_Clase
{
    private:
        char dni[11];
        int idClase;
        bool estado;
    public:
        Cupo_x_Clase(){estado=true;}
        void setIdClase(int i){idClase=i;}
        void setDni(char *doc){strcpy(dni,doc);}
        void setEstado(){estado=false;}
        bool getEstado(){return estado;}
        char* getDni(){return dni;}
        int getIdClase(){return idClase;}
        bool modificarEnDisco(int);
        bool leerDeDisco(int);
        bool escribirEnDisco();
};


///____________________________________________________________________///



///RUTINA
class Rutina
{
    private:
        int id;
        char nombre[30];
        bool estado;
    public:
            Rutina(){id=0;
                strcpy(nombre,"NO TIENE RUTINA");
                estado=true;}
            void setNombre(char *name){strcpy(nombre,name);}
            char* getNombre(){return nombre;}
            bool escribirEnDisco();
            bool leerDeDisco(int);
            bool modificarEnDisco(int);
            void setId(){id=cantReg_Rutina()+1;};
            int getId(){return id;}
            bool chequearRutina();
            bool getEstado(){return estado;}
            void setEstado(){estado=false;}
};


///____________________________________________________________________///



class Ejercicios_x_Rutina
{
    private:
            int idRutina, idEjercicio;
            bool estado;
    public:
            Ejercicios_x_Rutina(){estado=true;}
            void setIdRutina(int idR){idRutina=idR;}
            void setIdEjercicio(int idE){idEjercicio=idE;}
            void setEstado(){estado=false;}
            bool escribirEnDisco();
            bool leerDeDisco(int);
            bool modificarEnDisco(int);
            bool chequearEjNombre();
            int getIdRutina(){return idRutina;}
            int getIdEjercicio(){return idEjercicio;}
};


///____________________________________________________________________///



///PAGOS
class Pagos
{
    private:
        int tipoPago, formaPago, id;
        //Tipo: 1=Mes, 2=Año.
        //Forma: 1=Efec, 2=Deb 3=Cred.
        char dni[11];
        int mes, anio;
        Fecha fechaPago;
    public:
        Pagos(){id=cantReg_Pagos()+1;}
        void setDni(char *doc){strcpy(dni,doc);}
        void setTipoPago(int tipo){tipoPago=tipo;}
        void setFormaPago(int forma){formaPago=forma;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        void setFechaPago(Fecha f){fechaPago=f;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        int getTipoPago(){return tipoPago;}
        int getFormaPago(){return formaPago;}
        //float getMonto(){return monto;}
        char* getDni(){return dni;}
        Fecha getFecha(){return fechaPago;}
        bool modificarEnDisco(int);
        bool leerDeDisco(int);
        bool escribirEnDisco();
        int getId(){return id;}
};


///____________________________________________________________________///




///Rutina x Cliente

class Rutina_x_Cliente
{
    private:
        char dni[11];
        int idRutina;
        bool estado;
    public:
        Rutina_x_Cliente(){estado=true;}
        void setIdRutina(int id){idRutina=id;}
        void setDni(char *doc){strcpy(dni,doc);}
        void setEstado(){estado=false;}
        int getIdRutina(){return idRutina;}
        char* getDni(){return dni;}
        bool getEstado(){return estado;}
        bool escribirEnDisco();
        bool modificarEnDisco(int);
        bool leerDeDisco(int);
};

///____________________________________________________________________///



///CLIENTES
class Clientes
{
    private:
        char dni[11], nombre[25], apellido[30], email[50], obraSocial[30], factorSanguineo[3], telefono[20], sexo[2];
        Fecha fechaNac, fechaInscripcion;
        char dietaActual[30];
        int id;
        Domicilio domicilioActual;
        bool estado;

    public:
        ///Constructor
        Clientes()
        {
            estado=true;
            id=cantReg_Clientes()+1;
        }
        void setDni(char *documento){strcpy(dni,documento);}
        void setNombre(char *name){strcpy(nombre,name);}
        void setApellido(char *surname){strcpy(apellido,surname);}
        void setSexo(char *sex){strcpy(sexo,sex);}
        void setEstado(){estado=false;}
        void setTelefono(char *tel){strcpy(telefono,tel);}
        void setFactor(char *factor){strcpy(factorSanguineo,factor);}
        void setObraSocial(char *obra){strcpy(obraSocial,obra);}
        void setEmail(char *mail){strcpy(email,mail);}
        void setDomicilio(Domicilio dom){domicilioActual=dom;}
        char* getTelefono(){return telefono;}
        char* getDni(){return dni;}
        char* getNombre(){return nombre;}
        char* getApellido(){return apellido;}
        char* getSexo(){return sexo;}
        char* getFactor(){return factorSanguineo;}
        char* getObraSocial(){return obraSocial;}
        char* getEmail(){return email;}
        Domicilio getDomicilio(){return domicilioActual;}
        Fecha getFechaNac(){return fechaNac;}
        Fecha getFechaInsc(){return fechaInscripcion;}
        bool modificarEnDisco(int);
        bool leerDeDisco(int);
        bool escribirEnDisco();
        void mostrar();
        void cargarFechaNac(Fecha f){fechaNac=f;}
        void cargarFechaInsc(Fecha f){fechaInscripcion=f;}
        void setClienteDieta(char *d){strcpy(dietaActual,d);}
        char* getClienteDieta(){return dietaActual;}
        bool getEstado(){return estado;}
        int getId(){return id;}
};






///____________________________________________________________________///



///USUARIO
class Usuario
{
    private:
        char userid[15], pass[10];
        bool userAdm, permAdm, estado;
        int id;

    public:
        ///CONSTRUCTOR
        Usuario()
        {
               if(!(cantReg_Usuarios()))
                {
                    userAdm=true;
                    permAdm=true;
                }
                else
                {
                    userAdm=false;
                    permAdm=false;
                }
                id=cantReg_Usuarios()+1;
        }
        ///DESTRUCTOR
        ~Usuario(){};

        void setUserId(char *name){strcpy(userid,name);}
        void setPass(char *p){strcpy(pass,p);}
        void setDarPermAdm(){permAdm=true;}
        void setQuitarPermAdm(){permAdm=false;}
        char* getUserId(){return userid;}
        char* getPass(){return pass;}
        bool comprobarUsuario();
        bool comprobarUsuarioAdm();
        bool comprobarPermisosAdm();
        bool ingresar_usuario();
        bool chequearUsuario();
        bool chequearContra();
        bool modificarEnDisco(int);
        bool leerDeDisco(int);
        bool escribirEnDisco();
        void mostrar();
        int getId(){return id;}
};
///____________________________________________________________________///
#endif // CLASES_H_INCLUDED
