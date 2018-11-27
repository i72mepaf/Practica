#include <list.h>
#include <iostream>
#include <string>


class Alumno


class BaseAlumnos{
private:
	list<Alumno> alumnos_;
	void buscarAlumno();
public:
	void insertarAlumno();
	void eliminarAlumno();
	void mostrarAlumno();
	void modificarAlumno();
}