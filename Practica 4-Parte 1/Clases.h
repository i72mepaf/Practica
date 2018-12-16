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

using namespace std;

#ifndef CLASES_H
#define CLASES_H

class Alumno {
private: 
	string nombre_;
	string apellidos_;
	string DNI_;
	string correo_;
	string telefono_;
	string direccion_;
	int cursoMasAlto_;
	string fechaNacimiento_;
	bool lider_;
	int grupo_;
public:
	inline string getNombre(){return nombre_;};
	inline string getApellidos(){return apellidos_;};
	inline string getDNI(){return DNI_;};
	inline string getCorreo(){return correo_;};
	inline string getTelefono(){return telefono_;};
	inline string getDireccion(){return direccion_;};
	inline int getCursoMasAlto(){return cursoMasAlto_;};
	inline string getFechaNacimiento(){return fechaNacimiento_;};
	inline int getGrupo(){return grupo_;};
	inline bool getLider(){return lider_;};
	inline void setNombre(string nombre){nombre_=nombre;};
	inline void setApellidos(string apellidos){apellidos_=apellidos;};
	inline void setDNI(string DNI){DNI_=DNI;};
	inline void setCorreo(string correo){correo_=correo;};
	inline void setDireccion(string direccion){direccion_=direccion;};
	void setTelefono(string telefono);
	void setCursoMasAlto(int cursoMasAlto);
	void setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento);
	inline void setLider(bool lider){lider_=lider;};
	void setGrupo(int grupo);
};

class BaseAlumnos{
private:
	list<Alumno> alumnos_;
	bool buscarAlumno();
public:
	bool insertarAlumno();
	void eliminarAlumno();
	void mostrarAlumno();
	void modificarAlumno();
	inline list<Alumno> getListaAlumno()const{return alumnos_;};
	void setListaAlumno(list<Alumno> lista);
	void cargarFichero();
	void cargarCopia();
	void guardarFichero();
	void guardarCopia();
};

class Profesor{
private:
	string DNI_;
	string Rol_;
public:
	BaseAlumnos base_; //Publico porque osino no se guardan los cambios
	void eliminarBaseAlumnos();
	bool identificaProfesor();
	inline void setDNI(string DNI){DNI_=DNI;};
	inline string getDni()const{return DNI_;};
	inline void setRol(string Rol){Rol_=Rol;};
	inline string getRol()const{return Rol_;};
};

#endif