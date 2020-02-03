#include "funciones.hpp"
#include "paciente.hpp"
#include "macros.hpp"
#include "cita.hpp"
#include <string>
#include <fstream>

//void Paciente::buscarPaciente(const string &nombre, const string &apellidos);
void menu();

int main(){

std::list<Paciente> pacientes;

std::list<Cita> citas;


string option;
int selection = 0;

std::ifstream fichero;

cargarPacientes(pacientes);
CargarCitas(&citas);

// read the input

 
    do{ 
        system("clear");
        menu();

        cout<<"\n\nIntroduzca la opción que desee realizar:";
        std::getline(std::cin,option);
        selection = std::stoi(option);
        std::cout<<std::endl;

        guardarPacientes(pacientes);
        VolcarDatos(citas);

        switch(selection)

        {

            case 1 :{insertarPaciente(pacientes);}

            break;

            case 2 :{modificarPaciente(pacientes);}

            break;

            case 3 :{eliminarPaciente(pacientes);}

            break;

            case 4 :{buscarPaciente(pacientes);}

            break;

            case 5:{MostrarListaPacientes(pacientes);}

            break;

            case 6:{CrearCita(&citas);}

            break;

            case 7:{EliminarCita(&citas);}

            break;

            case 8:{MostrarCita(citas);}

            break;

            case 9:{MostrarListaCitas(&citas);}

        }

    }while(selection!=0);
    

    return 0;

   //Paciente paciente(a,b,c);
    //paciente.buscarPaciente(a,b,c);
}

void menu() {

    cout<<BCYAN<<"\n _______________________________________________________";
cout<<"\n|                          MENU                         |";
cout<<"\n|                                                       |";
cout<<"\n|                1 - Insertar paciente                  |";
cout<<"\n|                                                       |";
cout<<"\n|                2 - Modificar paciente                 |";
cout<<"\n|                                                       |";
cout<<"\n|                 3 - Eliminar paciente                 |";
cout<<"\n|                                                       |";
cout<<"\n|                  4 - Buscar paciente                  |";
cout<<"\n|                                                       |";
cout<<"\n|              5 - Mostrar lista de pacientes           |";
cout<<"\n|                                                       |";
cout<<"\n|                   6 - Crear una cita                  |";
cout<<"\n|                                                       |";
cout<<"\n|                 7 - Eliminar una cita                 |";
cout<<"\n|                                                       |";
cout<<"\n|                  8 - Mostrar una cita                 |";
cout<<"\n|                                                       |";
cout<<"\n|               9 - Mostrar lista de citas              |";
cout<<"\n|                                                       |";
cout<<"\n|                                                       |";
cout<<"\n|                       0 - Salir                       |";
cout<<"\n|_______________________________________________________|"<<RESET;

}