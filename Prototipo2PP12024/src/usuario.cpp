#include "usuario.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

usuario::usuario(string usuario, string contrasena)//parametros de la clase
{
    this -> usuarios=usuarios;
    this -> contrasena=contrasena;
}

string usuario::setUser(string usuarios)
{
    this -> usuarios=usuarios;
}

string usuario::getUser()
{
    return this->usuarios;
}

string usuario::setContrasena(string contrasena)
{
    this -> contrasena=contrasena;
}

string usuario::getContrasena()
{
    return this->contrasena;
}

//muestra el menu del login para ingresar
bool usuario::VerificarUsuario()
{
    string usuario,contrasena;
    int contador= 0; // contador de intentos
    bool encontrado =false; // indica si encontro user y contra

    //el ciclo se repite mientras el numero de intentos sea menor a 3 o no se encuentre user valido
    while(contador<3 && !encontrado)
    {
         system("cls");
    cout <<"\t\t\t--------------------"<<endl;
    cout <<"\t\t\t| LONGIN DE USUARIO |"<<endl;
    cout <<"\t\t\t---------------------"<<endl;

    // Mostrar mensaje de advertencia
    cout <<"\n\tSolo tienes permitido 3 intentos"<<endl;
    cout <<"\t----------------------------------"<<endl;


    cout << "\t\t\t\nIngrese el nombre de usuario:         ";
    cin >> usuario;
    cout << "\t\t\t\nIngrese la contrasena:         ";
    char caracter;
    caracter = getch();


    contrasena="";
        while (caracter!=13)
        {
        if(caracter !=8)
            {
                contrasena.push_back(caracter);
                cout<<".";
            }
        else
            {
                if(contrasena.length()>0)
                {
                    cout<<"\b \b";
                    contrasena=contrasena.substr(0,contrasena.length()-1);
                }
            }
            caracter=getch();
        }

    //abrira el archivo de Usuario y contraseñas--------------------------
    ifstream fileU_P;
    fileU_P.open("usuarios_y_contrasenas.txt",ios::in);


    //verificar si se abrio el archivo
    if (!fileU_P)
    {
        cout<<"No es posible abrir el archivo."<<endl;
        fileU_P.close();
        return false;
    }

    //busca el usuario en el archivo
    string user,pass;
    while (fileU_P>>user>>pass)
    {
        if (user==usuario && pass==contrasena)
        {
            encontrado=true;
            break;
        }
    }
     fileU_P.close();

    //si no encuentra user y pass , el contador incrementara
    if(!encontrado)
    {
        cout << "\n\tUSUARIO Y/O CONTRASEÑA INCORRECTOS" << endl;
        cout << "\n\tPerdio un intento, Intente de nuevo" << endl;
        contador++;
        system("pause");
    }
}

    //Si encuentra a usuario y contraseña , se retornara un true
   if (encontrado)
    {
    cout << "\n\tBienvenido " << usuario << "!" << endl;
    return true;
    }
   else
    {
    cout << "\n\tPERDIO LOS 3 INTENTOS" << endl;
    cout << "\n\tNO PODRA INGRESAR MAS INTENTOS" << endl;
    return false;
    }





}

void usuario::MenuUser()
{

    int opcion;
    char x;
    bool repetir=true;
    system("cls");
   do
   {

     cout <<"\t\t\t--------------------------------------------"<<endl;
    cout <<"\t\t\t |       BIENVENIDO AL MENU De USUARIOS     |"<<endl;
    cout <<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Nuevos Usuarios"<<endl;
	cout<<"\t\t\t 2. Despliegue De Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificar Usuarios"<<endl;
	cout<<"\t\t\t 4. Borrar Usuarios"<<endl;
	cout<<"\t\t\t 5. SALIR"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";

    cin>>opcion;

    switch(opcion)

   //--------------------------------------------------------------------------------------------------
    {

    case 1:
        do
            {  IngresarUser(); //metodo para ingresar usuarios
                cout<<"\n\t\t\t Agregar otra persona (S/N)"<<endl;
                cin>>x;//Recibe algo del usuario
            } while(x=='s'|| x=='S');// si el char que recive el usuario es S o s repetir el ciclo
            system("cls");
        break;
 //--------------------------------------------------------------------------------------------------

    case 2:

    DesplegarUSer();// metodo desplegar usuarios en el archivo txt
        system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 3:
        ModificarUser();
        system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 4:

         BorrarUser();
         system("pause");
        system ("cls");



        break;
 //--------------------------------------------------------------------------------------------------
  case 5:
        break;
//--------------------------------------------------------------------------------------------------
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    break;}
        }while(opcion!= 5);

}
void usuario::IngresarUser()
{
    system("cls");
    string usuario,contrasena;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Usuarios al Sistema--------------------------------------------"<<endl;
    cout << "\t\t\t\nIngrese el nombre de usuario:         ";
    cin >> usuario;
    cout << "\t\t\t\nIngrese la contrasena:         ";

    //ocultamiento de contraseña con caracteres
    char caracter;
    caracter=getch();
    contrasena="";

    while(caracter!=13)
    {
        if (caracter !=8)
        {
            contrasena.push_back(caracter);
            cout<<"*";
        }
        else
        {
         if(contrasena.length()>0)
            {
                cout<<"\b \b";
                contrasena=contrasena.substr(0,contrasena.length()-1);
            }
        }
    caracter = getch();
    }

    fstream fileIngresarU;
    fileIngresarU.open("usuarios_y_contrasenas.txt",ios::app| ios:: out);


    fileIngresarU<<std::left<<std::setw(15)<< usuario <<std::left <<std::setw(15)<< contrasena<<"\n";


    fileIngresarU.close();


    cout << "\t\t\t\nUsuario registrado exitosamente."<<endl;


}

