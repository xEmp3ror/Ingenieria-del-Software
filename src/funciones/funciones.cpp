#include "../CLASES/PACIENTE/paciente.hpp"
#include "../CLASES/HISTORIAL/historial.hpp"
#include "funciones.hpp"
#include "macros.hpp"
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <curses.h>


bool operator==(const Paciente& p1, const Paciente& p2){
    return p1.getNombre() == p2.getNombre() && p1.getApellidos() == p2.getApellidos();
}

void guardarPacientes(std::list<Paciente>& pacientes){
    std::list<Paciente>::iterator i=pacientes.begin();
    std::ofstream fichero;
    fichero.open ("../BD/pacientes.txt");
    
    for(i = pacientes.begin(); i != pacientes.end(); i++){
        /*std::cout<< i->getNombre() << "|" << i->getApellidos()<< "|"<< i->getEdad()<<"\n";*/
        fichero << i->getNombre()<< "|" << i->getApellidos()<< "|"<< i->getEdad()<< "|"<<i->getDomicilio()<< "|"<< i->getFechaNacimiento()<<"|"<< i->getTelefono()<<"\n";
    }
    
    fichero.close();
}

bool insertarPaciente(std::list<Paciente>& pacientes){
    string nombre, apellido, domicilio, telefono, fechanacimiento,stringedad, enfermedad, estaEnfermo, sintomas, tratamiento, duracionTratamiento;
    int edad, numerotelefono;
    bool checkEnfermo;
    std::list<Historial> historial;
    std::cout<<std::endl;
    std::cout<<BYELLOW<<"Introduzca el nombre del paciente"<<RESET<<std::endl;
    std::getline(std::cin, nombre);  
    std::cout<<std::endl;
    while(nombre=="none" || nombre==""){
        std::cout<<BRED<<"Por favor, introduzca un apellido válido"<<RESET<<std::endl;
        std::getline(std::cin, nombre);
        std::cout<<std::endl;     
    }
    std::cout<<BYELLOW<<"Introduzca el apellido del paciente"<<RESET<<std::endl;
    std::getline(std::cin, apellido);
    std::cout<<std::endl;
    while(apellido=="none" || apellido==""){
        std::cout<<BRED<<"Por favor, introduzca un apellido válido"<<RESET<<std::endl;
        std::getline(std::cin, apellido);
        std::cout<<std::endl;
    }
    std::cout<<BYELLOW<<"Introduzca la edad del paciente"<<RESET<<std::endl;
    std::getline(std::cin, stringedad);
    edad=std::stoi(stringedad);
    std::cout<<std::endl;
    
    while(edad<=0){
        std::cout<<BRED<<"Por favor, introduzca un número superior a 0"<<RESET<<std::endl;
        std::getline(std::cin, stringedad);
        edad=std::stoi(stringedad);
        std::cout<<std::endl;
    }
    std::cout<<BYELLOW<<"Introduzca el domicilio"<<RESET<<std::endl;
    std::getline(std::cin, domicilio);
    std::cout<<std::endl;
    std::cout<<BYELLOW<<"Introduzca el telefono"<<RESET<<std::endl;
    std::getline(std::cin, telefono);
    numerotelefono = std::stoi(telefono);
    std::cout<<std::endl;
    std::cout<<BYELLOW<<"Introduzca la fecha de nacimiento con el siguiente formato: día/mes/año"<<RESET<<std::endl;
    std::getline(std::cin, fechanacimiento);
    while(!checkFechaNacimiento(fechanacimiento)){
        std::cout<<"Formato erróneo, por favor ingrese la fecha de nuevo con el formato día/mes/año [XX/XX/XXXX]"<<std::endl;
        std::getline(std::cin, fechanacimiento);
    }
    std::cout<<std::endl;
    std::cout<<BYELLOW<<"Tiene el paciente alguna enfermedad? Si es así, introduzca 1. Si no ,0."<<RESET<<std::endl;
    std::getline(std::cin, estaEnfermo);
    std::cout<<std::endl;
    checkEnfermo = (estaEnfermo == "1");
    while(checkEnfermo){
        std::cout<<BYELLOW<<"Introduzca la enfermedad"<<RESET<<std::endl;
        std::getline(std::cin, enfermedad);
        std::cout<<std::endl;
        std::cout<<BYELLOW<<"Introduzca los sintomas"<<RESET<<std::endl;
        std::getline(std::cin, sintomas);
        std::cout<<std::endl;
        std::cout<<BYELLOW<<"Introduzca el tratamiento"<<RESET<<std::endl;
        std::getline(std::cin, tratamiento);
        std::cout<<std::endl;
        std::cout<<BYELLOW<<"Introduzca la duración del tratamiento"<<RESET<<std::endl;
        std::getline(std::cin, duracionTratamiento);
        std::cout<<std::endl;
        Historial h(enfermedad, sintomas, tratamiento, duracionTratamiento);
        historial.push_back(h);
        std::cout<<"si quiere seguir añadiendo enfermedades al historial, introduzca 1, si no, 0."<<std::endl;
        std::getline(std::cin, estaEnfermo);
        checkEnfermo = (estaEnfermo == "1");
    }
    Paciente paciente(nombre, apellido, edad, domicilio, fechanacimiento, numerotelefono);
    paciente.setHistorial(historial);
    cout<<"COMO PRUEBA, LOS SINTOMAS SON: "<<paciente.getHistorial().front().getSintomas()<<std::endl;
    if(!existePaciente(paciente, pacientes)){
        pacientes.push_back(paciente);

        //std::cout<<"FLAG IMPORTANTE"<<std::endl;
        return true;
    }
    else{
        std::cout<<"este paciente ya existe en la base de datos"<<std::endl;
        return false;
    }
    //std::cout<<"salio del bucle"<<std::endl;
}

