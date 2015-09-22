#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm> 
#include <ctime>
#include <limits>


class productos {
private:

    class producto {
    public:
        int id_producto;
        std::string nombre;
        std::string descripcion;
        float precio;
    };

    std::vector<producto> pro;

public:

    void save_data(int id, std::string name, std::string description, float price ) {
        producto p;
        p.id_producto = id;
        p.nombre = name;
        p.descripcion = description;
        p.precio = price;
        pro.push_back(p);
    }

    void show_all() {
        std::system("cls");
        for(int i = 0; i < pro.size(); i++) {
            std::cout<<"ID: "<<pro[i].id_producto<<"\nNombre: "<<pro[i].nombre<<"\nDescripcion: "<<pro[i].descripcion<<"\nPrecio: "<<pro[i].precio<<"\n";
            std::system("pause");
        }
    }

    int search_id(int id) {
        std::system("cls");
        for (int i = 0; i < pro.size(); ++i)
        {
            if (pro[i].id_producto == id)
            {
                std::cout<<"ID: "<<pro[i].id_producto<<"\nNombre: "<<pro[i].nombre<<"\nDescripcion: "<<pro[i].descripcion<<"\nPrecio: "<<pro[i].precio<<"\n";
                std::system("pause");
                return 1;
            }
        }
        return 0;
    }

    int search_name(std::string b_name) {
        std::system("cls");
        for (int i = 0; i < pro.size(); ++i)
        {
            if (pro[i].nombre == b_name)
            {
                std::cout<<"ID: "<<pro[i].id_producto<<"\nNombre: "<<pro[i].nombre<<"\nDescripcion: "<<pro[i].descripcion<<"\nPrecio: "<<pro[i].precio<<"\n";
                std::system("pause");
                return 1;
            }
        }
        return 0;
    }

    void modify(int id, std::string data, int caso) {
        std::stringstream auxiliar;
        float _aux;
        for (int i = 0; i < pro.size(); ++i)
        {
            if (pro[i].id_producto == id)
            {
                switch(caso) {
                    case 1:
                        pro[i].nombre = data;
                    break;
                    case 2:
                        pro[i].descripcion = data;
                    break;
                    case 3:
                        auxiliar<<data;
                        auxiliar>>_aux;
                        pro[i].precio = _aux;
                    break;
                }
            }
        }
    }

    void erase(int id) {
        int index;
        for (int i = 0; i < pro.size(); ++i)
        {
            if (pro[i].id_producto == id)
            {
                index = i;
            }
        }
        pro.erase(pro.begin() + index);
    }

    std::string get_name(int id) {
        for (int i = 0; i < pro.size(); ++i)
        {
            if (pro[i].id_producto == id)
            {
                return pro[i].nombre;
            }
        }

        return "No encontrado";
    }

    int get_price(int id) {
        for (int i = 0; i < pro.size(); ++i)
        {
            if (pro[i].id_producto == id)
            {
                return pro[i].precio;
            }
        }
        return 0;
    }


};

class menu_productos {

private:

    productos _p;

    std::vector<int> v;

    int capturar(std::string nom, std::string __description, float price) {
        std::srand(std::time(NULL));
        std::random_shuffle(v.begin(), v.end());

        int x = v[0];
        v.erase(v.begin());
        _p.save_data(x, nom, __description, price);

        return x;
    }

    int p_menu;


public:

    menu_productos() {
        for (int i = 0; i < 1000; ++i)
        {
            v.push_back(i);
        }
    }

    productos dump_data() {
        return _p;
    }

    void show_menu() {
       
        bool _salir = false;
        std::string pro_name, pro_descripcion, _aux;
        int p_id, s_menu;
        float pro_precio; 

        while (!_salir) {
            std::system("cls");
            std::cout<<"**Productos**\nSeleccione una opcion\n1-Nuevo producto\n2-Buscar producto\n3-Modificar producto\n4-Eliminar producto\n5-Mostrar todo el registro\n6-Salir\n";
                std::cin>>p_menu;
                try{
                    if (std::cin.fail())
                    {
                        throw "Ingrese un Numero valido";
                    }
                }
                catch(const char* error) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Error Inesperado\n"<<error<<"\n";
                    std::cin.get();
                }
            switch(p_menu) {
                case 1:
                    
                    std::system("cls");
                    std::cout<<"Nombre: ";
                    std::cin.get();
                    std::getline(std::cin, pro_name); std::cout<<std::endl;
                    std::cout<<"Descripcion: ";
                    std::cin.get();
                    std::getline(std::cin, pro_descripcion); std::cout<<std::endl;
                    std::cout<<"Precio: ";
                    std::cin>>pro_precio; std::cout<<std::endl;
                    std::cout<<"producto guardado con id: "<<capturar(pro_name, pro_descripcion, pro_precio)<<std::endl;
                    std::system("pause");

                break;
                case 2:
                    std::system("cls");
                    std::cout<<"Seleccione opcion:\n1-Busqueda por ID\n2-Busqueda por nombre\n";
                    std::cin>>s_menu;
                    switch(s_menu) {
                        case 1:
                            std::cout<<"Ingrese el ID a buscar: "; std::cin>>p_id;
                            if (_p.search_id(p_id) != 1)
                            {
                                std::cout<<"producto no encontrado\n";
                                std::system("pause");
                            }
                        break;
                        case 2:
                            std::cin.get();
                            std::cout<<"Ingrese nombre a buscar: "; std::getline(std::cin, pro_name);
                            if (_p.search_name(pro_name) != 1)
                            {
                                std::cout<<"producto no encontrado\n";
                                std::system("pause");
                            }
                        break;
                    }
                   
                break;
                case 3:
                    std::system("cls");
                    std::cout<<"Ingrese el ID a modificar: "; std::cin>>p_id;
                    std::system("cls");
                    std::cout<<"Seleccione dato a modificar\n1-Nombre\n2-Correo\n3-Precio: "; std::cin>>s_menu;
                    switch(s_menu) {
                        case 1:
                            std::cin.get();
                            std::cout<<"Ingrese el nuevo nombre: "; std::getline(std::cin, pro_name);
                            _p.modify(p_id, pro_name, s_menu);
                        break;
                        case 2:
                            std::cin.get();
                            std::cout<<"Ingrese la nueva Descripcion: "; std::getline(std::cin, pro_descripcion);
                            _p.modify(p_id, pro_descripcion, s_menu);
                        break;
                        case 3:
                            std::cin.get();
                            std::cout<<"Ingrese la nueva Precio: "; std::getline(std::cin, _aux);
                            _p.modify(p_id, _aux, s_menu);
                        break;
                    }
                    std::system("cls");
                    std::cout<<"\nDatos guardados\n";
                break;
                case 4:
                    std::cout<<"Ingrese id del producto a eliminar: "; std::cin>>p_id; 
                    std::cout<<std::endl;
                    _p.erase(p_id);
                break;
                case 5:
                    _p.show_all();
                break;
                case 6:
                    _salir = true;
                break;
            }
        }

    }
};