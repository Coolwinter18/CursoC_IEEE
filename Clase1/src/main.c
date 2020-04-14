#include <stdio.h>

//Clase 1
int main()
{
	int inicioComplementarios = 6;
	int finComplementarios = 9;
	int op = 0;
	int j;
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
		
		printf("Ejercicio 1: Imprimir el mensaje por pantalla \"Hola Mundo\"\n\n");

		//Codigo 

		printf("Hello World!\n");
		getchar();

		break;
	case 2: //Ejercicio 2

		printf("Ejercicio 2: Calcular el área de un círculo a partir de su radio (predefinido).\n\n");

		//Codigo
		#define pi 3.14f;
		float r = 3.5f;
		float area = r*r;
		area = area*pi;

		printf("El area del circulo de radio %f es %f",r,area);
	case 3: //Ejercicio 3

		printf("Ejercicio 3: Ingresar dos números por pantalla, multiplicarlos y devolver el resultado.\n\n");

		//Codigo
		float numero1,numero2;

		printf("Ingrese 1er Numero\n");
		scanf("%f",&numero1);
		printf("Ingrese 2do Numero\n");
		scanf("%f",&numero2);
		printf("El producto de %f por %f es: %f",numero1,numero2,(numero1*numero2));
	case 4: //Ejercicio 4

		printf("Ejercicio 4: Calcular el promedio de un estudiante en una materia con tres exámenes\n\n");

		//Codigo
		float promedio = 0;
		

	default:
		break;
	}

	

	return (0);
}