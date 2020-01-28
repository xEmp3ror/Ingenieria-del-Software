#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "../../include/funciones/funciones.hpp"

bool MostrarCita(list<Cita> c)
{
	string nombre;
	string apellidos;

	list<Cita>::iterator it;
	struct tm fyh;
	Paciente temp;

	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca los apellidos del paciente\n";
	getline(cin,apellidos);

	for(it=c.begin();it!=c.end();it++)
	{
		temp=it->getPaciente();
		if((nombre.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			fyh=it->getFechayHora();
			cout<<"\nNombre: "<<temp.getNombre()<<"\n";
			cout<<"Apellidos: "<<temp.getApellidos()<<"\n";
			cout<<"Telefono: "<<temp.getTelefono()<<"\n";
			cout<<"Fecha: "<<fyh.tm_mday<<"/"<<fyh.tm_mon<<"/"<<fyh.tm_year<<" a las "<<fyh.tm_hour<<":"<<fyh.tm_min<<"\n";
			cout<<"Descripcion:\n";
			cout<<"  ·"<<it->getDescripcion()<<"\n\n";
			return true;
		}
	}
	return false;
}