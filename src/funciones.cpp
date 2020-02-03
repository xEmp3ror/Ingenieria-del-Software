#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <string>
#include <fstream>
#include <list>

#include "funciones.hpp"
//#include "historial.hpp"
#include "cita.hpp"
#include "macros.hpp"

using namespace std;

void MostrarListaPacientes(list<Paciente> p)
{
	list<Paciente>::iterator it;
	for(it=p.begin();it!=p.end();it++)
	{
		cout<<"    ·Nombre "<<it->getNombre()<<"   ·Apellidos "<<it->getApellidos()<<"\n";
		cout<<"    ·Fecha Nacimiento"<<it->getFechaNacimiento()<<"  ·Edad"<<it->getEdad()<<"\n";
		cout<<"    ·Telefono "<<it->getTelefono()<<"   ·Domicilio "<<it->getDomicilio()<<"\n\n";

	}
}

void CargarCitas(list<Cita> *c)
{
	Cita X;
	Paciente temp;
	string nombre;
	string apellidos;
	string number;
	string info;
	string hora;
	string min;
	string dia;
	string mes;
	string year;
	struct tm fecha;

	ifstream fichero;
	fichero.open("../BD/citas.txt");
	if(fichero.is_open())
	{
		while(getline(fichero,nombre,'|'))
		{
			getline(fichero,apellidos,'|');
			getline(fichero,number,'|');
			getline(fichero,dia,'/');
			getline(fichero,mes,'/');
			getline(fichero,year,'|');
			getline(fichero,hora,':');
			getline(fichero,min,'|');
			getline(fichero,info,'\n');

			fecha.tm_mday=stoi(dia);
			fecha.tm_mon=stoi(mes);
			fecha.tm_year=stoi(year);
			fecha.tm_hour=stoi(hora);
			fecha.tm_min=stoi(min);
			temp.setNombre(nombre);
			temp.setApellidos(apellidos);
			temp.setTelefono(stoi(number));
			X.setPaciente(temp);
			X.setFechayHora(fecha);
			X.setDescripcion(info);
			c->push_back(X);
		}
	}
	fichero.close();
}

