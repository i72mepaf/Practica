# Cargar datos de un fichero binario

**ID:** 007

**Breve descripción:** El sistema carga los datos de los alumnos de un fichero binario.

**Actores principales:** Profesor.

**Actores secundarios:** Alumnos.

**Precondiciones:**

1. El fichero a cargar tiene que ser binario.
2. El fichero binario puede tener como máximo 150 alumnos.
3. El fichero binario a cargar debe existir en el sistema.

**Flujo principal:**

1. El caso de uso empieza cuando el profesor necesita cargar los datos de los alumnos de un fichero binario.
2. El sistema pregunta al profesor el nombre del fichero binario a cargar.
3. El sistema carga los datos del fichero binario en el sistema.

**Postcondiciones:**

* Una vez cargado el fichero, el sistema tiene la base de datos de los alumnos del fichero binario cargado.

**Flujos alternativos:**

2.a. Si el fichero binario a cargar no existe, muestra un mensaje de error.
2.b. El sistema preguntará si quiere volver a buscar con otro nombre el fichero binario a cargar.
