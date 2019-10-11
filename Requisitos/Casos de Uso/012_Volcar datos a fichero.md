## Volcar datos a fichero.

**ID**: 012.

**Descripción**: Volcado de datos desde la memoria principal al archivo de la base de datos.

**Actores principales**: Usuario.

**Actores secundarios**: _No hay._

**Precondiciones**:

- Debe haberse realizado al menos un (1) cambio.
- Debe existir la base de datos.

**Flujo principal**:

1. El sistema lee todo lo que se ha cambiado.
2. El sistema vuelca todo en el archivo de la base de datos.
3. Los guarda.

**Postcondiciones**:

- Los datos serán volcados en el archivo.

**Flujos alternativos**:

002.a. No existe el archivo o está dañado.
