# Borrar a todos los alumnos de la base de datos

**ID:** 006

**Breve descripción:** El sistema permite borrar a todos los alumnos de la base de datos.

**Actores principales:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones**

1. Debe de haber alumnos en la base de datos.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor quiera borrar a todos los alumnos de la base de datos.
2. El sistema muestra un menu con dos opciones (sí o no) y me pregunta si estoy seguro de ello.
3. Al seleccionar la opción de sí, el sistema borra a todos los alumnos de la base de datos.

**Postcondiciones:**

* La base de datos de los alumnos queda vacía.

**Flujos alternativos:**

3.a. Si no hay alumnos en la base de datos, el sistema mostrara un mensaje diciendo que la base de alumnos está vacia.

3.1.a. Al seleccionar la opción de no, el sistema no hace nada.