bool existePaciente(Paciente& p, std::list<Paciente>& pacientes){
    //std::cout<<"FLAG PARA LA LLAMADA A EXISTE_PACIENTE"<<std::endl;
    std::list<Paciente>::iterator i;
    bool found = false;
    for(i=pacientes.begin(); i != pacientes.end(); i++){
        if((*i)==p){
            found = true;
        }
    }
    return found;
}

bool modificarPaciente(std::list<Paciente>& pacientes){
    string option;
    int numero;
    Paciente p = buscarPaciente(pacientes);
    if(existePaciente(p, pacientes)){
        std::list<Paciente>::iterator it;
        std::cout<<"¿Qué datos desea modificar?\n\n1.Nombre\n2.Apellidos\n3.Edad\n4.Domicilio\n5.Fecha de nacimiento\n6.Teléfono\n7.Salir de esta opción\n\n";
        do{
            std::cout<<"introduzca el campo (el número asociado a él) que desee modificar, o teclee 7 para salir"<<std::endl;
            getline(std::cin, option);
            std::cout<<std::endl;
            numero = std::stoi(option);
            switch(numero)
            {
                case 1 :{
                    string nombre, confirmacion;
                    bool EqualNameAndConfirmation = false;
                    std::cout<<"Introduzca el nuevo nombre: "<<std::endl;
                    std::getline(std::cin, nombre);
                    std::cout<<"Confirme el nuevo nombre: "<<std::endl;
                    std::getline(std::cin, confirmacion);
                    if(nombre==confirmacion){
                        EqualNameAndConfirmation = true;
                    }
                    while(!EqualNameAndConfirmation){
                        std::cout<<"Los nombres introducidos no coinciden. Por favor, vuelva a introducir el nombre: "<<std::endl;
                        std::getline(std::cin, nombre);
                        std::cout<<"Confirme de nuevo: "<<std::endl;
                        std::getline(std::cin, confirmacion);
                        if(nombre==confirmacion){
                            EqualNameAndConfirmation = true;
                        }
                    }
                    for(it = pacientes.begin(); it != pacientes.end(); it++){
                        if(p==(*it)){
                            (*it).setNombre(nombre);
                            std::cout<<"se ha cambiado el nombre del paciente"<<std::endl;
                            std::cout<<std::endl;
                        }
                    }
                }

                break;

                case 2:{
                    string apellidos, confirmacion;
                    bool EqualSurnameAndConfirmation = false;
                    std::cout<<"Introduzca los nuevos apellidos: "<<std::endl;
                    std::getline(std::cin, apellidos);
                    std::cout<<"Confirme los nuevos apellidos: "<<std::endl;
                    std::getline(std::cin, confirmacion);
                    if(apellidos==confirmacion){
                        EqualSurnameAndConfirmation = true;
                    }
                    while(!EqualSurnameAndConfirmation){
                        std::cout<<"Los apellidos introducidos no coinciden. Por favor, vuelva a introducirlos: "<<std::endl;
                        std::getline(std::cin, apellidos);
                        std::cout<<"Confirme de nuevo: "<<std::endl;
                        std::getline(std::cin, confirmacion);
                        if(apellidos==confirmacion){
                            EqualSurnameAndConfirmation = true;
                        }
                    }
                    for(it = pacientes.begin(); it != pacientes.end(); it++){
                        if(p==(*it)){
                            (*it).setApellidos(apellidos);
                            std::cout<<"se han cambiado los apellidos del paciente"<<std::endl;
                            std::cout<<std::endl;
                        }
                    }
                
                }

                break;

                case 3:{
                    string edad, confirmacion;
                    int edadEntero;
                    bool EqualEdadAndConfirmation = false;
                    std::cout<<"Introduzca la nueva edad: "<<std::endl;
                    std::getline(std::cin,edad);
                    std::cout<<"Confirme la nueva edad: "<<std::endl;
                    std::getline(std::cin, confirmacion);
                    if(edad==confirmacion){
                        EqualEdadAndConfirmation = true;
                    }
                    while(!EqualEdadAndConfirmation){
                        std::cout<<"Las edades introducidas no coinciden. Por favor, vuelva a introducirlas: "<<std::endl;
                        std::getline(std::cin, edad);
                        std::cout<<"Confirmelo de nuevo: "<<std::endl;
                        std::getline(std::cin, confirmacion);
                        if(edad==confirmacion){
                            EqualEdadAndConfirmation = true;
                        }
                    }
                    edadEntero = std::stoi(edad);
                    for(it = pacientes.begin(); it != pacientes.end(); it++){
                        if(p==(*it)){
                            (*it).setEdad(edadEntero);
                            std::cout<<"se ha cambiado la edad del paciente"<<std::endl;
                            std::cout<<std::endl;
                        }
                    }
                }

                break;

                case 4:{
                    string domicilio, confirmacion;
                    bool EqualDomicilioAndConfirmation = false;
                    std::cout<<"Introduzca el nuevo domicilio: "<<std::endl;
                    std::getline(std::cin, domicilio);
                    std::cout<<"Confirme el nuevo domicilio: "<<std::endl;
                    std::getline(std::cin, confirmacion);
                    if(domicilio==confirmacion){
                        EqualDomicilioAndConfirmation = true;
                    }
                    while(!EqualDomicilioAndConfirmation){
                        std::cout<<"Los domicilios introducidos no coinciden. Por favor, vuelva a introducirlo: "<<std::endl;
                        std::getline(std::cin, domicilio);
                        std::cout<<"Confirmelo de nuevo: "<<std::endl;
                        std::getline(std::cin, confirmacion);
                        if(domicilio==confirmacion){
                            EqualDomicilioAndConfirmation = true;
                        }
                    }
                    for(it = pacientes.begin(); it != pacientes.end(); it++){
                        if(p==(*it)){
                            (*it).setDomicilio(domicilio);
                            std::cout<<"se ha cambiado el domicilio del paciente"<<std::endl;
                            std::cout<<std::endl;
                        }
                    }
                }

                break;

                case 5:{
                    string fecha, confirmacion;
                    std::cout<<"Introduzca la nueva fecha de nacimiento, con formato día/mes/año: "<<std::endl;
                    std::getline(std::cin, fecha);
                    std::cout<<std::endl;
                    std::cout<<"Confirme la nueva fecha: "<<std::endl;
                    std::getline(std::cin, confirmacion);
                    std::cout<<std::endl;
                    while(fecha!=confirmacion || !checkFechaNacimiento(fecha) || !checkFechaNacimiento(confirmacion)){
                        std::cout<<"las fechas no coinciden o el formato está mal, vuelve a introducir la fecha"<<std::endl;
                        std::getline(std::cin, fecha);
                        std::cout<<"Confirmela de nuevo: "<<std::endl;
                        std::getline(std::cin, confirmacion);
                    }
                    for(it = pacientes.begin(); it != pacientes.end(); it++){
                        if((*it)==p){
                            (*it).setFechaNacimineto(fecha);
                            std::cout<<"se ha cambiado la fecha del paciente"<<std::endl;
                            std::cout<<std::endl;
                        }
                    }
                }

                break;

                case 6:{
                    string telefono, confirmacion;
                    int TelefonoEntero;
                    bool EqualTelefonoAndConfirmation = false;
                    std::cout<<"Introduzca el nuevo telefono: "<<std::endl;
                    std::getline(std::cin,telefono);
                    std::cout<<"Confirmelo: "<<std::endl;
                    std::getline(std::cin, confirmacion);
                    std::cout<<std::endl;
                    if(telefono==confirmacion){
                        EqualTelefonoAndConfirmation = true;
                    }
                    while(!EqualTelefonoAndConfirmation){
                        std::cout<<"Las edades introducidas no coinciden. Por favor, vuelva a introducirlas: "<<std::endl;
                        std::getline(std::cin, telefono);
                        std::cout<<"Confirmelo de nuevo: "<<std::endl;
                        std::getline(std::cin, confirmacion);
                        if(telefono==confirmacion){
                            EqualTelefonoAndConfirmation = true;
                        }
                    }
                    TelefonoEntero = std::stoi(telefono);
                    for(it = pacientes.begin(); it != pacientes.end(); it++){
                        if(p==(*it)){
                            (*it).setTelefono(TelefonoEntero);
                            std::cout<<"se ha cambiado el telefono del paciente"<<std::endl;
                            std::cout<<std::endl;
                        }
                    }
                }

                break;
            }
        }while(numero!=7);
    }    
}

