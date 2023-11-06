#include <iostream>
#include <stdio.h> //Uso esta libreria y no <iftream> por fines Académicos
#include <string>

using namespace std;

const string nombre_archivo = "Lista_de_Tareas.bin";
//const int max_tarea=125;
const int max_venc=11;

//STRUCTS:
struct tarea{
	//char tarea[max_tarea];
	string tarea;//------->RECORDAR QUE PARA RECORRER ARCHIVO HABRA QUE GUARDAR EL TAMAÑO DE LECTURA DE LOS STRINGS... O RECORRER LAS CADENAS HASTA EL '\0'
	char vencimiento[max_venc];
};
struct nodo{
	nodo * siguiente=NULL;
	tarea tarea_registrada;
};

//PROTOTIPADO:
bool existe_archivo(const string);
nodo * primer_ingreso();
//_____ACTUALIZAR_ESTADO_SEGUN_FECHA_ACTUAL()
int menu(int &);// menu de opciones. Output: Int opcion
int opcion1();//const string);// AGREGAR TAREAS
int opcion2(nodo *);// VER SIGUIENTE/LISTA ENTERA
int opcion3();// ACTUALIZAR TAREAS (CAMBIAR PRIORIDADES, TAREAS FINALIZADAS, )
int salir();
int agregar_tarea(tarea &);
int insertarOrdenadoPers(nodo* &);
int informa_error();
int ImprimirListaPueba(nodo*);

/*
Notas de Commit:
Def: struct nodo;const int max_venc; erroresDeCodigo-- , Documentacion++, declaFunciones:primer_ingreso(),agregar_tarea(),insertarOrdenadoPers(),ImprimirListaPueba();
Notas de Version: En principio el modelo sera basico, el orden sera implementado por el usuario en la lista de tareas por medio de comparaciones binarias.
Futuros cambios:
>Las tareas se organizaran por comparaciones binarias y por comparacion de parametros.
>Las tareas podrian relacionarse por Arboles en caso de haber dependencias de tareas.
>El la cantidad de caracteres en las tareas pordria ser libre usando la clase string y adecuando la lecto/escritura del archivo con una variable
que indique la longitud de caracteres de cada cadena guardada.
>revisar bugs...
*/
int main(){
	int opcion=0;
	nodo * lista=NULL;
	if (!existe_archivo(nombre_archivo)){
		lista = primer_ingreso();
	}
	while (opcion == 0){
		menu(opcion);
		switch (opcion){
			case 1: opcion = opcion1(); break;
			case 2: opcion = opcion2(lista);break;
			case 3: opcion = opcion3();break;
			case 4: opcion = salir();break;
			default: informa_error();break;
		}//switch
	}//while
	return 0;//mainOutput
}//cierre_main

nodo * primer_ingreso(){//Falta Terminar de DECLARAR____________________<!!!!>_____________return nodo*
	char r='a';
	int c=0;
	nodo * tasklist = NULL; //-----lista o Nodo inicial
	cout<< "Aun no se han ingresado tareas a la <lista de tareas pendientes>"<<endl;
	cout << "Presiona Enter para continuar..."<<endl;
	cin.get();  // Espera a que se presione Enter
	while (r!='e'&&c<10){
		c++;
		system("cls");
		cout<<"Si desea ingresar una tarea a la lista presione 'y', de los contrario 'e' para salir: "<<endl;
		cin>>r;
		if (r=='y'){
			if (tasklist==NULL){//En caso de tratarse del primer elemento...
				tasklist = new nodo;
				agregar_tarea(tasklist->tarea_registrada);
				tasklist->siguiente= NULL;
			}
			else{//En el caso del segundo elemento en adelante...
				insertarOrdenadoPers(tasklist);
			}
		}
	}
	return tasklist;//----------------------->return tasklist_______ESTO ES PROVISORIO HASTA GRABAR EL PRIMER ARCHIVO
}//cierre_primer_ingreso
	/*
	2_DO: Hacer la siguiente pregunta hasta salir del programa:
		Desea ingresar una tarea o salir? <LISTO>
			SI:{
				>>Caso de la Primera Tarea: <LISTO>
					Crear lista e ingresar primera tarea a la lista. <LISTO>
				>>A Partir de la Segunta Tarea: <LISTO>
					Inserar ordenado, El criterio de orden es decision por comparacion de usuario. <LISTO>
				}
			SALIR:{------------------>         <FALTA>
				>>Lista vacia:
					Imprime mensaje--> Aun no se han incorporado tareas, por lo tanto no hay Tareas pendientes...
				>>Lista con elementos:
					Se crea archivo con lista de tareas.
					Iteracion:
						Se presentan elementos de la lista de forma ordenada.
						Se graban los elementos mostrados en el archivo.
					Se cierra el archivo.
			}
	3_Informe de errores?
	*/


