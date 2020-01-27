#include "mostrar_lista_citas.hpp"

bool MostrarListaCitas(list<Cita> *c,string name,int number) {

	list<Cita>::iterator it;
	struct tm fyh;
	
	for (it=p.begin();it!=pacientes_.end();it++) {

		cout << "Cita con : " << it->getNombre() << "." << endl;
        cout << "El día   : " << fyh.tm_mday<<"/"<<fyh.tm_mon<<"/"<<fyh.tm_year<<" a las "<<fyh.tm_hour<<":"<<fyh.tm_min << endl;
        cout << "Teléfono : " << it->getTelefono() << "." << endl;
        cout << "Dirección: " << it->getDireccion() << "." << endl;
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;

	}

	return false;
}