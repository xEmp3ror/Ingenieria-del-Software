program: main.o
	g++ -o program main.o funciones.o macros.o paciente.o

main.o: main.cpp
	g++ -c main.cpp

funciones.o: funciones.cpp funciones.hpp macros.hpp
	g++ -c funciones.cpp

paciente.o: paciente.cpp paciente.hpp
	g++ -c paciente.cpp


clean:
	rm -rf *.o
	