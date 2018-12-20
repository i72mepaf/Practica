#include "Clases.h"

struct Auxiliar2{
	char nombre[100];
	char apellidos[100];
	char DNI[100];
	char correo[100];
	char telefono[100];
	char direccion[256];
	int cursoMasAlto;
	char fechaNacimiento[100];
	bool lider;
	int grupo;
};

bool sortByCursoa(Auxiliar2 &lhs,Auxiliar2 &rhs){ return lhs.cursoMasAlto > rhs.cursoMasAlto ; }
bool sortByCursod(Auxiliar2 &lhs,Auxiliar2 &rhs){ return rhs.cursoMasAlto > lhs.cursoMasAlto ; }
bool sortByApella(Auxiliar2 &lhs,Auxiliar2 &rhs){ return lhs.apellidos > rhs.apellidos ; }
bool sortByApelld(Auxiliar2 &lhs,Auxiliar2 &rhs){ return rhs.apellidos > lhs.apellidos ; }

void BaseAlumnos::eliminarAlumno(){ //Felipe
	string ap;
	int cont=0, i;
	cout << "Introduzca los apellidos del alumno a eliminar:"<< endl;
	getline(cin, ap);
	list<Alumno>::iterator it;
	it=alumnos_.begin();
	for(i=0; i < (int) alumnos_.size(); i++){
		if(it->getApellidos() == ap)
			cont++;
		it++;
	}
	if(cont == 1){
		if(alumnos_.size()==1){
			it=alumnos_.begin();
			if(it->getApellidos() == ap){
				alumnos_.erase(it);
				cout << "Alumno con apellidos: '"<< ap <<"' eliminado con exito."<<endl;
			}
			else
				cout << "No hay ningún alumno con los apellidos '"<<ap<<"' en nuestra base de datos" << endl;
		}else{
			it = alumnos_.begin();
			while(it != alumnos_.end()){
				if(it->getApellidos() == ap){
					alumnos_.erase(it);
					it = alumnos_.begin();
				}
				else
					it++;
			}
			cout << "Alumno con apellidos: '"<< ap <<"' eliminado con exito."<<endl;
		}
	}
	else{
		if(cont == 0)
			cout << "No hay ningún alumno con los apellidos '"<<ap<<"' en nuestra base de datos" << endl;
		else{
			cont = 0;
			cout << "Hay varios alumnos con los apellidos: '" << ap << "'." << endl;
			cout << "Porfavor, introduzca el DNI del alumno a borrar:" << endl;
			getline(cin, ap);
			it=alumnos_.begin();
			while(it != alumnos_.end()){
				if(it->getDNI() == ap){
					alumnos_.erase(it);
					it = alumnos_.begin();
					cont++;
				}
				else
					it++;
			}
			if(cont == 1)
				cout << "Alumno con DNI: '"<< ap <<"' eliminado con exito." << endl;
			else
				cout << "El DNI: '"<< ap <<"' no coincide con ninguno de nuestra base de datos." << endl;
		}
	}
}
struct Auxiliar
{
	char d[100];
	char r[100];
};
bool Profesor::identificaProfesor(){
	int opcion = 0, contadorTipo=0, i, j;
	string dni, compDNI, compROL, dniAux, rolAux, dniInicial, dniAyudante, RolAyudante;
	Auxiliar aux;
	vector<Auxiliar> v;
	vector<Auxiliar>::iterator it;
	ifstream fichero("credenciales.bin", ios::in | ios::binary);
	if (fichero.is_open()){
		while(!fichero.eof() && fichero.read((char *)&aux, sizeof(Auxiliar))){
			v.push_back(aux);
		}
	}
	else{
		cout << "Error al abrir credenciales.bin porque no existe en el directorio." << endl;
		exit(-1);
	}
   	fichero.close();
		cout << "Bienvenido al programa de la base de datos de alumnos." << endl;
	while(opcion!=1 && opcion!=2){
		cout << "¿Es profesor Coordinador o Ayudante?" << endl;
		cout << "1. Coordinador.\n2. Ayudante." << endl;
		cin >> opcion;
		cin.ignore();
		system("clear");
		if(opcion!=1 && opcion!=2){
			cout << "Número Incorrecto. Intentelo de nuevo." << endl;
		}
		else{
			if(opcion==1){//Coordinador
				cout << "A continuación procederemos a identificarle como profesor Coordinador." << endl;
				cout << "Introduzca DNI: ";
				getline(cin, dniInicial);
				system("clear");
   				for (i = 0; i < (int) v.size(); i++)
   				{
   					compDNI = v[i].d;
   					compROL = v[i].r;
   					if(compDNI == dniInicial && compROL == "Coordinador")
   						cout << "Identificado Correctamente." << endl;
   					while(compDNI == dniInicial && compROL == "Coordinador"){
   						cout << "Eliga una opción:\n1. Iniciar.\n2. Cambiar DNI." << endl;
   						cout << "3. Eliminar Ayudante.\n4. Mostrar todos los profesores registrados." << endl;
   						cin >> opcion;
   						cin.ignore();
   						system("clear");
   						if(opcion!= 1 && opcion!=2 && opcion!=3 && opcion!=4){
   							cout << "Numero Incorrecto. Intentalo de nuevo." << endl;
   						}
   						else{
   							if(opcion == 1){
   								cout << "Iniciando..." << endl;
   								setDNI(compDNI);
   								setRol(compROL);
   								return true;
   							}
   							if(opcion==2){
   								cout << "Introduzca el nuevo DNI: ";
   								getline(cin, dni);
   								contadorTipo=0;
								for (i = 0; i < (int) v.size(); i++){
									dniAux = v[i].d;
									rolAux = v[i].r;
									if(dni == dniAux && rolAux!="Coordinador"){
										cout << "Ya existe un usuario registrado con ese DNI. Cambio no realizado" << endl;
										contadorTipo++;
									}
								}
								if(contadorTipo!=0){
									dniInicial=dni;
   									compDNI = dni;
   									compROL = "Coordinador";
								}else{
   								remove("credenciales.bin");
   								ofstream fEscCoord("credenciales.bin", ios::out | ios::binary);
								if (fEscCoord.is_open()){
									for(j=0; j < (int) v.size(); j++){
										compROL = v[j].r;
										if(compROL == "Coordinador")
											strcpy(v[j].d, dni.c_str());
										fEscCoord.write((char *)&v[j], sizeof(Auxiliar));
									}
   								}
   								else{
   									cout << "Error al abrir el fichero." << endl;
   									exit(-1);
   								}
   								fEscCoord.close();
   								cout << "DNI cambiado con exito." << endl;
   								dniInicial=dni;
   								compDNI = dni;
   								compROL = "Coordinador";
   								}
   							}
   							if(opcion == 3){
   								cout << "Introduzca el DNI del Profesor Ayudante a eliminar: ";
   								getline(cin, dni);
   								contadorTipo = 0;
   								it=v.begin();
   								for (i = 0; i < (int) v.size(); i++){
									dniAux = v[i].d;
									rolAux = v[i].r;
									if(dni == dniAux && rolAux=="Ayudante"){
										v.erase(it);
										it = v.begin();
										i=0;
										contadorTipo++;
									}
									else
										it++;
								}
								if(contadorTipo == 0){
									cout << "No existe registrado ningún profesor ayudante con ese DNI" << endl;
								}
								else{
									remove("credenciales.bin");
									ofstream fEscAyud("credenciales.bin", ios::out | ios::binary);
									if (fEscAyud.is_open()){
										for(int i=0; i < (int) v.size(); i++)
											fEscAyud.write((char *)&v[i], sizeof(Auxiliar));
   									}
   									else{
   										cout << "Error al abrir el fichero." << endl;
   										exit(-1);
   									}
   									fEscAyud.close();
									cout << "Profesor Ayudante eliminado correctamente" << endl;
								}
   							}
   							if(opcion == 4){
   								cout << "El número de profesores registrados es " << (int) v.size() <<":\n"<< endl; 
   								for (i = 0; i < (int) v.size(); ++i)
   									cout << i+1 <<". Rol: '"<< v[i].r << "' con DNI: '" << v[i].d << "'." << endl;
   								cout << endl;
   							}
   						}
   					}
				}
				cout << "Lo sentimos, no hemos podido identificarle, intentelo de nuevo." << endl;
   				opcion = 3;
   			}
			else{//Ayudante
				cout << "¿Desea registrarse o identificarse?" << endl;
				cout << "1. Registrar.\n2. Identificar." << endl;
				cin >> opcion;
				cin.ignore();
				system("clear");
   				if(opcion!= 1 && opcion!=2){
  					cout << "Numero Incorrecto. Intentalo de nuevo." << endl;
  					opcion = 3;
				}
				else{
					if(opcion == 1){//Registrarse
						contadorTipo=0;
						for (i = 0; i < (int) v.size(); i++)
						{
							compROL = v[i].r;
							if(compROL=="Ayudante")
								contadorTipo++;
						}
						if(contadorTipo < 5){
							cout << "Registro de un profesor ayudante.\nIntroduce el DNI: ";
							getline(cin, dni);
							strcpy(aux.d, dni.c_str());
							strcpy(aux.r, "Ayudante");
							contadorTipo=0;
							for (i = 0; i < (int) v.size(); i++){
								dniAux = v[i].d;
								if(dni == dniAux){
									cout << "Ya existe un usuario registrado con ese DNI" << endl;
									contadorTipo++;
								}
							}
							if(contadorTipo==0){
							v.push_back(aux);
							remove("credenciales.bin");
							ofstream fEscAyud("credenciales.bin", ios::out | ios::binary);
							if (fEscAyud.is_open()){
								for(i=0; i < (int) v.size(); i++)
									fEscAyud.write((char *)&v[i], sizeof(Auxiliar));
   							}
   							else{
   								cout << "Error al abrir el fichero." << endl;
   								exit(-1);
   							}
   							fEscAyud.close();
   							cout << "Registro correcto. Iniciando..." << endl;
   							setDNI(dni);
   							setRol("Ayudante");
   							return false;
   							}
   							else{
   								contadorTipo = 0;
   								opcion=3;
   							}
						}
						else{
							contadorTipo = 0;
							cout << "Lo sentimos. Ya existen registrados 5 profesores ayudantes." << endl;
  							opcion = 3;
						}
					}
					else{//Identificarse
						cout << "A continuación procederemos a identificarle como profesor Ayudante." << endl;
						cout << "Introduzca el DNI: ";
						getline(cin, dni);
						system("clear");
   						for (i = 0; i < (int) v.size(); i++)
   						{
   							compDNI = v[i].d;
   							compROL = v[i].r;
   							if(compDNI == dni && compROL == "Ayudante"){
   								cout << "Identificado Correctamente. Iniciando..." << endl;
   								setDNI(compDNI);
   								setRol(compROL);
   								return false;
							}
						}
							cout << "No se ha podido identificar, intentelo de nuevo." << endl;
							opcion = 3;
					}
				}
			}
		}
	}
}
void BaseAlumnos::setListaAlumno(list<Alumno> lista){
	while(alumnos_.size()!=0)
		alumnos_.pop_back();
	alumnos_=lista;
}
void Profesor::eliminarBaseAlumnos(){ //Felipe
	int opcion=0;
	list<Alumno> alumnos;
	alumnos = base_.getListaAlumno();
	while(opcion!=1 && opcion!=2){
		cout << "¿Esta seguro que desea eliminar la base de datos de los alumnos?" << endl;
		cout << "1. Sí.\n2. No."<<endl;
		cin >> opcion;
		cin.ignore();
		system("clear");
		if(opcion!=1 && opcion!=2)
			cout << "Error. Vuelva a intentarlo introduciendo un número valido" << endl;
	}
	if(opcion == 1){
		if(alumnos.size()==0){
			cout << "La base de los alumnos esta vacia" << endl;
		}
		else{
			while(alumnos.size()!=0)
				alumnos.pop_back();
			cout << "Base de Alumnos eliminada con exito" << endl;
		}
	}
	base_.setListaAlumno(alumnos);
}


