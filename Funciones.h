#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string.h>
#include <fstream>
#include "Datos.h"
#include "Materiales.h"

using namespace std;

void error()
{
	system("color 04");
	cout<<"Error al abrir el archivo de trabajadores, asegurese que el archivo se encuentre en\n";
	cout<<"la misma ubicación que el programa o que el archivo de texto se llame: \n";
	cout<<"trabajador.txt, si el archivo tiene otro nombre renómbrelo al ya mencionado\n\n";
	system("pause");
	system("color 0F");
}
class Funciones{
public:
	bool GuardarTrabajador(Trabajadores persona);
	bool GuardarMaterial(Materiales material);
	Trabajadores GetDatos(string codigo);
	Materiales GetMaterial(string codigomat);
	void ListaMateriales();
	bool EliminarDatos(string auxCodigo);
	Trabajadores PedirDatos(Trabajadores jefe);
	bool ModificarDatos(Trabajadores persona);
	bool RetirarMateriales(string codmataux, int cantidad);
};

bool Funciones::GuardarMaterial(Materiales material){
	ofstream escritura;
	ifstream verificador;
	string auxCodigoMat;
	string codigoMaterial, nombremat, almacen;
	string stock, tipo;
	verificador.open("Almacen.txt",ios::in);
	escritura.open("Almacen.txt",ios::app);
	if(escritura.is_open() && verificador.is_open()){
		fflush(stdin);
		auxCodigoMat = material.getCodMaterial();
		verificador.seekg(0);
		getline(verificador,codigoMaterial);
		while(!verificador.eof()){
			getline(verificador,nombremat);
			getline(verificador,almacen);
			getline(verificador,stock);
			getline(verificador,tipo);
			
			if(codigoMaterial==auxCodigoMat)
			{
				return false;
			}
			
			getline(verificador,codigoMaterial);
		}	
		codigoMaterial = material.getCodMaterial();
		nombremat = material.getNombreMat();
		almacen = material.getAlmacen();
		stock = material.getStock();
		tipo = material.getTipo();
		escritura<<codigoMaterial<<"\n"<<nombremat<<"\n"<<almacen
			<<"\n"<<stock<<"\n"<<tipo;
	}else{
		error();
		return false;
	}
	
	escritura.close();
	verificador.close();
	return true;
}

void Funciones::ListaMateriales(){
	ifstream mostrar;
	mostrar.open("Almacen.txt",ios::in);
	string codigoMaterial, nombremat, almacen, tipo, stock;
	if(mostrar.is_open())
	{
		getline(mostrar,codigoMaterial);
		while(!mostrar.eof())
		{
			getline(mostrar,nombremat);
			getline(mostrar,almacen);
			getline(mostrar,stock);
			getline(mostrar,tipo);
			cout<<"Codigo \t"<<codigoMaterial;
			cout<<"Objeto \t"<<nombremat;
			cout<<"Almacen \t"<<almacen;
			cout<<"Stock \t"<<stock;
			cout<<"Tipo \t"<<tipo;
			cout<<"\n\n";
			getline(mostrar,codigoMaterial);
		}
	}
	else
	{
		error();
	}
	mostrar.close();
	system("pause");
}

bool Funciones::EliminarDatos(string auxCodigo){
	ifstream lectura;
	ofstream auxiliar;
	bool encontrado=false;
	string codigoTrabajador, nombre, dni;
	string estado, rango, hrtr, pago;
	lectura.open("Trabajador.txt",ios::in);
	auxiliar.open("auxiliar.txt",ios::out);
	if(lectura.is_open() && auxiliar.is_open()){
		fflush(stdin);
		getline(lectura,codigoTrabajador);
		while(!lectura.eof()){
			getline(lectura,nombre);
			getline(lectura,dni);
			getline(lectura,estado);
			getline(lectura,rango);
			getline(lectura,hrtr);
			getline(lectura,pago);
			if(auxCodigo==codigoTrabajador){
				encontrado = true;				
			}else{
				auxiliar<<codigoTrabajador<<"\n"<<nombre<<"\n"<<dni<<"\n"<<estado<<"\n"
					<<rango<<"\n"<<hrtr<<"\n"<<pago;
			}
			getline(lectura,codigoTrabajador);
		}
	}else{
		error();
	}
	lectura.close();
	auxiliar.close();
	remove("Trabajador.txt");
	rename("auxiliar.txt","Trabajador.txt");
	return encontrado;
}

