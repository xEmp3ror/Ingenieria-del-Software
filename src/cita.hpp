#ifndef CITA_H
#define CITA_H

#include <string>
#include <ctime>
#include "paciente.hpp"

using namespace std;

class Cita
{
	private:
		Paciente paciente_;
		struct tm fechayhora_;
		string descripcion_;

	public:
		//Constructor
		Cita();
		//Observadores
		inline void setPaciente(Paciente p){ paciente_=p; }
		inline void setFechayHora(struct tm fyh){ fechayhora_=fyh; }
		inline void setDescripcion(string info){  descripcion_=info; }
		//Modificadores
		inline Paciente getPaciente() const{ return paciente_; }
		inline struct tm getFechayHora() const{ return fechayhora_; }
		inline string getDescripcion() const{ return descripcion_; }
};

#endif