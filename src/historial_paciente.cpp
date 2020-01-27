#include "historial_paciente.hpp"

void Historial::verHistorial() {

    cout << endl;
    cout << "Mostrando el historial de " << getPaciente()->getNombre() << " " << getPaciente()->getApellidos() << "." << endl;
    cout << endl;
    cout << "Fecha del expediente: " << getFecha() << "." << endl;
    cout << "Sintomas del paciente: " << getSintomas() << "." << endl;
    cout << "Alergias del paciente: " << getAlergias() << "." << endl;
    cout << endl;
    cout << "Medicación aplicada: " << getMedicacion() << "." << endl;
    cout << endl;

}

bool Historial::buscarHistorial(Paciente * p, vector <Historial> * v) {

    bool status = false;
    string nombre = p->getNombre();
    string apellido = p->getApellidos();

    fstream f("Historial de Pacientes.txt", ios::in);

    char fnombre[150], fapellido[150], fecha[150], sintomas[150], alergias[150];

    if(f.is_open()) {

        while(f.getline(fnombre, 150, ',')) {

            f.getline(fapellido, 150, ',');
            f.getline(fecha, 150, ',');
            f.getline(sintomas, 150, ',');
            f.getline(alergias, 150, '\n');

            if(fnombre == nombre && fapellido == apellido) {

                v -> push_back(Historial(p, fecha, sintomas, alergias));
            }
        }

        f.close();
        status = true;
    }

    return status;
}

bool Historial::guardarHistorial() {

    bool status = false;

    fstream f("Historial de Pacientes.txt", ios::app);

    if(f.is_open()) {

        f<<getPaciente()->getNombre()<<","<<getPaciente()->getApellidos()<<","<<getDate()<<","<<getSymptoms()<<","<<getAllergies()<<","<<getMedicacion()<<endl;
        f.close();

        status = true;
    }

    return status;
}