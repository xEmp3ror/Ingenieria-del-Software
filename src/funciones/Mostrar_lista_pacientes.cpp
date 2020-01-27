#include <cstdio>
#include <cstdlib>

#include "../../include/funciones/Mostrar_lista_pacientes.hpp"

using namespace std;

void MostrarListaPacientes(list<Paciente> *p)
{
	list<Persona>::iterator it;
	for(it=p.begin();it!=pacientes_.end();it++)
	{
		cout<<"Nombre "it->getNombrecompleto()<<"\n"
		cout<<"Numero "it->getTelefono()<<"\n"
		cout<<"e-Mail "it->getCorreo()<<"\n"
		cout<<"Direccion "it->getDireccion()<<"\n\n";

	}
}
