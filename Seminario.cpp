#include "masajes.h"

using namespace std;

int main()
{
    bool _exit = false;
    int menu;
    menu_masaje menu_m;
    
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
            break;
    
            case 3:
            break;
    
            case 4:
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