bool BaseAlumnos::insertarAlumno(){
	list<Alumno>::iterator it;
	Alumno alumno;
	string nombre;
	string apellidos;
	string DNI;
	string correo;
	string telefono;
	string direccion;
	int cursoMasAlto, diaNacimiento, mesNacimiento, anoNacimiento, cont=0;
	bool lider;
	int grupo;

	int opcion;
	if(alumnos_.size()==150){
		cout << "La base de Alumnos esta llena" << endl;
		return false;
	}
	
	cout<<"Introduce el DNI del alumno"<<endl;
	getline(cin, DNI);
	it = alumnos_.begin();
	while(it != alumnos_.end()){
		if(it->getDNI()==DNI) {
			cout << "ERROR.Este Alumno con este DNI ya existe" << endl;
			opcion=0;
			while(opcion!=1 && opcion !=2){
				cout << "¿Que desea?\n1. No introducir el alumno\n2.Introducir de nuevo el DNI" << endl;
				cin >> opcion;
				cin.ignore();
				system("clear");
				if(opcion!=1 && opcion !=2){
					cout << "ERROR. No ha seleccionado un número correcto. Vuelva a intentarlo" << endl;
				}
				else{
					if(opcion==2){
					cout << "Vuelva a introducir el DNI: ";
					getline(cin, DNI);
					it = alumnos_.begin();
					}
					else{
						cout << "No se ha introducido el alumno" << endl;
						return false;
					}
				}
			}
		}
		else{
			it++;
		}
	}
	cout<<"Introduzca el nombre del alumno"<<endl;
	getline(cin, nombre);
	cout<<"Introduzca el apellido del alumno"<<endl;
	getline(cin, apellidos);
	cout<<"Introduzca el correo del alumno"<<endl;
	getline(cin, correo);
	it=alumnos_.begin();
	while(it != alumnos_.end()){
		if(it->getCorreo()==correo) {
			cout << "ERROR.Este Alumno con este correo ya existe" << endl;
			opcion=0;
			while(opcion!=1 && opcion !=2){
				cout << "¿Que desea?\n1. No introducir el alumno\n2.Introducir de nuevo el correo" << endl;
				cin >> opcion;
				cin.ignore();
				system("clear");
				if(opcion!=1 && opcion !=2){
					cout << "ERROR. No ha seleccionado un número correcto. Vuelva a intentarlo" << endl;
				}
				else{
					if(opcion==2){
					cout << "Vuelva a introducir el correo: ";
					getline(cin, correo);
					it = alumnos_.begin();
					}
					else{
						cout << "No se ha introducido el alumno" << endl;
						return false;
					}
				}
			}
		}
		else{
			it++;
		}
	}

	cout<<"Introduzca el numero de telefono del alumno"<<endl;
	cin>>telefono;
	cin.ignore();
	cout<<"Introduzca la direccion del alumno"<<endl;
	getline(cin, direccion);
	cout<<"Introduzca el curso mas alto en el que el alumno esta matriculado"<<endl;
	cin>>cursoMasAlto;
	cin.ignore();
	cout<<"Introduzca el dia en el que el alumno nacio"<<endl;
	cin>>diaNacimiento;
	cin.ignore();
	cout<<"Introduzca el mes de nacimiento del alumno"<<endl;
	cin>>mesNacimiento;
	cin.ignore();
	cout<<"Introduzca el año de nacimiento del alumno"<<endl;
	cin>>anoNacimiento;
	cin.ignore();
	cout<<"Introduzca el grupo del alumno"<<endl;
	cin>>grupo;
	cin.ignore();
	cout<<"Introduzca si es lider o no de algun grupo"<<endl;
	opcion=0;
	while(opcion!=1 && opcion!=2){
		cout << "1.Lider\n2.No Lider" << endl;
		cin>>opcion;
		cin.ignore();
		if(opcion!=1 && opcion!=2){
			cout << "Error. Seleccione un número correcto" << endl;
		}
		else{
			if(opcion==1)
				lider=true;
			else
				lider=false;
		}
	}
	alumno.setNombre(nombre);
	alumno.setApellidos(apellidos);
	alumno.setDNI(DNI);
	alumno.setCorreo(correo);
	alumno.setTelefono(telefono);
	alumno.setDireccion(direccion);
	alumno.setCursoMasAlto(cursoMasAlto);
	alumno.setFechaNacimiento(diaNacimiento, mesNacimiento, anoNacimiento);
	it=alumnos_.begin();
	while(it != alumnos_.end()){
		if(it->getGrupo()==grupo)
			cont++;
		if(cont == 3){
			cout << "El grupo asignado ya esta lleno" << endl;
			cout << "Introduzca otro grupo: " << endl;
			cin>>grupo;
			cin.ignore();
			cont=0;
			it = alumnos_.begin();
		}
		else
			it++;
	}
	alumno.setGrupo(grupo);
	if(lider == true) {
		it=alumnos_.begin();
		if((int) alumnos_.size()==1){
			if(alumnos_.front().getGrupo() == alumno.getGrupo() && alumnos_.front().getLider() == true && lider==true) {
					cout<<"En este grupo ya hay un lider."<<endl;
					cout << "Por lo que el alumno insertado estará en el grupo pero no será lider"<<endl;
					lider=false;
			}
		}
		else{
			while(it != alumnos_.end()){
				if(it->getGrupo() == alumno.getGrupo() && it->getLider() == true && lider==true) {//Si hay alumnos en el grupo del estudiante insertado y si hay un lider en dicho grupo
					cout<<"En este grupo ya hay un lider."<<endl;
					cout << "Por lo que el alumno insertado estará en el grupo pero no será lider"<<endl;
					lider=false;
					it = alumnos_.begin();
				}
				else
					it++;	
			}
		}

	}
	alumno.setLider(lider);
	alumnos_.push_back(alumno);
	return true;

}
string intToString (int number){
     ostringstream ss;
     ss << number;
     return ss.str();
 }

