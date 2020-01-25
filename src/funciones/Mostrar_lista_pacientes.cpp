#include <cstdio>
#include <cstdlib>
#include "Mostrar_lista_pacientes.hpp"

using namespace std;

void Mostrar_lista_pacientes(list<Paciente> *p)
{
	list<Persona>::iterator it;
	for(it=p.begin();it!=pacientes_.end();it++)
	{
		cout<<it->getNombrecompleto()<<"|"<<it->getTelefono()<<"|"<<it->getCorreo()<<"|"<<it->getDireccion()<<"\n";

	}
}
