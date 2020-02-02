#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <string>

#include "paciente.hpp"

using namespace std;

class Historial {

    private:

    string fecha_;
    string alergias_;
    string sintomas_;
    string medicacion_;
    Paciente * p_;

    public:

    Historial(Paciente * p, string fecha, string sintomas, string alergias="") {
        p_ = p;
        fecha_ = fecha;
        sintomas_ = sintomas;
        alergias_ = alergias;
    }

    inline string getFechaHistorial(){ return fecha_; }
    inline string getSintomas(){ return sintomas_; }
    inline string getMedicacion(){ return medicacion_; }

    inline string getAlergias() { 

        if(alergias = "") {
            return "No hay alergias conocidas."
        } else {
            return alergias_;
        }
    }

    inline Paciente * getPaciente(){ return p_; }

    void verHistorial();
    bool guardarHistorial();
    static bool buscarHistorial(Paciente * p, vector<Historial> * v);
};


