#ifndef _PACIENTE_HPP_
#define _PACIENTE_HPP_

#include <string>
#include <iostream>
#include <cstdio>
#include <list>
#include "../HISTORIAL/historial.hpp"
using namespace std;

class Paciente {
  private:
    string nombre_;
    string apellidos_;
    int edad_;
    string domicilio_;
    string fechaNacimiento_;
    int telefono_;
    std::list<Historial> historial_;
    
  public:
    Paciente(const string &nombre="none", const string &apellidos="none", const int &edad=0, const string& domicilio="none", const string& fechanacimiento="none", const int& telefono=0): 
      nombre_(nombre), apellidos_(apellidos), edad_(edad), domicilio_(domicilio), fechaNacimiento_(fechanacimiento), telefono_(telefono){};
    const string & getNombre() const {return nombre_;};
    const string & getApellidos() const {return apellidos_;};
    const int & getEdad() {return edad_;};
    void setNombre(const string &nombre){nombre_ = nombre;};
    void setApellidos(const string & apellidos){apellidos_ = apellidos;};void setEdad(const int &edad){edad_ = edad;};
    const string & getFechaNacimiento() const {return fechaNacimiento_;}
    void setFechaNacimineto(const string &fechanacimiento){fechaNacimiento_=fechanacimiento;}
    const string & getDomicilio() const {return domicilio_;}
    void setDomicilio(const string &domicilio){domicilio_=domicilio;}
    void setTelefono(const int& telefono){telefono_=telefono;}
    const int& getTelefono(){return telefono_;}
    const std::list<Historial> getHistorial(){return historial_;}
    void setHistorial(const std::list<Historial>& historial){historial_ = historial;}
    //Paciente & insertarPaciente(const string &nombre, const string &apellidos);
    //Paciente & modificarPaciente(const string &nombre, const string &apellidos);
    //bool eliminarPaciente(const string &nombre, const string & apellidos);

};


#endif