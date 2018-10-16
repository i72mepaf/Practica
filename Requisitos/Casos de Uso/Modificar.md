# **Modificar alumno**

 **ID:** 002
 
 **Breve descripción:** El sistema permite la modificacion de los datos de un alumno 

 **Actores principales:** Profesor

 **Actores secundarios:** Alumnos

 **Precondiciones**

	 1.El alumno de existir en la base de datos

 **Flujo principal:**
	
	 1. El caso de uso empieza cuando el profesor quiera modificar los datos del un alumno.

	 2. El sistema pedira que el profesor introduzca el apellido del alumno a modificar, en caso de haber alumnos con el mismo apellido el sistema solicitara el DNI al profesor que debera introducirlo.

	 3. Una vez se tenga el alummno a modificar el sistema preguntara que dato se modificara y una vez hecho el sistema solicitara la modificacion del dato al usuario que debera introducirla

 **Postcondiciones:**
	
	 El sistema machaca los datos a modificar por los datos nuevos


 **Flujo alternativos:**
	Si el alumno no existe, el sistema muestra un mensaje de error.


