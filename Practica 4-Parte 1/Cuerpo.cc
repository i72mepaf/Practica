
void BaseAlumnos::eliminarAlumno(){ //Felipe

}
bool Profesor::identificaProfesor(){ //Felipe

}
void Profesor::eliminarBaseAlumnos(){ //Felipe

}

void BaseAlumnos::insertarAlumno(){
	list<Alumno>::iterator it;
	Alumno alumno;
	std::string nombre;
	std::string apellidos;
	std::string DNI;
	std::string correo;
	int telefono;
	int direccion
	int cursoMasAlto;
	int diaNacimiento, mesNacimiento, anoNacimiento;
	bool lider;
	int grupo;

	
	std::cout<<"Introduce el DNI del alumno"<<endl;
	std::cin>>DNI;
	
	it = alumnos_.begin();
	while(it != alumnos_.end){
		if(it.getDNI()==DNI) {
			std::cout<<("ERROR.Este Alumno ya existe")<<endl;
			exit(-1);
		}
	}
	std::cout<<"Introduzca el nombre del alumno"<<endl;
	std::cin>>nombre;
	std::cout>>"Introduce el apellido del alumno"<<endl;
	std::cin>>apellidos;
	std::cout<<"Introduce el corre del alumno"<<endl;
	std::cin>>correo;
	std::cout<<"Introduce el numero de telefono del alumno"<<endl;
	std::cin>>telefono;
	std::cout<<"Introduce la direccion del alumno"<<endl;
	std::cin>>direccion;
	std::cout<<"Introduce el curso mas alto en el que el alumno esta matriculado"<<endl;
	std::cin>>cursoMasAlto;
	std::cout<<"Introduce el dia en el que el alumno nacio"<<endl;
	std::cin>>diaNacimiento;
	std::cout<<"Introduce el mes de nacimiento del alumno"<<endl;
	std::cin>>mesNacimiento;
	std::cout<<"Introduce el año de nacimiento del alumno"<<endl;
	std::cin>>anoNacimiento;
	std::cout<<"Este alumno es lider de algun grupo"<<endl;
	std::cin>>lider;
	std::cout<<"Grupo del alumno"<<endl:

	alumno.setNombre(std::string nombre);
	alumno.setApellidos(std::string apellidos);
	alumno.setDNI(std::string DNI);
	alumno.setCorreo(std::string correo);
	alumno.setTelefono(int telefono);
	alumno.setDireccion(int direccion);
	alumno.setCursoMasAlto(int cursoMasAlto);
	alumno.setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento);
	alumno.setLider(bool lider);
	alumno.setGrupo(int grupo);
	alumnos_.push_back(alumno);
}

void Alumno::setNombre(std::string nombre) {
	nombre_=nombre;
}
void Alumno::setApellidos(std::string apellidos) {
	apellidos_=apellidos;
}
void Alumno::setDNI(std::string DNI) {
	DNI_ = DNI;
}
void Alumno::setCorreo(std::string correo) {
	correo_ = correo;
}
void Alumno::setTelefono(int telefono) {
	telefono_ = telefono;
}
void Alumno::setDireccion(int direccion) {
	direccion_ = direccion;
}
void Alumno::setCursoMasAlto(int cursoMasAlto) {
	cursoMasAlto_ = cursoMasAlto
}
void Alumno::setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento) {
	std::string aux;
	if(mesNacimiento <= 0 || mesNacimiento > 12) {
		std::cout<<"El mes numero "<<mesNacimiento<<"no existe"<<endl;
		exit(-1);
	}
	if(mesNacimiento == 1) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 2) {
		if(diaNacimiento <= 0 || diaNacimiento > 28) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 3) {
		if(diaNacimiento <= 0 || diaNacimiento > 29) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 4) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 5) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 6) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 7) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 8) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 9) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 10) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 11) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 12) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	itoa(diaNacimiento, mesNacimiento, anoNacimiento);
	aux = diaNacimiento+"/"+mesNacimiento+"/"+anoNacimiento;
	fechaNacimiento_ = aux;
}
void Alumno::setLider(bool lider) {}
void Alumno::setGrupo(int grupo) {
	grupo_ = grupo;
}