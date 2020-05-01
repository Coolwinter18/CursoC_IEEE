#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//Clase 4
float areaTriangulo(float base, float altura)
{
	return base*altura*0.5;
}
char caracterMayor(char string[])
{
	char mayor = string[0];
	for (size_t i = 0; i < strlen(string); i++)
	{
		if (string[i]>mayor)
		{
			mayor = string[i];
		}
		
	}
	return mayor;
}
int fibonacci(int n)
{
  if (n>2)
    return fibonacci(n-1) + fibonacci(n-2);
  else if (n==2)
    return 1;
  else if (n==1)       
    return 1;
  else if (n==0)
    return 0;
}
int factorial(n)
{
	if (n==0)
		return 1;
	else
		return n*factorial(n-1);
	
}
const char* reversoString(char entrada[],char salida[],int control)
{
	if(control==strlen(entrada))
		return strcat(salida,entrada[control]);
	else
		return strcat(salida,reversoString(entrada,salida,control+1));
	
	
}
int ackermann(int x, int y)
{
	if(x<0 || y<0)
		return -1;
	if(x==0)
		return y+1;
	if(y==0)
		return ackermann(x-1,1);
	return ackermann(x-1,ackermann(x,y-1));
}
bool parentesis(char string[])
{
	int control = 0;
	for (size_t i = 0; i < strlen(string); i++)
	{
		if (string[i]=='(')
		{
			control+=1;
		}
		if (string[i]==')')
		{
			control-=1;
		}
		
	}
	if (control == 0)
	{
		return true;
	}else
	{
		return false;
	}
}
int main()
{
	int inicioComplementarios = 5;
	int finComplementarios = 2;
	int op = 0;
	int j;
	do{
		for (size_t i = 1; i <= inicioComplementarios; i++)
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
		printf("%i) Salir\n",(finComplementarios + 1));

		printf("Ingrese el numero para seleccionar el ejercicio \n");
		scanf("%d",&op);
	
	}while(op < 1 || op > (finComplementarios + 1));
	switch (op)
	
	{
	case 1: //Ejercicio 1
	{
		printf("Ejercicio 1: Crear funcion que calcule el área de un triángulo, llamarla desde la función main.\n\n");
		//Codigo
		printf("el Area del triangulo de base 2 y altura 5 es: %f",areaTriangulo(2.0,5.0));
	}
	break;
	case 2: //Ejercicio 2
	{
		printf("Ejercicio 2: Crear función que reciba un string y devuelva la letra más alta (b es mayor que a)\n");
		

		//Codigo
		char string1[150] = "HoLa MuNdo2020";
		printf("String de muestra: 'HoLa MuNdo2020, el mayor caracter del string es: %c\n",caracterMayor(string1));
	}	
	break;
	case 3: //Ejercicio 3
	{
		printf("Ejercicio 3: Crear funcion recursiva que calcule un término de la serie de Fibonacci //nosotros\n\n");
		int n = 0;
		//Codigo
		printf("Ingrese el termino que desea calcular de la Serie de Fibonacci:\n");
		scanf("%d",&n);
	}
	break;	
	case 4: //Ejercicio 4
	{
		printf("Ejercicio 4: Crear funcion recursiva que calcule el factorial de un valor.\n\n");

		//Codigo
		printf("el factorial de 50 es:%i\n",factorial(50));
	}
	break;
	case 5: //Ejercicio 5
	{
		printf("Ejercicio 5: Crear funcion recursiva que genere el inverso de un string.\n\n");

		//Codigo
		printf("El reverso de 'Hola Mundo' es: &s",reversoString("Hola Mundo","",0));
	}
	break;
	case 6: //Ejercicio Comp 1
	{
		printf("Ejercicio Complementario 1: Implementar la función recursiva de Ackermann.");
		//Codigo
		printf("el Ackermann del par 4,4 es: %i",ackermann(4,4));
	}
	break;
	case 7: //Ejercicio Comp 2
	{
		printf("Ejercicio Complementario 2: Escribir una función que reciba como argumento \
		una cadena de caracteres, y chequee que no existan paréntesis sin cerrar en la cadena.");
		//Codigo
		char cadena[255];
		printf("Ingrese la cadena, y le diremos si los parentesis estan completos.\n");
		scanf("%s",&cadena);
		printf(parentesis(cadena));
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