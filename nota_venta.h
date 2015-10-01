#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "masajes.h"
#include "clientes.h"
#include "servicios.h"
#include "productos.h"

#ifdef _WIN32 || _WIN64
	#define CLEAR std::system("cls");
	#define PAUSE std::system("pause");
#else 
    #define CLEAR std::system("clear");
	#define PAUSE std::system("sleep 5s");
#endif

class nota_venta {

private:

	clientes cli;
	masajes mas;
	servicios ser;
	productos pro;
	int _id_cli, _id_serv, _id_pro;

public:
	void set_data(clientes _cli, masajes _mas, servicios _ser, productos _pro) {
		cli = _cli;
		mas = _mas;
		ser = _ser;
		pro = _pro;
	}

	void create_note(int id_cli, std::string fecha, int id_ser, int id_pro) {

		std::ofstream note("nota.txt");
		std::string name_p, descripcion_s; 
		float cost;
		int precio, duracion;

		CLEAR;
		std::cout<<"Nota creada\n";
		note <<"Cliente: "<< id_cli <<"\n"<<"Fecha: "<<fecha<<"\n"<<"Servicio: "<<ser.get_description(id_ser)<<" Costo: $"<<ser.get_precio(id_ser)<<"\nProducto Vendido: "<<pro.get_name(id_pro)<<" Costo: $"<<pro.get_price(id_pro)<<"\nTotal: "<<pro.get_price(id_pro) + ser.get_precio(id_ser)<<"\n"; 
		std::cout<<"Cliente: "<< id_cli <<"\n"<<"Fecha: "<<fecha<<"\n"<<"Servicio: "<<ser.get_description(id_ser)<<" Costo: $"<<ser.get_precio(id_ser)<<"\nProducto Vendido: "<<pro.get_name(id_pro)<<" Costo: $"<<pro.get_price(id_pro)<<"\nTotal: "<<pro.get_price(id_pro) + ser.get_precio(id_ser)<<"\n";
		PAUSE
	}

	void generate() {
		
		std::string date; 
		CLEAR
		std::cout<<"-Generar Nota de venta-\nIngrese el id del cliente\n";
		std::cin>>_id_cli;
		std::cout<<"\nIngrese la fecha dd/mm/aa\n";
		std::cin.get();
		std::getline(std::cin, date);
		std::cout<<"Ingrese el codigo del servicio: \n";
		std::cin>>_id_serv;
		std::cout<<"Ingrese el codigo del producto\n";
		std::cin>>_id_pro;

		create_note(_id_cli, date, _id_serv, _id_pro);

	}

};

