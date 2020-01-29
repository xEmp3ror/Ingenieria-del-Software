#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <string>
#include <fstream>
#include <list>

#include "../../include/funciones/funciones.hpp"

using namespace std;

void MostrarListaPacientes(list<Paciente> p)
{
	list<Paciente>::iterator it;
	for(it=p.begin();it!=p.end();it++)
	{
		cout<<"    ·Nombre "<<it->getNombre()<<"   ·Apellidos "<<it->getApellidos()<<"\n";
		cout<<"    ·Fecha Nacimiento"<<it->getFechaNacimiento()<<"  ·Edad"<<it->getEdad()<<"\n";
		cout<<"    ·Telefono "<<it->getTelefono()<<"   ·Domicilio "<<it->getDomicilio()<<"\n\n";

	}
}

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
	getline(cin,apellidos);
	cout<<"Introduza el telefono del paciente\n";
	cin>>num;
	temp.setNombre(name);
	temp.setApellidos(apellidos);
	temp.setTelefono(num);
	aux.setPaciente(temp);

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

	for(it=c->begin();it!=c->end();it++)
	{
		temp=it->getPaciente();
		//Busca que no haya otra cita del mismo paciente
		if((name.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			cout<<"Este paciente ya tiene una cita\n";
			N++;
		}
		//Busca que la fecha y hora seleccionada no coincidan con otra existente
		/**if(fyh==it->getFechayHora())
		{
			cout<<"La hora seleccionada para esta cita ya esta ocupada por otra\n";
			N++;
		}*/
	}

	if(N==0)
	{
		//Guardamos la nueva cita dentro de la lista
		aux.setFechayHora(fyh);
		aux.setDescripcion(info);
		c->push_back(aux);
		
		return true;
	}else
	{
		return false;
	}
}

bool ModificarCita(list <Cita> *c)
{
	list<Cita>::iterator it;
	Cita n;
	Paciente temp;
	int N=0;
	struct tm fyh;
	int number;
	string nombre;
	string apellidos;
	string info;

	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca los apellidos del paciente\n";
	getline(cin,apellidos);


	for(it=c->begin();(it!=c->end()&&(N==0));it++)
	{
		temp=it->getPaciente();
		if((nombre.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			temp=it->getPaciente();
			c->erase(it);
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
	cout<<"Indique la razon de la cita\n";
	cin.ignore();
	getline(cin,info);

	n.setPaciente(temp);
	n.setFechayHora(fyh);
	n.setDescripcion(info);
	c->push_back(n);
	return true;
}

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
