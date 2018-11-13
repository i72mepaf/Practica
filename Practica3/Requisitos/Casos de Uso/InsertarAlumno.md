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
2. El sistema pedirá los datos obligatorios al profesor.
3. El sistema pedirá los datos opcionales al profesor.
4. El sistema mostrará un mensaje diciendo que el alumno ha sido introducido correctamente.

**Postcondiciones:**

* Si no existe el alumno se inserta en la base de datos.
* Los datos opcionales al no ser introducidos se les asignará los valores por defecto (Nº equipo: 0 y Lider: No)

**Flujos alternativos:**

2.a. Si el DNI o el e-mail introducidos son iguales a otro ya en la base de datos, se da la opción de volver a introducir el dato o de parar de introducir el alumno y no introducir nada.

4.a. En caso de haber un error, se mostrará un mensaje diciendo que no se ha introducido correctamente.
