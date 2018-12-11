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
	int telefono_;
	string direccion_;
	int cursoMasAlto_;
	string fechaNacimiento_;
	bool lider_;
	int grupo_;
public:
	inline string getNombre()const{return nombre_;};
	inline string getApellidos()const{return apellidos_;};
	inline string getDNI()const{return DNI_;};
	inline string getCorreo()const{return correo_;};
	inline int getTelefono()const{return telefono_;};
	inline string getDireccion()const{return direccion_;};
	inline int getCursoMasAlto()const{return cursoMasAlto_;};
	inline string getFechaNacimiento()const{return fechaNacimiento_;};
	inline int getGrupo()const{return grupo_;};
	inline bool getLider()const{return lider_;};
	inline void setNombre(string nombre){nombre_=nombre;};
	inline void setApellidos(string apellidos){apellidos_=apellidos;};
	inline void setDNI(string DNI){DNI_=DNI;};
	inline void setCorreo(string correo){correo_=correo;};
	inline void setTelefono(int telefono){telefono_=telefono;};
	inline void setDireccion(string direccion){direccion_=direccion_;};
	inline void setCursoMasAlto(int cursoMasAlto){cursoMasAlto_=cursoMasAlto;};
	void setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento);
	inline void setLider(bool lider){lider_=lider;};
	inline void setGrupo(int grupo){grupo_=grupo;};
};

class BaseAlumnos{
private:
	list<Alumno> alumnos_;
	void buscarAlumno(){cout << "Esta funcionalidad aun no está disponible" << endl;};
public:
	bool insertarAlumno();
	void eliminarAlumno();
	void mostrarAlumno();
	inline void modificarAlumno(){cout << "Esta funcionalidad aun no está disponible" << endl;};
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