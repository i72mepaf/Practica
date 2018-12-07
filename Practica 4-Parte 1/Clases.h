#include <list>
#include <iostream>
#include <string>
#ifndef CLASES_H
#define CLASES_H

using namespace std;
class Alumno {
private: 
	string nombre_;
	string apellidos_;
	string DNI_;
	string correo_;
	int telefono_;
	int direccion_;
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
	inline int getDireccion()const{return direccion_;};
	inline int getCursoMasAlto()const{return cursoMasAlto_;};
	inline string getFechaNacimiento()const{return fechaNacimiento_;};
	inline int getGrupo()const{return grupo_;};
	inline bool getLider()const{return lider_;};
	void setNombre(std::string nombre);
	void setApellidos(std::string apellidos);
	void setDNI(std::string DNI);
	void setCorreo(std::string correo);
	void setTelefono(int telefono);
	void setDireccion(int direccion);
	void setCursoMasAlto(int cursoMasAlto);
	void setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento);
	void setLider(bool lider);
	void setGrupo(int grupo);
};

class BaseAlumnos{
private:
	list<Alumno> alumnos_;
	void buscarAlumno();
public:
	void insertarAlumno();
	void eliminarAlumno();
	void mostrarAlumno();
	void modificarAlumno();
};

class Profesor{
private:
	string DNI_;
	//FALTA: pointer: Puntero Base
	string Rol_;
public:
	void eliminarBaseAlumnos();
	void cargarFichero();
	void guardarFichero();
	bool identificaProfesor();
	void setDni();
	inline string getDni()const{return DNI_;};
	void setRol();
	inline string getRol()const{return Rol_;};
};

#endif