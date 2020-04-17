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
		break;
	case 3: //Ejercicio 3

		printf("Ejercicio 3: Ingresar dos números por pantalla, multiplicarlos y devolver el resultado.\n\n");

		//Codigo
		float numero1,numero2;

		printf("Ingrese 1er Numero\n");
		scanf("%f",&numero1);
		printf("Ingrese 2do Numero\n");
		scanf("%f",&numero2);
		printf("El producto de %f por %f es: %f",numero1,numero2,(numero1*numero2));
		break;
	case 4: //Ejercicio 4

		printf("Ejercicio 4: Calcular el promedio de un estudiante en una materia con tres exámenes\n\n");

		//Codigo
		float promedio = 0;
		float nota = 0; 

		for (size_t i = 1; i < 4; i++)
		{
			printf("Ingrese la nota del examen numero %i\n",i);
			scanf("%f",&nota);
			promedio+=nota;
		}
		promedio/=3;
		printf("El promedio de sus examenes es: %f\n",promedio);
		break;
	case 5: //Ejercicio 5

		printf("Ejercicio 4: Ingresar una nota y verificar si un alumno aprobó o desaprobó un examen.\n\n");

		//Codigo

		nota = 0;
		printf("Ingrese la nota de su examen\n");
		scanf("f",&nota);
		if (nota >=6.0)
		{
			printf("Examen Aprobado\n");
		}else{
			printf("Examen Desaprobado\n");
		}
		break;
	case 6: //Ejercicio Comp 1

		printf("Ejercicio Complementario 1: Se le solicita al usuario ingresar una número entero, \
		e imprimir por pantalla el número en forma de texto. Por ejemplo, si se ingresa el 4, el programa debe imprimir por pantalla \"cuatro\".\n\n");

		//Codigo
		int n = 0;
		printf("Ingrese un numero del 0 al 9 y le diremos como se escribe en letras");
		scanf("%i",&n);

		switch (n)
		{
		case 0:
			printf("cero");
			break;
		case 1:
			printf("uno");
			break;
		case 2:
			printf("dos");
			break;
		case 3:
			printf("tres");
			break;
		case 4:
			printf("cuatro");
			break;
		case 5:
			printf("cinco");
			break;
		case 6:
			printf("seis");
			break;
		case 7:
			printf("siete");
			break;
		case 8:
			printf("ocho");
			break;
		case 9:
			printf("nueve");
			break;
		default:
			break;
		}
	case 7: //Ejercicio Comp 2
			{
			//Codigo
			printf("Ejercicio Complementario 2: Probar que sucede si intentamos imprimir un número con \%c en lugar de con \%d. Probar qué sucede si imprimimos con %d un carácter.\n\n");
			printf("a)se va a intentar imprimir '1' con '\%c' y, luego,\nb) 'a' con '\%d'.- \n\n");
			printf("a) %c\n",1);
			printf("b) %d\n",'a');
			}
			break;
	case 8://Ejercicio Comp 3
			{
			//Codigo
			char prueba;
			printf("Ejercicio Complementario 3: Probar que sucede si intentamos leer con scanf, dos caracteres seguidos. Probar usar dos scanf separados. Luego imprimirlos.\n\n");
			printf("(Con un solo scanf() ): Ingrese 2 caracteres seguidos, puede ser 'aa' a modo de ejemplo y se intentara imprimir por pantalla los 2 caracteres.");
			scanf("%c",&prueba);
			printf("%c",prueba);
			printf("(Con dos scanf() ): Ingrese 2 caracteres seguidos, puede ser 'aa' a modo de ejemplo y se intentara imprimir por pantalla los 2 caracteres.");
			scanf("%c",&prueba);
			scanf("%c",&prueba);
			printf("%c",prueba);
			}
			break;
	default:
		//Salir
		printf("Programa Terminado, pulse una tecla para salir.");
		getchar();
		break;
	}

	

	return (0);
}