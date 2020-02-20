#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

#include <conio.h>
//Prototipos Generales


///____________________________________________________________________///



bool Usuario::modificarEnDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_USUARIOS,"rb+");
    if(p==NULL)return false;
    fseek(p,sizeof(Usuario)* pos,0);
    fwrite(this,sizeof(Usuario),1,p);
    fclose(p);
    return true;
}

bool Usuario::leerDeDisco(int pos)
{
    FILE *p;
    p=fopen(ARCH_USUARIOS,"rb");
    if(p==NULL)return false;
    fseek(p,sizeof(Usuario)* pos,0);
    fread(this,sizeof(Usuario),1,p);
    fclose(p);
    return true;
}

bool Usuario::escribirEnDisco()
{
    FILE *p;
    p=fopen(ARCH_USUARIOS,"ab");
    if(p==NULL)return false;
    fwrite(this,sizeof(Usuario),1,p);
    fclose(p);
    return true;
}



///____________________________________________________________________///



void crear_usuario()
{
    system("cls");
    Usuario nuevo;
    char name[15], pass[10];
    if(nuevo.comprobarUsuarioAdm()){
    system("cls");
    cout<<"Ingrese el nombre de usuario: ";
    cin.getline(name,15,'\n');
    nuevo.setUserId(name);
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"El nombre de usuario no puede tener mas de 15 caracteres."<<endl;
        cout<<endl<<"Ingrese el nombre de usuario: ";
        cin.getline(name,15,'\n');
    }
    if(nuevo.chequearUsuario()){
    cout<<"Ingrese la contraseña: ";
    cin.getline(pass,10,'\n');
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"La contraseña no puede tener mas de 10 caracteres."<<endl;
        cout<<"Ingrese la contraseña: ";
        cin.getline(pass,10,'\n');
    }
    nuevo.setPass(pass);
    if(nuevo.chequearContra()){
    if(nuevo.escribirEnDisco())
    {
        cout<<"Usuario creado."<<endl;
        system("pause");

    }
    else cout<<"No se puedo guardar el usuario."<<endl;
        }
    }
 }
}



///____________________________________________________________________///



void crear_usuarioAdm()
{
    system("cls");
    Usuario nuevo;
    char name[15], pass[10];
    system("cls");
    cout<<"Se va a crear el usuario administrador: "<<endl;
    cout<<endl<<"Ingrese el nombre de usuario: ";
    cin.getline(name,15,'\n');
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"El nombre de usuario no puede tener mas de 15 caracteres."<<endl;
        cout<<endl<<"Ingrese el nombre de usuario: ";
        cin.getline(name,15,'\n');
    }
    nuevo.setUserId(name);
    cout<<"Ingrese la contraseña: ";
    cin.getline(pass,10,'\n');
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout<<"La contraseña no puede tener mas de 10 caracteres."<<endl;
        cout<<"Ingrese la contraseña: ";
        cin.getline(pass,10,'\n');
    }
    nuevo.setPass(pass);

    if(nuevo.chequearContra()){
    if(nuevo.escribirEnDisco())
    {
        cout<<"Usuario creado."<<endl;
        system("pause");

    }
    else cout<<"No se puedo guardar el usuario."<<endl;
        }
}



///____________________________________________________________________///



bool ingresar_usuario()
{
    system("cls");
    Usuario ingreso;
    char id[15],pass[10];
    cout<<"BIENVENIDO: "<<endl;
    cout<<endl<<"Ingrese sus datos: "<<endl;
    cout<<"Usuario: ";
    cin.getline(id,15,'\n');
    ingreso.setUserId(id);
    cout<<"Contraseña: ";
     for (int i=0;i<10;i++)
     {
      pass[i] = getch();
      if(pass[i]==13)
      {
          pass[i]='\0';
          break;
      }
      cout<<"*";
     }
     cout<<endl;
    ingreso.setPass(pass);
    return ingreso.comprobarUsuario();
}


///____________________________________________________________________///



bool Usuario::comprobarUsuario()
{
    Usuario aux;
    for(int i=0;i<cantReg_Usuarios();i++)
    {
        aux.leerDeDisco(i);
        if(0==strcmp(this->userid,aux.userid) && 0==strcmp(this->pass,aux.pass))
        {
                return true;
        }
        }
    cout<<"Usuario inválido."<<endl;
    system("pause");
    return false;
}