void Alumno::setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento) {
	string aux;
	while(mesNacimiento <= 0 || mesNacimiento > 12) {
		cout<<"El mes numero "<<mesNacimiento<<" no existe"<<endl;
		cout << "Introduzca de nuevo el número del mes:" << endl;
		cin >> mesNacimiento;
		cin.ignore();
	}
	if(mesNacimiento == 1) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 2) {
		while(diaNacimiento <= 0 || diaNacimiento > 28) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 3) {
		while(diaNacimiento <= 0 || diaNacimiento > 29) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 4) {
		while(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 5) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 6) {
		while(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 7) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 8) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 9) {
		while(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 10) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 11) {
		while(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 12) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	
	aux = intToString(diaNacimiento) + "/"+ intToString(mesNacimiento) +"/"+ intToString(anoNacimiento);
	fechaNacimiento_ = aux;
}
void imprimeVector(vector <Auxiliar2> v,int nele); //Cabeceras de funciones para que no haya error al compilar

void imprimeAlumno(Auxiliar2 a);

void BaseAlumnos::mostrarAlumno(){
	int menu, menu2, comp=0, comp2=0, cont=0, i;
	string aux;
	list <Alumno>:: iterator it;
	vector<Auxiliar2> v;
	Auxiliar2 relleno;
	while((int)v.size()!= (int) alumnos_.size())
		v.push_back(relleno);

	it=alumnos_.begin();
	for(i=0; i < (int) v.size(); i++){
		strcpy(v[i].nombre, it->getNombre().c_str());
		strcpy(v[i].apellidos, it->getApellidos().c_str());
		strcpy(v[i].DNI, it->getDNI().c_str());
		strcpy(v[i].correo, it->getCorreo().c_str());
		strcpy(v[i].telefono, it->getTelefono().c_str());
		strcpy(v[i].direccion, it->getDireccion().c_str());
		v[i].cursoMasAlto = it->getCursoMasAlto();
		strcpy(v[i].fechaNacimiento, it->getFechaNacimiento().c_str());
		v[i].lider = it->getLider();
		v[i].grupo = it->getGrupo();
		it++;
	}
	
	do{
	cout << "1. Mostrar todos los alumnos"<< endl;
	cout << "2. Mostrar solo un alumno"<< endl;
	cin>> menu;
	cin.ignore();
	system("clear");
	
		switch(menu){
			case 1:
				do{
				cout << "1. Mostrar ordenados ascendentemente por curso mas alto matriculado"<< endl;
				cout << "2. Mostrar ordenados descendentemente por curso mas alto matriculado"<< endl;
				cout << "3. Mostrar ordenados ascendentemente por apellidos"<< endl;
				cout << "4. Mostrar ordenados descendentemente por apellidos"<< endl;
				cin>> menu2;
				cin.ignore();	
				system("clear");		
					switch(menu2){
						case 1:
						sort(v.begin(),v.end(),sortByCursoa);
						cout<< "══════════════════════════════════"<<endl;
						imprimeVector(v, (int) v.size());
						comp2=1;
						break;

						case 2:
						sort(v.begin(),v.end(),sortByCursod);
						cout<< "══════════════════════════════════"<<endl;
						imprimeVector(v, (int) v.size());
						comp2=1;
						break;

						case 3:
						comp2=1;
						sort(v.begin(),v.end(),sortByApella);
						cout<< "══════════════════════════════════"<<endl;
						imprimeVector(v, (int) v.size());
						break;

						case 4:
						sort(v.begin(),v.end(),sortByApelld);
						cout<< "══════════════════════════════════"<<endl;
						imprimeVector(v, (int) v.size());
						comp2=1;
						break;

						default:
							cout << "Error ,introduzca una opcion válida"<< endl;
							break;					
					}
				}while(comp2 == 0);

				comp=1;
				break;

			case 2:
				do{
					cout <<"1. Mostrar un alumno por dni"<<endl;
					cout <<"2. Mostrar un alumno por Apellidos"<<endl;
					cin >> menu2;
					cin.ignore();
					system("clear");
					switch(menu2){
						case 1:
						cout <<"Introduzca el dni del alumno a mostrar"<<endl;
						cin>>aux;
						cin.ignore();
						system("clear");
						comp2=0;
						for (int i=0;i<(int)v.size();i++){
							if(aux == v[i].DNI){
								imprimeAlumno(v[i]);
								comp2=1;
							}
						}
						if(comp2==0)
							cout <<"No se encontro el alumno"<<endl;
						comp2=1;
						break;

						case 2:
						cout <<"Introduzca los apellidos del alumno a mostrar"<<endl;
						getline(cin, aux);
						system("clear");
						for (int i=0;i<(int) v.size();i++){
							if(aux == v[i].apellidos){
								cont++;
							}
						}
						if(cont!=1){
							cout <<"No se puede imprimir el alumno por apellidos"<<endl;
							break;
						}
						for (int i=0;i< (int) v.size();i++){
							if(aux == v[i].apellidos){
							imprimeAlumno(v[i]);	
							}
						}
						comp2 =1;
						break;

						default:
							cout << "Error ,introduzca una opcion válida"<< endl;
							break; 
					}

				}while(comp2 == 0);
				comp=1;
				break;

			default:
				cout << "Error ,introduzca una opcion válida"<< endl;
				break;
		}
	}while(comp == 0);
}

