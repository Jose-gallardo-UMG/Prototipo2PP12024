#include "menuG.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

menuG::menuG(string id, string nombre, string precio, string cantidad)
{
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

string menuG::setId( string id)
{
    this-> id=id;
}
string menuG::getId()
{
    return this -> id;
}

string menuG::setNombre(string nombre)
{
    this->nombre=nombre;
}

string menuG::getNombre()
{
    return this->nombre;
}

string menuG::setPrecio(string precio)
{
    this->precio=precio;
}

string menuG::getPrecio()
{
    return this->precio;
}

string menuG::setCantidad(string cantidad)
{
    this->cantidad=cantidad;
}

string menuG::getCantidad()
{
    return this->cantidad;
}

void menuG::menuPrincipal()
{
        bool salir = false;
    int opcion;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|       MENU DE CATALOGOS         |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. CRUD CATALOGOS"<<endl;
	cout<<"\t\t\t 2. INFORMES"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        submenu();
		break;
	case 2:

		desplegar();
		system("pause");
        system ("cls");
		break;
	case 3:
	    salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
    }while(opcion!= 3);
}

void menuG::submenu()
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
	cout<<"\t\t\t 1. Ingreso Nuevos "<<endl;
	cout<<"\t\t\t 2. Modificar "<<endl;
	cout<<"\t\t\t 3. Borrar"<<endl;
	cout<<"\t\t\t 4. SALIR"<<endl;

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
            {  insertar(); //metodo para ingresar usuarios
                cout<<"\n\t\t\t Agregar otra persona (S/N)"<<endl;
                cin>>x;//Recibe algo del usuario
            } while(x=='s'|| x=='S');// si el char que recive el usuario es S o s repetir el ciclo
            system("cls");
        break;
 //--------------------------------------------------------------------------------------------------

    case 2:
        modificar();
        system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 3:
         borrar();
         system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 4:
        break;
 //-------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    break;}
        }while(opcion!= 4);

}
void menuG::desplegar()
{
   system("cls");
int total=0;

//imprimir encabezado
cout<<"\n-------------------------Tabla de Registrados-------------------------"<<endl;
fstream fileDesplegar;
fileDesplegar.open("catalogos.txt",ios::in);

if(!fileDesplegar)
    {
    cout<<"\n\t\t\tNo hay información...";
		fileDesplegar.close();
    }
else
    {
        fileDesplegar >> id>> nombre>>precio>>cantidad;

        while(!fileDesplegar.eof())
        {
         total++;
         cout<<"\t\t\t ID "<<id<<endl;
         cout<<"\t\t\t NOMBRE: "<<nombre<<endl;
         cout<<"\t\t\t PRECIO: "<<precio<<endl;
        cout<<"\t\t\t CANTIDAD: "<<cantidad<<endl<<endl<<endl;
        fileDesplegar >> id>> nombre>>precio>>cantidad;
        }

        if(total==0)
        {
            cout<<"\n\t\t\tNo hay informacion..."; // muestra un mensaje de error
        }
    }
    fileDesplegar.close();
}

void menuG::insertar()
{
    system("cls");
    string id,nombre,precio,cantidad;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar producto--------------------------------------------"<<endl;
    cout << "\t\t\t\nIngrese el ID del producto:         ";
    cin >> id;
      cout << "\t\t\t\nIngrese el nombre del producto:         ";
    cin >> nombre;
      cout << "\t\t\t\nIngrese el precio del producto:         ";
    cin >> precio;
      cout << "\t\t\t\nIngrese la cantidad del producto:         ";
    cin >> cantidad;


    fstream fileIngresar;
    fileIngresar.open("catalogos.txt",ios::app| ios:: out);


    fileIngresar<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< precio<<std::left <<std::setw(15)<< cantidad<<"\n";


    fileIngresar.close();


    cout << "\t\t\t\nregistrado exitosamente."<<endl;


}

void menuG::modificar()
{

	system("cls");
    fstream fileOri, fileModif;
    string productoModificar;

    int contador=0;
    cout<<"\n-------------------------Modificacion de cosas-------------------------"<<endl;
    fileOri.open("catalogos.txt",ios::in);

    if(!fileOri)  // Si el archivo no se pudo abrir
    {
        cout<<"\n\t\t\tNo hay informacion..,";
        fileOri.close();
    }
    else
    {
        cout<<"\n Ingrese el nombre del producto que quiere modificar: ";
        cin>>productoModificar;
        fileModif.open("record2.txt",ios::app | ios::out);
        fileOri >> id>> nombre>>precio>>cantidad;

        while(!fileOri.eof())
        {
            if(productoModificar!=nombre)
                {
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";


                }

            else  // Si se encuentra el usuario a modificar
                {
                cout << "\t\t\t\nIngrese el nuevo id:         ";
                cin >> id;
                cout << "\t\t\t\nIngrese el nuevo nombre:         ";
                cin >> nombre;
                cout << "\t\t\t\nIngrese el nuevo precio:         ";
                cin >> precio;
                cout << "\t\t\t\nIngrese la nueva cantidad:         ";
                cin >> cantidad;
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";
                contador++;  // Incrementa el contador de usuarios modificados
                cout << "\t\t\t\nUsuario Modificado exitosamente.";
                }

                    fileOri >> id>> nombre>>precio>>cantidad; // Lee el siguiente usuario y contraseña del archivo
        }

        fileModif.close();  // Cierra el archivo temporal
        fileOri.close();  // Cierra el archivo original

        remove("catalogos.txt");  // Elimina el archivo original
        rename("record2.txt","catalogos.txt");  // Renombra el archivo temporal con el nombre del archivo original
         cout << "\t\t\t\nUsuario no encontrado.";
          // Muestra un mensaje en pantalla
    }
}

void menuG::borrar()
{
   	system("cls");

	// Declarar dos objetos de la clase fstream para manejar los archivos
	fstream file, file1;

	// Declarar una variable para almacenar el nombre del usuario a borrar
	string partcipante;

	// Declarar una variable para indicar si se encontró al usuario a borrar
	int encontrados= 0;

	// Mostrar un mensaje para indicar que se va a borrar un usuario
	cout << "\n-------------------------producto a Borrar-------------------------" << endl;

	// Abrir el archivo "Usuarios1.txt" en modo lectura
	file.open("catalogos.txt", ios::in);

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
		cout << "\n Ingrese el nombre del producto que quiere Borrar: ";
		cin >> partcipante;

		// Abrir el archivo "Record.txt
		file1.open("record2.txt", ios::app | ios::out);

		// Leer el nombre de usuario y contraseña del archivo "Usuario y contraseñas.txt"
		file >> id>> nombre>>precio>>cantidad;

		// Mientras no se llegue al final del archivo "Usuarios1.txt"
		while (!file.eof())
		{
			// Verificar si el nombre de usuario leído es diferente al nombre del usuario a borrar
			if (partcipante != nombre)
			{
				// Escribir el nombre de usuario y contraseña en el archivo "Record.txt"
                file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar
			}
			else
			{
				// Incrementar el contador de usuarios encontrados
				encontrados++;

				// Mostrar un mensaje indicando que se borró al usuario exitosamente
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}

			// Leer el siguiente nombre de usuario y contraseña del archivo "Usuarios1.txt"
                file >> id>> nombre>>precio>>cantidad;

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
		remove("catalogos.txt");

		// Renombrar el archivo "Record.txt" como "Usuarios1.txt"
		rename("record2.txt", "catalogos.txt");
	}
}