int menu(int &opcion){// FUNCION DECLARADA
	system("cls");
	cin.ignore();
	cout<<"________MENU________"<<endl<<endl;
	cout<<"Seleccione 1 si sos de C&S"<<endl;
	cout<<"Seleccione 2 imprimir lista de prueba (funcionamiento provisorio)"<<endl;
	cout<<"Seleccione 3 si desea ejecutar la tercera opcion (no definida)"<<endl;
	cout<<"Seleccione 4 si desea salir"<<endl;
	cout<<"INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA: ";
	cin>>opcion;
	return 0;
}//menu

int opcion1(){//Falta declarar
	/*______________AGREGAR TAREAS_____________
	Este modulo tiene que agregar tareas y objetivos nuevos.
	Supone que la lista ya tiene tareas porque el primer metodo que las agrega es primer_ingreso():
	Por lo que en un principio mostrara la lista actual, para luego preguntar en donde se incertara la nueva tarea según la urgencia o necesidad aparente.
	Imprimiendo la lista y preguntando al usuario en medio de cuales tareas se debe incertar la tarea actual y con cuales objetivos se relacionan estas tareas.
	El orden es por lo pronto una aproximación, luego se evaluara si la posicion es correcta por medio de Actualizar*/
	system("cls");  // Borra la pantalla en Windows (usa "clear" en sistemas Unix/Linux)
	cin.ignore();
    cout << "Ejecutando modulo1:" << endl<< endl;
	cout << "Deberian solicitar una entrevista conmigo (Nicolas Barreiro)..." << endl;
	cout << "Asi les puedo contar los beneficios que podrian obtener al contratarme;" << endl;
	cout << "Les comento un par de ideas locas que tengo..." << endl;
	cout << "Y cuales son mis planes de negocio;" << endl;
	cout << "Capaz me contraten y saquemos algunos de ellos adelante. Uno nunca sabe..." << endl<< endl;
	cout << "Me gustaria trabajar con Uds..." << endl;
    cout << "Presiona Enter para continuar..."<<endl;
	cin.get();  // Espera a que se presione Enter
    system("cls");
    return 0;
}//cierre_opcion1

int opcion2(nodo * lista){//Falta declarar
	/*___________________VER SIGUIENTE/S__________________________
	este modulo es una presentacion de resultados. En el se podra ver la lista para informarse de las tareas perndientes y los objetivos perseguidos actuales.
	El primer supuesto es que uno puede ver N tareas que encabezan la lista de tareas urgentes o la totalidad de la lista
	A su vez y con que objetivos estan relacionadas*/
	system("cls");  // Borra la pantalla en Windows (usa "clear" en sistemas Unix/Linux)
    cout << "_______________Ejecutando modulo2___________" << endl;
    cout << "Esta presentacion de resultados es solamente de Prueba..." << endl;
    ImprimirListaPueba(lista);
    cin.ignore();
    cout << "Presiona Enter para continuar..."<<endl;
	cin.get();  // Espera a que se presione Enter
    system("cls");
    return 0;
}//cierre_opcion2

int opcion3(){//Falta declarar
	// CUERPO DE SENTENCIAS
	system("cls");  // Borra la pantalla en Windows (usa "clear" en sistemas Unix/Linux)
    cout << "Ejecutando modulo3" << endl;
    cin.ignore();
    cout << "Presiona Enter para continuar..."<<endl;
	cin.get();  // Espera a que se presione Enter
	system("cls");
    return 0;
}//cierre_opcion3

int salir(){// FUNCION DECLARADA
	system("cls");  // Borra la pantalla en Windows (usa "clear" en sistemas Unix/Linux)
	cout<<"Ha elegido SALIR DEL PROGRAMA"<<endl<<endl;
	return 1;
}//cierre_salir

int informa_error(){//Falta declarar
	// CUERPO DE SENTENCIAS
	return 0;
}//cierre_informa_error

bool existe_archivo(const string nombre_archivo) { //FUNCION ACTUALIZADA
    FILE* pArchivo = fopen(nombre_archivo.c_str(), "rb");
    if (pArchivo) {
        fclose(pArchivo);
        return true;
    }
    return false;
}//cierre existe_archivo()

