# Documento de Extracción de Requisitos


## Partes Interesadas

Las partes interesadas de nuestro sistema serán los profesores que utilicen el programa para el almacenamiento de datos de los alumnos.

## Datos a almacenar

Los datos que introduce el profesor, que se guardan en un fichero binario, serán los siguientes:

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
* Uso de commits.
* Se utilizará Git y como repositorio remoto GitHub.
* La aplicación se utilizara en Linux.
* Se podrán almacenar como máximo 150 alumnos.
* Solamente habra 1 lider por grupo.
* Los alumnos se mostraran en formato HTML o Markdown.
* Como criterio de ordenación y busqueda se utilizara DNI, Apellido, Curso más alto en el que el alumno esta matriculado.
* Se ordenara alfabeticamente de forma ascendente o descendente.
* Se permite cambiar, borrar y asignar al lider de un grupo.

## Priorizacion de Requistos:
### Nº de Prioridad: Requisito
Prioridad 1: Insertar alumno.

Prioridad 2: Cargar copia de seguridad de un fichero binario.

Prioridad 2: Guardar copia de seguridad en un fichero binario.

Prioridad 3: Buscar alumno.

Prioridad 4: Mostrar alumno.

Prioridad 4: Eliminar alumno.

Prioridad 4: Modificar alumno.

Prioridad 5: Eliminar base de datos de los alumnos.