bool Funciones::GuardarTrabajador(Trabajadores persona){
	ofstream escritura;
	ifstream verificador;
	string auxCodigo;
	string codigoTrabajador, nombre, dni;
	string estado, hrtr, rango, pago;
	verificador.open("Trabajador.txt",ios::in);
	escritura.open("Trabajador.txt",ios::app);
	if(escritura.is_open() && verificador.is_open()){
		fflush(stdin);
		auxCodigo = persona.getCodTrabajador();
		verificador.seekg(0);
		getline(verificador,codigoTrabajador);
		while(!verificador.eof())
		{
			getline(verificador,nombre);
			getline(verificador,dni);
			getline(verificador,estado);
			getline(verificador,hrtr);
			getline(verificador,rango);
			getline(verificador,pago);
			
			if(codigoTrabajador==auxCodigo)
			{
				return false;
			}
			
			getline(verificador,codigoTrabajador);
		}	
		codigoTrabajador = persona.getCodTrabajador();
		nombre = persona.getNombre();
		dni = persona.getDni();
		estado = persona.getEstado();
		rango = persona.getRango();
		hrtr = persona.getHrtr();
		pago = persona.getPago();
		escritura<<codigoTrabajador<<"\n"<<nombre<<"\n"<<dni
			<<"\n"<<estado<<"\n"<<hrtr<<"\n"<<rango<<"\n"<<pago;
	}else{
		error();
		return false;
	}
	
	escritura.close();
	verificador.close();
	return true;
}

Trabajadores Funciones::GetDatos(string codigo){
	Trabajadores persona = Trabajadores();
	ifstream mostrar;
	string codigoTrabajador, nombre, dni;
	string estado, rango, hrtr, pago;
	bool encontrado=false;
	mostrar.open("Trabajador.txt",ios::in);
	if(mostrar.is_open()){
		fflush(stdin);
		getline(mostrar,codigoTrabajador);
		while(!mostrar.eof()){
			getline(mostrar,nombre);
			getline(mostrar,dni);
			getline(mostrar,estado);
			getline(mostrar,rango);
			getline(mostrar,hrtr);
			getline(mostrar,pago);		
			if(codigo==codigoTrabajador){
				encontrado=true;
				persona.setCodTrabajador(codigo);
				persona.setNombre(nombre);
				persona.setDni(dni);
				persona.setEstado(estado);
				persona.setRango(rango);
				persona.setHrtr(hrtr);
				persona.setPago(pago);
			}
			getline(mostrar,codigoTrabajador);
		}
		if(encontrado==false){
			return Trabajadores();
		}
	}else{
		error();
	}
	mostrar.close();	
	return persona;
}

Materiales Funciones::GetMaterial(string codigomat){
	Materiales material = Materiales();
	ifstream mostrar;
	string codigoMaterial, nombremat, almacen, stock, tipo;
	bool encontrado=false;
	mostrar.open("Almacen.txt",ios::in);
	if(mostrar.is_open()){
		fflush(stdin);
		getline(mostrar,codigoMaterial);
		while(!mostrar.eof()){
			getline(mostrar,nombremat);
			getline(mostrar,almacen);
			getline(mostrar,stock);
			getline(mostrar,tipo);	
			if(codigomat==codigoMaterial){
				encontrado=true;
				material.setCodMaterial(codigomat);
				material.setNombreMat(nombremat);
				material.setAlmacen(almacen);
				material.setStock(stock);
				material.setTipo(tipo);
			}
			getline(mostrar,codigoMaterial);
		}
		if(encontrado==false){
			return Materiales();
		}
	}else{
		error();
	}
	mostrar.close();	
	return material;
}

