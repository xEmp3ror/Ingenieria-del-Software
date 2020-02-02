#ifndef _FUNCIONES_HPP_
#define _FUNCIONES_HPP_
#include "../CLASES/PACIENTE/paciente.hpp"
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

#endif