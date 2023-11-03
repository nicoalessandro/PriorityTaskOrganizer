#include <iostream>
#include <stdio.h> //Uso esta libreria y no <iftream> por fines Académicos
#include <string>
using namespace std;

const char* nombre_archivo = "Lista_de_Tareas.bin";

//PROTOTIPADO:
bool existe_archivo(string);
int primer_ingreso();
int menu(&opcion;);// menu de opciones. Output: Int opcion
int opcion1(const string);// imprimir_tareas()
int opcion2();// actualizar_tareas()
int opcion3();// agregar_tareas()
int salir();
int informa_error();


int main(){
	int opcion=0;
	if (!existe_archivo(nombre_archivo);)
	{
		primer_ingreso();
	}
	while (opcion == 0)
	{//while
		menu(&opcion);
		switch (opcion)
		{//switch
			case 1: opcion = opcion1(); break;
			case 2: opcion = opcion2();break;
			case 3: opcion = opcion3();break;
			case 4: opcion = salir();break;
			default: informa_error();break;
		}//switch
	}//while
	return 0;//mainOutput
}//cierre_main

int primer_ingreso(){//Falta declarar
	// CUERPO DE SENTENCIAS
}//cierre_primer_ingreso

int menu(int &opcion){// FUNCION DECLARADA
	int respuesta;
	cout<<"________MENU________"<<endl<<endl;
	cout<<"Seleccione 1 si desea ejecutar la primera opción"<<endl;
	cout<<"Seleccione 2 si desea ejecutar la segunda opción"<<endl;
	cout<<"Seleccione 3 si desea ejecutar la tercera opción"<<endl;
	cout<<"Seleccione 4 si desea salir"<<endl;
	cout<<"INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA: ";
	cin>>opcion;
	return 0;
}//menu

int opcion1(){//Falta declarar
	// CUERPO DE SENTENCIAS
	cout<<"Ejecutando modulo1"<<endl;
	return 0;
}//cierre_opcion1

int opcion2(){//Falta declarar
	// CUERPO DE SENTENCIAS
	cout<<"Ejecutando modulo2"<<endl;
	return 0;
}//cierre_opcion2

int opcion3(){//Falta declarar
	// CUERPO DE SENTENCIAS
	cout<<"Ejecutando modulo3"<<endl;
	return 0;
}//cierre_opcion3

int salir(){// FUNCION DECLARADA
	cout<<"Ha elegido SALIR DEL PROGRAMA"<<endl;
	return 1;
}//cierre_salir

int informa_error(){//Falta declarar
	// CUERPO DE SENTENCIAS
	return 0;
}//cierre_informa_error

bool existe_archivo(string nombre_archivo){// FUNCION DECLARADA
	/*  <>Input: El Argumento de esta funcion es el nombre del archivo a comprobar.
		<>Output: "1" si habia un archivo existente; "0" FALSE se no habia archivo existente.*/
		
	bool b=0; // Variable de entorno local...
	FILE* pArchivo = fopen(nombre_archivo, "r");
    if (pArchivo) 
	{//if1
        b=1;
        fclose(pArchivo); // Cierra el archivo después de usarlo
        return b;
    } //if1
	else 
	{//else1
        b=0;
        return b;
	}//else1
}//cierre_comprobar_archivo

