# Borrar Alumno

**ID:** 005

**Breve Descripción:** El programa borra un alumno de la base de datos.

**Actores principales:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:** 

1. El alumno debe existir.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor quiere borrar los datos de un alumno de la base de datos.
2. El profesor introduce el DNI o los apellidos del alumno a borrar.
3. El sistema busca a ese alumno. 

**Postcondiciones:**

* Si se encuentra al alumno, lo borra de la base de datos.

**Flujos alternativos:**

2.a. Si al introducir los apellidos hay varios alumnos con los mismos apellidos, se requerirá buscar por DNI.
3.a. Si no existe el alumno se muestra un mensaje de error.