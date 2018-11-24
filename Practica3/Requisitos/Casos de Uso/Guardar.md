# Guardar datos en un fichero binario

**ID:** 008

**Breve descripción:** El sistema guarda la base de datos de los alumnos en un fichero binario.

**Actores principales:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. Si la base de datos está vacía, el archivo binario donde se guardarán los datos quedará vacío.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor necesita guardar los datos de los alumnos en un fichero binario.
2. El sistema pregunta al profesor el nombre del fichero binario a crear para guardar los datos.
3. El sistema crea el fichero y guarda la base de datos de los alumnos.

**Postcondiciones:**

* El fichero binario tiene todos los datos de los alumnos de la base de datos en ese instante al ser guardado.

**Flujos alternativos:**

2.a. Si el fichero binario ya existe, el sistema preguntará al profesor si quiere sobrescribirlo o no.