bool CrearCita(list <Cita> *c)
{
	Cita aux;
	Paciente temp;
	string name;
	string apellidos;
	string info;
	int num;
	struct tm fyh;
	list<Cita>::iterator it;

	cout<<"Introduza el nombre del paciente\n";
//	cin.ignore();
	getline(cin,name);
	cout<<"Introduza los apellidos del paciente\n";
	getline(cin,apellidos);
	//Busca que no haya otra cita del mismo paciente
	for(it=c->begin();it!=c->end();it++)
	{
		temp=it->getPaciente();

		if((name.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			return false;
		}
	}
	temp.setNombre(name);
	temp.setApellidos(apellidos);

	cout<<"Introduza el telefono del paciente (no mas de 9 digitos)\n";
	cin>>num;
	do
	{
		if(num>=1000000000)
		{
			cout<<"Error. Introduzca otra vez el telefono(9 digitos)\n";
			cin>>num;
		}
	}while(num>=1000000000);
	temp.setTelefono(num);
	aux.setPaciente(temp);
	
	do
	{
		InsertFyH(&fyh);
	}while(Inv_date(*c,fyh)!=false);
	aux.setFechayHora(fyh);

	cout<<"Indique las razones de la cita\n";
	cin.ignore();
	getline(cin,info);
	aux.setDescripcion(info);

	c->push_back(aux);
	return true;
}

bool EliminarCita(list <Cita> *c)
{
	list<Cita>::iterator it;
	Paciente temp;
	string nombre;
	string apellidos;

	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca los apellidos del paciente\n";
	getline(cin,apellidos);

	//Buscamos que haya una cita asociada al Nombre y Apellidos dados
	for(it=c->begin();it!=c->end();it++)
	{
		temp=it->getPaciente();

		//Si el sistema localiza la cita que buscabamos la elimina de la lista
		if((nombre.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			c->erase(it);
			return true;
		}
	}
	return false;
}

bool ModificarCita(list <Cita> *c)
{
	list<Cita>::iterator it;
	Cita n;
	Paciente temp;
	int N=0;
	struct tm fyh;
	string nombre;
	string apellidos;
	string info;

	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca los apellidos del paciente\n";
	getline(cin,apellidos);

	//Buscamos que haya una cita asociada al Nombre y Apellidos dados
	for(it=c->begin();(it!=c->end())&&(N==0);it++)
	{
		temp=it->getPaciente();
		if((nombre.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			n.setPaciente(it->getPaciente());
			n.setFechayHora(it->getFechayHora());
			n.setDescripcion(it->getDescripcion());
			c->erase(it);
			N++;
		}
	}

	//Si el Valor de N no ha variado==No existe la cita del paciente
	if(N==0)
	{
		return false;
	}
	temp=n.getPaciente();
	fyh=n.getFechayHora();
	cout<<"\nNombre: "<<temp.getNombre()<<"\n";
			cout<<"Apellidos: "<<temp.getApellidos()<<"\n";
			cout<<"Telefono: "<<temp.getTelefono()<<"\n";
			cout<<"Fecha: "<<fyh.tm_mday<<"/"<<fyh.tm_mon<<"/"<<fyh.tm_year<<" a las "<<fyh.tm_hour<<":"<<fyh.tm_min<<"\n";
			cout<<"Descripcion:\n";
			cout<<"  ·"<<n.getDescripcion()<<"\n\n";

	//Si N es distinto de 0==Hay una cita del paciente
	do
	{
		cout<<"\nIndique que parametro de la cita desea modificar: 1.Telefono/2.Fecha/3.Descripcion/4.Nada\n";
		cin>>N;
		switch(N)
		{
			case 1:
			{
				cout<<"Introduza el telefono del paciente (no mas de 9 digitos)\n";
				cin>>N;
				do
				{
					if(N>=1000000000)
					{
						cout<<"Error. Introduzca otra vez el telefono(no mas de 9 digitos)\n";
						cin>>N;
					}
				}while(N>=1000000000);
				temp.setTelefono(N);
				n.setPaciente(temp);
			}break;

			case 2:
			{
				cout<<"Indique la hora nueva del paciente\n";
				do
				{
					InsertFyH(&fyh);
				}while(Inv_date(*c,fyh)!=false);
				n.setFechayHora(fyh);
			}break;

			case 3:
			{
				cout<<"Describa la razon de la cita\n";
				cin.ignore();
				getline(cin,info);
				n.setDescripcion(info);
			}break;

			case 4:
			{
				//En caso de que se elija la opcion 4
			}break;

			default:
			{
				cout<<"La opcion elegida no esta dentro de las posibles a realizar\n";
			}break;
		}

	}while(N!=4);
	
	c->push_back(n);
	
	return true;
}

bool MostrarCita(list<Cita> c)
{
	string nombre;
	string apellidos;
	list<Cita>::iterator it;
	struct tm fyh;
	Paciente temp;

	//Pedimos el Nombre y Apellidos del paciente
	cout<<"Introduzca el nombre del paciente\n";
	cin.ignore();
	getline(cin,nombre);
	cout<<"Introduzca los apellidos del paciente\n";
	getline(cin,apellidos);

	for(it=c.begin();it!=c.end();it++)
	{
		temp=it->getPaciente();

		//Si encontramos coincidencia en Nombre y Apellidos se imprime por pantalla la cita encontrada
		if((nombre.compare(temp.getNombre())==0)&&(apellidos.compare(temp.getApellidos())==0))
		{
			fyh=it->getFechayHora();
			cout<<"\nNombre: "<<temp.getNombre()<<"\n";
			cout<<"Apellidos: "<<temp.getApellidos()<<"\n";
			cout<<"Telefono: "<<temp.getTelefono()<<"\n";
			cout<<"Fecha: "<<fyh.tm_mday<<"/"<<fyh.tm_mon<<"/"<<fyh.tm_year<<" a las "<<fyh.tm_hour<<":"<<fyh.tm_min<<"\n";
			cout<<"Descripcion:\n";
			cout<<"  ·"<<it->getDescripcion()<<"\n\n";
			return true;
		}
	}
	return false;
}

bool MostrarListaCitas(list<Cita> *c) {

	list<Cita>::iterator it;
	
    Paciente p;
    struct tm fyh;
	
	for (it=c->begin(); it!=c->end(); it++) {

        p = it->getPaciente();
        fyh = it->getFechayHora();

		cout << "Cita con   : " << p.getNombre() << " " << p.getApellidos() << "." << endl;
        cout << "El día     : " << fyh.tm_mday<<"/"<<fyh.tm_mon<<"/"<<fyh.tm_year<<" a las "<<fyh.tm_hour<<":"<<fyh.tm_min << endl;
        cout << "Teléfono   : " << p.getTelefono() << "." << endl;
        cout << "Descripcion: " << it->getDescripcion() << "." << endl;
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;

	}

	return false;
}
/*
bool ModificarHistorial(list <Historial> *h)
{
	Historial temp;
	list<Historial>::iterator ith;
	string enfermedad,mod;
	int cntr=0;

	cout<<"Se procedera a mostrar el historial del paciente\n";
	cout<<"---------Historial---------\n";
	for(ith=h->begin();ith!=h->end();ith++)
	{
		cout<<"  ·Enfermedad:"<<h->getEnfermedad()<<"\n";
		cout<<"  ·Sintomas:"<<h->getSintomas()<<"\n";
		cout<<"  ·Tratamiento:"<<h->getTratamiento()<<"\n";
		cout<<"  ·Duracion tratamiento:"<<h.getDuracionTratamiento()<<"\n";
	}
	cout<<"\nReferente a que enfermedad desea modificar el historial\n";
	cin.ignore();
	getline(cin,enfermedad);
	for(ith=h->begin();ith!=h->end();ith++)
	{
		if(enfermedad.compare(ith->getEnfermedad())==0)
		{
			temp=ith;
			h->erase(ith);
			cntr++;
		}
	}
	if(cntr==0)
	{
		cout<<"Error el paciente no tiene tal enfermedad\n";
		return false;
	}

	temp.setEnfermedad(enfermedad);
	do
	{
		cout<<"\nIndique que desea modificar: 1.Sintomas /2.Tratamiento /3.Duracion de tratamiento/4.Nada\n";
		cin>>cntr;
		switch(cntr)
		{
			case 1:
			{
				cout<<"Introduzca los nuevos sintomas\n";
				cin.ignore();
				getline(cin,mod);
				temp.setSintomas(mod);

			}break;

			case 2:
			{
				cout<<"Introduzca el nuevo tratamiento\n";
				cin.ignore();
				getline(cin,mod);
				temp.setTratamiento(mod);

			}break;

			case 3:
			{
				cout<<"Introduzca la nueva duracion del tratamiento\n";
				cin.ignore();
				getline(cin,mod);
				temp.setDuracionTratamiento(mod);

			}break;

			case 4:
			{
				//Solo para cuando se introduzca valor 4
			}break;

			default:
			{
				cout<<"La opcion elegida no esta dentro de las posibles a realizar\n";
			}
		}
	}while(cntr!=4);
	h->push_back(temp);
	return true;
}


bool buscarHistorial(Paciente * p, vector <Historial> * v) {

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


void guardarHistorial(std::list<Paciente>& pacientes) {

    std::list<Paciente>::iterator i = pacientes.begin();
	list<Paciente>::iterator j = pacientes.historial
    std::ofstream fichero;
    fichero.open ("../BD/historial.txt");
    
    for(i = pacientes.begin(); i != pacientes.end(); i++) {

		for ()

        fichero << i->getNombre()<< "|" << i->getApellidos()<< "|"<< i->getHistorial().getEnfermedad()<< "|"<<i->getHistorial().getTratamiento()<< "|"<< i->getFechaNacimiento()<<"|"<< i->getTelefono()<<"\n";

    }
    
    fichero.close();
}


void verHistorial() {

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
*/
void InsertFyH(struct tm *FH)
{
	int cntr=0;

	cout<<"Introduzca el Año,Mes,Dia de la cita,en numero\n";
	cout<<"Año: ";
	cin>>FH->tm_year;
	//Mes
	do
	{
		cout<<"Mes: ";
		cin>>FH->tm_mon;
		if((FH->tm_mon<=0)||(FH->tm_mon>=13))
		{
			cntr++;
			cout<<"\nParametro fuera de intervalo permitido [0-12]\n";
			cout<<"Vuelva a dar el dato pedido\n";
		}else
		{
			cntr=0;
		}
	}while(cntr!=0);
	//Dia
	do
	{
		cout<<"Dia: ";
		cin>>FH->tm_mday;
		if((FH->tm_mday<=0)||(FH->tm_mday>=32))
		{
			cntr++;
			cout<<"\nParametro fuera de intervalo permitido [0-31]\n";
			cout<<"Vuelva a dar el dato pedido\n";
		}else
		{
			cntr=0;
		}
	}while(cntr!=0);

	cout<<"\nIntroduzca la hora y minuto de la cita\n";
	do
	{
		cout<<"Hora: ";
		cin>>FH->tm_hour;
		if((FH->tm_hour<=-1)||(FH->tm_hour>=24))
		{
			cntr++;
			cout<<"\nParametro fuera de intervalo permitido [0-23]\n";
			cout<<"Vuelva a dar el dato pedido\n";
		}else
		{
			cntr=0;
		}
	}while(cntr!=0);

	do
	{
		cout<<"Minuto: ";
		cin>>FH->tm_min;
		if((FH->tm_min<=-1)||(FH->tm_min>=60))
		{
			cntr++;
			cout<<"\nParametro fuera de intervalo permitido [0-59]\n";
			cout<<"Vuelva a dar el dato pedido\n";
		}else
		{
			cntr=0;
		}
	}while(cntr!=0);
}

bool Inv_date(list<Cita> c,struct tm FH)
{
	struct tm temp;
	list<Cita>::iterator it;

	for(it=c.begin();it!=c.end();it++)
	{
		temp=it->getFechayHora();
		if(FH.tm_year==temp.tm_year)
		{
			if(FH.tm_mon==temp.tm_mon)
			{
				if(FH.tm_mday==temp.tm_mday)
				{
					if(FH.tm_hour==temp.tm_hour)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void VolcarDatos(list<Cita> c)
{
	Paciente temp;
	list<Cita>::iterator it;
	struct tm FH;

	ofstream fichero;
	fichero.open("../BD/citas.txt");
	if(fichero.is_open())
	{
		for(it=c.begin();it!=c.end();it++)
		{
			temp=it->getPaciente();
			FH=it->getFechayHora();
			fichero<<temp.getNombre()<<"|"<<temp.getApellidos()<<"|"<<temp.getTelefono()<<"|";
			fichero<<FH.tm_mday<<"/"<<FH.tm_mon<<"/"<<FH.tm_year<<"|"<<FH.tm_hour<<":"<<FH.tm_min<<"|";
			fichero<<it->getDescripcion()<<"\n";
		}
	}
}

bool operator==(const Paciente& p1, const Paciente& p2){
    return p1.getNombre() == p2.getNombre() && p1.getApellidos() == p2.getApellidos();
}

void guardarPacientes(std::list<Paciente>& pacientes) {
    
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
//    std::list<Historial> historial;
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
/*    std::cout<<BYELLOW<<"Tiene el paciente alguna enfermedad? Si es así, introduzca 1. Si no ,0."<<RESET<<std::endl;
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
*/
    Paciente paciente(nombre, apellido, edad, domicilio, fechanacimiento, numerotelefono);
//    paciente.setHistorial(historial);
//    cout<<"COMO PRUEBA, LOS SINTOMAS SON: "<<paciente.getHistorial().front().getSintomas()<<std::endl;
    if(!existePaciente(paciente, pacientes)){
        pacientes.push_back(paciente);

        //std::cout<<"FLAG IMPORTANTE"<<std::endl;
        return true;
    }
    else{
        std::cout<<"Este paciente ya existe en la base de datos"<<std::endl;
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


void cargarPacientes(std::list<Paciente>& pacientes) {

    std::ifstream fichero;

    int entero, telefono, edad;
    string nombre, apellidos, fechanacimiento, domicilio, linea;

    fichero.open ("../BD/pacientes.txt");
    fichero.seekg (0, ios::beg);

    Paciente p;

    while(getline(fichero, nombre, '|')) {
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