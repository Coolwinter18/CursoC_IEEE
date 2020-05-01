#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int* ContadorString(char DataString[])
{
	static int arreglo[3] = {0,0,0};
		for (size_t i = 0; i < strlen(DataString); i++)
		{
			if (DataString[i]==' ')
			{
				arreglo[0]+=1;
			}else
			{
				if (isalpha(DataString[i]))
				{
					if (isupper(DataString[i]))
					{
						arreglo[1]++;
					}else
					{
						arreglo[2]++;
					}
					
					
				}
				
			}
		}
		return arreglo;
}
int main()
{
	int inicioComplementarios = 6;
	int finComplementarios = 6;
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
		printf("Ejercicio 1: Sumar dos variables mediante punteros, devolver el resultado mediante uno.\n\n");
	
		//Codigo
		int a=1;
		int b=2;
		int c=3;
		int* pointerA=&a;
		int* pointerB=&b;
		printf("int a=1,b=2,c=3;\n int* pointerA=&a,*pointerB=&b;\n\n(valor,direccion)\na)=(%i,%p)\nb)=(%i,%p)\nc)=(%i,%p)\n",a,&a,b,&b,c,&c);
		printf("asigne un valor entero a 'pointerA':\n");
		scanf("%d",pointerA);
		printf("pointerA) valor: %i direccion %p\n",pointerA,&pointerA);
		printf("Asigne un valor en'pointerB':\n");
		scanf("%d",pointerB);
		printf("pointerB) valor: %i direccion %p\n",pointerB,&pointerB);
		printf("sumamos el contenido de 'pointerB' y 'pointerA' a c  c = *pointerA + *pointerB.\n\n");
		c= *pointerA + *pointerB;
		printf("Imprimimos los resultados finales (valor,direccion):\na)(%i,%p)\nb)(%i,%p)\nc)(%i,%p)\n",a,&a,b,&b,c,&c);
		printf("Imprimimos los resultados finales (valor,direccion):\npointerA)(%i,%p)\npointerB)(%i,%p)\n",pointerA,&pointerA,pointerB,&pointerB);

	}
	break;
	case 2: //Ejercicio 2 
	{
		printf("Ejercicio 2: Declarar un arreglo de n elementos, cargarlo (manualmente o con valores aleatorios).\n");
		printf(" Imprimir los valores desde el último elemento hasta el primero mediante punteros./n/n");

		//Codigo
		float array[10]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
		float *pointer = &array[9];
		int array2[10]={1,2,3,4,5,6,7,8,9,10};
		int *pointer2 = &array2[9];
		for (size_t i = 0; i < 10; i++)
		{
			printf("%f\n",*pointer);
			printf("%d\n",*pointer2);
			pointer--;
			pointer2--;
		}
	}
	break;
	case 3: //Ejercicio 3
	{
		printf("Ejercicio 3: Crear una función que realice lo mismo que el ejercicio 3.2,\n");
		printf("la función debe devolver el arreglo que almacena las cantidades de espacios, mayusculas y minusculas.\n\n");
		int *point = ContadorString("Hola Mundo");
		printf("%p",point);

	}
	default:
	{

	}
	break;
	}
	return (0);
}