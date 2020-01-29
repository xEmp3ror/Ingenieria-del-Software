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

	cout<<"Introduza el nombre del paciente\n";
	cin.ignore();
	getline(cin,name);
	cout<<"Introduza los apellidos del paciente\n";
	getline(cin,apellidos);
	//Busca que no haya otra cita del mismo paciente
	for(it=c->begin();it!=c->end();it++)
	{
		temp=it->getPaciente();

		if((name.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			cout<<"Este paciente ya tiene una cita\n";
			return false;
		}
	}
	temp.setNombre(name);
	temp.setApellidos(apellidos);

	cout<<"Introduza el telefono del paciente\n";
	cin>>num;
	temp.setTelefono(num);
	aux.setPaciente(temp);
	
	do
	{
		InsertFyH(&fyh);
	}while(Inv_date(*c,fyh)!=false);
	aux.setFechayHora(fyh);

	cout<<"Indique las razones de la cita\n";
	cin.ignore();
	getline(cin,info);
	aux.setDescripcion(info);

	c->push_back(aux);
	return true;
}

bool ModificarCita(list <Cita> *c)
{
	list<Cita>::iterator it;
	Cita n;
	Paciente temp;
	int N=0;
	struct tm fyh;
	string nombre;
	string apellidos;
	string info;

	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca los apellidos del paciente\n";
	getline(cin,apellidos);

	//Buscamos que haya una cita asociada al Nombre y Apellidos dados
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
	n.setPaciente(temp);
	//Establecemos nueva hora de la cita
	cout<<"Indique la hora nueva del paciente\n";
	do
	{
		InsertFyH(&fyh);
	}while(Inv_date(*c,fyh)!=false);
	n.setFechayHora(fyh);

	//Modificacion de la descripcion de la cita
	cout<<"Indique la razon de la cita\n";
	cin.ignore();
	getline(cin,info);
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

	//Pedimos el Nombre y Apellidos del paciente
	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca los apellidos del paciente\n";
	getline(cin,apellidos);

	for(it=c.begin();it!=c.end();it++)
	{
		temp=it->getPaciente();

		//Si encontramos coincidencia en Nombre y Apellidos se imprime por pantalla la cita encontrada
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

void InsertFyH(struct tm *FH)
{
	int cntr=0;

	cout<<"Introduzca el Año,Mes,Dia de la cita,en numero\n";
	cout<<"Año: ";
	cin>>FH->tm_year;
	//Mes
	do
	{
		cout<<"Mes: ";
		cin>>FH->tm_mon;
		if((FH->tm_mon<=0)||(FH->tm_mon>=13))
		{
			cntr++;
			cout<<"\nParametro fuera de intervalo permitido [0-12]\n";
			cout<<"Vuelva a dar el dato pedido\n";
		}else
		{
			cntr=0;
		}
	}while(cntr!=0);
	//Dia
	do
	{
		cout<<"Dia: ";
		cin>>FH->tm_mday;
		if((FH->tm_mday<=0)||(FH->tm_mday>=32))
		{
			cntr++;
			cout<<"\nParametro fuera de intervalo permitido [0-31]\n";
			cout<<"Vuelva a dar el dato pedido\n";
		}else
		{
			cntr=0;
		}
	}while(cntr!=0);

	cout<<"\nIntroduzca la hora y minuto de la cita\n";
	do
	{
		cout<<"Hora: ";
		cin>>FH->tm_hour;
		if((FH->tm_hour<=-1)||(FH->tm_hour>=24))
		{
			cntr++;
			cout<<"\nParametro fuera de intervalo permitido [0-23]\n";
			cout<<"Vuelva a dar el dato pedido\n";
		}else
		{
			cntr=0;
		}
	}while(cntr!=0);

	do
	{
		cout<<"Minuto: ";
		cin>>FH->tm_min;
		if((FH->tm_min<=-1)||(FH->tm_min>=60))
		{
			cntr++;
			cout<<"\nParametro fuera de intervalo permitido [0-59]\n";
			cout<<"Vuelva a dar el dato pedido\n";
		}else
		{
			cntr=0;
		}
	}while(cntr!=0);
}

bool Inv_date(list<Cita> c,struct tm FH)
{
	struct tm temp;
	list<Cita>::iterator it;

	for(it=c.begin();it!=c.end();it++)
	{
		temp=it->getFechayHora();
		if(FH.tm_year==temp.tm_year)
		{
			if(FH.tm_mon==temp.tm_mon)
			{
				if(FH.tm_mday==temp.tm_mday)
				{
					if(FH.tm_hour==temp.tm_hour)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void VolcarDatos(list<Cita> c)
{
	Paciente temp;
	list<Cita>::iterator it;
	struct tm FH;

	ofstream fichero;
	fichero.open("../BD/citas.txt");
	if(fichero.is_open())
	{
		for(it=c.begin();it!=c.end();it++)
		{
			temp=it->getPaciente();
			FH=it->getFechayHora();
			fichero<<temp.getNombre()<<"|"<<temp.getApellidos()<<"|"<<temp.getTelefono()<<"|";
			fichero<<FH.tm_mday<<"/"<<FH.tm_mon<<"/"<<FH.tm_year<<"|"<<FH.tm_hour<<:<<FH.tm_min<<"|";
			fichero<<it->getDescripcion()<<"\n";
		}
	}
}