## Añadir datos al historial de Paciente.

**ID**: 010.

**Descripción**: Permite añadir datos adicionales al historial médico del paciente.

**Actores principales**: Usuario.

**Actores secundarios**: Paciente.

**Precondiciones**:

- El paciente debe existir en la base de datos.

**Flujo principal**:

1. El usuario especifica sobre qué paciente quiere añadir datos al historial.
2. El sistema busca dicho paciente en el historial.
3. El sistema muestra por pantalla los resultados de la búsqueda.
4. El usuario confirma sobre qué paciente quiere realizar la adición.
5. El sistema le pregunta qué quiere añadir.
6. El usuario realiza las adiciones pertinentes.
7. El sistema guarda los datos.

**Postcondiciones**:

- La Postcondición que sea necesaria.

**Flujos alternativos**:

- 2.a. El paciente no se encuentra.