int agregar_tarea(tarea &registro){//FUNCION DECLARADA
	/*---------------------------------------------------------------------------------------------------------------------
	Esta funcion recive una variable tipo tarea y en el completa los campos de tarea y vencimiento,
	solicitandocelos al usuario.
	----------------------------------------------------------------------------------------------------------------------*/
	//Declaracion de variables locales:
	char r='a';
	int c=0;
	//Se indica al usuario que de entrada a una tarea:
	cout<<"Escriba la tarea que quiere agregar a la lista y luego presione <Enter> para finalizar: ";
	//La tarea se asigna al campo tarea del struc apuntado por el nodo al que pasamos como argumento.
	cin.ignore();
	getline(cin, registro.tarea);
	cin.ignore();
	do{//Hasta que ingrese entrada valida o realice 3 intentos invalidos.
		cout<<"Su tarea tiene fecha de vecimiento?('y' para si y 'n' para no): ";// DE ACA SALTA... EN LA PRIMERA VUELTA PREGUNTA SI QUERES INGRESAR OTRA TAREA Y EN LA SEGUNDA SALTA VALOR INCORRECTO
		r=cin.get();
		if (r!='y' && r!='n' && c<3){//Si la respuesta es invalida y no se alcanzaron los 3 intentos
			cout<<endl<<"Intento Nro"<<c<<":  El valor ingresado a sido incorrecto. Vuelva a intentarlo"<<endl;
			c++;
			r='a';
		}
		else if (c==3){
			cout<<"Ha intentado varias veces, se tomara como respuesta default que no...";
			r='n';
		}
		cout << "Presiona Enter para continuar..."<<endl;
		cin.get();
	}while(r!='y' && r!='n' && c<3);
	if (r == 'y') {
        cout << "A continuacion ingrese la fecha de vencimiento de su tarea (en formato dd/mm/aaaa): ";
        cin>>registro.vencimiento;
	}
	else{
		registro.vencimiento[0]='\0';
	}
	return 0;
}//cierre agregar_tarea

int insertarOrdenadoPers(nodo* &lista){
	/*--------------------------------------------------------------------------------------------------------------------------------
	Esta funcion debe recivir como argumento el nodo inicial de la lista.
	Luego debe solicitar al usuario la tarea a registrar y ordenarla comparandola con otras tareas.
	----------------------------------------------------------------------------------------------------------------------------------*/
	char r='a';
	nodo* nodo_l = lista;
	nodo* nodo_n = new nodo; // direccion de un nuevo nodo para el registro
	agregar_tarea(nodo_n->tarea_registrada);//Se le pregunto al usuario por la nueva tarea.
	while(nodo_l!=NULL){
		cout<<"Si la Tarea ingresada tiene mas prioridad que:"<<endl;
		cout<<"<<< "<<nodo_l->tarea_registrada.tarea;
		if (nodo_l->tarea_registrada.vencimiento!=NULL){
			cout<<" >>>........que tiene vencimiento el dia: "<<nodo_l->tarea_registrada.vencimiento<<endl;
		}
		cout<<"Entonces ingrese 'y' de lo contrario presione otra cosa..."<<endl;
		r=cin.get();
		if(r=='y' && nodo_l==lista){// Es mas prioritario que el primero por lo que debe encavezar la lista.
			nodo_n->siguiente = lista;
			lista = nodo_n;
		}
		else if(r=='y'){
			nodo_n->siguiente = nodo_l;// tienen mayor prioridad (segundo o mas) y se inserta...
			nodo_l = nodo_n;
		}
		else{
			if(nodo_l->siguiente!=NULL){ 
				nodo_l->siguiente=nodo_n;//LLego al ultimo, se coloca al final...
			}
			else{
				nodo_l = nodo_l->siguiente;//Aun no se inserto, se compara con el siguiente...
			}
		}
	}
	return 0;
}//cierre comparacion_binaria

int ImprimirListaPueba(nodo*lista){//-------------------------Funcion de Pruebas 
	int c=0;
	nodo*NodoImprimir = lista;
	cout<<"____________LISTA DE TAREAS_____________"<<endl<<endl;
	while(NodoImprimir!=NULL){
		c++;
		cout<<"La tarea N°"<<c<<" es: "<<lista->tarea_registrada.tarea;
		if (lista->tarea_registrada.vencimiento!=NULL){
			cout<<"....que vence el dia: "<<lista->tarea_registrada.vencimiento<<endl;
		}
		NodoImprimir = NodoImprimir->siguiente;
	}//cierre while
	return 0;
}//cierre ImprimirListaPrueba
/*

*/
