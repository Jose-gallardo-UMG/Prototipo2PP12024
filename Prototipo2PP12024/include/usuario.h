#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class usuario
{
    public:
        usuario(string usuarios,string contrasena);

        string setUser(string usuarios);
        string getUser();

        string setContrasena(string contrasena);
        string getContrasena();


        bool VerificarUsuario();

        void MenuUser();
        void IngresarUser();
        void DesplegarUSer();
        void ModificarUser();
        void BorrarUser();


    private:
        string usuarios,contrasena;
};

#endif // USUARIO_H
