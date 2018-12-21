#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <sstream>
// Todas las librerías usadas
using namespace std;
// Añadimos el espacio de nombre std ya que usamos muchísimo cout, endl, cin, etc.
#ifndef CLASES_H
#define CLASES_H // Realizamos su correspondiente guardas de inclusión a las clases

class Alumno {
private: 
	string nombre_;	// Nombre del alumno
	string apellidos_; // Apellidos del alumno
	string DNI_; // DNI del alumno
	string correo_; // Correo electrónico del alumno
	string telefono_; // Nº de teléfono del alumno
	string direccion_; // Dirección del alumno
	int cursoMasAlto_; // Curso más alto matriculado del alumno
	string fechaNacimiento_; // Decha de nacimiento del alumno
	bool lider_; // Variable que marca si el alumno es lider (true) o no (false)
	int grupo_; // Nº del grupo al que pertenece el alumno
public:
	inline string getNombre(){return nombre_;}; // Devuelve el nombre del alumno
	inline string getApellidos(){return apellidos_;}; // Devuelve los apellidos del alumno
	inline string getDNI(){return DNI_;}; // Devuelve el DNI del alumno
	inline string getCorreo(){return correo_;}; // Devuelve el correo electronico del alumno
	inline string getTelefono(){return telefono_;}; // Devuelve el número de teléfono del alumno
	inline string getDireccion(){return direccion_;}; // Devuelve la dirección del alumno
	inline int getCursoMasAlto(){return cursoMasAlto_;}; // Devuelve el curso más alto matriculado del alumno
	inline string getFechaNacimiento(){return fechaNacimiento_;}; // Devuelve la fecha de nacimiento del alumno
	inline int getGrupo(){return grupo_;}; // Devuelve el Nº del grupo que pertenece el alumno
	inline bool getLider(){return lider_;}; // Devuelve si el alumno es lider (true) o no (false)
	inline void setNombre(string nombre){nombre_=nombre;}; // Da al nombre del alumno el valor pasado
	inline void setApellidos(string apellidos){apellidos_=apellidos;}; // Da a los apellidos del alumno el valor pasado
	inline void setDNI(string DNI){DNI_=DNI;}; // Da al DNI del alumno el valor pasado
	inline void setCorreo(string correo){correo_=correo;}; // Da al correo electronico del alumno el valor pasado
	inline void setDireccion(string direccion){direccion_=direccion;}; // Da a la dirección del alumno el valor pasado
	void setTelefono(string telefono); // Da al telefono del alumno el valor pasado
	void setCursoMasAlto(int cursoMasAlto); // Da al curso mas alto matriculado del alumno el valor pasado
	void setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento); // Da a la fecha de nacimiento del alumno el valor pasado
	inline void setLider(bool lider){lider_=lider;}; // Da al liderazgo (true o false) del alumno el valor pasado
	void setGrupo(int grupo); // Da al Nº del grupo al que pertenece el alumno el valor pasado
};

class BaseAlumnos{
private:
	list<Alumno> alumnos_; // Es la lista de alumnos con la que se trabajará
public:
	bool insertarAlumno(); // Se encarga de insertar un alumno nuevo
	void eliminarAlumno(); // Se encarga de eliminar un alumno
	void mostrarAlumno(); // Se encarga de mostrar un alumno o todos los alumnos en diferentes ordenes
	void modificarAlumno(); // Se encarga de modificar un alumno
	inline list<Alumno> getListaAlumno()const{return alumnos_;}; // Devuelve la lista de alumnos
	void setListaAlumno(list<Alumno> lista); // Da a la lista de alumnos el valor pasado
	void cargar(); // Se encarga de cargar los datos del fichero CopiaSeguridad.bin en la base de datos 
	void cargarCopia(); // Se encarga de cargar los datos del fichero introducido por el profesor en la base de datos 
	void guardar(); // Se encarga de guardar los datos de la base de datos en el fichero CopiaSeguridad.bin
	void guardarCopia(); // Se encarga de guardar los datos de la base de datos en el fichero introducido por el profesor
	bool buscarAlumno(); // Se encarga de buscar a un alumno
};

class Profesor{
private:
	string DNI_; // DNI del profesor
	string Rol_; // Rol del profesor (Coordinador o Ayudante)
public:
	BaseAlumnos base_; // Publico porque osino no se guardan los cambios // Es la base de datos en la que se trabaja
	void eliminarBaseAlumnos(); // Elimina el contenido de toda la base de datos
	bool identificaProfesor();	// Identifica al profesor con su DNI y Rol al iniciar con el archivo credenciales.bin
	inline void setDNI(string DNI){DNI_=DNI;}; // Da al DNI del profesor el valor pasado
	inline string getDni()const{return DNI_;}; // Devuelve el DNI del profesor
	inline void setRol(string Rol){Rol_=Rol;}; // Da al Rol del profesor el valor pasado
	inline string getRol()const{return Rol_;}; // Devuelve el Rol del profesor
};

#endif // Finaliza la guarda de inclusión