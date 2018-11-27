# Buscar Alumno

**ID:** 003

**Breve descripción:** El sistema buscará un alumno en la base de datos.

**Actores principales:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno debe existir

**Flujo principal:**

1. El caso de uso empieza cuando el sistema quiere buscar un alumno de la base de datos.
2. El sistema pide al profesor introducir los apellidos del alumno a buscar.
3. El sistema busca a ese alumno y muestra sus datos por pantalla.

**Postcondiciones:**

* Si se encuentra el alumno lo muestra por pantalla.

**Flujos alternativos:**

2.a. Si al introducir los apellidos hay varios alumnos con los mismos se requerirá buscar por DNI.

2.a.1. Si el DNI introducido no está en la base de datos se muestra un mensaje de error.

3.a. Si no existe el alumno se muestra un mensaje de error.
