#include <iostream>
#include <stdio.h>
#include <string>
#include "Datos.h"
#include "Menu.h"
#include "Materiales.h"
#include "Funciones.h"
using namespace std;

int main(int argc, char *argv[]) {
	cout<<"****************************************"<<endl;
	cout<<"///////////////BIENVENIDO///////////////"<<endl;
	cout<<"****************************************"<<endl;
	cout<<" "<<endl;
	int opcion1;
	Materiales material;
	Trabajadores persona;
	Menu menu = Menu();
	Funciones funcion = Funciones();
	string auxcodigo = menu.Pre_Menu();
	system("cls");
	
	if(auxcodigo!="0"){
		persona=funcion.GetDatos(auxcodigo);
		do{
			system("cls");
			switch(menu.MenuPrincipal(persona)){
				system("cls");
			case 1: //Menu Trabajadores
				switch(menu.MenuTrabajadores(persona)){
					system("cls");
				case 'a'://Buscar Trabajadores
					switch(BuscarTrabajador()){
					case 'a'://Buscar Por Nombre
						
						break;
					case 'b'://Buscar Por Codigo
						
						break;
					}
				case 'b'://Imprimir Lista de Trabajadores
											
				case 'c'://Agregar Nuevo Trabajador
					if(persona.getRango()=="Jefe"|| persona.getRango()=="Gerente"){
						//FUNCION AGREGAR
						
					}else{
						cout<<"Opcion incorreta";
					}
					break;
				case 'd'://Eliminar Trabajador
					if(persona.getRango()=="Jefe"|| persona.getRango()=="Gerente"){
						//FUNCION ELIMINAR
					}else{
						cout<<"Opcion incorreta";
					}
					break;
				case 'e'://Modificar Trabajador
					if(persona.getRango()=="Jefe"|| persona.getRango()=="Gerente"){
						//FUNCION MODIFICAR
					}else{
						cout<<"Opcion incorreta";
					}
					break;
				} 
				system("pause");
				system("cls");
				break;
			case 2://Menu Marcaciones
				menu.MenuMarcaciones(persona);
				system("pause");
				system("cls");
				break;          
				
			case 3://Funcion Retirar Objetos
				MenuRetirar_Objetos();
				system("pause");
				system("cls");
				break;                   
			case 4://Funcion Pago
				switch(menu.MenuPago(persona)){
				case 'a'://Informacion de la Cuenta
					
				case 'b'://Retirar Dinero de la Cuenta
					system("pause");
					system("cls");
					break;
				}
			case 5://Salir
				return 0;
			}
			
			
			
			
		}while(opcion1!=6);
		return 0;
	}
	
}
