#ifndef MENUGENERAL_H
#define MENUGENERAL_H


class menugeneral
{
   public:
        menugeneral(string id, string nombre, string precio, string cantidad);
       string setId(string id);
        string getId();

        string setNombre(string nombre);
        string getNombre();

        string setPrecio(string precio);
        string getPrecio();

        string setCantidad(string cantidad);
        string getCantidad();
//metodos

     void menuPrincipal();
     void submenu();
     void insertar();
     	void desplegar();
		void modificar();
		void buscar();
		void borrar();

    protected:

    private:
    string id,nombre,precio,cantidad;
};

#endif // MENUGENERAL_H