void imprimeVector(vector <Auxiliar2> v, int nele){
	for(int i=0;i< nele;i++){
		cout<< "Nombre: "<< v[i].nombre<<endl;
		cout<< "Apellidos: "<<  v[i].apellidos<<endl;
		cout<< "DNI: "<<  v[i].DNI<<endl;
		cout<< "Correo: "<<  v[i].correo<<endl;
		cout<< "Telefono: "<<  v[i].telefono<<endl;
		cout<< "Dirección: "<<  v[i].direccion<<endl;
		cout<< "Curso más alto: "<<  v[i].cursoMasAlto<<endl;
		cout<< "Fecha de nacimiento: "<<  v[i].fechaNacimiento<<endl;
		cout<< "Grupo: "<<  v[i].grupo<<endl;
		cout << "Lider: ";
		if(v[i].lider)
			cout << "Si"<< endl;
		else
			cout << "No" << endl;
		cout<< "══════════════════════════════════"<<endl;
	}
}

void imprimeAlumno(Auxiliar2 a){
	cout<< "══════════════════════════════════"<<endl;
	cout<< "Nombre: "<< a.nombre<<endl;
	cout<< "Apellidos: "<< a.apellidos<<endl;
	cout<< "DNI: "<< a.DNI<<endl;
	cout<< "Correo: "<< a.correo<<endl;
	cout<< "Telefono: "<< a.telefono<<endl;
	cout<< "Dirección: "<< a.direccion<<endl;
	cout<< "Curso más alto: "<< a.cursoMasAlto<<endl;
	cout<< "Fecha de nacimiento: "<< a.fechaNacimiento<<endl;
	cout<< "Grupo: "<< a.grupo<<endl;
	cout<< "Lider: ";
	if(a.lider)
		cout << "Si"<< endl;
	else
		cout << "No" << endl;
	cout<< "══════════════════════════════════"<<endl;
}

