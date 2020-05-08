#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


//  https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/

/*

FUNCIONES POR NICOLAS ZINI


void imprimirLista(tpuntero cabeza){
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        printf("%4d",cabeza->valor); //Imprimimos el valor del nodo
        cabeza = cabeza->sig; //Pasamos al siguiente nodo
    }
}
 
void borrarLista(tpuntero *cabeza){ 
    tpuntero actual; //Puntero auxiliar para eliminar correctamente la lista
  
    while(*cabeza != NULL){ //Mientras cabeza no sea NULL
        actual = *cabeza; //Actual toma el valor de cabeza
        *cabeza = (*cabeza)->sig; //Cabeza avanza 1 posicion en la lista
        free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y cabeza queda apuntando al que ahora es el primero
    }
}

////////////////////////////////////////////////////////////////////


include <stdio.h>
#include <stdlib.h>
 
typedef struct snodo{
    int valor;
    struct snodo *sig;
} tnodo;
 
typedef tnodo *tpuntero;
 
void imprimirLista(tpuntero cabeza);
void borrarLista (tpuntero *cabeza);
 
int main(){
    int e;
    tpuntero cabeza = NULL;
    tpuntero aux = NULL;
 
    printf("Ingresar elementos\n");
    scanf("%d",&e);
    cabeza = malloc(sizeof(tnodo));
    cabeza->valor = e;
    cabeza->sig = NULL;
    aux = cabeza;
 
    while(e != 0){
        printf("Ingresado correctamente\n");
        printf("Ingrese un elemento, indique 0 para finalizar\n");
        scanf("%d",&e);
        if(e != 0){
            tpuntero nuevo;
            nuevo = malloc(sizeof(tnodo));
            nuevo->valor=e;
            nuevo->sig = NULL;
            aux->sig = nuevo;
            aux = aux->sig;
        }
 
    }
    printf("Imprimimos la lista\n");
    imprimirLista(cabeza);
    printf("\nBorramos la lista\n");
    borrarLista(&cabeza);
}
 
void imprimirLista(tpuntero cabeza){
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        printf("%4d",cabeza->valor); //Imprimimos el valor del nodo
        cabeza = cabeza->sig; //Pasamos al siguiente nodo
    }
}
 
void borrarLista(tpuntero *cabeza){
    tpuntero actual; //Puntero auxiliar para eliminar correctamente la lista
 
    while(*cabeza != NULL){ //Mientras cabeza no sea NULL
        actual = *cabeza; //Actual toma el valor de cabeza
        *cabeza = (*cabeza)->sig; //Cabeza avanza 1 posicion en la lista
        free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y cabeza queda apuntando al que ahora es el primero
    }
}
*/
typedef struct node //definition of node
{
	int data;
	struct node *next;
	struct node *previus;
}node;

typedef struct list
{
	node *header;
	//struct list *next;
	unsigned short index;
}list;

typedef struct queue //definition of queue
{
	node *header;
	node *last;
	unsigned short index;
}queue;
/*
node createNode(){
    node *temp; // declare a node
    temp = (node*)malloc(sizeof(struct node)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return *temp;//return the new node
}
*/
//SEGMENTATION FAULT
void add_element_to_linked_list(list *pointer, int value)
{
	node *newNode;// =  createNode();
	newNode -> data = value;

	if (pointer -> header == NULL)
	{
		//Primer Elemento
		newNode -> next = NULL;
	}else
	{
		//i-esimo elemento.
		newNode -> next = pointer -> header;
	}
	pointer -> header = newNode;	
}


void removeElementFromLinkedList(list *pointer,int index)
{
	if (pointer->header == NULL || index > (pointer->index))
	{
		//lista Vacia o fuera de rango
		printf("Error, lista vacia o fuera de rango, intente de nuevo.");
	}else
	{
		node *remove = pointer -> header;
		if (!pointer->index == 1)
		{
			//eliminar nodo respecto a su indice.
			while(index > 1)
			{
				remove = remove -> next;
				index--;
			}
			
			remove -> next = (remove -> next) -> next;
		}
	}	
}

void addElementToQueue(queue *pointer,int value)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = value;
	newNode->previus = NULL;
	if (pointer->header == NULL)
	{
		//Primer elemento
		pointer ->header = newNode;
		pointer->last = newNode;
		pointer->index = 1 ;
		newNode->next = NULL;
		
	}else
	{
		//n-esimo elemento.
		newNode->next = pointer->header;
		(pointer->header)->previus = newNode;
		pointer->index+=1;
	}
	pointer->header = newNode;
}
void removeElementFromQueue(queue *pointer)
{
	if (pointer-> header == NULL)
	{
		//No Hay elementos
		printf("Error, no elements to dispose.");
	}else
	{	
		if (pointer->header == pointer->last)
		{
			//Eliminar unico elemento de la lista
			pointer->header = NULL;
			pointer->last = NULL;
			pointer->index = 0;

		}else
		{
			//Eliminar ultimo elemento de la lista.
			pointer->last = (pointer->last)->previus;
			(pointer->last)->next = NULL;
		}
		
		
		
	}
	
	
}
int main()
{
	int inicioComplementarios = 3;
	int finComplementarios = 3;
	int j = 0;
	int op = 0;
	do{
		for (size_t i = 1; i < inicioComplementarios; i++)
		{
			printf("%i) Ejercicio Nro:%i \n",i,i);
		}
		;
		j = 1;
		for (size_t i = inicioComplementarios; i <= finComplementarios; i++)
		{
			printf("%i) Ejercicio Complementario Nro:%i \n",i,j);
			j++;
		}
		printf("%i) Salir\n",(finComplementarios));

		printf("Ingrese el numero para seleccionar el ejercicio \n");
		scanf("%d",&op);
	
	}while(op < 1 || op > (finComplementarios + 1));
	switch (op)
	
	{
	case 1: //Ejercicio 1
	{
		printf("Ejercicio 1: Crear una lista simple que contenga valores enteros, con una función que agregue elementos ingresados por el usuario.\n\n");
	
		//Codigo
		list *aList;
		for (size_t i = 0; i < 10; i++)
		{
			add_element_to_linked_list(aList,i +1);
		}
		removeElementFromLinkedList(aList,11);

		
		


		
	}
	break;
	case 2: //Ejercicio 2 
	{
		
	}
	break;
	case 3: //Ejercicio 3
	{
		
	}
	default:
	{

	}
	break;
	}
	return (0);
}