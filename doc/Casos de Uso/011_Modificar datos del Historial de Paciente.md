## Modificar datos del Historial de Paciente.

**ID**: 011.

**Descripción**: Permite al usuario modificar los datos del historial médico del paciente.

**Actores principales**: Usuario.

**Actores secundarios**: Paciente.

**Precondiciones**:

- El paciente debe existir en la base de datos.

**Flujo principal**:

1. El usuario especifica sobre qué paciente quiere añadir datos al historial.
2. El sistema busca dicho paciente en el historial.
3. El sistema muestra por pantalla los resultados de la búsqueda.
4. El usuario confirma sobre qué paciente quiere realizar la modificación.
5. El sistema le pregunta qué quiere modificar.
6. El usuario realiza las modificaciones pertinentes.
7. El sistema guarda los datos.

**Postcondiciones**:

- Los datos quedarán modificados.

**Flujos alternativos**:

002.a. Si no se encuentra el paciente, se muestra una advertencia.
006.a. Si las modificaciones no se corresponden con lo que se quería modificar, se muestra un error.
