#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
typedef struct data
{
	unsigned short month;
	unsigned short day;
	unsigned int income;
}record;



typedef struct node
{
	record data;
	struct node *next;
}node;

void addNodeOrdered(node *head,record data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL; 
	if (head == NULL)
	{
		newNode = head;
	}else
	{
		node *aux = head;
		while (data.income > aux->data.income && aux->next!= NULL)
		{
			aux = aux->next;
		}
		if (head == aux)
		{
			/* code */
			if (data.income > aux->data.income)
			{
				/* code */

			}
			
		}
		
		
	}
	
	
};
const char menu[][10] = {"Los Alamos","Vectores","Exit"};
int main()
{
	printf("Modelo Examen Parcial\n\n");
	short opt = 0;
	int menu_lenght = *(&menu + 1) - menu; //sizeof(menu) / sizeof(menu[0]);
	while (opt < 1 || opt > menu_lenght)
	{
		int condicion = menu_lenght;
		for (short  i = 0; i < condicion; i++)  /**menu_lenght**/
		{
			printf("%i) %s \n",i+1,menu[i]);
		}
		printf("\n Selecionar: ");
		scanf("%d",&opt);
	}
	printf("\n\n");
	switch (opt)
	{
	case 1:
	{
		//Case 1 - Los Alamos
		int op = 0;
		node *list = newNode();
		list->next = NULL;
			do
			{
				do
				{
					printf("Ingrese '1' para iniciar la carga, pulse '0' para finalizar la carga,");
					scanf("%d",&op);
				} while (op != 0 || op != 1);
				if (op == 1)
				{
					record newData;  
					/* codigo para cargar un dato a lista */
					printf("Ingrese el Dia\n");
					scanf("%d",&newData.day);
					printf("Ingrese el Mes\n");
					scanf("%d",&newData.month);
					printf("Ingrese el Ingreso\n");
					scanf("%d",&newData.income);
					addNodeOrdered(list,newData);
					
				}else{
					/*codigo para cargar lista a archivo*/
				}
			} while (op != 0);
		
	}
	break;
	case 2:
	{
		/* code */
	}
	break;
	default:
		break;
	}

	return (0);
}