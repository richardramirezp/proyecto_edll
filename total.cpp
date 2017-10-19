#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo));
//Estructura Nodo
struct Nodo{
	int dato;
	Nodo *siguiente;
};
//Variables Globales
Nodo *pila;
int dato;
int opc;
int valor;
FILE *archivo;
int cantDatos;
//Prototipo funciones Pila
void Insertar_Elemento();
void Quitar_Elemento();
bool Pila_Vacia();
void Mostrar_Elementos();
bool Buscar_Elemento();
void Quitar_Elementos();
void Editar_Elemento();
void Ordenar_Elemento();
void Salvar_Elementos();
void Estado_Pila();
//Fuinciones Colas
void generarDatos(Nodo *&, Nodo *&);
void insertarDatosCola(int, Nodo *&, Nodo *&);
void ordenarDatos(Nodo *);
void imprimirDatos(Nodo *);
void Eliminar_ElementoCola(Nodo *&,Nodo *&);
void Quitar_ElementoCola( Nodo *&, Nodo *&, int );
void Buscar_ElementoCola(Nodo *, Nodo *);
bool Cola_Vacia(Nodo *);
void Editar_ElementoCola(Nodo *&, Nodo *&);
void Salvar_ElementosCola(Nodo *&);
void Estado_Cola(Nodo *);
//Funciones Recolecion de datos
void Pedir_Dato();
void Cargar();
void Generar();
//Funcione DE Ordenamiento
void Burbuja();
void Rapido();
//Prototipos Menus
void Menu();
void Menu_Eliminar();
void Menu_Principal();
void Menu_Generar();
void Menu_Cargar();
void Menu_Ordenar();
void Menu_EliminarCola(Nodo *, Nodo *, int);
void Menu_Generar(Nodo *&, Nodo *&);
//Funcion Principal
int main(){
	Menu_Principal();
}
//Funcion Menu Principal
void Menu_Principal(){
	do{
		printf("*******************\n");
		printf("+ Menu Principal  +\n");
		printf("*******************\n");
		printf("+                 +\n");
		printf("+   1. Pila.      +\n");
		printf("+   2. Cola.      +\n");
		printf("+   0. Salir      +\n");
		printf("+                 +\n");
		printf("*******************\n");
		printf("\nQue deceas hacer: ");
		scanf("%d",&opc);
		system("cls");
		switch(opc){
			case 0:exit(0);
				break;
			case 1:Menu();
				break;
			case 2:Menu();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opc != 0);
}
//Funcion Menu Pila
void Menu(){
	Nodo *inicio = NULL;
	Nodo *fin = NULL;
	int opcion;
	do{
		printf("*******************************\n");
		printf("+            Menu             +\n");
		printf("*******************************\n");
		printf("+                             +\n");
		printf("+   1. Generar Elementos.     +\n");
		printf("+   2. Cargar Elementos.      +\n");
		printf("+   3. Mostrar Elementos.     +\n");
		printf("+   4. Eliminar Elementos.    +\n");
		printf("+   5. Buscar Elementos.      +\n");
		printf("+   6. Editar Elemento.       +\n");
		printf("+   7. Ordenar Elementos.     +\n");
		printf("+   8. Salvar Elementos.      +\n");
		printf("+   9. Estado.                +\n");
		printf("+   0. Salir                  +\n");
		printf("+                             +\n");
		printf("*******************************\n");
		printf("\nQue deceas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		if(opc == 1){
			switch(opcion){
				case 0:Menu_Principal();
					break;
				case 1:Menu_Generar();
					break;
				case 2:Menu_Cargar();
					break;
				case 3:Mostrar_Elementos();
					break;
				case 4:Menu_Eliminar();
					break;
				case 5:Buscar_Elemento();
					break;
				case 6:Editar_Elemento();
					break;
				case 7:Menu_Ordenar();
					break;
				case 8:Salvar_Elementos();
					break;
				case 9:Estado_Pila();
					break;
				default:printf("Numero Equivocado!\n");
					break;
			}
		}
		else{
			switch(opcion){
				case 1:Menu_Generar(inicio,fin);
					break;
				case 2:
					break;
				case 3:imprimirDatos(inicio);
					break;
				case 4:Menu_EliminarCola(inicio,fin,dato);
					break;
				case 5:Buscar_ElementoCola(inicio,fin);
					break;
				case 6:Editar_ElementoCola(inicio,fin);
					break;
				case 7:ordenarDatos(inicio);
					break;
				case 8:Salvar_ElementosCola(inicio);
					break;
				case 9:Estado_Cola(inicio);
					break;
				case 0:Menu_Principal();
					break;
				default:printf("Numero Equivocado\n");
			}
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion Menu Pila
void Menu_Generar(){
	int opcion;
	do{
		printf("*******************************\n");
		printf("+         Menu Generar        +\n");
		printf("*******************************\n");
		printf("+                             +\n");
		printf("+   1. 1000000                +\n");
		printf("+   2. 2000000                +\n");
		printf("+   3. 5000000                +\n");
		printf("+   4. 10000000               +\n");
		printf("+   5. 20000000               +\n"); 
		printf("+   0. Salir                  +\n");
		printf("+                             +\n");
		printf("*******************************\n");
		printf("\nQue deceas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 0:Menu();
				break;
			case 1:valor = 1000000;
				Generar();
				break;
			case 2:valor = 2000000;
				Generar();
				break;
			case 3:valor = 5000000;
				Generar();
				break;
			case 4:valor = 10000000;
				Generar();
				break;
			case 5:valor = 20000000;
				Generar();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion Menu Cargar
void Menu_Cargar(){
	int opcion;
	do{
		printf("*******************************\n");
		printf("+         Menu Cargar         +\n");
		printf("*******************************\n");
		printf("+                             +\n");
		printf("+   1. 1000000.               +\n");
		printf("+   2. 2000000.               +\n");
		printf("+   3. 5000000.               +\n");
		printf("+   4. 10000000.              +\n");
		printf("+   5. 20000000.              +\n"); 
		printf("+   6. Elementos Salvados.    +\n"); 
		printf("+   0. Salir                  +\n");
		printf("+                             +\n");
		printf("*******************************\n");
		printf("\nQue deceas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 0:Menu();
				break;
			case 1:	archivo = fopen("Unmillon.txt", "r");
				Cargar();
				break;
			case 2:archivo = fopen("Dosmillon.txt", "r");
				Cargar();
				break;
			case 3:archivo = fopen("Cincomillon.txt", "r");
				Cargar();
				break;
			case 4:archivo = fopen("Diezmillon.txt", "r");
				Cargar();
				break;
			case 5:archivo = fopen("Veintemillon.txt", "r");
				Cargar();
				break;
			case 6:archivo = fopen("Pila.txt","r");
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion Menu Eliminar
void Menu_Eliminar(){
	int opcion;
	do{
		printf("********************************\n");
		printf("+         Menu Eliminar        +\n");
		printf("********************************\n");
		printf("+                              +\n");
		printf("+   1. Eliminar Todo.          +\n");
		printf("+   2. Eliminar un elemento.   +\n");
		printf("+   0. Salir.                  +\n");
		printf("+                              +\n");
		printf("********************************\n");
		printf("\nQue Deseas Hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:Quitar_Elementos();
				break;
			case 2:Quitar_Elemento();
				break;
			case 0:Menu();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion Menu Ordenar
void Menu_Ordenar(){
	int opcion;
	do{
		printf("***********************\n");
		printf("+   Menu Ordenamiento +\n");
		printf("***********************\n");
		printf("+                     +\n");
		printf("+   1. Burbuja.       +\n");
		printf("+   2. Rapido.        +\n");
		printf("+   0. Salir.         +\n");
		printf("+                     +\n");
		printf("***********************\n");
		printf("\nQue Deseas Hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:Burbuja();
				break;
			case 2:Rapido();
				break;
			case 0:Menu();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion de insertar elemento en la pila
void Insertar_Elemento(){
	Nodo *elemento = reservar_memoria;
	elemento->dato = dato;
	elemento->siguiente = pila;
	pila = elemento;
	if(elemento != NULL){
		printf("\nElemento guardado satisfactoriamente!\n\n");
	}else{
		printf("\nError\n");
	}
}
//Funcion quitar un elemento de la pila
void Quitar_Elemento(){
	char rpt;
	if(Pila_Vacia()){
		printf("\nPila vacia!\n");
	}else{
		do{
			Nodo *aux = pila;
			dato = aux->dato;
			pila = aux->siguiente;
			free(aux);
			fflush(stdin);
			printf("\nElemento Borrado Exitosamente!\n");
			printf("\nQuieres Eliminar otro dato (s/n): ");
			fflush(stdin);
			scanf("%c",&rpt);	
			system("cls");
		}while((rpt == 'S') || (rpt == 's'));
	}
}
//Funcion quitar todos los elementos de la pila
void Quitar_Elementos(){
	if(Pila_Vacia() == true){
		printf("\nPila vacia!\n");
	}else{
		while(pila != NULL){
			Nodo *aux = pila;
			dato = aux->dato;
			pila = aux->siguiente;
			printf("\nElemento %d Borrado Exitosamente!\n",aux->dato);
			free(aux);
		}
	}
}
//Funcion comprobar estado de pila
bool Pila_Vacia(){
	return (pila == NULL)?true:false;
}
//Funcion de mostrar los elementos de una pila
void Mostrar_Elementos(){
	Nodo *Nueva_Pila = pila;
	if(Pila_Vacia()){
		printf("La pila esta vacia!\n");
	}else{
		if(Nueva_Pila != NULL){
			while(Nueva_Pila != NULL){
				printf("%d,",Nueva_Pila->dato);
				Nueva_Pila = Nueva_Pila->siguiente;	
			}
		}else{
			printf("%d.",Nueva_Pila->dato);
		}printf("\n");
	}
}
//Funcion para buscar un elemento
bool Buscar_Elemento(){
	fflush(stdin);
	Nodo *pilita = pila;
	int datos, contador = 0;
	bool encontrado = false;
	if(Pila_Vacia() == true){
		printf("\nPila Vacia!\n");
	}else{
		if(Pila_Vacia() == false){
			printf("\nIngrese dato a buscar: ");
			scanf("%d",&datos);
			system("cls");
		}
		while((pilita != NULL)){
			if(datos == pilita->dato){
				contador += 1;
				encontrado = true;
				printf("\nDato Encontrado: %d\n",pilita->dato);	
			}
			pilita = pilita->siguiente;
		}
	}
	if(contador == 0){
		printf("\nDato no encontrado: %d\n",datos);
	}
}
//Funcion para eliminar un elemento de la pila
void Editar_Elemento(){
	fflush(stdin);
	Nodo *pilita = pila;
	int datos;
	char rpt;
	
	bool encontrado = false;
	if(Pila_Vacia() == true){
		printf("\nPila Vacia!\n");
	}else{
		do{
			printf("\nIngrese dato a Modificar: ");
			scanf("%d",&datos);
			system("cls");
			while((pilita != NULL)){
				if(datos == pilita->dato){
					encontrado = true;
					printf("\nDato Encontrado: %d\n",pilita->dato);
					printf("\nIngrese el nuevo dato: ");
					scanf("%d",&pilita->dato);
					printf("\nDato modificado!\n\n");	
				}	
				pilita = pilita->siguiente;
			}
			if(encontrado == false){
				printf("\nDato no encontrado: %d\n",datos);
			}
			printf("\nQuieres Modificar otro dato(s/n): ");
			fflush(stdin);
			scanf("%c",&rpt);	
			system("cls");
		}while((rpt == 'S') || (rpt == 's'));
	}		
}
//Funcion de Ordenamiento Burbuja
void Burbuja(){
	Nodo *p = pila;
	Nodo *j;
	
	while(p != NULL){
		j = p->siguiente;
		while(j != NULL){
			if(p->dato > j->dato){
				int aux = j->dato;
				j->dato = p->dato;
				p->dato = aux;
			}
			j = j->siguiente;
		}
		p = p->siguiente;
	}
	printf("Ordenado Satisfactoriamente!\n\n");
}

//Funcion para observar el estado de la pila
void Estado_Pila(){
	if(Pila_Vacia()){
		printf("\nPila Vacia!\n\n");
	}else{
		printf("\nPila Llena!\n\n");
	}
}
//Funcion de Ordenamiento Rapido
void Rapido(){
}
//Funcion de Salvar los elementos Ordenados
void Salvar_Elementos(){
	Nodo *polo = pila;
	archivo = fopen("pila.txt", "w");
	while(polo != NULL){
		dato = polo->dato;
		fprintf(archivo, "%d\n", dato);
		polo = polo->siguiente;

	}
	fclose(archivo);
}
//Funcion Generar los elementos
void Generar(){
	int i;
	Nodo *nueva_pila = pila;
	srand(time(NULL));
	while(i != valor){
		dato = (rand() % (1999999 + 1)- 1000000);
		Insertar_Elemento();
		i += 1;
	}
}
//Funcion De Cargar Elementos
void Cargar(){
	Nodo *polo = pila;
	while(!feof(archivo)){
		fscanf(archivo,"%d\n",&dato);
		Insertar_Elemento();
		printf("%d\n",dato);
			
	}printf("Cargado con exito\n");
	fclose(archivo);
}
//Cola
void Menu_Generar(Nodo *&inicio, Nodo *&fin){
	int opcion;
		printf("*******************************\n");
		printf("+         Menu Generar        +\n");
		printf("*******************************\n");
		printf("+                             +\n");
		printf("+   1000000.                  +\n");
		printf("+   2000000.                  +\n");
		printf("+   5000000.                  +\n");
		printf("+   10000000.                 +\n");
		printf("+   20000000.                 +\n"); 
		printf("+   0.Salir                   +\n");
		printf("+                             +\n");
		printf("*******************************\n");
		printf("\nCuantos datos quieres generar: ");
		scanf("%d",&cantDatos);
		system("cls");
		if(cantDatos == 0){
			Menu();
		}else{
			generarDatos(inicio,fin);	
		}
		system("pause");
		system("cls");
}
void Menu_EliminarCola(Nodo *inicio, Nodo *fin, int n){
	int opcion;
	do{
		printf("********************************\n");
		printf("+         Menu Eliminar        +\n");
		printf("********************************\n");
		printf("+                              +\n");
		printf("+   1. Eliminar Todo.          +\n");
		printf("+   2. Eliminar un elemento.   +\n");
		printf("+   0. Salir.                  +\n");
		printf("+                              +\n");
		printf("********************************\n");
		printf("\nQue Deseas Hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:Eliminar_ElementoCola(inicio,fin);
				break;
			case 2:Eliminar_ElementoCola(inicio,fin);
				break;
			case 0:Menu();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
void generarDatos(Nodo *&inicio, Nodo *&fin){
	fflush(stdin);
	int i, aleatorio;
	srand(time(NULL));
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosCola(aleatorio, inicio, fin);
	}
}

void insertarDatosCola(int n, Nodo *&inicio, Nodo *&fin){
	Nodo * nuevo_nodo = reservar_memoria;
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	if(inicio == NULL){
		inicio = nuevo_nodo;
	}else{
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}

void ordenarDatos(Nodo *inicio){
	int aux;
	Nodo * x = inicio;
	Nodo * y = NULL;
	if(inicio == NULL){
		printf("Me la gane suave\n");
	}else{
		while(x != NULL){
			y = x -> siguiente;
			while(y != NULL){
				if(x -> dato > y -> dato){
					aux = x -> dato;
					x -> dato = y -> dato;
					y -> dato = aux;
				}
				y = y -> siguiente;
			}
			x = x -> siguiente;
		}
	}
}
void imprimirDatos(Nodo *inicio){
	Nodo * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux -> dato);
			aux = aux -> siguiente;
		}
	}
}
void Quitar_ElementoCola( Nodo *&inicio, Nodo *&fin,int n){
	Nodo *aux = inicio;
	n = aux->dato;
	inicio = aux->siguiente;
	free(inicio);
}
void Eliminar_ElementoCola(Nodo *&inicio,Nodo *&fin){
	Nodo *aux = inicio;
	
	if(inicio == fin){
		inicio = aux->siguiente;
		fin = NULL;
	}else{
		inicio = inicio -> siguiente;
	}
	delete aux;
	printf("La Cola fue Borrada Exitosamente!\n");
}
void Buscar_ElementoCola(Nodo *inicio, Nodo *fin){
	fflush(stdin);
	Nodo *colita = inicio;
	int datos;
	bool encontrado = false;
	if(Cola_Vacia(inicio) == true){
		printf("\nCola Vacia!\n");
	}
	if(Cola_Vacia(inicio) == false){
		printf("\nIngrese dato a buscar: ");
		scanf("%d",&datos);
		system("cls");
	}
	while((colita != NULL)){
		if(datos == colita->dato){
			encontrado = true;
			printf("\nDato Encontrado: %d\n",colita->dato);	
		}
		colita = colita->siguiente;
	}
	if(encontrado == false){
		printf("\nDato no encontrado: %d\n",datos);
	}
}
bool Cola_Vacia(Nodo *cabeza){
	return (cabeza == NULL)? true : false;
}
void Editar_ElementoCola(Nodo *&inicio, Nodo *&fin){
	fflush(stdin);
	Nodo *colita = inicio;
	int datos;
	char rpt;
	
	bool encontrado = false;
	if(Cola_Vacia(inicio) == true){
		printf("\nPila Vacia!\n");
	}else{
		do{
			printf("\nIngrese dato a Modificar: ");
			scanf("%d",&datos);
			system("cls");
			while((colita != NULL)){
				if(datos == colita->dato){
					encontrado = true;
					printf("\nDato Encontrado: %d\n",colita->dato);
					printf("\nIngrese el nuevo dato: ");
					scanf("%d",&colita->dato);
					printf("\nDato modificado!\n\n");	
				}	
				colita = colita->siguiente;
			}
			if(encontrado == false){
				printf("\nDato no encontrado: %d\n",datos);
			}
			printf("\nQuieres Modificar otro dato(s/n): ");
			fflush(stdin);
			scanf("%c",&rpt);	
			system("cls");
		}while((rpt == 'S') || (rpt == 's'));
	}		
}
void Salvar_ElementosCola(Nodo *&inicio){
	int dato;
	Nodo *polo = inicio;
	archivo = fopen("cola.txt", "w");
	while(polo != NULL){
		dato = polo->dato;
		fprintf(archivo, "%d\n", dato);
		polo = polo->siguiente;

	}
	fclose(archivo);
}
void Estado_Cola(Nodo *inicio){
	if(Cola_Vacia(inicio)){
		printf("\nCola Vacia!\n\n");
	}else{
		printf("\nCola Llena!\n\n");
	}
}