bool eliminarPaciente(std::list<Paciente>& pacientes){
    std::cout<<"Introduzca nombre y apellidos del paciente a eliminar"<<std::endl;
    Paciente p = ingresarDatos();
    int contador = 0;
    std::list<Paciente>::iterator it;
    if(!existePaciente(p, pacientes)){
        std::cout<<"Este paciente no se encontraba en la base de datos"<<std::endl;
    }
    else{
        pacientes.remove(p);
    }
}

Paciente ingresarDatos(){
    string nombre, apellidos;
    std::cout<<"NOMBRE: "<<std::endl;
    std::getline(std::cin, nombre); 
    std::cout<<std::endl;
    std::cout<<"APELLIDOS: "<<std::endl;
    std::getline(std::cin, apellidos);
    std::cout<<std::endl;
    Paciente p(nombre, apellidos);
    return p;
}


void cargarPacientes(std::list<Paciente>& pacientes){
    std::list<Paciente>::iterator it;
    std::ifstream fichero;
    string linea;
    int entero;
    string nombre, apellidos, fechanacimiento, domicilio;
    int telefono;
    int edad;
    //fichero.close();
    fichero.open ("../BD/pacientes.txt");
    fichero.seekg (0, ios::beg);
    it=pacientes.begin();
    Paciente p;
    while(getline(fichero, nombre, '|')){
        getline(fichero, apellidos, '|');
        getline(fichero, linea, '|');
        edad = std::stoi(linea);
        getline(fichero, domicilio, '|');
        getline(fichero, fechanacimiento, '|');
        getline(fichero, linea, '\n');
        telefono = std::stoi(linea);
        p.setEdad(edad);
        p.setNombre(nombre);
        p.setApellidos(apellidos);
        p.setDomicilio(domicilio);
        p.setFechaNacimineto(fechanacimiento);
        p.setTelefono(telefono);
        pacientes.push_back(p);
        it++;
    }
    fichero.close();
}

