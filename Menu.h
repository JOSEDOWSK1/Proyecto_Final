#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "Datos.h"
#include "Materiales.h"
#include "Funciones.h"
using namespace std;


class Menu{
public:
	string Pre_Menu();
	int MenuPrincipal(Trabajadores persona);
	char MenuTrabajadores(Trabajadores persona);
	char BuscarTrabajador();
	char NuevoTrabajador();
	char EliminarTrabajador();
	string MenuRetirar_Objetos();
	void MenuMarcaciones(Trabajadores persona);
	char MenuPago(Trabajadores persona);
	char MenuAgregar_Objetos(Trabajadores persona);
};

string Menu::Pre_Menu(){
	string auxcodigo;
	Trabajadores persona;
	Funciones funcion = Funciones();
	cout<<"Ingrese su codigo para identificarse: ";cin>>auxcodigo;
	persona = funcion.GetDatos(auxcodigo);
	if (persona.getCodTrabajador()==auxcodigo){
		return auxcodigo;
	}else{
		return "0";
	}
}

int Menu::MenuPrincipal(Trabajadores persona){
	int opcion;
	cout<<endl;
	system("cls");
	cout<<"\t\t\t\tWEB PARA TRABAJADORES DE LA EMPRESA"<<"\n"<<"\n";
	cout<<persona.getNombre()<<"\t"<<persona.getCodTrabajador(); 
	cout<<endl;
	cout<<"1. Trabajador:"<<endl;
	cout<<"2. Marcaciones:"<<endl;
	cout<<"3. Retirar objetos:"<<endl;
	cout<<"4. Pago:"<<endl;
	cout<<"5. Salir:\n"<<endl;
	if( persona.getRango()=="Jefe"){
		cout<<"6. Agregar objetos: "<<endl;
	}
	cout<<"\t\t\t\t\t\t\t\tELIJA SU OPCION\t ->  ";cin>>opcion;
	return opcion;
}

char Menu::MenuTrabajadores(Trabajadores persona){
	char opcion;
	system("cls");
	cout<<"******************"<<endl;
	cout<<"* TRABAJADORES : *"<<endl;
	cout<<"******************\n"<<endl;
	cout<<"\ta. BUSCAR TRABAJADOR"<<endl;
	//cout<<"\tb. LISTA DE LOS TRABAJADORES"<<endl;
	if (persona.getRango()=="Jefe" || persona.getRango()=="Gerente"){
		cout<<"\tc. NUEVO TRABAJADOR"<<endl;
		cout<<"\td. ELIMINAR TRABAJADOR"<<endl;
		cout<<"\te. MODIFICAR INFORMACION DE TRABAJADOR"<<endl;
	}
	cout<<"\t\t\t\t\t\t\t\tELIJA SU OPCION\t ->  ";cin>>opcion;
	if (opcion!='a'){
		if(persona.getRango()!="Jefe" || persona.getRango()!="Gerente"){
			cout<<"ERROR: Opcion ingresada incorrecta"<<endl;
		}
	}
	
	return opcion;
} 
char BuscarTrabajador(){
	char opcion;
	system("cls");
	cout<<"***********************"<<endl;
	cout<<"* BUSCAR TRABAJADOR : *"<<endl;
	cout<<"***********************\n"<<endl;
	cout<<"a. Buscar por nombre: "<<endl;
	cout<<"b. Buscar por codigo: "<<endl;
	cout<<"\t\t\t\t\t\t\t\tELIJA SU OPCION\t ->  ";cin>>opcion;
	return opcion;
}
void NuevoTrabajador(){
	system("cls");
	cout<<"**********************"<<endl;
	cout<<"* NUEVO TRABAJADOR : *"<<endl;
	cout<<"**********************\n"<<endl;
}
		
char EliminarTrabajador(){
	char opcion;
	system("cls");
	cout<<"***********************" <<endl;
	cout<<"* ELIMINAR TRABAJADOR *" <<endl;
	cout<<"***********************\n" <<endl;
	cout<<"a. Buscar por nombre: "<<endl;
	cout<<"b. Buscar por codigo: "<<endl;
	cout<<"\t\t\t\t\t\t\t\tELIJA SU OPCION\t ->  ";cin>>opcion;
	return opcion;
}	
char EditarTrabajador(){
	char opcion;
	system("cls");
	cout<<"*********************" <<endl;
	cout<<"* EDITAR TRABAJADOR *" <<endl;
	cout<<"*********************\n" <<endl;
	cout<<"a. Buscar por nombre: "<<endl;
	cout<<"b. Buscar por codigo: "<<endl;
	cout<<"\t\t\t\t\t\t\t\tELIJA SU OPCION\t ->  ";cin>>opcion;
	return opcion;
}
void Menu::MenuMarcaciones(Trabajadores persona){
	string estado;
	Funciones funcion = Funciones();
	int h1,m1,h2,m2;
	estado = persona.getEstado();
	system("cls");
	if(estado=="Fuera de servicio"){
		cout<<"*****************"<<endl;
		cout<<"* MARCACIONES : *"<<endl;
		cout<<"*****************\n"<<endl;
		cout<<"\tIngrese hora de entrada (hh mm):  ";cin>>h1; cin>>m1;
		system("cls");
		cout<<"\n\tSU HORA DE ENTRADA ES: "<<h1<<":"<<m1<<endl<<endl;
		cout<<"\tYA SE ENCUENTRA EN SERVICIO";
		persona.setEstado("En servicio");
		funcion.ModificarDatos(persona);
		system("pause");
	}
	if(estado=="En servicio"){
		cout<<"*****************"<<endl;
		cout<<"* MARCACIONES : *"<<endl;
		cout<<"*****************\n"<<endl;
		cout<<"\tIngrese hora de salida (hh mm):  ";cin>>h2; cin>>m2; 
		system("cls");
		cout<<"\tSU HORA DE SALIDA ES: "<<h2<<":"<<m2;
		cout<<"\tYA NO SE ENCUENTRA EN SERVICIO";
		persona.setEstado("Fuera de servicio");
		funcion.ModificarDatos(persona);
		system("pause");
	}
}

char Menu::MenuPago(Trabajadores persona){
	char opcion;
	system("cls");
	cout<<"***********"<<endl;
	cout<<"* PAGOS : *"<<endl;
	cout<<"***********\n"<<endl;
	cout<<"a. INFORMACION DE LA CUENTA\n"<<endl;
	//cout<<"b. RETIRAR DINERO DE LA CUENTA\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\tELIJA SU OPCION\t ->  ";cin>>opcion;
	return opcion;
}

string MenuRetirar_Objetos(){
	string auxcodmat;
	system("cls");
	Funciones funcion = Funciones();
	funcion.ListaMateriales();
	cout<<"\t\t\t\t\t\t\tIngrese el codigo del material\t ->  ";cin>>auxcodmat;
	return auxcodmat;
}
					
char Menu::MenuAgregar_Objetos(Trabajadores persona){
	char opcion;
	system("cls");
	cout<<"a. Agregar stock\n"<<endl;
	cout<<"b. Agregar objetos\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\tELIJA SU OPCION\t ->  ";cin>>opcion;
	return opcion;
}
#endif	
