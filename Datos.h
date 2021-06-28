#ifndef DATOS_H
#define DATOS_H

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Trabajadores{
private:
	string codigoTrabajador;
	string nombre;
	string dni;
	string estado = "Fuera de servicio";
	string hrtr;
	string pago;
	string rango;

public:
	string getCodTrabajador();
	void setCodTrabajador(string codigo);
	string getNombre();
	void setNombre(string nombre);
	string getDni();
	void setDni(string Dni);
	string getEstado();
	void setEstado(string estado);
	string getRango();
	void setRango(string rango);
	string getPago();
	void setPago(string pago);
	string getHrtr();
	void setHrtr(string hrtr);
	
}; 

string Trabajadores::getCodTrabajador(){
	return this->codigoTrabajador; 
}
void Trabajadores::setCodTrabajador(string codigo){
	this->codigoTrabajador = codigo;
}
string Trabajadores::getNombre(){
	return this->nombre;
}
void Trabajadores::setNombre(string nombre){
	this->nombre = nombre;
}
string Trabajadores::getDni(){
	return this->dni;
}
void Trabajadores::setDni(string dni){
	this->dni = dni;
}
string Trabajadores::getEstado(){
	return this->estado;
}
void Trabajadores::setEstado(string estado){
	this->estado = estado;
}
string Trabajadores::getRango(){
	return this->rango;
}
void Trabajadores::setRango(string rango){
	this->rango = rango;
}
string Trabajadores::getHrtr(){
	return this->codigoTrabajador; 
}
void Trabajadores::setHrtr(string hrtr){
	this->hrtr = hrtr;
}
string Trabajadores::getPago(){
	return this->codigoTrabajador; 
}
void Trabajadores::setPago(string pago){
	this->pago = pago;
}

#endif
