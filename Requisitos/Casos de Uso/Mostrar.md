# Mostrar alumno

**ID:** 004
 
**Breve descripción:** El sistema muestra los datos de un alumno, de todos los alumnos o de los alumnos de un grupo.

**Actores principales:** Profesor.
 
**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno debe estar en la base de datos.

**Flujo principal:**
	
1. El caso de uso empieza cuando el profesor quiera ver los datos de un alumno, de todos los alumnos o de los alumnos de un grupo.
2. El sistema mostrara un menú en el que muestra las opciones de muestra mostrar datos de un alumno, todos los alumnos o de los alumnos de un grupo.
3. El sistema muestra otro menú en el que el profesor selecciona si se muestra por DNI, por apellido, curso más alto matriculado y si se muestra por ordenación ascendente o descendente.

**Postcondiciones:**
	
* El sistema muestra los datos de lo solicitado alfabéticamente y mostrara si el alumno es líder de algún grupo.

**Flujos alternativos:**
	
1.a. Si el profesor selecciona mostrar datos de un alumno, el sistema pedirá el apellido del alumno, en caso de haber múltiples alumnos con el mismo apellido el sistema pedirá el DNI. 

1.b. Si el alumno no existe en la base de datos, el sistema muestra un mensaje de error.

2.a. Si el profesor selecciona mostrar datos de todos los alumnos, el sistema muestra la información de todos los datos.

2.b. Si no hay alumnos en la base de datos, el sistema muestra un mensaje de error.

3.a. Si el profesor selecciona mostrar los datos de los alumnos de un grupo, el sistema pedirá el número del grupo.

3.b. Si el número del grupo introducido no existe, el sistema muestra un mensaje de error.

3.c. Si no hay alumnos en el grupo, el sistema muestra un mensaje de error.
