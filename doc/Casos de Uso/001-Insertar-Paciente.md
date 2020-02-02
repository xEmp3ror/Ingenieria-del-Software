## Insertar Paciente

**ID**: 001
**Descripción**: Se introducen los datos de un paciente en memoria local.

**Actores principales**: Administrador
**Actores secundarios**: Paciente

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El administrador desea insertar los datos de un paciente
1. El administrador selecciona la opción de inserción de un paciente en el menú principal
1. El administrador introduce el nombre, apellidos, dirección, fecha de nacimiento, teléfono y tipo de cliente.
1. El sistema ejecuta la función de guardar datos (volcar los datos modificados de memoria principal a la base de datos).

**Postcondiciones**:

* El paciente insertado debe existir en la base de datos.

**Flujos alternativos**:

4.a. Si el paciente ya existe, se muestra un mensaje de error.
