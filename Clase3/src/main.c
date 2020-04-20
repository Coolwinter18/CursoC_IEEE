#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Clase 3
int main()
{
	int inicioComplementarios = 2;
	int finComplementarios = 5;
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
		printf("Ejercicio 1: Crear un registro que contenga nombre y edad de un estudiante.\n");
		printf("1.a) Crear un arreglo de registros del punto anterior, y almacenar los datos de 10 estudiantes.\n\n");
		//Codigo
		struct student
		{
			char name[250];
			short age;
		};
		struct student array[10];
		for (size_t i = 0; i < strlen(array); i++)
		{
			printf("Ingrese el nombre del alumno Nro:%i\n",i+1);
			scanf("%s",&array[i].name);
			print("Ingrese la edad del Alumno Nro: %i\n",i+1);
			scanf("%d",&array[i].age);
		}
		printf("Datos Guardados:\n");
		for (size_t i = 0; i < strlen(array); i++)
		{
			printf("Nombre: %s Edad: %i \n\n",array[i].name,array[i].age);
		}
	}
	break;
	case 2: //Ejercicio 2
	{
		printf("Ejercicio 2: Dado un string, recorrerlo y guardar en otro arreglo los siguientes valores:\n");
		printf("Cantidad de\na)Espacios en blanco\nb)Mayusculas\nc)Minusculas\n\n");

		//Codigo
		printf("String de muestra: 'HoLa MuNdo2020");
		char string[150] = "HoLa MuNdo2020";
		int arreglo[3] = {0,0,0};
		for (size_t i = 0; i < strlen(string); i++)
		{
			if (string[i]==' ')
			{
				arreglo[0]+=1;
			}else
			{
				if (isalpha(string[i]))
				{
					if (string[i]==toupper(string[i]))
					{
						arreglo[1]+=1;
					}else
					{
						arreglo[2]+=1;
					}
					
					
				}
				
			}
			
			
		}
		char result[3][50] = {"Espacios","Mayusculas","Minusculas"};
		for (size_t i = 0; i < strlen(result); i++)
		{
			printf("%s : %i\n",result[i],arreglo[i]);
		}
	}	
	break;
	case 3: //Ejercicio 1 Comp
	{
		printf("Ejercicio Complementario 1: Concatenar dos arreglos de caracteres de cualquier longitud.\n\n");

		//Codigo
		char string1[255],string2[255];
		printf("Ingrese primer string a concatenar:\n");
		scanf("%s",&string1);
		printf("Ingrese segundo string a concatenar:\n");
		scanf("%s",&string2);
		printf("String concatenado: %s", strcat(string1, string2));
	}
	break;	
	case 4: //Ejercicio 2 Comp
	{
		printf("Ejercicio Complementario 2: Comprobar si un arreglo de caracteres es palindromo.\n\n");

		//Codigo
		printf("el string de prueba es 'neuquen'\n");
		char string[] = {"neuquen"};
		int start = 0,end,band = 1;
		if (strlen(string)%2==0)
		{
			end = (strlen(string))/2.0;
		}else
		{
			end= (strlen(string)+1)/2.0;
		}
		while (band == 1 && start <= end)
		{
			if (string[start]!=string[strlen(string) - start])
			{
				band = 0;
			}
			
		}
		if (band)
		{
			printf("El string es palindromo");
		}else
		{
			print("El stirng NO es palindromo");
		}
	}
	break;
	case 5: //Ejercicio 3 Comp
	{
		printf("Ejercicio Complementario 3: Dado un conjunto de mediciones y el valor real, calcular error absoluto, relativo y porcentual\n\n");

		//Codigo
		float mediciones[]= {2.9 , 3.1 , 3.2 , 3.0 , 2.4 , 3.0, 3.2};
		float valorReal = 3.0;
		printf("Valor Real: %f\n",valorReal);
		for (size_t i = 0; i < strlen(mediciones); i++)
		{
			printf("Valor: %f, Error Abs: %f, Error Rel: %f, Error Por: %f",valorReal-mediciones[i],(valorReal-mediciones[i])/valorReal,100/valorReal*(valorReal-mediciones[i]));
		}
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