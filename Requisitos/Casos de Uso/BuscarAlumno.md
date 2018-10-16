# **Buscar Alumno**

**ID** : 003

**Breve Descripción :** El programa buscara un alumno en la base de datos


**Actores principales :** Profesor

**Actores secundarios :** Alumno

**Precondiciones :** 

	1. El alumno debe existir


**Flujo principal :**

	1.El caso de uso empieza cuando el profesor quiere buscar un alumno de la base de datos

	2.El profesor introduce el dni o los apellidos del alumno a buscar

	3.El sistema busca a ese alumno

**Postcondiciones :**

	1.Si se encuentra el alumno lo muestra por pantalla


**Flujos alternativos :**

	2.a. Si al introducir los apellidos hay varios alumnos con los mismos se requerira buscar por dni

	3.a. Si no existe el alumno se muestra un mensaje de error
