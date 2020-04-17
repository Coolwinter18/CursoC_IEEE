#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int inicioComplementarios = 7;
	int finComplementarios = 8;
	int op = 0;
	int j, numero;
	int divisores;
	int dividendos;
	do{
		for (size_t i = 1; i < inicioComplementarios; i++)
		{
			printf("%i) Ejercicio Nro:%i \n",i,i);
		}
		;
		j = 1;
		for (size_t i = inicioComplementarios; i < finComplementarios; i++)
		{
			printf("%i) Ejercicio Complementario Nro:%i \n",i,j);
			j++;
		}
		printf("%i) Salir\n",(finComplementarios + 1));

		printf("Ingrese el numero para seleccionar el ejercicio \n");
		scanf("%d",&op);
	
	}while(op < 1 || op > (finComplementarios + 1));
	switch (op)
	
	{
	case 1: //Ejercicio 1
		printf("Ejercicio 1: Crear un menú de opciones para una calculadora.//switch\n\n");

		//Codigo
		char op[][255] = {"suma","resta","multiplicacion","division","potencia","raiz"};
		
		for (size_t i = 0; i < sizeof(op)/sizeof(op[0]); i++)
		{
			printf("%i) %s\n",i+1,op[i]);
		}
		int select;
		do{
		printf("Ingrese el numero de operacion");
		scanf("%d",&select);
		}while(select < 1 || select > (sizeof(op)));

		switch (select)
		{
		case 1:
			printf("Suma\n");
			break;
		case 2:
			printf("Resta\n");
			break;
		case 3:
			printf("Multiplicacicon\n");
			break;
		case 4:
			printf("Division\n");
			break;
		case 5:
			printf("Potencia\n");
			break;
		case 6:
			printf("Raiz\n");
			break;
		default:
			break;
		}
	break;

	case 2: // Ejercicio 2

			printf("Ejercicio 2: Calcular el factorial de un número.//for\n\n");
			
			//Codigo
			printf("Ingrese el numero:");
			scanf("%d",numero);
			int factorial = 1;
			for (size_t i = numero; i > 0; i--)
			{
				factorial*=i;
			}
			printf("El factorial de %i es: %i",numero,factorial);

	break;

	case 3: //Ejercicio 3

			printf("Ejercicio 3: Ingresar un número, determinar si es primo.//while\n\n");
			
			//Codigo
			int divisores = 0;
			int dividendos = 1;
			printf("Ingrese un numero entero y le diremos si es primo o no\n");
			scanf("%d",&numero);

			divisores = 0;
			dividendos = 1;
			while (divisores < 3 && dividendos <= numero )
			{
				if (numero%dividendos==0)
				{
					divisores+=1;
				}
				dividendos+=1;
			}
			if (divisores < 3)
			{
				printf("Es Primo\n");
			}else
			{
				printf("No es Primo\n");
			};
	break;		

	case 4: //Ejercicio 4

			printf("Ejercicio 4: Imprimir los primeros n números primos.//tarea\n\n");

			//Codigo
			
			printf("Ingrese un numero mayor a 0 y le diremos los numeros primos que hay hasta dicho numeor");
			scanf("%i",&numero);
			printf("los numeros son: \n");
			for (size_t i = 1; i <= numero; i++)
			{
				dividendos = 1;
				divisores = 0;
				while (divisores < 3 && dividendos <= i )
				{
					if (numero%dividendos==0)
					{
						divisores+=1;
					}
					dividendos+=1;
				}
				if (divisores < 3)
				{
					printf("%i, ",i);
			}
			printf("\n");
	break;

	case 5: //Ejercicio 5

			printf("Ejercicio 5: Cargar un arreglo con números ingresados por el usuario, al final, mostrarlos en el sentido inverso al que fueron cargados. //primero, en clase mostrarlos al derecho.\n\n");

			//Codigo
			char action;
			int* array = NULL;
			int index = 0;
			do
			{
				printf("ingrese 'i' para ingresar un numero, o pulse otra tecla para terminar e imprimir todos los numeros ingresados\n");
				scanf("%c",&action);
				if (action=='i' || action =='I')
				{
					index+=1;
					array = realloc(array,index*sizeof(int));
					printf("Ingrese el numero:\n");
					scanf("%d",&array[index]);
				}
			} while (action =='i');
			if (array != NULL)
			{
				printf("Lista de numeros ingresados por el usuario:\n");
				for (size_t i = index; i >= 0; i--)
				{
					printf("%i ,",i);
				}
			};
			printf("\n");
	break;

	default:

	break;
	}
}return 0;