#include "nota_venta.h"
#include <limits>

#ifdef _WIN32 || _WIN64
    #define CLEAR std::system("cls");
    #define PAUSE std::system("pause");
#else 
    #define CLEAR std::system("clear");
    #define PAUSE std::system("sleep 5s");
#endif

using namespace std;

class SpaCandy
{

private:

    bool _exit;
    int menu;
    menu_masaje menu_m;
    menu_cliente menu_c;
    menu_servicios menu_s;
    menu_productos menu_p;
    nota_venta n_venta;


public:

    SpaCandy() {
        _exit = false;
    }

    void show_menu() {

        while (!_exit) {

            CLEAR
            cout<<"Seleccione una opcion\n1-Masajistas\n2-Clientes\n3-Servicios\n4-Productos\n5-Nota de Venta\n6-Salir"<<endl;

            cin>>menu;
                try{
                    if (cin.fail())
                    {
                        throw "Ingrese un Numero valido";
                    }
                }
                catch(const char* error) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"Error Inesperado:\n"<<error<<"\n";
                    cin.get();
                }
        
            switch(menu) {
                case 1:
                    menu_m.show_menu();
                break;
        
                case 2:
                    menu_c.show_menu();
                break;
        
                case 3:
                    menu_s.show_menu();
                break;
        
                case 4:
                    menu_p.show_menu();
                break;
        
                case 5:
                    n_venta.set_data(menu_c.dump_data(), menu_m.dump_data(), menu_s.dump_data(), menu_p.dump_data());
                    n_venta.generate();
                    
                break;
                
                case 6:
                    _exit = true;
                break;
        
            }
        }

    }
    
};

int main(int argc, char const *argv[])
{
    SpaCandy s;

    s.show_menu();

    return 0;
}