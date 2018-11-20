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
1. **Modificadores (set)**: Son operaciones que, con el valor pasado, modifican el atributo correspondiente.

Todos estos tipos de operaciones son de tipo *void*. Por ejemplo, la operacion **setDNI()** modificará el DNI del alumno en cuestión con el valor pasado.

Algunos ejemplos más son: **setNombre(), setApellidos(), etc**.


2. **Observadores (get)**: Son operaciones que devuelven el atributo correspondiente.

Cada operacion de este tipo es del tipo correspondiente a su atributo. Por ejemplo, la operación **getDNI** devolverá el DNI del alumno en cuestión, es decir, devolverá un atributo de tipo *string*.

Algunos ejemplos más son: **getNombre(), getApellidos(), etc**.


### Base de Datos
#### Atributos





#### Operaciones





### Profesor
#### Atributos





#### Operaciones




### Base de Datos de los Profesores
#### Atributos





#### Operaciones

## Relaciones entre las Clases
