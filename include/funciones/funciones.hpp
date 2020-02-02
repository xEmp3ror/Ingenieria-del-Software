#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <list>

#include "../clases/cita.hpp"
#include "../clases/paciente.hpp"
#include <string>
#include <iostream>
#include <cstdio>

bool insertarPaciente(std::list<Paciente>& pacientes);

bool modificarPaciente(std::list<Paciente>& pacientes);

bool eliminarPaciente(std::list<Paciente>& pacientes);

void guardarPacientes(std::list<Paciente>& pacientes);

bool existePaciente(Paciente& p, std::list<Paciente>& pacientes);

void cargarPacientes(std::list<Paciente>& pacientes);

bool fileEmpty(std::ifstream& file);

void recorrerLista(std::list<Paciente>& pacientes);

Paciente buscarPaciente(std::list<Paciente>& pacientes);

Paciente ingresarDatos();

bool operator==(const Paciente& p1, const Paciente& p2);

bool checkFechaNacimiento(const string &fecha);

void MostrarListaPacientes(list<Paciente> p);

bool CrearCita(list <Cita> *c);

bool EliminarCita(list <Cita> *c);

bool MostrarCita(list<Cita> c);

bool ModificarCita(list <Cita> *c);

bool MostrarListaCitas(list<Cita> *c,string name,int number);

bool ModificarHistorial(list <Historial> *h);

//Carga las citas que existen dentro del documento citas.txt en la carpeta BD
void CargarCitas(list <Cita> *c);

//Funcion para introducir la hora de una cita bajo restringciones
void InsertFyH(struct tm *FH);

//Funcion que nos permite comprobar que la hora de una cita no coincida con ninguna otra de la lista
bool Inv_date(list<Cita> c,struct tm FH);

//Guarda la lista de citas en un fichero
void VolcarDatos(list<Cita> c);

#endif