#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <sstream>


class masajes {
private:

    class masajista {
    public:
        int id_mas;
        std::string nombre;
        int edad;
        std::string especialidad;
    };

    std::vector<masajista> mas;

public:

    void save_data(int id, std::string name, int age, std::string speciality ) {
        masajista m;
        m.id_mas = id;
        m.nombre = name;
        m.edad = age;
        m.especialidad = speciality;
        mas.push_back(m);
    }

    void show_all() {
        for(int i = 0; i < mas.size(); i++) {
            std::cout<<"ID: "<<mas[i].id_mas<<"\nNombre: "<<mas[i].nombre<<"\nEdad: "<<mas[i].edad<<"\nEspecialidad: "<<mas[i].especialidad<<"\n";
            std::system("pause");
        }
    }

    void search(int id) {
        std::system("cls");
        for (int i = 0; i < mas.size(); ++i)
        {
            if (mas[i].id_mas == id)
            {
                std::cout<<"ID: "<<mas[i].id_mas<<"\nNombre: "<<mas[i].nombre<<"\nEdad: "<<mas[i].edad<<"\nEspecialidad: "<<mas[i].especialidad<<"\n";
                std::system("pause");
            }
        }
    }

    void modify(int id, std::string data, int caso) {
        std::stringstream auxiliar;
        int _aux;
        for (int i = 0; i < mas.size(); ++i)
        {
            if (mas[i].id_mas == id)
            {
                switch(caso) {
                    case 1:
                        mas[i].nombre = data;
                    break;
                    case 2:
                        auxiliar<<data;
                        auxiliar>>_aux;
                        mas[i].edad = _aux;
                    break;
                    case 3:
                        mas[i].especialidad = data;
                    break;
                }
            }
        }
    }


};

class menu_masaje {

private:

    masajes _m;

    int capturar(std::string nom, int e, std::string special) {
        int id = rand() % 10;
        _m.save_data(id, nom, e, special);

        return id;
    }

    void mostrar(int id);
    void modificar(int id);
    void eliminar(int id);
    int m_menu;


public:

    void show_menu() {
       
        bool _salir = false;
        std::string mas_name, mas_special;
        int mas_edad, m_id, s_menu; 

        while (!_salir) {
            std::system("cls");
            std::cout<<"**Masajistas**\nSeleccione una opcion\n1-Nuevo Masajista\n2-Buscar masajista\n3-Modificar Masajista\n4-Eliminar Masajista\n5-Salir\n";
                try{
                    std::cin>>m_menu;
                }
                catch(int err) {
                }
            switch(m_menu) {
                case 1:
                    
                    std::system("cls");
                    std::cout<<"Nombre: ";
                    std::cin.get();
                    std::getline(std::cin, mas_name); std::cout<<std::endl;
                    std::cout<<"Edad: ";
                    std::cin>>mas_edad; std::cout<<std::endl;
                    std::cout<<"Especialidad: ";
                    std::cin.get();
                    std::getline(std::cin, mas_special); std::cout<<std::endl;
                    std::cout<<"Masajista guardado con id: "<<capturar(mas_name, mas_edad, mas_special)<<std::endl;
                    std::system("pause");

                break;
                case 2:
                    std::system("cls");
                    std::cout<<"Ingrese el ID a buscar: "; std::cin>>m_id;
                    _m.search(m_id);
                break;
                case 3:
                    std::system("cls");
                    std::cout<<"Ingrese el ID a modificar: "; std::cin>>m_id;
                    std::system("cls");
                    std::cout<<"Seleccione dato a modificar\n1-Nombre\n2-Edad\n3-Especialidad: "; std::cin>>s_menu;
                    switch(s_menu) {
                        case 1:
                            std::cin.get();
                            std::cout<<"Ingrese el nuevo nombre: "; std::getline(std::cin, mas_name);
                            _m.modify(m_id, mas_name, s_menu);
                        break;
                        case 2:
                            std::cin.get();
                            std::string aux;
                            std::cout<<"Ingrese la nueva edad: "; std::getline(std::cin, aux);
                            _m.modify(m_id, aux, s_menu);
                        break;
                        case 3:
                            std::cin.get();
                            std::cout<<"Ingrese la nueva especialidad: "; std::getline(std::cin, mas_special);
                            _m.modify(m_id, mas_special, s_menu);
                        break;
                    }
                    std::system("cls");
                    std::cout<<"\nDatos guardados\n";
                break;
                case 4:
                break;
                case 5:
                    _salir = true;
                break;
            }
        }

    }
};
