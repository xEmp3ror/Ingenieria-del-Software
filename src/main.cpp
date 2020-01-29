//#include "../FUNCIONES/funciones.hpp"
//#include "../CLASES/PACIENTE/paciente.hpp"
//#include "../FUNCIONES/macros.hpp"
#include "../include/clases/cita.hpp"
#include "../include/clases/paciente.hpp"
#include "../include/funciones/funciones.hpp"
#include <string>
#include <fstream>

//void Paciente::buscarPaciente(const string &nombre, const string &apellidos);

int main(){

std::list<Paciente> pacientes;
std::list<Cita> citas;
string option;
int selection = 0;

std::ifstream fichero;
fichero.open ("../BD/pacientes.txt");
if (!fileEmpty(fichero)) {    
     cargarPacientes(pacientes);
     std::cout<<" SE HAN CARGADO LOS PACIENTES EN MEMORIA"<<std::endl;
}
fichero.close();

CargarCitas(&citas);

 

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
cout<<"\n|                 5 - Guardar pacientes                 |";
cout<<"\n|                                                       |";
cout<<"\n|                    6 - Crear Cita                     |";
cout<<"\n|                                                       |";
cout<<"\n|                  7 - Modificar Cita                   |";
cout<<"\n|                                                       |";
cout<<"\n|                   8 - Mostrar Cita                    |";
cout<<"\n|                                                       |";
cout<<"\n|                   9 - Guardar citas                   |";
cout<<"\n|                                                       |";
cout<<"\n|                       10 - Salir                       |";
cout<<"\n|_______________________________________________________|"<<RESET;


// read the input

 
    do{
        cout<<"\n\nIntroduzca la opción que desee realizar:";
        std::getline(std::cin,option);
        selection = std::stoi(option);
        std::cout<<std::endl;
        switch(selection)

        {

           /* case 1 :{insertarPaciente(pacientes);}

            break;

            case 2 :{modificarPaciente(pacientes);}

            break;

            case 3 :{eliminarPaciente(pacientes);}

            break;

            case 4 :{buscarPaciente(pacientes);}

            break;

            case 5:{guardarPacientes(pacientes);}

            break;*/

            case 6:
            {
                if(CrearCita(&citas)==true)
                {
                    std::cout<<"Cita creada con exito\n";
                }else
                {
                    std::cout<<"Error el paciente ya tiene una cita\n";
                }
            }

            break;

            case 7:
            {
                if(ModificarCita(&citas)==true)
                {
                    std::cout<<"Cita modificada con exito\n";
                }else
                {
                    std::cout<<"Error el paciente no tiene ninguna cita prevista\n";
                }
            }

            break;

            case 8:{MostrarCita(citas);}

            break;

            case 9:{VolcarDatos(citas);}

            break;

            // other than A, M, D and X...

        }

    }while(selection!=6);
    

    return 0;

   //Paciente paciente(a,b,c);
    //paciente.buscarPaciente(a,b,c);
}