void usuario::DesplegarUSer()
{

system("cls");
int total=0;

//imprimir encabezado
cout<<"\n-------------------------Tabla de Usuarios Registrados-------------------------"<<endl;
fstream fileDesplegar;
fileDesplegar.open("usuarios_y_contrasenas.txt",ios::in);
//condicion si el archivo no se puede abrir
if(!fileDesplegar)
    {
    cout<<"\n\t\t\tNo hay información...";
		fileDesplegar.close();
    }
else
    {
        fileDesplegar >> usuarios >> contrasena;

        while(!fileDesplegar.eof())
        {
         total++;//contador
         cout<<"\t\t\t Nombre de usuario: "<<usuarios<<endl; // muestra el nombre del usuario
         cout<<"\t\t\t Contrasenaa del usuario: "<<contrasena<<endl<<endl<<endl; // muestra la contraseña del usuario
        fileDesplegar>> usuarios >> contrasena;//leera el siguiente registro del archivo
        }

        if(total==0)
        {
            cout<<"\n\t\t\tNo hay informacion..."; // muestra un mensaje de error
        }
    }
    fileDesplegar.close();
}

void usuario::ModificarUser()
{
	system("cls");
    fstream fileOri, fileModif;
    string UsuarioModificar;

    int contador=0;
    cout<<"\n-------------------------Modificacion de Usuarios-------------------------"<<endl;
    fileOri.open("usuarios_y_contrasenas.txt",ios::in);

    if(!fileOri)
    {
        cout<<"\n\t\t\tNo hay informacion..,";
        fileOri.close();
    }
    else  // Si el archivo se pudo abrir
    {
        cout<<"\n Ingrese el nombre del Usuario que quiere modificar: ";
        cin>>UsuarioModificar;
        fileModif.open("record.txt",ios::app | ios::out);
        fileOri >> usuarios>> contrasena;

        while(!fileOri.eof())
        {
            if(UsuarioModificar!=usuarios)
                {
                fileModif<<std::left<<std::setw(15)<< usuarios <<std::left<<std::setw(15)<< contrasena << "\n";


                }

            else
                {
                cout << "\t\t\t\nIngrese el nuevo nombre de usuario:         ";
                cin >> usuarios;
                cout << "\t\t\t\nIngrese la nueva contrasena:         ";
                cin >> contrasena;
                fileModif<<std::left<<std::setw(15)<< usuarios <<std::left<<std::setw(15)<< contrasena << "\n";
                contador++;
                cout << "\t\t\t\nUsuario Modificado exitosamente.";
                }

            fileOri >> usuarios >> contrasena;
        }

        fileModif.close();  // Cierra el archivo temporal
        fileOri.close();  // Cierra el archivo original

        remove("usuarios_y_contrasenas.txt");  // Elimina el archivo original
        rename("record.txt","usuarios_y_contrasenas.txt");  // Renombra el archivo temporal con el nombre del archivo original
         cout << "\t\t\t\nUsuario no encontrado.";
          // Muestra un mensaje en pantalla
    }
}

void usuario::BorrarUser()
{
    	system("cls");

	// Declarar dos objetos de la clase fstream para manejar los archivos
	fstream file, file1;

	// Declarar una variable para almacenar el nombre del usuario a borrar
	string partcipante;

	// Declarar una variable para indicar si se encontró al usuario a borrar
	int encontrados= 0;

	// Mostrar un mensaje para indicar que se va a borrar un usuario
	cout << "\n-------------------------Usuarios a Borrar-------------------------" << endl;

	// Abrir el archivo "Usuarios1.txt" en modo lectura
	file.open("usuarios_y_contrasenas.txt", ios::in);

	// Verificar si el archivo se pudo abrir
	if (!file)
	{
		cout << "\n\t\t\tNo hay informacion...";

		// Cerrar el archivo
		file.close();
	}
	else
	{
		// Pedir al usuario que ingrese el nombre del usuario a borrar
		cout << "\n Ingrese el nombre del Usuario que quiere Borrar: ";
		cin >> partcipante;

		// Abrir el archivo "Record.txt
		file1.open("record.txt", ios::app | ios::out);

		// Leer el nombre de usuario y contraseña del archivo "Usuario y contraseñas.txt"
		file >> usuarios>> contrasena;

		// Mientras no se llegue al final del archivo "Usuarios1.txt"
		while (!file.eof())
		{
			// Verificar si el nombre de usuario leído es diferente al nombre del usuario a borrar
			if (partcipante != usuarios)
			{
				// Escribir el nombre de usuario y contraseña en el archivo "Record.txt"
				file1 << std::left << std::setw(15) << usuarios << std::left << std::setw(15) << contrasena << "\n";
			}
			else
			{
				// Incrementar el contador de usuarios encontrados
				encontrados++;

				// Mostrar un mensaje indicando que se borró al usuario exitosamente
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}

			// Leer el siguiente nombre de usuario y contraseña del archivo "Usuarios1.txt"
			file >> usuarios >> contrasena;
		}

		// Verificar si no se encontró al usuario a borrar
		if (encontrados == 0)
		{
			cout << "\n\t\t\t Nombre del Usuario no encontrado...";
		}

		// Cerrar los archivos
		file1.close();
		file.close();

		// Borrar el archivo "Usuarios1.txt"
		remove("usuarios_y_contrasenas.txt");

		// Renombrar el archivo "Record.txt" como "Usuarios1.txt"
		rename("record.txt", "usuarios_y_contrasenas.txt");
	}
}