bool fileEmpty(std::ifstream& file){
    return file.peek() == std::ifstream::traits_type::eof();
}

void recorrerLista(std::list<Paciente>& pacientes){
    std::list<Paciente>::iterator it;
    for(it = pacientes.begin(); it!= pacientes.end(); it++){
        std::cout<<it->getNombre()<<" ,"<<it->getApellidos()<< " ,"<<it->getEdad()<<std::endl;
    }
}

Paciente buscarPaciente (std::list<Paciente>& pacientes){
    std::list<Paciente>::iterator  it = pacientes.begin();
    string nombre, apellidos;
    bool found = false;
    std::cout<<"Introduzca los nombres y apellidos del paciente que desea buscar"<<std::endl;
    std::cout<<std::endl;
    Paciente p = ingresarDatos();
    if(existePaciente(p, pacientes)){
        while(it != pacientes.end() && !found){
            if((*it)==p){
                found = true;
                std::cout<<"Los datos del paciente son: "<<std::endl;
                std::cout<<"Edad: "<<it->getEdad()<<std::endl;
                std::cout<<"Domicilio: "<<it->getDomicilio()<<std::endl;      
                std::cout<<"Fecha de nacimiento: "<<it->getFechaNacimiento()<<std::endl;
                std::cout<<"Telefono: "<<it->getTelefono()<<std::endl<<std::endl;
                std::cout<<std::endl;
                return p;
            }
            it++;
            std::cout<<"FLAG PARA LA VIOLACION DE SEGMENTO EN LA BUSQUEDA"<<std::endl;
        }

    }
    else{std::cout<<"Lo sentimos, no existe dicho paciente";}
}

bool checkNombreApellidos(const string & cadena){
    if(cadena=="" || cadena=="none"){
        return false;
    }
    else return true;
}

bool checkTelefono(const int & telefono){
    if(std::to_string(telefono).length()!=9){
        return false;
    }
    else if(telefono < 600000000 || telefono > 799999999){
        return false;
    }
    else return true;
}

bool checkFechaNacimiento(const string & fecha){
    string fechalocal = fecha;
    int day, month, year;
    string delimitador = "/";
    int posicion = fechalocal.find(delimitador);
    day = std::stoi(fechalocal.substr(0, posicion));
    fechalocal.erase(0, posicion + delimitador.length());
    posicion = fechalocal.find(delimitador);
    month=std::stoi(fechalocal.substr(0, posicion));
    fechalocal.erase(0, posicion + delimitador.length());
    posicion = fechalocal.find(delimitador);
    year=std::stoi(fechalocal.substr(0,posicion));
    if(day<1 || day > 31){
        return false;
    }
    else if(day > 29 && month == 2){
        return false;
    }
    else if(month < 1 || month > 12){
        return false;
    }
    else if(year>2020 || year < 1900){
        return false;
    }
    else return true;
}
