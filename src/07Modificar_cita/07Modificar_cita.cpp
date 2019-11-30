#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <string>

#include "07Modificar_cita.hpp"

using namespace std;

bool ModificarCita(list <Cita> *c,string name,int number)
{
	Cita aux;
	list<Cita>::iterator it;
	int N=0;
	struct tm fyh;

	for(it=c->begin();(it!=c->end()&&(N==0));it++)
	{
		if((name.compare(it->getNombre())==0)&&(it->getTelefono()==number))
		{
			N++;
		}
	}

	//Si el Valor de N no ha variado
	if(N==0)
	{
		cout<<"La cita que esta buscando no existe\n";
		return false;
	}

	//Si N es distinto de 0 
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
