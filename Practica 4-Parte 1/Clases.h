#include <list.h>
#include <iostream>
#include <string>

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
	bool ¿lider?_;
	int grupo_;
public:
	string getNombre();
	string getApellidos();
	string getDNI();
	string getCorreo();
	int getTelefono();
	int getDireccion();
	int getCursoMasAlto();
	string getFechaNacimiento();
	int getGrupo();
	bool getLider();
	void setNombre();
	void setApellidos();
	void setDNI();
	void setCorreo();
	void setTelefono();
	void setDireccion();
	void setCursoMasAlto();
	void setFechaNacimiento();
	void setLider();
	void setGrupo();
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
>>>>>>> 0b68108ab49f1bc1a9511752a6d22f8918d3cc18
};