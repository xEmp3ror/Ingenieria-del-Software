#include "06Crear_cita.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

bool Crear_cita(list <Cita> *c)
{
	Cita aux;
	string name;
	int num;
	struct tm fyh;

	cout<<"Introduza el nombre del paciente\n";
	cin>>name;
	cout<<"Introduza el numero telefonico del paciente\n";
	cin>>num;
	cout<<"Introduzca la hora de la cita\n";
	cout<<"Hora";
	cin>>fyh.tm_hour;
	cout<<"Minuto";
	cin>>fyh.tm_min;
	cout<<"Introduzca el Dia,Mes,Año de la cita,en numero\n";
	cout<<"Dia";
	cin>>fyh.tm_mday;
	cout<<"Mes";
	cin>>fyh.tm_mon;
	cout<<"Año";
	cin>>fyh.tm_year;
	//if(Buscarcita(c,name,num)==false)
	//{
		aux.setNombre(name);
		aux.setTelefono(num);
		aux.setFechayHora(fyh);
		c->push_back(aux);
		return true;
	//}else
//	{
	//	return false;
//	}
}
