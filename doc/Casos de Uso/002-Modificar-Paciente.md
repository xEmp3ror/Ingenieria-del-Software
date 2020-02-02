## Buscar usuario por nombre y apellidos

**ID**: 002
**Descripción**: Se modifica alguno de los datos del paciente.

**Actores principales**: Administrador
**Actores secundarios**: Paciente

**Precondiciones**:
* Debe existir el paciente cuyos datos se van a modificar.

**Flujo principal**:
1. El administrador desea modificar los datos de un paciente
1. El administrador selecciona la opción de modificar paciente en el menú principal
1. El administrador selecciona el campo o campos que quiere modificar.
1. El sistema pide permisos para la modificación.
1. El administrador modifica dichos campos.
1. El sistema actualiza los datos modificados en la base de datos.

**Postcondiciones**:

* Los datos modificados están actualizados en la base de datos.

**Flujos alternativos**:

4.a. Si el paciente no existe, se da la opción de insertarlo.
