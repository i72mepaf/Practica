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
}