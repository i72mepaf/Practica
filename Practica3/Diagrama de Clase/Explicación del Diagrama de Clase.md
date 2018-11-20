# Explicación del Diagrama de Clase
Como podemos observar, nuestro diagrama de clase está compuesto por **4 clases** diferentes, estas son:
1. **Alumno**
2. **Base de Datos**
3. **Profesor**
4. **Base de Datos de los Profesores**
También esta formado por **3 relaciones** diferentes, estas son:
1. **Relación Alumno - Base de Datos**
2. **Relación Base de Datos - Profesor**
3. **Relación Profesor - Base de Datos de los Profesores**
## Clases
A continuación se van a ir **desarrollando cada una de las clases** que contiene nuestro diagrama:
### Alumno
La **clase Alumno** representa al alumno y todos sus datos.
#### Atributos
A continuación se describirán todos los atributos de la clase Alumno.

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
5. **modificarAlumno()**: Se encarga de **modificar un alumno** en específico de la *Lista Alumnos*. Es de tipo *void* y es una operación **pública**.
### Profesor
La **clase Profesor** representa a un profesor de la clase de los alumnos.
#### Atributos
A continuación se describirán todos los atributos de la clase Profesor.

Cabe destacar que **todos sus atributos son privados**, estos son:
1. **DNI**: Representa el DNI del profesor. Es un atributo de tipo *string*.
2. **PunteroBase**:Es un atributo de tipo *pointer*.
3. **Rol**: Representa el tipo del profesor, es decir, si es Profesor Coordinador o Profesor Ayudante. Es un atributo de tipo *string*.
#### Operaciones
A continuación se describirán todas las operaciones de la clase Profesor.
Cabe resaltar que **todas sus operaciones son públicas**, estas son:
1. **eliminarBaseAlumno()**: Se encarga de **eliminar la base de datos** de los alumnos completamente. Es de tipo *void*.
2. **cargarFichero()**: Se encarga de **cargar una copia de seguridad** de la base de datos de los alumnos guardada en un fichero binario. Es de tipo *void*.
3. **guardarFichero()**: Se encarga de **guardar una copia de seguridad** de la base de datos de los alumnos en un fichero binario. Es de tipo *void*.
4. **identificaProfesor()**: Se encarga de **registrar o identificar al profesor** que accede al programa. Los datos utilizados para registrarse o identificarse se guardarán en la *Base de datos de los Profesores*. Es de tipo *void*
5. **setDni()**: Se encarga de **modificar el DNI** del profesor en cuestión con el valor pasado. Es de tipo *void*.
6. **getDni()**: Se encarga de **devolver el DNI** del profesor en cuestión. Es de tipo *string*.
7. **setRol()**: Se encarga de **modificar el tipo (coordinador o ayudante)** del profesor en cuestión con el valor pasado. Es de tipo *void*.
8. **getRol()**: Se encarga de **devolver el tipo** del profesor en cuestión. Es de tipo *string*.
### Base de Datos de los Profesores
Representa el archivo de credenciales con los datos de los alumnos registrados.
#### Atributos
Su único atributo es **Lista Profesores** el cual representa la lista de todos los profesores registrados en el archivo de crendenciales. Es una **lista** de tipo *Profesor*, es decir, es una lista de elementos de la **clase Profesor**. El atributo es de tipo **privado**, ya que si no lo fuera se puede vulnerar la seguridad de la base de datos.
#### Operaciones
Esta clase no contiene ninguna operación.
## Relaciones entre las Clases
A continuación se van a ir **desarrollando cada una de las relaciones entre clases** que contiene nuestro diagrama:
### Relación Alumno - Base de Datos
### Relación Base de Datos - Profesor
### Relación Profesor - Base de Datos de los Profesores