void BaseAlumnos::guardarCopia(){ //Guardar copia de seguridad
	Auxiliar2 aux;
	Alumno alum;
	vector<Auxiliar2> v;
	list <Alumno>::iterator it;
	int i;
	string fechanam, nFichero;
	cout << "Introduzca el nombre del Fichero para guardar:" << endl;
	getline(cin, nFichero);
	while(nFichero=="CopiaSeguridad.bin" || nFichero=="credenciales.bin" || nFichero=="Cuerpo.cc" || nFichero=="Clases.h" || nFichero=="main.cc"){
		cout << "Error, el archivo no se puede llamar '"<<  nFichero << "', intentelo de nuevo" << endl;
		getline(cin, nFichero);
		system("clear");
	}
	while((int)v.size()!= (int) alumnos_.size())
		v.push_back(aux);

	it=alumnos_.begin();
	for(i=0; i < (int) v.size(); i++){
		strcpy(v[i].nombre, it->getNombre().c_str());
		strcpy(v[i].apellidos, it->getApellidos().c_str());
		strcpy(v[i].DNI, it->getDNI().c_str());
		strcpy(v[i].correo, it->getCorreo().c_str());
		strcpy(v[i].telefono, it->getCorreo().c_str());
		strcpy(v[i].direccion, it->getDireccion().c_str());
		v[i].cursoMasAlto = it->getCursoMasAlto();
		strcpy(v[i].fechaNacimiento, it->getFechaNacimiento().c_str());
		v[i].lider = it->getLider();
		v[i].grupo = it->getGrupo();
		it++;
	}
	remove(nFichero.c_str());
	ofstream fGuardar(nFichero.c_str(), ios::out | ios::binary);
	if (fGuardar.is_open()){
		for (i = 0; i < (int) v.size(); ++i)
			fGuardar.write((char *)&v[i], sizeof(Auxiliar2));
		fGuardar.close();
		cout << "Guardado Correcto" << endl;
	}
	else
		cout << "Error al sobrescribir el fichero." << endl;
}
void BaseAlumnos::guardar(){
	Auxiliar2 aux;
	Alumno alum;
	vector<Auxiliar2> v;
	list <Alumno>::iterator it;
	int i;
	string fechanam;
	while((int)v.size()!= (int) alumnos_.size())
		v.push_back(aux);

	it=alumnos_.begin();
	for(i=0; i < (int) v.size(); i++){
		strcpy(v[i].nombre, it->getNombre().c_str());
		strcpy(v[i].apellidos, it->getApellidos().c_str());
		strcpy(v[i].DNI, it->getDNI().c_str());
		strcpy(v[i].correo, it->getCorreo().c_str());
		strcpy(v[i].telefono, it->getCorreo().c_str());
		strcpy(v[i].direccion, it->getDireccion().c_str());
		v[i].cursoMasAlto = it->getCursoMasAlto();
		strcpy(v[i].fechaNacimiento, it->getFechaNacimiento().c_str());
		v[i].lider = it->getLider();
		v[i].grupo = it->getGrupo();
		it++;
	}
	ofstream fGuardar("CopiaSeguridad.bin", ios::out | ios::binary);
	if (fGuardar.is_open()){
		for (i = 0; i < (int) v.size(); ++i)
			fGuardar.write((char *)&v[i], sizeof(Auxiliar2));
		fGuardar.close();
		cout << "Guardado Correcto" << endl;
	}
	else
		cout << "Error al sobrescribir el fichero." << endl;
}