Trabajadores Funciones::PedirDatos(Trabajadores jefe){
	Funciones funcion = Funciones();
	char opcion;
	string auxcodigo, nombre, dni, auxrango, vercodigo;
	cout<<"Ingrese los siuientes datos del nuevo trabajador: "<<endl;
	cout<<"Codigo de trabajador: ";cin>>auxcodigo;
	Trabajadores persona = funcion.GetDatos(auxcodigo);
	if (persona.getCodTrabajador()!=auxcodigo){
		persona.setCodTrabajador(auxcodigo);
		system("cls");
		cout<<"Codigo de trabajador: "<<auxcodigo;
		cout<<"\n\n";
		cout<<"Nombre: ";
		getline(cin,nombre);
		cout<<"\n\n";
		persona.setNombre(nombre);
		cout<<"DNI: ";
		getline(cin,dni);
		cout<<"\n\n";
		persona.setDni(dni);
		cout<<"\n\n";
		cout<<"Ingrese su rango: ";
		cout<<"\t1. Jefe";
		cout<<"\t2. Gerente";
		cout<<"\t3. Supervisor";
		cout<<"\t4. Obrero";
		cout<<"\t\t\t\t\t\t\t\tELIJA SU OPCION\t ->  ";cin>>opcion;
		auxrango=jefe.getRango();
		switch(opcion){
		case 1:
			if(auxrango=="Jefe"){
				persona.setRango("Jefe");
			}else{
				cout<<"Su rango no es suficiente para ejecutar esta acción";
			}
			break;
		case 2:
			persona.setRango("Gerente");
			break;
		case 3:
			persona.setRango("Supervisor");
			break;
		case 4:
			persona.setRango("Obrero");
			break;
		default:
			cout<<"ERROR: OPCION INGRESADA NO EXISTE";
		}
		if(funcion.GuardarTrabajador(persona)){
			cout<<"El trabajador fue añadido exitosamente"<<endl;
		}else{
			cout<<"Ocurrió un error al guardar los datos del trabajador"<<endl;
		}
		
	}
	system("pause");
	system("cls");
	return persona;
	
}

bool Funciones::ModificarDatos(Trabajadores persona){
	ifstream lectura, verificador;
	ofstream auxiliar;
	string auxCodigo = persona.getCodTrabajador();
	string codigoTrabajador, nombre, dni;
	string estado, rango, hrtr, pago;
	bool respuesta=false;
	lectura.open("Trabajador.txt",ios::in);
	verificador.open("Trabajador.txt",ios::in);
	auxiliar.open("auxiliar.txt",ios::out);
	if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open()){
		fflush(stdin);
		getline(lectura,codigoTrabajador);
		while(!lectura.eof()){
			getline(lectura,nombre);
			getline(lectura,dni);
			getline(lectura,estado);
			getline(lectura,rango);
			getline(lectura,hrtr);
			getline(lectura,pago);
			if(codigoTrabajador == auxCodigo)
			{
				codigoTrabajador = persona.getCodTrabajador();
				nombre = persona.getNombre();
				dni = persona.getDni();
				estado = persona.getEstado();
				rango = persona.getRango();
				hrtr = persona.getHrtr();
				pago = persona.getPago();
				respuesta = true;
			}
			auxiliar<<codigoTrabajador<<"\n"<<nombre<<"\n"<<dni
			   <<"\n"<<estado<<"\n"<<rango<<"\n"
			   <<hrtr<<"\n"<<pago<<"\n";
			
			getline(lectura,codigoTrabajador);
		}
	}else{
		error();
		return false;
	}
	lectura.close();
	auxiliar.close();
	verificador.close();
	remove("Trabajador.txt");
	rename("auxiliar.txt","Trabajador.txt");
	return respuesta;
}

#include <iostream>
#include <string.h>
#include <fstream>
#include "Datos.h"
#include "Materiales.h"
using namespace std;


bool Funciones::RetirarMateriales(string codmataux, int cantidad){
	ifstream lectura, verificador;
	ofstream auxiliar;
	string codigoMaterial, nombremat, almacen;
	string stock, tipo;
	int intstock;
	Materiales material = Materiales();
	bool respuesta=false;
	lectura.open("Almacen.txt",ios::in);
	verificador.open("Almacen.txt",ios::in);
	auxiliar.open("auxiliar.txt",ios::out);
	GetMaterial(codmataux);
	material = GetMaterial(codmataux);
	
		if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open()){
		fflush(stdin);
		getline(lectura,codigoMaterial);
		while(!lectura.eof()){
			getline(lectura,nombremat);
			getline(lectura,almacen);
			getline(lectura,stock);
			getline(lectura,tipo);
			if(codigoMaterial == codmataux)
			{
				intstock = stoi(material.getStock()) + cantidad;
				codigoMaterial = material.getCodMaterial();
				nombremat = material.getNombreMat();
				almacen = material.getAlmacen();
				stock = to_string(intstock);
				tipo = material.getTipo();
				respuesta = true;
			}
			auxiliar<<codigoMaterial<<"\n"<<nombremat<<"\n"<<almacen
			   <<"\n"<<stock<<"\n"<<tipo<<"\n";
			
			getline(lectura,codigoMaterial);
		}
	}else{
			return false;
		}
		lectura.close();
		auxiliar.close();
		verificador.close();
		remove("Almacen.txt");
		rename("auxiliar.txt","Almacen.txt");
		return respuesta;
}

	
#endif
