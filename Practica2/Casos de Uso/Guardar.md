# Guardar datos en un fichero binario preestablecido

**ID:** 008

**Breve descripción:** El sistema guarda la base de datos de los alumnos en un fichero binario preestablecido.

**Actores principales:** Profesor Coordinador o Ayudante.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Si la base de datos está vacía, el archivo binario donde se guardarán los datos quedará vacío.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor necesita guardar los datos de los alumnos en un fichero binario.
3. El sistema crea/sobrescribe el fichero preestablecido y guarda la base de datos de los alumnos.

**Postcondiciones:**

* El fichero binario tiene todos los datos de los alumnos de la base de datos en ese instante al ser guardado.

**Flujos alternativos:**

2.a. Si hay un error a la hora de crearse/sobrescribirse el fichero, se muestra un mensaje de error.
