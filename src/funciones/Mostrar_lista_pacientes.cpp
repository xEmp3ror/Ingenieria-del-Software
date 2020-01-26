#include <cstdio>
#include <cstdlib>
#include "../include/funciones/Mostrar_lista_pacientes.hpp"

using namespace std;

void MostrarListaPacientes(list<Paciente> *p)
{
	list<Persona>::iterator it;
	for(it=p.begin();it!=pacientes_.end();it++)
	{
		cout<<it->getNombrecompleto()<<"|"<<it->getTelefono()<<"|"<<it->getCorreo()<<"|"<<it->getDireccion()<<"\n";

	}
}
