#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

//  https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/

typedef struct node
{
	int data;
	struct node *next;
} node;

typedef struct list
{
	node *header;
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
	temp->index = 0;
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
	}
	else
	{
		///i-esimo elemento.
		node *pos = aVector->header;
		while (pos->next != NULL)
		{
			pos = pos->next;
		}
		pos->next = newNode;
	}
	aVector->index++;
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
			if (pointer->index == 1)
			{
				///borrar unico elemento
				pointer->header = NULL;
			}
			else
			{
				pointer->header = (pointer->header)->next;
			}
		}
		else
		{
			///borrar elemento i-esimo de la lista.
			node *aux = pointer->header;
			while (aux->next != remove)
			{
				aux = aux->next;
			}
			aux->next = remove->next;
		}
		pointer->index--;
		free(remove);
	}
}
/**
 * @brief Procedure that eliminates the vector from memory, calling 'delElementFromVector(aVector,1)' until its empty.
 * 
 * @param aVector 
 */
void cleanVector(vector *aVector)
{
	while (aVector->header != NULL)
	{
		delElementFromVector(aVector, 1);
	}
	free(aVector);
}

/**
 * @brief Function that returns a Vector sorted from lower to higher.
 * 
 * @param aVector 
 */
vector *SortVector(vector *aVector)
{
	vector *sortedVector = createVector(sortedVector);
	while (aVector->index > 1)
	{

		node *data = aVector->header;
		int min = data->data;
		unsigned short idx = 1;
		unsigned short x = 1;
		while (data->next != NULL)
		{

			if (data->data < min)
			{
				min = data->data;
				idx = x;
			}
			x++;
			data = data->next;
		}
		addElementToVector(sortedVector, min);
		delElementFromVector(aVector, idx);
	}
	addElementToVector(sortedVector, (aVector->header)->data);
	cleanVector(aVector);
	return sortedVector;
}

/**
 * @brief Procedure that prints all digits of a Vector.
 * 
 * @param aVector 
 */
void printVector(vector *aVector)
{
	node *data = aVector->header;
	printf("[");
	while (data != NULL)
	{
		printf("%i, ", data->data);
		data = data->next;
	}
	printf("]\n");
}

/**
 * @brief Function that returns a value from a Vector, given a value. if there is 2 or more coincidences, it returns what it finds first.
 * 
 * @param aVector 
 */
void seekInVector(vector *aVector, int aValue)
{
	node *data = aVector->header;
	unsigned short idx = 0, i = 1;
	while (idx == 0 && data != NULL)
	{
		if (data->data == aValue)
		{
			idx = i;
		}
		i++;
	}
	if (idx != 0)
	{
		printf("Caso exitoso, se encontro el numero '%i' en la posicion %i\n", aValue, idx);
	}
	else
	{
		printf("Caso fallido, no se encontrol el numero buscado.\n");
	}
}
/**
 * @brief Definicion de un tipo multivaluado.
 * 
 */
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
	int finComplementarios = 2;
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
		int data = 0;
		vector *numbers = createVector(numbers);
		for (unsigned short i = 1; i <= 5; i++)
		{
			printf("Ingrese el valor %i/5, en el vector.\n", i);
			scanf("%d", &data);
			addElementToVector(numbers, data);
			printf("Numero %i agregado al vector. \n", data);
			printf("Indice del vector: %i\n", numbers->index);
		}
		printf("Imprimiendo vector...\n");
		node *aNumber = numbers->header;
		while (aNumber != NULL)
		{
			printf("value: %i\n", aNumber->data);
			aNumber = aNumber->next;
		}
		printf("pulse una tecla para limpiar el vector... y terminar.\n");
		getchar();
		cleanVector(numbers);
	}
	break;
	case 2: //Ejercicio 2
	{
		printf("Ejercicio 2: Crear una lista simple ordenada, en un programa que contenga un menú de opciones que permite agregar un elemento, buscar un elemento, y eliminarlo.\n");
		unsigned short opcion = 0;
		char opciones[][255] = {"Agregar Nodo", "Ver Nodo", "Eliminar Nodo", "Salir"};
		vector *num = createVector(num);
		int data = 0;
		do
		{
			printf("Menu Opciones\n");
			for (unsigned short i = 1; i < 5; i++)
			{
				printf("%i)%s\n", i, opciones[i - 1]);
			}
			printf("Seleccione una opcion:\n");
			do
			{
				scanf("%d", &opcion);
			} while (opcion < 1 && opcion > strlen(opciones));

			switch (opcion)
			{
			case 1: // Agregar Nodo
			{
				printf("Ingrese valor a agregar:\n");
				scanf("%d", &data);
				addElementToVector(num, data);
				num = SortVector(num);
			}
			break;
			case 2: // Ver Nodo
			{

				if (num->index > 0)
				{
					printf("Ingrese valor a buscar:\n");
					scanf("%d", &data);
					seekInVector(num, data);
				}
				else
				{
					printf("Vector vacio, agregue elementos para poder buscarlos\n");
				}
			}
			break;
			case 3: //Borrar Nodo
			{
				if (num->index > 0)
				{
					printf("Ingrese el indice de posicion del valor a borrar.\n 1-%i\n", num->index);
					printVector(num);
					scanf("%d", &data);
					delElementFromVector(num, data);
				}
				else
				{
					printf("Vector vacio, agregue elementos para poder eliminarlos\n");
				}
			}
			default:
				break;
			}			   //end switch opciones de operaciones.
		} while (op != 4); //end while opcioones de operaciones
	cleanVector(num);
	}					   //end ejercicio 2
	break;
	default:
	{
	}
	break;

	} //end switch ejercicios.
	return (0);
}