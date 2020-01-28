#include <cstdio>
#include <cstdlib>

#include "../../include/funciones/funciones.hpp"

using namespace std;

void MostrarListaPacientes(list<Paciente> p)
{
	list<Persona>::iterator it;
	for(it=p.begin();it!=pacientes_.end();it++)
	{
		cout<<"Nombre: "it->getNombre()<<"   |   Apellidos: "it->getApellidos()<<"\n";
		cout<<"Fecha de nacimiento "it->getFechaNacimiento()<<"   |   Edad:"it->getEdad()<<"\n";
		cout<<"Telefono "it->getTelefono()<<"\n";
		cout<<"Direccion "it->getDireccion()<<"\n\n";

	}
}
