#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Estructuras Ejercicio 1
typedef struct data
{
	char titulo[50];
	int estreno;
	char director[50];
}record;

typedef struct node
{
	record data;
	struct node *next;
	struct node *previous;
	int index;
}node;

void add_node(node *head, record data);
{
	node *tmp = (node*)malloc(sizeof(node));
	if(head == NULL)
	{
		//Lista Vacia - Primer Elemento.
	}
}

void free_list(node *head)
{
	while(head != NULL)
	{
		node *delete = head;
		head = head->next;
		free(delete);
	}
	free(head);
}
void display_list(node *head)
{
	node *tmp = head;
	while(tmp != NULL)
	{
		printf("Titulo: %s\nEstreno: %i\nDirector: %s",tmp->data.titulo,tmp->data.estreno,tmp->data.director);
		printf("\n\n");
		tmp = tmp->next;
	}
}
void search_movie(node *head, char name[50])
{
	node *tmp = head;
	while(tmp !=NULL)
	{
		if (name == tmp->data.titulo)
		{
			printf("Busqueda Exitosa:\n");
			printf("datos de la pelicula: \n");
			printf("Titulo: %s\n",tmp->data.titulo);
			printf("Anio de Estreno: %s\n",tmp->data.estreno);
			printf("Director: %s",tmp->data.director);
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		printf("Busqueda No exitosa, no se ha encontrado la pelicula con ese nombre.\n");
	}
}
int ejecutar_ej1()
{
	node *lista = NULL;
	lista = (node*)malloc(sizeof(node));
	lista->next = NULL;
	lista->previous = NULL;
	lista->index = 0;
	char op_list[][50]={"Agregar Titulo\n","Buscar Titulo\n","Mostrar Titulos\n","Salir y Generar Archivo.\n"};
	int longitud_op = *(&op_list+1) - op_list;
	int opcion = 0;
	for (size_t i = 0; i < longitud_op; i++)
	{
		printf("%i) %s",i+1,op_list[i]);
	}
	scanf("%d",&opcion);
	switch (opcion)
	{
		case 1:
		{
			//Agregar Nodo
			record input;
			printf("Por Favor ingrese:\n");
			printf("Titulo de la Pelicula\n");
			scanf("%s",&input.titulo);
			printf("Anio de Estreno");
			scanf("%d",&input.estreno);
			print("Nombre del Director\n");
			scanf("%s",&input.director);
			add_node(lista,input);
		}
		break;
		case 2:
		{
			//Buscar Pelicula
			if (lista->index == 0)
			{
				printf("Lo Siento, La lista Se encuentra vacia, agregue un titulo para listar.")
			}else
			{
				char name[50];
				printf("Ingrese el nombre de la pelicula para buscar\n");
				scanf("%s",&name);
				search_movie(lista,name);
			}
			
		}
		break;
		case 3:
		{
			//Mostrar Lista
			display_list(lista);
		}
		break;
	default: 
		{
			// Generar archivo, liberar lista y Salir
			generate_file(lista);
			free_list(lista);
		}
		break;
	}
	return 1;
}
//Estructuras Ejercicio 2
int ejecutar_ej2()
{
	return 1;
}

//Estructuras Ejercicio 3
int ejecutar_ej3()
{
	return 1;
}
int main()
{
	int select = 0;
	printf("Examen de Programacion C [IEEE Certification]\n");
	char op[][50]= {"Listas: tusPelis.com\n","Funciones: Caracter repetidos\n","Debugging: Fibonacci + insertar_en_lista\n"};
	int longitud = *(&op +1) - op;
	for (short i = 0; i < longitud; i++)
	{
		printf("%i) Ejercicio de %s",i+1,op[i]);
	}
	printf("%i) Salir.",longitud+1);
	scanf("%d",&select);
	switch (select)
	{
		case 1:
		{
			//Ejecutar Ejercicio 1 de Listas
			
			while (true)
			{
				ejecutar_ej1();
			}
			
		}
		break;
		case 2:
		{
			//Ejecutar Ejercicio 2 de Funciones
			ejecutar_ej2();
		}
		break;
		case 3:
		{
			//Ejecutar Ejercicio 3 de Debugging.(codigo corregido con comentarios)
			ejecutar_ej3();
		}
	default: //Salir.
		break;
	}
	return (0);
}