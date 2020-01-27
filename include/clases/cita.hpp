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
		string descripcion_;

	public:
		//Constructor
		Cita();
		//Observadores
		inline void setNombre(string name){ nombre_=name; }
		inline void setTelefono(int telef) { telefono_=telef; }
		inline void setFechayHora(struct tm fyh){ fechayhora_=fyh; }
		inline void setDescripcion(string info) const{  descripcion_=info; }
		//Modificadores
		inline string getNombre() const{ return nombre_; }
		inline int getTelefono() const{ return telefono_; }
		inline struct tm getFechayHora() const{ return fechayhora_; }
		inline string getDescripcion() const{ return descripcion_; }
};

#endif