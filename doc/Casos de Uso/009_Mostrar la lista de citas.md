## Mostrar la lista de citas.

**ID**: 009

**Descripción**: Muestra la lista de citas que tiene el profesional en la semana pedida.

**Actores principales**: Usuario.

**Actores secundarios**: Paciente.

**Precondiciones**:

- Debe haber como mínimo una (1) cita en la base de datos.

**Flujo principal**:

1. El sistema solicita la semana sobre la que se quiere hacer la consulta.
2. El usuario introduce el número del día que corresponde al lunes de esa semana.
3. El sistema busca y recopila todas las citas de la semana pedida.
4. El sistema muestra las citas por pantalla en orden cronológico.

**Postcondiciones**:

- El sistema muestra las citas correspondientes a esa semana ordenadas cronológicamente y en una línea por cada cita.

**Flujos alternativos**:

- 3.a. Si no hay ninguna cita ese día, se muestra una advertencia sobre ello.
