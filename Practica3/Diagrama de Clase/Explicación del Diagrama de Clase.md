# Explicación del Diagrama de Clase
Como podemos observar, nuestro diagrama de clase está compuesto por **4 clases** diferentes, estas son:
1. **Alumno**
2. **Base de Datos**
3. **Profesor**
4. **Base de Datos de los Profesores**
## Clases
A continuación se van a ir **desarrollando cada una de las clases** que contiene nuestro diagrama:
### Alumno
La **clase Alumno** representa al alumno y todos sus datos.
#### Atributos
A continuación se describirán todos los atributos de la clase Alumno:
Cabe resaltar que **todos sus atributos son privados**, estos son:
1. **Nombre**: Representa el nombre del alumno. Es un atributo de tipo *string*.
2. **Apellidos**: Representa los apellidos del alumno. Es un atributo de tipo *string*.
3. **DNI**: Representa el DNI del alumno. Es un atributo de tipo *string*.
4. **Correo**: Representa el correo del alumno. Es un atributo de tipo *string*.
5. **Dirección**: Representa la dirección del alumno. Es un atributo de tipo string.
6. **Telefono**: Representa el número de teléfono del alumno. Es un atributo de tipo *int*.
7. **Dirección Postal**: Representa el número de dirección postal del alumno. Es un atributo de tipo *int*.
8. **Curso más alto matriculado**: Representa el curso más alto matriculado del alumno. Es un atributo de tipo *int*.
9. **Fecha nacimiento**: Representa la fecha de nacimiento del alumno. Es un atributo de tipo *int*.
10. **¿Líder?**: Representa si el alumno es lider o no de un grupo. Es un atributo de tipo *boolean*.
11. **Número del Grupo**: Representa el número del grupo del alumno. Es un atributo de tipo *int*.

A la hora de crear un alumno, estos dos últimos atributos son los únicos que pueden tomar valores *NULL*.
#### Operaciones
A continuación se describirán todas las operaciones de la clase Alumno:
Cabe resaltar que **todas sus operaciones son públicas**, estas se pueden catalogar en dos tipos:
1. **Modificadores (set)**:
Son operaciones que, con el valor pasado, **modifican el atributo** correspondiente.
Todos estos tipos de operaciones son de **tipo** ***void***.
Por ejemplo, la operacion **setDNI()** modificará el DNI del alumno en cuestión con el valor pasado.
Algunos ejemplos más son: **setNombre(), setApellidos(), etc**.

2. **Observadores (get)**:
Son operaciones que **devuelven el atributo** correspondiente.
Cada operacion de este tipo devuelve un atributo del **tipo correspondiente a su atributo**.
Por ejemplo, la operación **getDNI** devolverá el DNI del alumno en cuestión, es decir, devolverá un atributo de tipo *string*.
Algunos ejemplos más son: **getNombre(), getApellidos(), etc**.
### Base de Datos
La **clase Base de Datos** representa la base de datos de todos los alumnos y las operaciones que puede llevar a cabo esta.
#### Atributos
Su único atributo es **Lista Alumnos** el cual representa la lista de todos los alumnos. Es una **lista** de tipo *Alumno*, es decir, es una lista de elementos de la **clase Alumno**. El atributo es de tipo **privado**, ya que si no lo fuera se puede vulnerar la seguridad de la base de datos.
#### Operaciones
A continuación se describirán todas las operaciones de la clase Base de datos:
1. **buscarAlumno()**: Se encarga de **buscar un alumno** en específico en la *Lista Alumnos*. Es de tipo *void* y es una operación **privada**.
2. **insertarAlumno()**: Se encarga de **insertar un nuevo alumno** en la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
3. **eliminarAlumno()**: Se encarga de **eliminar un alumno** en específico de la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
4. **mostrarAlumno()**: Se encarga de **mostrar un alumno, todos los alumnos o los alumnos de un grupo** de la *Lista Alumnos* de distintas formas (ascendente por apellido o descendente por DNI, etc). Es de tipo *void* y es una operación **pública**.
5. **modificarAlumno()**: Se encarga de modificar un alumno en específico de la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
### Profesor
La **clase Profesor** representa a un profesor de la clase de los alumnos.
#### Atributos
A continuación se describirán todos los atributos de la clase Profesor:
Cabe resaltar que **todos sus atributos son privados**, estos son:




#### Operaciones




### Base de Datos de los Profesores
#### Atributos





#### Operaciones

## Relaciones entre las Clases