///____________________________________________________________________///



 void listarUsuarios()
 {
     Usuario reg;
     system("cls");
     cout<<"SOLO EL USUARIO ADMINISTRADOR PUEDE VER LOS USUARIOS Y CONTRASEÑAS."<<endl;
    if(reg.comprobarUsuarioAdm())
     {
         system("cls");
         for(int i=0; i<cantReg_Usuarios();i++){
         reg.leerDeDisco(i);
         reg.mostrar();
       }
       system("pause");
     }
 }


 ///____________________________________________________________________///



 void Usuario::mostrar()
 {

         cout<<endl<<"Usuario: "<<this->userid<<endl;
         cout<<"Contraseña: "<<this->pass<<endl;
         cout<<"ADMINISTRADOR: "<<this->userAdm<<endl;
         cout<<"PERMISOS DE ADMINISTRADOR: "<<this->permAdm<<endl;
         cout<<"-----------------"<<endl;
 }



 ///____________________________________________________________________///



bool Usuario::comprobarUsuarioAdm()
 {
    Usuario reg;
    char id[15],p[10];
    cin.ignore();
    cout<<"Ingrese el usuario administrador: ";
    cin.getline(id,15,'\n');
    cout<<"Ingrese la contraseña: ";
    for (int i=0;i<10;i++)
     {
      p[i] = getch();
      if(p[i]==13)
      {
          p[i]='\0';
          break;
      }
      cout<<"*";
     }
     cout<<endl;
    for(int i=0; i<cantReg_Usuarios();i++)
    {
        reg.leerDeDisco(i);
        if(0==strcmp(id,reg.userid) && 0==strcmp(p,reg.pass) && reg.userAdm==true)
        {
            return true;
        }
    }
    cout<<"No es usuario administrador."<<endl;
    system("pause");
    return false;
}


///____________________________________________________________________///



int cantReg_Usuarios()
{
    FILE *p;
    int y;
    p=fopen(ARCH_USUARIOS, "rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    y=ftell(p)/sizeof(Usuario);
    fclose(p);
    return y;

}


///____________________________________________________________________///



bool Usuario::comprobarPermisosAdm()
 {
    Usuario chequeo;
    char id[15],p[10];
    cout<<"Ingrese el usuario:";
    cin.getline(id,15,'\n');
    cout<<"Ingrese la contraseña:";
    cin.getline(p,10,'\n');
    for(int i=0; i<cantReg_Usuarios();i++)
    {
        chequeo.leerDeDisco(i);
        if(0==strcmp(chequeo.userid,id) && 0==strcmp(chequeo.pass,p) && chequeo.permAdm==true)
        {
            return true;
        }
    }
    cout<<"No tiene permisos de administrador."<<endl;
    system("pause");
    return false;
}


///____________________________________________________________________///



void darPermisoAdministrador()
{
    system("cls");
    Usuario chequeo;
    char id[15];

    if(chequeo.comprobarUsuarioAdm())
    {
        cout<<"Ingrese el usuario al que le quiere dar permisos:"<<endl;
        cin.getline(id,15,'\n');
        for(int i=0; i<cantReg_Usuarios();i++)
        {
            chequeo.leerDeDisco(i);
            if(strcmp(id,chequeo.getUserId())==0)
            {
                chequeo.setDarPermAdm();
                if(chequeo.modificarEnDisco(i))cout<<"Permiso Modificado."<<endl;
                system("pause");
                return;

            }
        }
        cout<<"Usuario Inexistente."<<endl;
        system("pause");
        return;
    }
}


///____________________________________________________________________///



void quitarPermisoAdministrador()
{
    system("cls");
    Usuario chequeo;
    char id[15];

    if(chequeo.comprobarUsuarioAdm())
    {
        cout<<"Ingrese el usuario al que le quiere dar permisos:"<<endl;
        cin.getline(id,15,'\n');
        for(int i=0; i<cantReg_Usuarios();i++)
        {
            chequeo.leerDeDisco(i);
            if(strcmp(id,chequeo.getUserId())==0)
            {
                chequeo.setQuitarPermAdm();
                if(chequeo.modificarEnDisco(i))cout<<"Permiso Modificado."<<endl;
                system("pause");
                return;
            }
        }
        cout<<"Usuario Inexistente."<<endl;
        system("pause");
        return;
    }
}


///____________________________________________________________________///



bool Usuario::chequearUsuario()
{
    Usuario chequeo;
    for(int i=0; i<cantReg_Usuarios();i++)
    {
        chequeo.leerDeDisco(i);
        if(0==strcmp(chequeo.userid,this->userid))
        {
            return false;
        }
        }

    return true;
}


///____________________________________________________________________///



bool Usuario::chequearContra()
{
    char cheqpassword[10];
    cout<<"Reingrese la contraseña: ";
    cin.getline(cheqpassword,10,'\n');
    if(0!=strcmp(this->pass,cheqpassword))
       {
           cout<<"Las contraseñas no coinciden."<<endl;
           return false;
       }
    return true;
}

///____________________________________________________________________///


#endif // USUARIOS_H_INCLUDED
