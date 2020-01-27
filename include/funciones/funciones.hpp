#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <list>

#include "../clases/cita.hpp"

void MostrarListaPacientes(list<Paciente> p);

bool CrearCita(list <Cita> *c);

bool MostrarCita(list<Cita> c);

bool ModificarCita(list <Cita> *c);

#endif