#include <list>
#include <iostream>
#include <cstdio>
#include "../include/funciones/Modificar_cita.hpp"

using namespace std;

bool ModificarCita(list <Cita> *c)
{
	list<Cita>::iterator it;
	int N=0;
	struct tm fyh;
	int number;
	string nombre;

	cout<<"Introduzca el nombre del paciente\n";
	getline(cin,nombre);
	cout<<endl;
	cout<<"Introduzca el numero del paciente\n";
	cin>>number;


	for(it=c->begin();(it!=c->end()&&(N==0));it++)
	{
		if((nombre.compare(it->getNombre())==0)&&(it->getTelefono()==number))
		{
			N++;
		}
	}

	//Si el Valor de N no ha variado==No existe la cita del paciente
	if(N==0)
	{
		return false;
	}

	//Si N es distinto de 0==Hay una cita del paciente
	cout<<"Indique la hora nueva del paciente\n";
	cout<<"Hora ";
	cin>>fyh.tm_hour;
	cout<<"Minuto ";
	cin>>fyh.tm_min;
	cout<<"Indica la fecha nueva del paciente\n";
	cout<<"Dia ";
	cin>>fyh.tm_mday;
	cout<<"Mes ";
	cin>>fyh.tm_mon;
	cout<<"Año ";
	cin>>fyh.tm_year;

	it->setFechayHora(fyh);
	return true;
}
