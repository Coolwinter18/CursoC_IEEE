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
}node;


node *new_node()
{
	node *head = NULL;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	return head;
}
node *add_node(node *head, record data)
{
	node *nuevo_nodo = new_node();
	nuevo_nodo->data = data;
	node *aux = head;
	node *aux2 = NULL;
	while (aux != NULL && aux->data.director< data.director)
	{
		aux2 = aux;
		aux = aux->next;
	}
	if (aux == head)
	{
		head = nuevo_nodo;
	}else
	{
		aux2->next = nuevo_nodo;		
	}
	nuevo_nodo->next = aux;
	free(aux2);
	free(aux);
	return head;
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


void generate_file(node *head)
{
	//Genera el archivo catalogo.txt
	FILE *fp;

	fp = fopen("catalogo.txt","w");
	if (fp == NULL)
	{
		printf("Error al abrir el archivo");
		exit(1);
	}else
	{
		node *aux = head;
		while (aux != NULL)
		{
			//Imprime titulo de pelicula
			char *line[] = "Titulo: "; 
			fprintf(fp,"%s",line);
			fprintf(fp,"%s\n",aux->data.titulo);
			//imprime anio de estreno
			char *line2[] = "Anio de Estreno: ";
			fprintf(fp,"%s",line2);
			fprintf(fp,"%i\n",aux->data.estreno);
			//Imprime nombre del director y salta una linea para siguiente registro.
			char *line3[] = "Director: ";
			fprintf(fp,"%s\n\n",aux->data.director);

			//avanzo al siguiente registro.
			aux = aux->next;
		}
		fclose(fp);
	}
	
	

}
int ejecutar_ej1()
{
	int opcion = 0;
	do
	{
	
	
		node *lista = NULL;
		char op_list[][50]={"Agregar Titulo\n","Buscar Titulo\n","Mostrar Titulos\n","Salir y Generar Archivo.\n"};
		int longitud_op = *(&op_list+1) - op_list;
		
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
				lista = add_node(lista,input);
			}
			break;
			case 2:
			{
				//Buscar Pelicula
				if (lista  == NULL)
				{
					printf("Lo Siento, La lista Se encuentra vacia, agregue un titulo para listar.");
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
				if (lista == NULL)
				{
					printf("No se generara ningun archivo ya que no ingreso titulos a la lista.");
				}else
				{
					printf("Generando archivo 'catalogo.txt'...");
					generate_file(lista);
					printf("Catalogo generado, saliendo del programa.");
				}
				free_list(lista);
			}
			break;
		}
	}while(opcion != 4);
	return 1;
}
//Estructuras Ejercicio 2
typedef struct result
{
	char c;
	int i;
}result;

result caracteresRepetidos(char *arreglo[],int sizeArreglo)
{
	static result sal;
	///CONTINUAR DESDE ACA
}
int ejecutar_ej2()
{
	//le pido que ingrese la cadena de caracteres.
	char *string ;
	printf("ingrese la cadena de caracteteres a utilizar en la funcion.");
	fscan("%s",&string);
	int size = *(&string + 1) - string;
	result salida = caracteresRepetidos(string,size);
	printf("el caracter mas repetido consecutivamente es: '%c' un total de '%i' veces",salida.c,salida.i);
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