# Explicación del Diagrama de Clase
Este archivo es una explicación del Diagrama de Clase llamado *Class Diagram1.jpg* incluido en esta misma carpeta.

El Diagrama de Clase consiste en una estructura estática que muestra las **clases, el sistema, atributos, métodos y relaciones entre ellos**.

Como podemos observar, nuestro diagrama de clase está compuesto por **3 clases** diferentes, estas son:
1. **Alumno**
2. **Base de Datos**
3. **Profesor**

También está formado por **2 relaciones** diferentes, estas son:
1. **Relación Alumno - Base de Datos**
2. **Relación Base de Datos - Profesor**
## Clases
A continuación, se van a ir **desarrollando cada una de las clases** que contiene nuestro diagrama:
### Alumno
La **clase Alumno** representa al alumno y todos sus datos.
#### Atributos
A continuación, se describirán todos los atributos de la clase Alumno.

Cabe resaltar que **todos sus atributos son privados**, estos son:
1. **Nombre**: Representa el nombre del alumno. Es un atributo de tipo *string*.
2. **Apellidos**: Representa los apellidos del alumno. Es un atributo de tipo *string*.
3. **DNI**: Representa el DNI del alumno. Es un atributo de tipo *string*.
4. **Correo**: Representa el correo del alumno. Es un atributo de tipo *string*.
5. **Dirección**: Representa la dirección del alumno. Es un atributo de tipo string.
6. **Teléfono**: Representa el número de teléfono del alumno. Es un atributo de tipo *string*, ya que podían existir números de telefono mayores a lo que un *int* y un *double* podían representar.
7. **Dirección Postal**: Representa el número de dirección postal del alumno. Es un atributo de tipo *int*.
8. **Curso más alto matriculado**: Representa el curso más alto matriculado del alumno. Es un atributo de tipo *int*.
9. **Fecha nacimiento**: Representa la fecha de nacimiento del alumno. Es un atributo de tipo *int*.
10. **¿Líder?**: Representa si el alumno es lider o no de un grupo. Es un atributo de tipo *boolean*.
11. **Número del Grupo**: Representa el número del grupo del alumno. Es un atributo de tipo *int*.

#### Operaciones
A continuación, se describirán todas las operaciones de la clase Alumno.


Cabe resaltar que **todas sus operaciones son públicas**, estas se pueden catalogar en dos tipos:
1. **Modificadores (set)**:
Son operaciones que, con el valor pasado, **modifican el atributo** correspondiente.
Todos estos tipos de operaciones son de **tipo** ***void***.
Por ejemplo, la operación **setDNI()** modificará el DNI del alumno en cuestión con el valor pasado.
Algunos ejemplos más son: **setNombre(), setApellidos(), etc**.

2. **Observadores (get)**:
Son operaciones que **devuelven el atributo** correspondiente.
Cada operación de este tipo devuelve un atributo del **tipo correspondiente a su atributo**.
Por ejemplo, la operación **getDNI** devolverá el DNI del alumno en cuestión, es decir, devolverá un atributo de tipo *string*.
Algunos ejemplos más son: **getNombre(), getApellidos(), etc**.
### Base de Datos
La **clase Base de Datos** representa la base de datos de todos los alumnos y las operaciones que puede llevar a cabo esta.
#### Atributos
Su único atributo es **Lista Alumnos** el cual representa la lista de todos los alumnos. Es una **lista** de tipo *Alumno*, es decir, es una lista de elementos de la **clase Alumno**. El atributo es de tipo **privado**, ya que si no lo fuera se puede vulnerar la seguridad de la base de datos.
#### Operaciones
A continuación, se describirán todas las operaciones de la clase Base de datos:
1. **buscarAlumno()**: Se encarga de **buscar un alumno** en específico en la *Lista Alumnos*. Es de tipo *bool* y es una operación **pública**.
2. **insertarAlumno()**: Se encarga de **insertar un nuevo alumno** en la *Lista Alumnos*. Es de tipo *bool* y es una operación **pública**.
3. **eliminarAlumno()**: Se encarga de **eliminar un alumno** en específico de la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
4. **mostrarAlumno()**: Se encarga de **mostrar un alumno, todos los alumnos o los alumnos de un grupo** de la *Lista Alumnos* de distintas formas (ascendente por apellido o descendente por DNI, etc). Es de tipo *void* y es una operación **pública**.
5. **modificarAlumno()**: Se encarga de **modificar un alumno** en específico de la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
6. **guardar()**: Se encarga de **guardar los datos en un fichero preestablecido** de la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
7. **guardarCopia()**: Se encarga de **guardar los datos en una copia de seguridad binaria** de la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
8. **cargar()**: Se encarga de **cargar los datos de un fichero preestablecido** a la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
9. **cargarCopia()**: Se encarga de **cargar los datos de una copia de seguridad binaria** a la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
10. **getListaAlumno()**: Se encarga de **devolver el atributo** ***Lista Alumnos***. Es de tipo *list<Alumno>* y es una operación **pública**.
11. **setListaAlumno()**: Se encarga de **modificar el atributo** ***Lista Alumnos*** con el valor pasado. Es de tipo *void* y es una operación **pública**.
### Profesor
La **clase Profesor** representa a un profesor de la clase de los alumnos.
#### Atributos
A continuación, se describirán todos los atributos de la clase Profesor.

1. **DNI**: Representa el DNI del profesor. Es un atributo de tipo *string*. Este atributo es **privado**.
2. **Rol**: Representa el tipo del profesor, es decir, si es Profesor Coordinador o Profesor Ayudante. Es un atributo de tipo *string*. Este atributo es **privado**.
3. **Base**: Representa la base de alumnos con la que interactúa el profesor. Este atributo es de tipo *BaseAlumnos*. Este atributo es **público**.
#### Operaciones
A continuación, se describirán todas las operaciones de la clase Profesor.

Cabe resaltar que **todas sus operaciones son públicas**, estas son:
1. **eliminarBaseAlumno()**: Se encarga de **eliminar la base de datos** de los alumnos completamente. Es de tipo *void*.
2. **identificaProfesor()**: Se encarga de **registrar o identificar al profesor** que accede al programa. Los datos utilizados para registrarse o identificarse se guardarán en la *Base de datos de los Profesores*. Es de tipo *void*
3. **setDni()**: Se encarga de **modificar el DNI** del profesor en cuestión con el valor pasado. Es de tipo *void*.
4. **getDni()**: Se encarga de **devolver el DNI** del profesor en cuestión. Es de tipo *string*.
5. **setRol()**: Se encarga de **modificar el tipo (coordinador o ayudante)** del profesor en cuestión con el valor pasado. Es de tipo *void*.
6. **getRol()**: Se encarga de **devolver el tipo** del profesor en cuestión. Es de tipo *string*.
## Relaciones entre las Clases
A continuación, se van a ir **desarrollando cada una de las relaciones entre clases** que contiene nuestro diagrama:
### Relación Alumno - Base de Datos
Como se puede observar, la relación indica que **un alumno está en una sola base de datos y una base de datos está compuesta por 0 o muchos alumnos**.

Esta relación es una relación de **Agregación**, es decir, la base de datos está compuesta por alumnos.
### Relación Base de Datos - Profesor
Esta relación indica que **un profesor interactúa con una base de datos de los alumnos, y una base de datos de los alumnos es utilizada por uno o varios profesores**.

Esta relación es una relación de **Asociación**, es decir, es una relación estática entre ambas clases.
