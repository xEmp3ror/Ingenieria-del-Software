#include <iostream>

#include "../../include/funciones/funciones.hpp"

using namespace std;

bool CrearCita(list <Cita> *c)
{
	Cita aux;
	Paciente temp;
	string name;
	string apellidos;
	string info;
	int num;
	struct tm fyh;
	list<Cita>::iterator it;
	int N=0;

	cout<<"Introduza el nombre del paciente\n";
	cin.ignore();
	getline(cin,name);
	cout<<"Introduza los apellidos del paciente\n";
	cin.ignore();
	getline(cin,apellidos);
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
	cout<<"Indique las razones de la cita\n";
	cin.ignore();
	getline(cin,info);

	for(it=c->begin();(it!=c->end())||(N==0);it++)
	{
		temp=it->getPaciente();
		//Busca que no haya otra cita del mismo paciente
		if((name.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())))
		{
			cout<<"Este paciente ya tiene una cita\n";
			N++;
		}
	}

	if(N==0)
	{
		//Guardamos la nueva cita dentro de la lista
		temp.setNombre(name);
		temp.setApellidos(apellidos);
		temp.setTelefono(num);
		aux.setPaciente(temp);
		aux.setFechayHora(fyh);
		aux.setDescripcion(info);
		c->push_back(aux);
		
		return true;
	}else
	{
		return false;
	}
}
