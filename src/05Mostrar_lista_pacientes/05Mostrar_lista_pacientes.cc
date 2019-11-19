#include <cstdio>
#include <cstdlib>

using namespace std;

void Mostrar_lista_pacientes()
{
	list<Persona>::iterator it;
	for(it=pacientes_.begin();it!=pacientes_.end();it++)
	{
		cout<<it->getNombrecompleto()<<"|"<<it->getTelefono()<<"|"<<it->getCorreo()<<"|"<<it->getDireccion()<<"\n";

	}
}
