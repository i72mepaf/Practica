# Modificar alumno

**ID:** 002

**Breve descripción:** El sistema permite la modificación de los datos de un alumno.

**Actores principales:** Profesor Coordinador o Ayudante.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El alumno debe existir en la base de datos.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor quiere modificar los datos de un alumno.
2. El sistema pedirá que el profesor introduzca el DNI del alumno a modificar.
3. Una vez se encuentre al alumno a modificar el sistema mostrará un mensaje que dice que seleccione un atributo a modificar o seleccione la opción salir, y mostrará un menú con todos los atributos del alumno y la opcion salir.
4. Al seleccionar la opción de salir, el sistema se sale y no modifica nada.

**Postcondiciones:**

* El sistema machaca los datos a modificar por los datos nuevos.

**Flujos alternativos:**

2.a. Si el alumno no existe, el sistema muestra un mensaje de error.

4.a. Al seleccionar la opción de cualquier atributo, el sistema pedirá el valor nuevo del atributo seleccionado.

4.b. El valor del alumno será modificado en la base de datos.

4.c. El flujo vuelve al punto 3 del flujo principal.

4.a.a. Al no seleccionar ninguna opción, el sistema muestrá un mensaje de error.

4.a.b. El flujo vuelve al punto 3 del flujo principal.

4.b.a. Si el valor pasado no es compatible (Ej.: Dia de Nacimiento del Alumno: 34 de Diciembre), el sistema vuelve a pedir el valor hasta que sea compatible.

4.b.b. El flujo vuelve al punto 4.b. del flujo alternativo.
