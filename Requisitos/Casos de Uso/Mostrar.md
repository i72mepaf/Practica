# **Mostrar alumno**

 **ID:** 004
 
 **Breve descripción:** El sistema muestra los datos de un alumno, de todos los alumnos o de los alumnos de un grupo.

 **Actores principales:** Profesor
 
 **Actores secundarios:** Alumnos

 **Precondiciones**

	### 1.El alumno debe estar en la base de datos

 **Flujo principal:**
	
	### 1. El caso de uso empieza cuando el profesor quiera ver los datos de un alumno, de todos los alumnos o de los alumnos de un grupo.

	### 2. El sistema mostrara un menu en el que muestra las opciones de muestra mostrar datos de un alumno, todos los alumnos o de los alumnos de un grupo.

	### 3. El sistema muestra otro menu en el que el profesor selecciona si se muestra por DNI, por apellido, curso mas alto matriculado y si se muestra por ordenacion ascendente o descendente.

 **Postcondiciones:**
	
	### El sistema muestra los datos de lo solicitado alfabeticamente y mostrara si el alumno es lider de algun grupo.


 **Flujo alternativos:**
	
	1a. Si el profesor selecciona mostrar datos de un alumno, el sistema pedira el apellido del alumno, en caso de haber multiples alumnos con el mismo apellido el sistema pedira el DNI. 

	1b. Si el alumno no existe en la base de datos, el sistema muestra un mensaje de error.

	2a. Si el profesor selecciona mostrar datos de todos los alumnos, el sistema muestra la informacion de todos los datos

	2b. Si no hay alumnos en la base de datos, el sistema muestra un mensaje de error.

	3a. Si el profesor selecciona mostrar los datos de los alumnos de un grupo, el sistema pedira el numero del grupo.

	3b. Si el numero del grupo introducido no existe, el sistema muestra un mensaje de error.

	3c. Si no hay alumnos en el grupo, el sistema muestra un mensaje de error.
