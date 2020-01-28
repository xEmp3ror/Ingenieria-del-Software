#include <iostream>
#include <list>
#include <cstdio>
#include <string>
#include <ctime>
#include <fstream>

#include "../../include/funciones/funciones.hpp"

void CargarCitas(list<Cita> *c)
{
	Cita X;
	Paciente temp;
	string nombre;
	string apellidos;
	string number;
	string info;
	string hora;
	string min;
	string dia;
	string mes;
	string year;
	struct tm fecha;

	ifstream fichero;
	fichero.open("../BD/citas.txt");
	if(fichero.is_open())
	{
		while(getline(fichero,nombre,'|'))
		{
			getline(fichero,apellidos,'|');
			getline(fichero,number,'|');
			getline(fichero,dia,'/');
			getline(fichero,mes,'/');
			getline(fichero,year,'|');
			getline(fichero,hora,':');
			getline(fichero,min,'|');
			getline(fichero,info,'\n');

			fecha.tm_mday=stoi(dia);
			fecha.tm_mon=stoi(mes);
			fecha.tm_year=stoi(year);
			fecha.tm_hour=stoi(hora);
			fecha.tm_min=stoi(min);
			temp.setNombre(nombre);
			temp.setApellidos(apellidos);
			temp.setTelefono(stoi(number));
			X.setPaciente(temp);
			X.setFechayHora(fecha);
			X.setDescripcion(info);
			c->push_back(X);
		}
	}
	fichero.close();
}