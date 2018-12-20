# Modificar alumno

**ID:** 002

**Breve descripción:** El sistema permite la modificación de los datos de un alumno.

**Actores principales:** Profesor Coordinador o Ayudante.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno de existir en la base de datos.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor quiere modificar los datos de un alumno.
2. El sistema pedirá que el profesor introduzca el apellido del alumno a modificar, en caso de haber alumnos con el mismo apellido el sistema solicitara el DNI al profesor que deberá introducirlo.
3. Una vez se tenga el alumno a modificar el sistema preguntará que dato se modificará y una vez hecho el sistema solicitará la modificación del dato al usuario que deberá introducirla.

**Postcondiciones:**

* El sistema machaca los datos a modificar por los datos nuevos.

**Flujos alternativos:**

2.a. Si el alumno no existe, el sistema muestra un mensaje de error.

3.a. Si el dato a modificar es liderazgo de grupo, se preguntará, en caso de eliminar liderazgo, que alumno se hace líder del grupo.
