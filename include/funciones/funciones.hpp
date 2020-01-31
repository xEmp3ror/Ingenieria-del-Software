#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <list>

#include "../clases/cita.hpp"
#include "../clases/paciente.hpp"

void MostrarListaPacientes(list<Paciente> p);

bool CrearCita(list <Cita> *c);

bool EliminarCita(list <Cita> *c);

bool MostrarCita(list<Cita> c);

bool ModificarCita(list <Cita> *c);

bool ModificarHistorial(list <Paciente> *p);

//Carga las citas que existen dentro del documento citas.txt en la carpeta BD
void CargarCitas(list <Cita> *c);

//Funcion para introducir la hora de una cita bajo restringciones
void InsertFyH(struct tm *FH);

//Funcion que nos permite comprobar que la hora de una cita no coincida con ninguna otra de la lista
bool Inv_date(list<Cita> c,struct tm FH);

//Guarda la lista de citas en un fichero
void VolcarDatos(list<Cita> c);

#endif