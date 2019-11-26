
#ifndef CITA_H
#define CITA_H

#include <string>

using namespace std;

class Cita
{
	private:
		string nombre_;
		int telefono_;
		struct tm fechayhora_;

	public:
		
		Cita();

		inline void setNombre(string name){ nombre_=name; }
		inline string getNombre() const{ return nombre_; }

		inline void setTelefono(int telef) { telefono_=telef; }
		inline int getTelefono() const{ return telefono_; }

		inline void setFechayHora(struct tm fyh){ fechayhora_=fyh; }
		inline struct tm getFechayHora() const{ return fechayhora_; }
};

#endif