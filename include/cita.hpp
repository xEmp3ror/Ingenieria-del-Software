#ifndef CITA_H
#define CITA_H

#include <string>
#include <ctime>

using namespace std;

class Cita
{
	private:
		string nombre_;
		int telefono_;
		struct tm fechayhora_;

	public:
		//Constructor
		Cita();
		//Observadores
		inline void setNombre(string name){ nombre_=name; }
		inline void setTelefono(int telef) { telefono_=telef; }
		inline void setFechayHora(struct tm fyh){ fechayhora_=fyh; }
		//Modificadores
		inline string getNombre() const{ return nombre_; }
		inline int getTelefono() const{ return telefono_; }
		inline struct tm getFechayHora() const{ return fechayhora_; }
};

#endif