void BaseAlumnos::cargarCopia(){
	Auxiliar2 aux;
	Alumno alum;
	vector<Auxiliar2> v;
	int i;
	string fechanam, nFichero;
	cout << "Introduzca el nombre del fichero binario a cargar: " << endl;
	getline(cin, nFichero);

	ifstream fichero(nFichero.c_str(), ios::in | ios::binary);
	if (fichero.is_open()){
		while(!fichero.eof() && fichero.read((char *)&aux, sizeof(Auxiliar2))){
			v.push_back(aux);
		}
		fichero.close();
		if((int)v.size() > 150){
			cout << "Error. El fichero contiene más de 150 alumnos" << endl;
			return;
		}
		while(alumnos_.size()!=0)
   		alumnos_.pop_back();

   		for (i = 0; i < (int) v.size(); ++i){
   		alum.setNombre((string)v[i].nombre);
   		alum.setApellidos((string)v[i].apellidos);
   		alum.setDNI((string)v[i].DNI);
   		alum.setCorreo((string)v[i].apellidos);
   		alum.setDireccion((string)v[i].direccion);
   		alum.setCursoMasAlto(v[i].cursoMasAlto);
   		alum.setDireccion((string)v[i].direccion);
   		fechanam = v[i].fechaNacimiento;
		alum.setFechaNacimiento(atoi((fechanam.substr(0, fechanam.find("/"))).c_str()), 
			atoi((fechanam.substr(fechanam.find("/")+1, fechanam.find("/"))).c_str()), 
			atoi((fechanam.substr(fechanam.find("/")+fechanam.find(fechanam.substr(fechanam.find("/")+1, 
				fechanam.find("/"))))).c_str()));
		alum.setLider(v[i].lider);
		alum.setGrupo(v[i].grupo);
   		alumnos_.push_back(alum);
   		}
   		cout << "Cargado Correcto" << endl;
	}
	else{
		cout << "Error al cargar '"<< nFichero <<"' porque no existe en el directorio." << endl;
	}
}

