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

typedef struct node
{
	int data;
	struct node *next;
	//struct node *previus;
} node;

typedef struct list
{
	node *header;
	node *next;
	unsigned short index;
} vector, queue, stack;

/**
 * @brief Create a Node object
 * 
 * @param temp 
 * @return node* 
 */
node *createNode(node *temp)
{
	temp = (node *)malloc(sizeof(node));
	temp->next = NULL;
	return temp;
}

/**
 * @brief Create a Vector object
 * 
 * @param temp 
 * @return vector* 
 */
vector *createVector(vector *temp)
{
	temp = (vector *)malloc(sizeof(struct list));
	temp->header = NULL;
	temp->next = NULL;
	temp->index = 0;
	temp->next = NULL;
	return temp;
}

/**
 * @brief Function that add an element to a Vector, it adds at the end
 * 
 * @param pointer: header of the vector
 * @param value:  the 'value' to add
 */
void addElementToVector(vector *aVector, int value)
{
	printf("Agregando Elemento..\n");
	node *newNode = createNode(newNode);
	newNode->data = value;
	newNode->next = NULL;
	if (aVector->header == NULL)
	{
		///Primer Elemento
		aVector->header = newNode;
		aVector->next = NULL;
	}
	else
	{
		///i-esimo elemento.
		node *pos = aVector->header;
		while(pos->next != NULL)
		{
			pos = pos->next; 
		}
		pos ->next =  newNode;
	}
	aVector->index ++;
}
/**
 * @brief Procedure that removes an element from the vector, given an index of position in vector.
 * 
 * @param pointer 
 * @param index 
 */
void delElementFromVector(vector *pointer, unsigned short index)
{
	if (index > (pointer->index))
	{
		//Vector vacio o indice fuera de rango
		printf("Error, vector vacio o fuera de rango\n");
	}	
	else
	{
		node *remove = pointer->header;
		while (index != 1)
		{
			///buscar nodo respecto a su indice.
			remove = remove->next;
			index--;
		}
		if (remove == pointer->header)
		{
			///borrar primer elemento del Vector
			if (index == 1)
			{
				///borrar unico elemento
				pointer->header = NULL;
				pointer->next=NULL;
			}else
			{
				pointer->header=(pointer->header)->next;
			}
			pointer->header = (pointer->header) ->next;
		}else
		{
			///borrar elemento i-esimo de la lista.
			node *aux = pointer->header;
			while(aux->next != remove)
			{
				aux = aux->next;
			}
			aux->next = remove->next;
		}
		pointer->index--;
		free(remove);
	}
}


#define typename(x) _Generic((x),                                      \
							 _Bool                                     \
							 : "_Bool", unsigned char                  \
							 : "unsigned char",                        \
							   char                                    \
							 : "char", signed char                     \
							 : "signed char",                          \
							   short int                               \
							 : "short int", unsigned short int         \
							 : "unsigned short int",                   \
							   int                                     \
							 : "int", unsigned int                     \
							 : "unsigned int",                         \
							   long int                                \
							 : "long int", unsigned long int           \
							 : "unsigned long int",                    \
							   long long int                           \
							 : "long long int", unsigned long long int \
							 : "unsigned long long int",               \
							   float                                   \
							 : "float", double                         \
							 : "double",                               \
							   long double                             \
							 : "long double", char *                   \
							 : "pointer to char",                      \
							   void *                                  \
							 : "pointer to void", int *                \
							 : "pointer to int",                       \
							   default                                 \
							 : "other", node *                         \
							 : "pointer to node")
int main()
{
	int inicioComplementarios = 3;
	int finComplementarios = 3;
	int j = 0;
	int op = 0;
	do
	{
		for (size_t i = 1; i < inicioComplementarios; i++)
		{
			printf("%i) Ejercicio Nro:%i \n", i, i);
		};
		j = 1;
		for (size_t i = inicioComplementarios; i <= finComplementarios; i++)
		{
			printf("%i) Ejercicio Complementario Nro:%i \n", i, j);
			j++;
		}
		printf("%i) Salir\n", (finComplementarios));

		printf("Ingrese el numero para seleccionar el ejercicio \n");
		scanf("%d", &op);

	} while (op < 1 || op > (finComplementarios + 1));
	switch (op)

	{
	case 1: ///Ejercicio 1
	{
		printf("Ejercicio 1: Crear una lista simple que contenga valores enteros, con una función que agregue elementos ingresados por el usuario.\n\n");

		//Codigo
		vector *numbers = createVector(numbers);
		for (unsigned short i = 1; i <= 10; i++)
		{
			printf("entra al ciclo for para agregar elementos\n\n");
			addElementToVector(numbers,i);
			printf("Numero %i agregado a la lista \n",i+1);
			printf("Indice del vector: %i\n",numbers->index);
		}
		printf("Imprimiendo vector...\n");
		node *aNumber = numbers->header;
		while (aNumber->next != NULL)
		{
			printf("value: %i\n",aNumber->data);
			aNumber = aNumber->next;
		}
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