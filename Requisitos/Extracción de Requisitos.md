# Documento de extracción de requisitos


## Partes Interesadas

Las partes interesadas de nuestro sistema seran los profesorea que utilizen el programa para el almacenamiento de datos de los alumnos

## Datos a almacenar

Los datos que introduce el profesor,que se guardan en un fichero binario,seran los siguientes :

1. DNI
2. Nombre
3. Apellidos
4. Teléfono
5. Email
6. Dirección postal
7. Curso mas alto matriculado
8. Fecha de nacimiento
9. Número de grupo
10. Si es lider de su grupo o no


## Requisitos funcionales:
* Insertar alumno
* Buscar alumno
* Mostrar alumno 
* Cargar datos de un fichero binario
* Guardar datos en un fichero binario
* Eliminar alumno
* Modificar alumno
* Eliminar a todos los alumnos de la base de datos


## Requisitos no funcionales:
* Lenguaje de programacion:C++.
* Documentacion en Markdown.
* IDE Eclipse
* Uso de commits
* Se utilizará Git y como repositorio remoto GitHub.
* La aplicación se utilizara en Linux
* Se podran almacenar como maximo 150 alumnos
* Solamente habra 1 lider por grupo
* Los alumnos se mostraran en formato HTML o Markdown
* Como criterio de ordenación y busqueda se utilizara DNI, Apellido, Curso más alto en el que el alumno esta matriculado.
* Se ordenara alfabeticamente de forma ascendente o descendente
* Se permite cambiar, borrar y asignar al lider de un grupo

## Priorizacion de Requistos:
### Prioridad: Requisito
Prioridad 1. Insertar Alumno

Prioridad 2. Cargar copia de seguridad de un fichero binario

Prioridad 2. Guardar copia de seguridad en un fichero binario

Prioridad 3. Buscar Alumno

Prioridad 4. Mostrar Alumno

Prioridad 4. Eliminar Alumno

Prioridad 4. Modificar Alumno

Prioridad 5. Eliminar base de datos de los alumnos