## Crear cita

**ID**: 06
**Descripción**: El sistema creara una cita para un paciente

**Actores principales**: Usuario
**Actores secundarios**: Paciente

**Precondiciones**:
* No exista una cita del mismo paciente.

**Flujo principal**:
1. El usuario desea crear una cita para un paciente.
1. El usuario inicia el programa y solicita crear una cita.
1. El usuario introduce todos los datos del paciente.
1. El sistema confirma la creacion de la cita.

**Postcondiciones**:

* Se confirma la cita creada y se la muestra al usuario

**Flujos alternativos**:

6.a. Si los datos no se introducen correctamente, el sistema muestra un mensaje de error
6.b. Si la cita creada coincide en hora y dia con otra el sistema pedira que introduzcas otro dia y hora
