#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm> 
#include <ctime>


class clientes {
private:

    class cliente {
    public:
        int id_cliente;
        std::string nombre;
        std::string correo;
        int telefono;
    };

    std::vector<cliente> cli;

public:

    void save_data(int id, std::string name, std::string mail, int phone ) {
        cliente c;
        c.id_cliente = id;
        c.nombre = name;
        c.correo = mail;
        c.telefono = phone;
        cli.push_back(c);
    }

    void show_all() {
        std::system("cls");
        for(int i = 0; i < cli.size(); i++) {
            std::cout<<"ID: "<<cli[i].id_cliente<<"\nNombre: "<<cli[i].nombre<<"\nCorreo: "<<cli[i].correo<<"\nTelefono: "<<cli[i].telefono<<"\n";
            std::system("pause");
        }
    }

    int search_id(int id) {
        std::system("cls");
        for (int i = 0; i < cli.size(); ++i)
        {
            if (cli[i].id_cliente == id)
            {
                std::cout<<"ID: "<<cli[i].id_cliente<<"\nNombre: "<<cli[i].nombre<<"\nCorreo: "<<cli[i].correo<<"\nTelefono: "<<cli[i].telefono<<"\n";
                std::system("pause");
                return 1;
            }
        }
        return 0;
    }

    int search_name(std::string b_name) {
        std::system("cls");
        for (int i = 0; i < cli.size(); ++i)
        {
            if (cli[i].nombre == b_name)
            {
                std::cout<<"ID: "<<cli[i].id_cliente<<"\nNombre: "<<cli[i].nombre<<"\nCorreo: "<<cli[i].correo<<"\nTelefono: "<<cli[i].telefono<<"\n";
                std::system("pause");
                return 1;
            }
        }
        return 0;
    }

    void modify(int id, std::string data, int caso) {
        std::stringstream auxiliar;
        int _aux;
        for (int i = 0; i < cli.size(); ++i)
        {
            if (cli[i].id_cliente == id)
            {
                switch(caso) {
                    case 1:
                        cli[i].nombre = data;
                    break;
                    case 2:
                        cli[i].correo = data;
                    break;
                    case 3:
                        auxiliar<<data;
                        auxiliar>>_aux;
                        cli[i].telefono = _aux;
                    break;
                }
            }
        }
    }

    void erase(int id) {
        int index;
        for (int i = 0; i < cli.size(); ++i)
        {
            if (cli[i].id_cliente == id)
            {
                index = i;
            }
        }
        cli.erase(cli.begin() + index);
    }


};

class menu_cliente {

private:

    clientes _c;

    std::vector<int> v;

    int capturar(std::string nom, std::string __mail, int tel) {

        std::srand(std::time(NULL));
        std::random_shuffle(v.begin(), v.end());

        int x = v[1];
        v.erase(v.begin());
        _c.save_data(x, nom, __mail, tel);

        return x;
    }

    int c_menu;


public:

    menu_cliente() {
        for (int i = 0; i < 1000; ++i)
        {
            v.push_back(i);
        }
    }

    clientes dump_data() {
        return _c;
    }

    void show_menu() {
       
        bool _salir = false;
        std::string cli_name, cli_correo, _aux;
        int cli_tel, c_id, s_menu; 

        while (!_salir) {
            std::system("cls");
            std::cout<<"**Clientes**\nSeleccione una opcion\n1-Nuevo Cliente\n2-Buscar cliente\n3-Modificar Cliente\n4-Eliminar Cliente\n5-Mostrar todo el registro\n6-Salir\n";
                try{
                    std::cin>>c_menu;
                }
                catch(int err) {
                }
            switch(c_menu) {
                case 1:
                    
                    std::system("cls");
                    std::cout<<"Nombre: ";
                    std::cin.get();
                    std::getline(std::cin, cli_name); std::cout<<std::endl;
                    std::cout<<"Correo: ";
                    std::cin.get();
                    std::getline(std::cin, cli_correo); std::cout<<std::endl;
                    std::cout<<"telefono: ";
                    std::cin>>cli_tel; std::cout<<std::endl;
                    std::cout<<"Cliente guardado con id: "<<capturar(cli_name, cli_correo, cli_tel)<<std::endl;
                    std::system("pause");

                break;
                case 2:
                    std::system("cls");
                    std::cout<<"Seleccione opcion:\n1-Busqueda por ID\n2-Busqueda por nombre\n";
                    std::cin>>s_menu;
                    switch(s_menu) {
                        case 1:
                            std::cout<<"Ingrese el ID a buscar: "; std::cin>>c_id;
                            if (_c.search_id(c_id) != 1)
                            {
                                std::cout<<"Cliente no encontrado\n";
                                std::system("pause");
                            }
                        break;
                        case 2:
                            std::cin.get();
                            std::cout<<"Ingrese nombre a buscar: "; std::getline(std::cin, cli_name);
                            if (_c.search_name(cli_name) != 1)
                            {
                                std::cout<<"Cliente no encontrado\n";
                                std::system("pause");
                            }
                        break;
                    }
                   
                break;
                case 3:
                    std::system("cls");
                    std::cout<<"Ingrese el ID a modificar: "; std::cin>>c_id;
                    std::system("cls");
                    std::cout<<"Seleccione dato a modificar\n1-Nombre\n2-Correo\n3-Telefono: "; std::cin>>s_menu;
                    switch(s_menu) {
                        case 1:
                            std::cin.get();
                            std::cout<<"Ingrese el nuevo nombre: "; std::getline(std::cin, cli_name);
                            _c.modify(c_id, cli_name, s_menu);
                        break;
                        case 2:
                            std::cin.get();
                            std::cout<<"Ingrese la nueva correo: "; std::getline(std::cin, cli_correo);
                            _c.modify(c_id, cli_correo, s_menu);
                        break;
                        case 3:
                            std::cin.get();
                            std::cout<<"Ingrese la nueva telefono: "; std::getline(std::cin, _aux);
                            _c.modify(c_id, _aux, s_menu);
                        break;
                    }
                    std::system("cls");
                    std::cout<<"\nDatos guardados\n";
                break;
                case 4:
                    std::cout<<"Ingrese id del Cliente a eliminar: "; std::cin>>c_id; 
                    std::cout<<std::endl;
                    _c.erase(c_id);
                break;
                case 5:
                    _c.show_all();
                break;
                case 6:
                    _salir = true;
                break;
            }
        }

    }
};