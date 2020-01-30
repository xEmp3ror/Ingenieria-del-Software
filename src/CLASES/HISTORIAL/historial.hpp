#ifndef _HISTORIAL_HPP_
#define _HISTORIAL_HPP_

#include <string>
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

class Historial {
    private:
        string enfermedad_;
        string sintomas_;
        string tratamiento_;
        string duracionTratamiento_;
        
    public:
        Historial (const string& enfermedad="ninguna", const string& sintomas="ninguna", const string& tratamiento="ninguno", const string& duracionTratamiento = "ninguna" ):
            enfermedad_(enfermedad), sintomas_(sintomas), tratamiento_(tratamiento), duracionTratamiento_(duracionTratamiento){}
        void setEnfermedad(const string& enfermedad){enfermedad_ = enfermedad;}
        void setTratamiento(const string& tratamiento){tratamiento_ = tratamiento;}
        void setDuracionTratamiento(const string& duracionTratamiento){duracionTratamiento_ = duracionTratamiento;}
        void setSintomas(const string& sintomas){sintomas_ = sintomas;}
        const string& getEnfermedad() const {return enfermedad_;}
        const string& getTratamiento() const {return tratamiento_;};
        const string& getDuracionTratamiento() const {return duracionTratamiento_;}
        const string& getSintomas() const {return sintomas_;}
};

#endif