# Mostrar alumno

**ID:** 004
 
**Breve descripción:** El sistema muestra los datos de un alumno, de todos los alumnos o de los alumnos de un grupo.

**Actores principales:** Profesor.
 
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno a buscar, en el caso de elegir un solo alumno debe estar en la base de datos.

**Flujo principal:**
	
1. El caso de uso empieza cuando el profesor quiera ver los datos de un alumno o de todos los alumnos.
2. El sistema mostrara un menú en el que muestra las opciones de muestra mostrar datos de un alumno o todos los alumnos.
3. En el caso de elegir mostrar todos los alumnos, el sistema muestra otro menú en el que el profesor selecciona si se muestra por curso más alto matriculado o por apellido y si se muestra por ordenación ascendente o descendente.
4. El sistema muestra los datos de los alumnos de la forma elegida.

**Postcondiciones:**
	
* Si no hay ningún alumno, no mostrará nada.

**Flujos alternativos:**
	
2.a. Si el profesor selecciona mostrar datos de un alumno, el sistema pedirá buscar por el apellido o por el DNI del alumno.

2.b. Si ha seleccionado la opcion por apellido, el sistema pedirá al profesor el apellido del alumno.

2.c. Si el alumno ha sido encontrado, se muestran sus datos por pantalla.

2.c.1.a. Si existen varios alumnos con el mismo apellido se muestra un mensaje de error.

2.c.2.a. Si no existe ningun alumno con el apellido introducido, se muestra un mensaje de error.

2.b.a. Si ha seleccionado la opcion por DNI, el sistema pedirá al profesor el DNI del alumno.

2.b.b. Si el alumno ha sido encontrado, se muestran sus datos por pantalla.

2.b.b.a. Si no existe ningun alumno con el DNI introducido, se muestra un mensaje de error.