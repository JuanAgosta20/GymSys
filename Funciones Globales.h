#ifndef FUNCIONES_GLOBALES_H_INCLUDED
#define FUNCIONES_GLOBALES_H_INCLUDED

//Prototipos

void exportarClientesExcel();
void darPermisoAdministrador();
void quitarPermisoAdministrador();


///____________________________________________________________________///




///LISTAR
void listarUsuarios();
void listarCliente_DNI();
void mostrarDieta();
void mostrarEjercicio();
void mostrarRutinasxCliente(char*);
void mostrarRutina_nombre(char*);
void mostrarRutina_ID(int);
void medidaActual_DNI();
void mostrarClase_x_ID();
void mostrarClases_x_Cliente(char*);
void listarClientes_Todos(int);
void listarClientesxRangoDeFechas(int);
void listarEjerciciosxDificultad();
void listarEjerciciosOrdxMusculo();
void listarRutinasxNombre();
void listarDietasxNombre();
void listarDietasxVariables(int);
void listarClases(int);
void listarRutinasxCliente();
void informeProgreso();
void informeDietaMasUsada();
void informeRutinaMasUsada();
void informeMesDeAnioActualMayorInsc();
void mostrarMes(int);
//bool devuelveClasexID(int, Clases&);

///____________________________________________________________________///



///CARGAR
void cargarDieta();
void cargarPago();
void cargarCliente();
void cargarEjercicio();
void crear_usuario();
void crear_usuarioAdm();
void cargarRutina();
void cargarEj_x_Rutina();
void cargarMedidas();
void cargarClase();
void cargarCupo_x_Clase();
void cargarRutina_x_Cliente();

///____________________________________________________________________///



///CANTIDAD DE REGISTROS
int cantReg_Usuarios();
int cantReg_Ejercicios();
int cantReg_Dietas();
int cantReg_Pagos();
int cantReg_Clientes();
int cantReg_Rutina();
int cantReg_Medidas();
int cantReg_Clases();
int cantReg_Cupo_x_Clases();
int cantReg_EjxRut();
int cantReg_Rutina_x_Cliente();
int cantInscriptosClase(int);

///____________________________________________________________________///


///MODIFICAR
void modificarCliente();
void eliminarCliente();
void eliminarCupo_x_Clase();
void eliminarClase();
void eliminarRutina();
void eliminarEjercicio();
void eliminarDieta();

///____________________________________________________________________///



///MENÚS
void menuRestBkp();
void menuHacerBkp();
void menuBackups();
void menuUsuarios();
void menuConfiguracion();
void menuClientes();
void menuReportes();
void menuConsultas();
void menuPagos();
void menuListados();
void menuListadosClientes();
void menuListadosEjercicios();
void menuListadosRutinas();
void menuListadosDietas();
void menuListadosClases();
void menuInformes();

///____________________________________________________________________///


///CHEQUEOS
bool chequearIdRutina(int);
bool chequearRutina(char*);
bool chequearIdEjercico(int);
bool buscarDNI_Cliente(const char*);
bool chequearCupo(int);
bool chequearDieta(char*);
bool chequearClase(char*);
bool chequearPago(char*);


///____________________________________________________________________///


void ponerVec0_INT(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        v[i]=0;
    }
}


int buscarMayor(int *v, int tam)
{
    int maximo=0, maxpos=0;
    for(int i=0; i<tam; i++)
    {
        if(i==0)
        {
            maximo=v[i];
            maxpos=i;
        }
        else if(v[i]>maximo)
        {
            maximo=v[i];
            maxpos=i;
        }
    }
    return maxpos;
}

#endif // FUNCIONES_GLOBALES_H_INCLUDED
