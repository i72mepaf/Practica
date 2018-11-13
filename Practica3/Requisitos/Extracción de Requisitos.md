# Documento de Extracción de Requisitos

## Partes Interesadas:

Las partes interesadas de nuestro sistema serán los profesores que utilicen el programa para el almacenamiento de datos de los alumnos.

## Datos a almacenar:
#### Archivo de Credenciales:
Los datos que introduce el profesor para registrarse/identificarse en/con el archivo de credenciales son los siguientes:

1. DNI.

#### Base de Datos de los Alumnos:
Los datos que introduce el profesor, que se guardan en un fichero binario, que hará de base de datos de los alumnos, serán los siguientes:

1. DNI.
2. Nombre.
3. Apellidos.
4. Teléfono.
5. Email.
6. Dirección postal.
7. Curso más alto matriculado.
8. Fecha de nacimiento.
9. Número de grupo.
10. Si es líder de su grupo o no.

## Requisitos funcionales:
* Identificar profesor.
* Insertar alumno.
* Buscar alumno.
* Mostrar alumno.
* Cargar datos de un fichero binario.
* Guardar datos en un fichero binario.
* Eliminar alumno.
* Modificar alumno.
* Eliminar a todos los alumnos de la base de datos.

## Requisitos no funcionales:
* Lenguaje de programación: C++.
* Documentación en Markdown.
* IDE Eclipse.
* Uso de Commits.
* Se utilizará Git y como repositorio remoto GitHub.
* La aplicación se utilizará en Linux.
* Se podrán almacenar como máximo 150 alumnos.
* Solamente habrá 1 líder por grupo.
* Se podrá almacenar en el archivo de credenciales como máximo un profesor coordinador y 5 profesores ayudantes.
* Los alumnos se mostrarán en formato HTML o Markdown.
* Como criterio de ordenación y búsqueda se utilizará DNI, Apellido, Curso más alto en el que el alumno está matriculado.
* Se ordenará alfabéticamente de forma ascendente o descendente.
* Se permite cambiar, borrar y asignar al líder de un grupo.

## Priorización de Requisitos:
### N.º de Prioridad: Requisito
Prioridad 1: Identificar profesor.

Prioridad 1: Insertar alumno.

Prioridad 2: Cargar copia de seguridad de un fichero binario.

Prioridad 2: Guardar copia de seguridad en un fichero binario.

Prioridad 3: Buscar alumno.

Prioridad 4: Mostrar alumno.

Prioridad 4: Eliminar alumno.

Prioridad 4: Modificar alumno.

Prioridad 5: Eliminar base de datos de los alumnos.
