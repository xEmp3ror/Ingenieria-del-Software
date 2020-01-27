#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "../../include/funciones/Mostrar_cita.hpp"

bool MostrarCita(list<Cita> c)
{
	string nombre;
	int number;

	list<Cita>::iterator it;
	struct tm fyh;

	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca el numero del paciente\n";
	cin>>number;
	
	for(it=c.begin();it!=c.end();it++)
	{
		if((nombre.compare(it->getNombre())==0)&&(it->getTelefono()==number))
		{
			fyh=it->getFechayHora();
			cout<<"Nombre"<<it->getNombre()<<"\n";
			cout<<"Telefono"<<it->getTelefono()<<"\n";
			cout<<"Fecha: "<<fyh.tm_mday<<"/"<<fyh.tm_mon<<"/"<<fyh.tm_year<<" a las "<<fyh.tm_hour<<":"<<fyh.tm_min<<"\n\n";
			return true;
		}
	}
	return false;
}

