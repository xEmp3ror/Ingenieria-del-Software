## Modificar cita

**ID**: 07
**Descripción**: El sistema modifica la cita del paciente deseado.

**Actores principales**: Usuario
**Actores secundarios**: Paciente

**Precondiciones**:
* Debe existir la cita del paciente que se desea modificar

**Flujo principal**:
1. El usuario desea modificar una cita para un paciente.
1. El usuario inicia el programa y solicita modificar una cita
1. El usuario introduce el nombre y apellidos del paciente que busca modificar la cita.
1. El usuario modifica los datos deseados de la cita del paciente.
1. El sistema confirma la creacion de la cita y la muestra por pantalla.

**Postcondiciones**:

* Se confirma la cita modificada y se la muestra al usuario.

**Flujos alternativos**:

7.a. Si la cita a modificar no existe, el sistema muestra un mensaje de error
