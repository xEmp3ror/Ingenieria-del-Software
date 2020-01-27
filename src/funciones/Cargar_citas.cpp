#include <iostream>
#include <list>
#include <cstdio>
#include <string>
#include <ctime>
#include <fstream>

#include "../../include/funciones/Cargar_citas.hpp"

void CargarCitas(list<Cita> *c)
{
	Cita X;
	string nombre;
	string number;
	string hora;
	string min;
	string dia;
	string mes;
	string year;
	struct tm fecha;

	ifstream fichero;
	fichero.open("citas.txt");
	if(fichero.is_open())
	{
		while(getline(fichero,nombre,'|'))
		{
			getline(fichero,number,'|');
			getline(fichero,dia,'/');
			getline(fichero,mes,'/');
			getline(fichero,year,'|');
			getline(fichero,hora,':');
			getline(fichero,min,'\n');

			fecha.tm_mday=stoi(dia);
			fecha.tm_mon=stoi(mes);
			fecha.tm_year=stoi(year);
			fecha.tm_hour=stoi(hora);
			fecha.tm_min=stoi(min);
			X.setNombre(nombre);
			X.setTelefono(stoi(number));
			X.setFechayHora(fecha);
			c->push_back(X);
		}
	}
	fichero.close();
}