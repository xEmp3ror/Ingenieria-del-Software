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
			return false;
		}
	}
	temp.setNombre(name);
	temp.setApellidos(apellidos);

	cout<<"Introduza el telefono del paciente (no mas de 9 digitos)\n";
	cin>>num;
	do
	{
		if(num>=1000000000)
		{
			cout<<"Error. Introduzca otra vez el telefono(9 digitos)\n";
			cin>>num;
		}
	}while(num>=1000000000);
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

bool EliminarCita(list <Cita> *c)
{
	list<Cita>::iterator it;
	Paciente temp;
	string nombre;
	string apellidos;

	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca los apellidos del paciente\n";
	getline(cin,apellidos);

	//Buscamos que haya una cita asociada al Nombre y Apellidos dados
	for(it=c->begin();it!=c->end();it++)
	{
		temp=it->getPaciente();

		//Si el sistema localiza la cita que buscabamos la elimina de la lista
		if((nombre.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			c->erase(it);
			return true;
		}
	}
	return false;
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
	for(it=c->begin();(it!=c->end())&&(N==0);it++)
	{
		temp=it->getPaciente();
		if((nombre.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			n.setPaciente(it->getPaciente());
			n.setFechayHora(it->getFechayHora());
			n.setDescripcion(it->getDescripcion());
			c->erase(it);
			N++;
		}
	}

	//Si el Valor de N no ha variado==No existe la cita del paciente
	if(N==0)
	{
		return false;
	}
	temp=n.getPaciente();
	fyh=n.getFechayHora();
	cout<<"\nNombre: "<<temp.getNombre()<<"\n";
			cout<<"Apellidos: "<<temp.getApellidos()<<"\n";
			cout<<"Telefono: "<<temp.getTelefono()<<"\n";
			cout<<"Fecha: "<<fyh.tm_mday<<"/"<<fyh.tm_mon<<"/"<<fyh.tm_year<<" a las "<<fyh.tm_hour<<":"<<fyh.tm_min<<"\n";
			cout<<"Descripcion:\n";
			cout<<"  ·"<<n.getDescripcion()<<"\n\n";

	//Si N es distinto de 0==Hay una cita del paciente
	do
	{
		cout<<"\nIndique que parametro de la cita desea modificar: 1.Telefono/2.Fecha/3.Descripcion/4.Nada\n";
		cin>>N;
		switch(N)
		{
			case 1:
			{
				cout<<"Introduza el telefono del paciente (no mas de 9 digitos)\n";
				cin>>N;
				do
				{
					if(N>=1000000000)
					{
						cout<<"Error. Introduzca otra vez el telefono(no mas de 9 digitos)\n";
						cin>>N;
					}
				}while(N>=1000000000);
				temp.setTelefono(N);
				n.setPaciente(temp);
			}break;

			case 2:
			{
				cout<<"Indique la hora nueva del paciente\n";
				do
				{
					InsertFyH(&fyh);
				}while(Inv_date(*c,fyh)!=false);
				n.setFechayHora(fyh);
			}break;

			case 3:
			{
				cout<<"Describa la razon de la cita\n";
				cin.ignore();
				getline(cin,info);
				n.setDescripcion(info);
			}break;

			case 4:
			{
				//En caso de que se elija la opcion 4
			}break;

			default:
			{
				cout<<"La opcion elegida no esta dentro de las posibles a realizar\n";
			}break;
		}

	}while(N!=4);
	
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

bool ModificarHistorial(list <Historial> *h)
{
	Historial temp;
	list<Historial>::iterator ith;
	string enfermedad,mod;
	int cntr=0;

	cout<<"Se procedera a mostrar el historial del paciente\n";
	cout<<"---------Historial---------\n";
	for(ith=h->begin();ith!=h->end();ith++)
	{
		cout<<"  ·Enfermedad:"<<h->getEnfermedad()<<"\n";
		cout<<"  ·Sintomas:"<<h->getSintomas()<<"\n";
		cout<<"  ·Tratamiento:"<<h->getTratamiento()<<"\n";
		cout<<"  ·Duracion tratamiento:"<<h.getDuracionTratamiento()<<"\n";
	}
	cout<<"\nReferente a que enfermedad desea modificar el historial\n";
	cin.ignore();
	getline(cin,enfermedad);
	for(ith=h->begin();ith!=h->end();ith++)
	{
		if(enfermedad.compare(ith->getEnfermedad())==0)
		{
			temp=ith;
			h->erase(ith);
			cntr++;
		}
	}
	if(cntr==0)
	{
		cout<<"Error el paciente no tiene tal enfermedad\n";
		return false;
	}

	temp.setEnfermedad(enfermedad);
	do
	{
		cout<<"\nIndique que desea modificar: 1.Sintomas /2.Tratamiento /3.Duracion de tratamiento/4.Nada\n";
		cin>>cntr;
		switch(cntr)
		{
			case 1:
			{
				cout<<"Introduzca los nuevos sintomas\n";
				cin.ignore();
				getline(cin,mod);
				temp.setSintomas(mod);

			}break;

			case 2:
			{
				cout<<"Introduzca el nuevo tratamiento\n";
				cin.ignore();
				getline(cin,mod);
				temp.setTratamiento(mod);

			}break;

			case 3:
			{
				cout<<"Introduzca la nueva duracion del tratamiento\n";
				cin.ignore();
				getline(cin,mod);
				temp.setDuracionTratamiento(mod);

			}break;

			case 4:
			{
				//Solo para cuando se introduzca valor 4
			}break;

			default:
			{
				cout<<"La opcion elegida no esta dentro de las posibles a realizar\n";
			}
		}
	}while(cntr!=4);
	h->push_back(temp);
	return true;
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