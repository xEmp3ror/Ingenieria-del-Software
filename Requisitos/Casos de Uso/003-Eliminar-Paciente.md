## Buscar usuario por nombre y apellidos

**ID**: 003
**Descripción**: Se borran los datos relativos a un paciente.
**Actores principales**: Administrador
**Actores secundarios**: Paciente

**Precondiciones**:
* El paciente debe existir en la base de datos.

**Flujo principal**:
1. El administrador desea borrar los datos de un paciente
1. El administrador selecciona la opción de borrar paciente en el menú principal
1. El sistema pide permisos para borrar los datos al administrador
1. El sistema actualiza la base de datos borrando al paciente. 

**Postcondiciones**:

* El paciente no existe en la base de datos.

**Flujos alternativos**:

4.a. Si el paciente no existe, se muestra un mensaje de error.
