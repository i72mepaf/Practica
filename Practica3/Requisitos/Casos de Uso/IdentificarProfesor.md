# Identificar Profesor Coordinador o Ayudante

**ID:** 009

**Breve descripción:** El sistema identifica como coordinador o ayudante al profesor gracias a unas credenciales de un fichero binario.

**Actores principales:** Profesor.

**Actores secundarios:** No existen actores secundarios en este caso.

**Precondiciones:**

1. Si el archivo de credenciales está vacío, el sistema no tendrá nigun profesor coordinador o ayudante registrado.
2. Como máximo, solo habrá un profesor coordinador en el sistema.
3. El número máximo de profesores ayudantes en el sistema será de 5.

**Flujo principal:**

1. El caso de uso empieza cuando el sistema necesita identificar al profesor.
2. El sistema pregunta al profesor si es profesor coordinador o ayudante.
3. El sistema pedirá.

**Postcondiciones:**

* El fichero binario tiene todos los datos de los alumnos de la base de datos en ese instante al ser guardado.

**Flujos alternativos:**

2.a. Si el fichero binario ya existe, el sistema preguntará al profesor si quiere sobrescribirlo o no.
