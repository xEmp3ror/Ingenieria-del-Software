#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <string>

#include "../include/funciones/Mostrar_cita.hpp"

bool MostrarCita(list<Cita> *c,string name,int number)
{
	list<Cita>::iterator it;
	struct tm fyh;
	
	for(it=c->begin();it!=c->end();it++)
	{
		if((name.compare(it->getNombre())==0)&&(it->getTelefono()==telf))
		{
			fyh=it->getFechayHora();
			cout<<it->getNombre()<<"|"<<it->getTelefono()<<"|"<<it->getDireccion()<<"\n";
			cout<<"Fecha: "<<fyh.tm_mday<<"/"<<fyh.tm_mon<<"/"<<fyh.tm_year<<" a las "<<fyh.tm_hour<<":"<<fyh.tm_min;
			return true;
		}
	}
	return false;
}