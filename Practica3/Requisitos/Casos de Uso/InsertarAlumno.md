# Insertar Alumno

**ID:** 001

**Breve Descripción:** El profesor introducirá, en la base de datos, los datos de un alumno.

**Actores principales:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno no debe existir.
2. Los datos obligatorios a introducir son: DNI, Nombre, Apellidos, Tlf., e-mail corporativo(UCO), dirección postal, curso más alto en el que está matriculado y Fecha de Nacimiento.
3. Los datos opcionales a introducir son: Número del equipo que pertenece y si es Lider del grupo o no.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor quiere introducir un alumno a la base de datos.

2. El sistema recibe los datos del alumno por teclado.

**Postcondiciones:**

* Si no existe el alumno se inserta en la base de datos.

**Flujos alternativos:**

2.a. Si existe el alumno se muestra un mensaje de error.
