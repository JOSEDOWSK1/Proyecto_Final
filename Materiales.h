#ifndef MATERIALES_H
#define MATERIALES_H

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Materiales{
private:
	string codigoMaterial;
	string nombremat;
	string almacen;
	string stock;
	string tipo;
	
public:
	string getCodMaterial();
	void setCodMaterial(string codigoMaterial);
	string getNombreMat();
	void setNombreMat(string nombremat);
	string getAlmacen();
	void setAlmacen(string almacen);
	string getStock();
	void setStock(string stock);
	string getTipo();
	void setTipo(string tipo);
	
}; 

string Materiales::getCodMaterial(){
	return this->codigoMaterial; 
}
void Materiales::setCodMaterial(string codigoMaterial){
	this->codigoMaterial = codigoMaterial;
}
string Materiales::getNombreMat(){
	return this->nombremat;
}
void Materiales::setNombreMat(string nombremat){
	this->nombremat = nombremat;
}
string Materiales::getAlmacen(){
	return this->almacen;
}
void Materiales::setAlmacen(string almacen){
	this->almacen = almacen;
}
string Materiales::getStock(){
	return this->stock;
}
void Materiales::setStock(string stock){
	this->stock = stock;
}
string Materiales::getTipo(){
	return this->tipo;
}
void Materiales::setTipo(string tipo){
	this->tipo = tipo;
}

#endif
