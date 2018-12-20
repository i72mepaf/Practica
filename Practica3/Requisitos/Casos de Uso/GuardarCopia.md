# Guardar datos en una copia de seguridad binaria

**ID:** 011

**Breve descripción:** El sistema guarda la base de datos de los alumnos en una copia de seguridad.

**Actores principales:** Profesor Coordinador.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Si la base de datos está vacía, el archivo binario donde se guardarán los datos quedará vacío.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor necesita guardar los datos de los alumnos en un fichero binario.
2. El sistema pregunta al profesor el nombre del fichero binario a crear/sobrescribir para guardar los datos.
3. El sistema crea/sobrescribe el fichero y guarda la base de datos de los alumnos.

**Postcondiciones:**

* El fichero binario tiene todos los datos de los alumnos de la base de datos en ese instante al ser guardado.

**Flujos alternativos:**

2.a. Si el nombre introducido no es valido, se volverá a pedir por teclado el nombre del fichero binario a guardar.


3.a. Si hay un error a la hora de crearse/sobrescribirse el fichero, se muestra un mensaje de error.