void BaseAlumnos::cargar(){
	Auxiliar2 aux;
	Alumno alum;
	vector<Auxiliar2> v;
	int i;
	string fechanam;
	ifstream fichero("CopiaSeguridad.bin", ios::in | ios::binary);
	if (fichero.is_open()){
		while(!fichero.eof() && fichero.read((char *)&aux, sizeof(Auxiliar2))){
			v.push_back(aux);
		}
		fichero.close();

		if((int)v.size() > 150){
			cout << "Error. El fichero contiene más de 150 alumnos" << endl;
			return;
		}
		
		while(alumnos_.size()!=0)
   		alumnos_.pop_back();

   		for (i = 0; i < (int) v.size(); ++i){
   		alum.setNombre((string)v[i].nombre);
   		alum.setApellidos((string)v[i].apellidos);
   		alum.setDNI((string)v[i].DNI);
   		alum.setCorreo((string)v[i].apellidos);
   		alum.setDireccion((string)v[i].direccion);
   		alum.setCursoMasAlto(v[i].cursoMasAlto);
   		alum.setDireccion((string)v[i].direccion);
   		fechanam = v[i].fechaNacimiento;
		alum.setFechaNacimiento(atoi((fechanam.substr(0, fechanam.find("/"))).c_str()), 
			atoi((fechanam.substr(fechanam.find("/")+1, fechanam.find("/"))).c_str()), 
			atoi((fechanam.substr(fechanam.find("/")+fechanam.find(fechanam.substr(fechanam.find("/")+1, 
				fechanam.find("/"))))).c_str()));
		alum.setLider(v[i].lider);
		alum.setGrupo(v[i].grupo);
   		alumnos_.push_back(alum);
   		}
   		cout << "Cargado Correcto" << endl;
	}
	else{
		cout << "Error al abrir CopiaSeguridad.bin porque no existe en el directorio." << endl;
	}
}

bool BaseAlumnos::buscarAlumno() {
	string apellido;
	int contador = 0;//Se utilizara para ver el numero de alumnos que comparten apellido
	string DNI;
	
	cout<<"Introduza el apellido del alumno que desea buscar: "<<endl;
	getline(cin, apellido);
	list<Alumno>::iterator it;
	it = alumnos_.begin();
	while(it != alumnos_.end()) {
		if(it->getApellidos() == apellido) {
			contador++;
		}
		it++;
	}
	if(contador == 0) {
		cout<<"No hay alumnos con el apellido introducido"<<endl;
		return false;
	}
	if(contador == 1) {
		cout<<"Alumno encontado"<<endl;
		return true; 
	}
	if(contador != 1 && contador != 0) {
		cout<<"Hay " << contador << " alumnos con el apellido introducido"<<endl;
		cout<<"Porfavor, introduzca el DNI del alumno para verificar que existe:"<<endl;
		getline(cin, DNI);
		it = alumnos_.begin();
		while(it != alumnos_.end()) {
			if(it->getDNI() == DNI) {
				cout<<"Alumno encontrado :" << it->getNombre()+" "+it->getApellidos() <<endl;
				return true;
			}
			it++;
		}
		cout<<"Alumno no encontrado"<<endl;
		return false;
	}
}


