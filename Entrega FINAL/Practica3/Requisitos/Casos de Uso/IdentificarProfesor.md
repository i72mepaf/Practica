# Identificar Profesor Coordinador o Ayudante

**ID:** 009

**Breve descripción:** El sistema identifica como coordinador o ayudante al profesor gracias a unas credenciales de un fichero binario.

**Actores principales:** Profesor.

**Actores secundarios:** No existen actores secundarios en este caso.

**Precondiciones:**

1. Si el archivo de credenciales está vacío, el sistema no tendrá ningún profesor coordinador o ayudante registrado.
2. Como máximo, en el archivo de credenciales solo habrá un profesor coordinador.
3. El número máximo de profesores ayudantes en el archivo de credenciales será de 5.

**Flujo principal:**

1. El caso de uso empieza cuando el sistema necesita identificar al profesor al iniciar.
2. El sistema pregunta si quiere identificarse o registrarse.
3. El sistema pregunta al profesor si es profesor coordinador o ayudante.
4. El sistema pedirá el DNI del profesor.
5. El sistema identificará/registrará al profesor con/en el archivo de credenciales.

**Postcondiciones:**

* Al identificarse como profesor coordinador tendrá acceso a todas las tareas del sistema.
* Al identificarse como profesor ayudante tendrá accesos a todas las tareas del sistema excepto aquellas tareas que trabajan con las copias de seguridad, las cuales son Guardar/Cargar la base de datos de los alumnos en/de un fichero binario.

**Flujos alternativos:**

1.a. Si el archivo de credenciales está vacío, el sistema obligará al profesor registrarse.

1.b. El sistema volverá al punto 3 del flujo principal.

---

2.a Si se elige la acción de identificarse el sistema saltará al punto 4.

---

3.a. Si al marcar una de las dos opciones, el archivo de credenciales está lleno en la elección, es decir, un profesor coordinador o 5 profesores ayudantes, saltará un mensaje diciendo que el archivo de credenciales respecto a ese tipo de profesor está lleno.

3.b. El sistema volverá al punto 2 del flujo principal.

---

4.a. A la hora de registrarse, si el DNI introducido ya existe, saltará un mensaje de error diciendo que el DNI ya existe en el archivo de credenciales.

4.b. El sistema volverá al punto 2 del flujo principal.
