# Identificar Profesor Coordinador o Ayudante

**ID:** 009

**Breve descripción:** El sistema identifica como coordinador o ayudante al profesor gracias a unas credenciales de un fichero binario.

**Actores principales:** Usuario No Identificado.

**Actores secundarios:** No existen actores secundarios en este caso.

**Precondiciones:**

1. El archivo de credenciales tiene que existir.
2. Como máximo, en el archivo de credenciales solo habrá un profesor coordinador.
3. El número máximo de profesores ayudantes en el archivo de credenciales será de 5.

**Flujo principal:**

1. El caso de uso empieza cuando el sistema necesita identificar al profesor al iniciar.
2. El sistema pregunta al usuario no identificado si es profesor Coordinador o Ayudante.
3. En el caso de seleccionar Coordinador, el sistema pedirá el DNI del profesor coordinador.
4. El sistema comprueba si el DNI introducido coincide con el DNI del profesor Coordinador del archivo de credenciales.
5. Si los DNIs coinciden, el sistema mostrará un menú con 4 opciones: Iniciar, Cambiar DNI, Eliminar Profesor Ayudante y Mostrar todos los Profesores Registrados.
6. En el caso de seleccionar Iniciar, el sistema inicia el programa con las funcionalidades de profesor Coordinador.

**Postcondiciones:**

* Al identificarse como profesor coordinador tendrá acceso a todas las tareas del sistema.
* Al identificarse como profesor ayudante tendrá accesos a todas las tareas del sistema excepto aquellas tareas que trabajan con las copias de seguridad, las cuales son Guardar/Cargar la base de datos de los alumnos en/de una copia de seguridad binaria.

**Flujos alternativos:**

1.a. Si el archivo de credenciales no existe, el sistema muestra un mensaje diciendo que el archivo de credenciales no existe.

---

2.a. En el caso de seleccionar Ayudante, el sistema mostrará un menú con dos opciones: Registrarse o Identificarse.

2.b. En el caso de seleccionar Registrarse, el sistema pedirá el DNI a registrar como profesor Ayudante.

2.c. El sistema guarda el DNI en el archivo de credenciales como profesor Ayudante.

2.b. El sistema inicia el programa con las funcionalidades de profesor Ayudante.

---

    2.b.1.a. En el caso de no seleccionar ninguna opción, el sistema muestra un mensaje de error diciendo que se ha elegido una opción incorrecta.

    2.b.1.b. El flujo vuelve al punto 2 del flujo principal.

---

    2.b.2.a. En el caso de seleccionar Registrarse y existir 5 profesores ayudantes en el archivo de credenciales, el sistema muestra un mensaje diciendo que ya hay 5 profesores ayudantes registrados.

    2.b.2.b. El flujo vuelve al punto 2 del flujo principal.

---

    2.b.3.a. En el caso de seleccionar Identificarse, el sistema pedirá el DNI para identificarlo.

    2.b.3.b. El sistema comprueba si el DNI introducido coincide con alguno de los profesores ayudantes del archivo de credenciales.

    2.b.3.c. En el caso de coincidir, el sistema inicia el programa con las funcionalidades de profesor Ayudante.
---
        2.b.3.c.a. En el caso de no coincidir, el sistema muestra un mensaje diciendo que no se ha podido identificar.

        2.b.3.c.b. El flujo vuelve al punto 2 del flujo principal.
---

3.a. En el caso de no seleccionar ninguna opción, el sistema muestra un mensaje de error diciendo que se ha elegido una opción incorrecta.

3.b. El flujo vuelve al punto 2 del flujo principal.

---

5.a. Si el DNI introducido no concuerda con el del profesor Coordinador de las credenciales, el sistema muestra un mensaje de error diciendo que no se ha podido identificar correctamente.

5.b. El flujo vuelve al punto 2 del flujo principal.

---

    6.a.1.a. En el caso de seleccionar Cambiar DNI, el sistema pedirá al profesor el nuevo DNI que desea.

    6.a.1.b. El sistema comprueba que el DNI introducido no coincide con alguno de los profesores ayudantes de las credenciales.

    6.a.1.c. Si no coincide, el sistema cambia el DNI del profesor coordinador por el DNI insertado en las credenciales.

    6.a.1.d. El sistema muestrá un mensaje diciendo que el cambio se ha realizado correctamente.

    6.a.1.e. El flujo vuelve al punto 5 del flujo principal.

---

      6.a.1.c.a. Si coincide con alguno, el sistema muestra un mensaje de error diciendo que el DNI introducido coincide con el DNI de un profesor ayudante.

      6.a.1.c.b. El flujo vuelve al punto 5 del flujo principal.

---

    6.a.2.a. En el caso de seleccionar Eliminar Profesor Ayudante, el sistema pedirá al profesor el DNI del profesor Ayudante a Eliminar

    6.a.2.b. El sistema comprueba que el DNI introducido coincide con alguno de los profesores ayudantes de las credenciales.

    6.a.2.c. Si coincide, el sistema elimina el profesor ayudante encontrado de las credenciales.

    6.a.2.d. El sistema muestra un mensaje diciendo que el profesor ayudante se ha eliminado correctamente.

    6.a.2.e. El flujo vuelve al punto 5 del flujo principal.

---

      6.a.2.c.a. Si no coincide con ninguno, el sistema muestra un mensaje de error diciendo que no se encuentra ningún profesor ayudante con ese DNI.

      6.a.2.c.b. El flujo vuelve al punto 5 del flujo principal.

---

    6.a.3.a. En el caso de seleccionar Mostrar todos los Profesores Registrados, el sistema recopilará del archivo de credenciales todos los datos de los profesores.

    6.a.3.b. El sistema mostrará por pantalla el número de profesores registrados y, a continuación, escribirá sus roles (Coordinador o Ayudante) y sus DNIs correspondientes.

    6.a.3.c. El flujo vuelve al punto 5 del flujo principal.