void BaseAlumnos::modificarAlumno(){
	string cadena;
	int opcion = 0;//Para evitar que el valor basure tome un valor innecesario
	int encontrado=0, curso, diaNacimiento, mesNacimiento, anoNacimiento, grupo;
	bool lider;
	cout<<"Introduzca el DNI del alumno a buscar:"<<endl;
	getline(cin, cadena);
    list<Alumno>::iterator it2, it;
    it2 = alumnos_.begin();
    do{
    	if(it2->getDNI() == cadena) {
    		while(opcion != 11) {
			cout<<"Seleccione el atributo a modificar:"<<endl;
			cout<<"1.Nombre"<<endl;
			cout<<"2.Apellidos"<<endl;
			cout<<"3.DNI"<<endl;
			cout<<"4.Correo"<<endl;
			cout<<"5.Telefono"<<endl;
			cout<<"6.Direccion"<<endl;
			cout<<"7.cursoMasAlto"<<endl;
			cout<<"8.getFechaNacimiento"<<endl;
			cout<<"9.Liderazgo"<<endl;
			cout<<"10.Grupo"<<endl;
			cout<<"11.Salir"<<endl;
			cin>>opcion;
			cin.ignore();
			system("clear");
			switch(opcion) {
				case 1: {
					cout<<"Introduzca el nombre:"<<endl;
					getline(cin, cadena);
					it2->setNombre(cadena);
					cout<<"Nombre modificado correctamente"<<endl;	
					break;
				}
				case 2: {
					cout<<"Introduzca el apellido:"<<endl;
					getline(cin, cadena);
					it2->setApellidos(cadena);
					cout<<"Apellido modificado correctamente"<<endl;	
					break;
				}
				case 3: {
					cout<<"Introduzca el DNI:"<<endl;
					getline(cin, cadena);
					it = alumnos_.begin();
					while(it != alumnos_.end()) {
						if(it->getDNI() == cadena) {
							cout<<"Error ya existe un alumno con el mismo DNI"<<endl;
							encontrado = 1;
						}
						it++;
					}   
					if(encontrado == 0) {
						it2->setDNI(cadena);
						cout<<"DNI modificado correctamente"<<endl;	
					}
					break;
				}
				case 4: {
					cout<<"Introduzca el correo:"<<endl;
					getline(cin, cadena);
					it = alumnos_.begin();
					while(it != alumnos_.end()) {
						if(it->getCorreo() == cadena) {
							cout<<"Error ya existe un alumno con el mismo DNI"<<endl;
							encontrado = 1;
						}
						it++;
					}   
						if(encontrado == 0) {
						it2->setCorreo(cadena);
						cout<<"Correo modificado correctamente"<<endl;
					}
					break;
				}
				case 5: {
					cout<<"Introduza el telefono"<<endl;
					getline(cin, cadena);
					it2->setTelefono(cadena);
					cout<<"Telefono modificado correctamente"<<endl;	
					break;
				}
				case 6: {
					cout<<"Introduza el direccion"<<endl;
					getline(cin, cadena);
					it2->setDireccion(cadena);
					cout<<"Direccion modificada correctamente"<<endl;	
					break;
				}
				case 7: {
					cout<<"Introduza el curso mas alto en el que el alumno esta matriculado"<<endl;
					cin >> curso;
					it2->setCursoMasAlto(curso);
					cout<<"Curso más alto modificado correctamente"<<endl;
					break;
				}
				case 8: {
					cout<<"Introduzca el dia en el que el alumno nacio"<<endl;
					cin>>diaNacimiento;
					cin.ignore();
					cout<<"Introduzca el mes de nacimiento del alumno"<<endl;
					cin>>mesNacimiento;
					cin.ignore();
					cout<<"Introduzca el año de nacimiento del alumno"<<endl;
					cin>>anoNacimiento;
					cin.ignore();
					it2->setFechaNacimiento(diaNacimiento, mesNacimiento, anoNacimiento);
					cout<<"Fecha de nacimiento modificada correctamente"<<endl;					
					break;
				}
				case 9: {
					opcion=0;
					while(opcion!=1 && opcion!=2){
						cout << "1.Lider\n2.No Lider" << endl;
						cin>>opcion;
						cin.ignore();
						if(opcion!=1 && opcion!=2){
						cout << "Error. Seleccione un número correcto" << endl;
						}else{
						if(opcion==1)
						lider=true;
						else
						lider=false;
						}
					}
					if(lider == true) {
						it=alumnos_.begin();
						if((int) alumnos_.size()==1){
							if(it->getGrupo() == it2->getGrupo() && it->getLider() == true) {//Si hay alumnos en el grupo del estudiante insertado y si hay un lider en dicho grupo
								cout << "En este grupo ya hay un lider." << endl;
								cout << "Modificacion no realizada." << endl;
								lider=false;
							}
						}
						else{
							for(it=alumnos_.begin(); it != alumnos_.end(); it++){
								if(it2->getGrupo() == it->getGrupo() && it->getLider() == true) {//Si hay alumnos en el grupo del estudiante insertado y si hay un lider en dicho grupo
								cout << "En este grupo ya hay un lider." << endl;
								cout << "Modificacion no realizada." << endl;
								lider=false;
								}
							}
						}
					}
					it2->setLider(lider);
					cout<<"Liderazgo modificado correctamente"<<endl;	
					break;
				}
				case 10: {
					cout<<"Introduzca el grupo el cual el alumno pertenece"<<endl;
					cin>>grupo;
					it2->setGrupo(grupo);
					cout<<"Grupo modificado correctamente"<<endl;
					break;
				}
				case 11: {
					cout << "Saliendo de Modificar Alumno..." << endl;
					break;
				}
				default: cout<<"Error. Seleccione una opcion disponible"<<endl;
			}
			}
    	}
    	it2++;
	}while(it2 != alumnos_.end());
}
void Alumno::setTelefono(string numero) {
	int p = 0;
	while(p!=1){
		if(strlen(numero.c_str()) <= 15 && strlen(numero.c_str()) >= 7) {//Este criterio segun el estandar ITU-T E.164, definido por el CCITT.
			telefono_ = numero;
			p=1;
		} 
		else {
		cout<<"El numero de telefono introducido es incorrecto"<<endl;
		cout<<"Intentalo de nuevo"<<endl;
		cin>>numero;
		cin.ignore();
		system("clear");
	}
}
}

void Alumno::setGrupo(int grupo) {
	int control = 0;
	while(control != 1) {
		if(grupo < 51 && grupo > 0) {
			grupo_ = grupo;
			control = 1;
		} else {
			cout<<"Numero de grupo fuera de rango (1-50)"<<endl;
			cout<<"Intentalo de nuevo"<<endl;
			cin>>grupo;
			cin.ignore();
			system("clear");
		}
	}
}

void Alumno::setCursoMasAlto(int curso) {
	int control = 0;
	while(control != 1) {
		if(curso > 0 && curso < 5) {//Asumimos que solo hay 4 cursos
			cursoMasAlto_ = curso;
			control = 1;
		} else {
			cout<<"El curso introducido esta fuera de rango (1-4)"<<endl;
			cout<<"Intentalo de nuevo"<<endl;
			cin>>curso;
		}
	}
}
