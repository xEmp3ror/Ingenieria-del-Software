#include <iostream>

#include "../../include/funciones/funciones.hpp"

using namespace std;

bool CrearCita(list <Cita> *c)
{
	Cita aux;
	string name;
	string info;
	int num;
	struct tm fyh;
	list<Cita>::iterator it;
	int N=0;

	cout<<"Introduza el nombre del paciente\n";
	getline(cin,name);
	cout<<endl;
	cout<<"Introduza el numero telefonico del paciente\n";
	cin>>num;
	cout<<"Introduzca el Dia,Mes,Año de la cita,en numero\n";
	cout<<"Dia: ";
	cin>>fyh.tm_mday;
	cout<<"Mes: ";
	cin>>fyh.tm_mon;
	cout<<"Año: ";
	cin>>fyh.tm_year;
	cout<<"Introduzca la hora de la cita\n";
	cout<<"Hora: ";
	cin>>fyh.tm_hour;
	cout<<"Minuto: ";
	cin>>fyh.tm_min;
	cout<<"Indique las razones de la cita\n"
	getline(cin,info);
	cout<<endl;

	for(it=c->begin();it!=c->end();it++)
	{
		if((name.compare(it->getNombre())==0)&&(it->getTelefono()==num))
		{
			N++;
		}
	}

	if(N==0)
	{
		aux.setNombre(name);
		aux.setTelefono(num);
		aux.setFechayHora(fyh);
		aux.setDescripcion(info);
		c->push_back(aux);
		
		return true;
	}else
	{
		return false;
	}
}
