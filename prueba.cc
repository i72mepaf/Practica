#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
using namespace std;
class Profesor{
	public:
	string DNI_;
	string Rol_;
};
struct Conv
{
	char dni[100];
	char rol[100];
};

int main(int argc, char const *argv[])
{
	Profesor p1;
	Conv c1;
	p1.DNI_="1111";
	p1.Rol_="Coordinador";
	strcpy(c1.dni, p1.DNI_.c_str());
	strcpy(c1.rol, p1.Rol_.c_str());
	ofstream c( "credenciales.bin", ios::binary );
	if ( c.is_open() ) {
		c.write((char*)&c1, sizeof(Conv));
	} 
	else{ cout << "Error de apertura de archivo." << endl;}
	c.close();

	strcpy(c1.dni, "AAAAAAAAAAAA");
	strcpy(c1.rol, "XXXXXXXXXX");

	ifstream f("credenciales.bin", ios::binary);
	if (f.is_open()){
			f.read((char*)&c1, sizeof(Conv));
	} 
	else {cout << "Error de apertura de archivo." << endl;}
	f.close();

	cout << "DNI y Rol introducidos: "<< p1.DNI_ <<" "<< p1.Rol_<< endl;
	cout << "DNI y Rol leidos: "<< c1.dni <<" "<< c1.rol << endl;
	return 0;
}