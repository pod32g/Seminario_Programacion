#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm> 
#include <ctime> 


class servicios {
private:

    class servicio {
    public:
        int codigo;
        std::string descripcion;
        int p_min;
        int p_max;
        int duracion;
    };

    std::vector<servicio> ser;

public:



    void save_data(int id, std::string description, int _min, int _max, int _time) {

        servicio s;
        s.codigo = id;
        s.descripcion = description;
        s.p_min = _min;
        s.p_max = _max;
        s.duracion = _time;
        ser.push_back(s);
    }

    void show_all() {
        std::system("cls");
        for(int i = 0; i < ser.size(); i++) {
            std::cout<<"Codigo: "<<ser[i].codigo<<"\nDescripcion: "<<ser[i].descripcion<<"\nPrecio Minimo: "<<ser[i].p_min<<"\nPrecio Maximo: "<<ser[i].p_max<<"\nDuracion: "<<ser[i].duracion<<"\n";
            std::system("pause");
        }
    }

    int search_id(int id) {
        std::system("cls");
        for (int i = 0; i < ser.size(); ++i)
        {
            if (ser[i].codigo == id)
            {
                std::cout<<"Codigo: "<<ser[i].codigo<<"\nDescripcion: "<<ser[i].descripcion<<"\nPrecio Minimo: "<<ser[i].p_min<<"\nPrecio Maximo: "<<ser[i].p_max<<"\nDuracion: "<<ser[i].duracion<<"\n";
                std::system("pause");
                return 1;
            }
        }
        return 0;
    }


    void modify(int id, std::string data, int caso) {
        std::stringstream auxiliar;
        int _aux;
        for (int i = 0; i < ser.size(); ++i)
        {
            if (ser[i].codigo == id)
            {
                switch(caso) {
                    case 1:
                        ser[i].descripcion = data;
                    break;
                    case 2:
                        auxiliar<<data;
                        auxiliar>>_aux;
                        ser[i].p_min = _aux;
                    break;
                    case 3:
                        auxiliar<<data;
                        auxiliar>>_aux;
                        ser[i].p_max = _aux;
                    break;
                    case 4:
                        auxiliar<<data;
                        auxiliar>>_aux;
                        ser[i].duracion = _aux;
                    break;
                }
            }
        }
    }

    void erase(int id) {
        int index;
        for (int i = 0; i < ser.size(); ++i)
        {
            if (ser[i].codigo == id)
            {
                index = i;
            }
        }
        ser.erase(ser.begin() + index);
    }

    std::string get_description(int id) {

        for (int i = 0; i < ser.size(); ++i)
        {
            if (ser[i].codigo == id)
            {
                return ser[i].descripcion;
                
            }
        }

        return "No encontrado";
    }

    int get_precio(int id) {

        for (int i = 0; i < ser.size(); ++i)
        {
            if (ser[i].codigo == id)
            {
                
                return ser[i].p_max;
                
            }
        }

        return 0;
    }


};

class menu_servicios {

private:

    std::vector<int> v;

    servicios _s;

    int capturar(std::string _descripcion, int __min, int __max, int __time) {
        std::srand(std::time(NULL));
        std::random_shuffle(v.begin(), v.end());

        int x = v[1];
        v.erase(v.begin());
        _s.save_data(x, _descripcion, __min, __max, __time);

        return x;
    }

    int s_menu;


public:

    menu_servicios() {
        for (int i = 0; i < 1000; ++i)
        {
            v.push_back(i);
        }
    }

    servicios dump_data() {
        return _s;
    }

    void show_menu() {
       
        bool _salir = false;
        std::string ser_des,  _aux;
        int ser_min, s_id, s_menu, ser_max, dur; 

        while (!_salir) {
            std::system("cls");
            std::cout<<"**Servicios**\nSeleccione una opcion\n1-Nuevo Servicio\n2-Buscar Servicio\n3-Modificar Servicio\n4-Eliminar Servicio\n5-Mostrar todo el registro\n6-Salir\n";
                try{
                    std::cin>>s_menu;
                }
                catch(int err) {
                }
            switch(s_menu) {
                case 1:
                    
                    std::system("cls");
                    std::cout<<"Descripcion: ";
                    std::cin.get();
                    std::getline(std::cin, ser_des); std::cout<<std::endl;
                    std::cout<<"Precio Minimo: ";
                    std::cin>>ser_min; std::cout<<std::endl;
                    std::cout<<"Precio Maximo: ";
                    std::cin>>ser_max; std::cout<<std::endl;
                    std::cout<<"Duracion: ";
                    std::cin>>dur; std::cout<<std::endl;
                    std::cout<<"Servicio guardado con Codigo: "<<capturar(ser_des, ser_min, ser_max, dur)<<std::endl;
                    std::system("pause");

                break;
                case 2:
                    std::system("cls");
                    std::cout<<"Ingrese el Codigo a buscar: "; std::cin>>s_id;
                    if (_s.search_id(s_id) != 1)
                    {
                        std::cout<<"Servicio no encontrado\n";
                        std::system("pause");
                    }
                break;
                case 3:
                    std::system("cls");
                    std::cout<<"Ingrese el Codigo del servicio a modificar: "; std::cin>>s_id;
                    std::system("cls");
                    std::cout<<"Seleccione dato a modificar\n1-Descripcion\n2-Precio Minimo\n3-Precio Maximo\n4-Duracion\n"; std::cin>>s_menu;
                    switch(s_menu) {
                        case 1:
                            std::cin.get();
                            std::cout<<"Ingrese la nueva descripcion: "; std::getline(std::cin, ser_des);
                            _s.modify(s_id, ser_des, s_menu);
                        break;
                        case 2:
                            std::cin.get();
                            std::cout<<"Ingrese El nuevo precio minimo: "; std::getline(std::cin, _aux);
                            _s.modify(s_id, _aux, s_menu);
                        break;
                        case 3:
                            std::cin.get();
                            std::cout<<"Ingrese el nuevo precio Maximo "; std::getline(std::cin, _aux);
                            _s.modify(s_id, _aux, s_menu);
                        break;
                        case 4:
                            std::cin.get();
                            std::cout<<"Ingrese la nueva duracion (en minutos) "; std::getline(std::cin, _aux);
                            _s.modify(s_id, _aux, s_menu); 
                        break;
                    }
                    std::system("cls");
                    std::cout<<"\nDatos guardados\n";
                break;
                case 4:
                    std::cout<<"Ingrese Codigo del Servicio a eliminar: "; std::cin>>s_id; 
                    std::cout<<std::endl;
                    _s.erase(s_id);
                break;
                case 5:
                    _s.show_all();
                break;
                case 6:
                    _salir = true;
                break;
            }
        }

    }
};