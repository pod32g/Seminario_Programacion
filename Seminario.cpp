#include "masajes.h"
#include "clientes.h"
#include "servicios.h"
#include "productos.h"

using namespace std;

int main()
{
    bool _exit = false;
    int menu;
    menu_masaje menu_m;
    menu_cliente menu_c;
    menu_servicios menu_s;
    menu_productos menu_p;
    
    while (!_exit) {

        system("cls");
        cout<<"Seleccione una opcion\n1-Masajistas\n2-Clientes\n3-Servicios\n4-Productos\n5-Nota de Venta\n6-Salir"<<endl;

        try {
            cin>>menu;
        }
    
        catch(int err) {
    
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
                
            break;
            case 6:
                _exit = true;
            break;
    
        }
    }


    return 0;
}
