#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>
#include <time.h>


float* operate()
{
	
}
int main()
{
	unsigned short orden = 0;
	do
	{
		printf("Ingrese el Orden(N) de la Matriz. El minimo es 2.\n");
		scanf("%i",&orden);
	}while(orden < 2);
	float *line =NULL;
	line = realloc(line,orden*sizeof(float));
	float matrix[sizeof(line)/sizeof(float)][sizeof(line)/sizeof(float)];
	float tmp[sizeof(line)/sizeof(float)][sizeof(line)/sizeof(float)];
	free(line);
	
	for (unsigned short  i = 0; i < orden; i++)
	{
		for (unsigned short j = 0; j < orden; j++)
		{
			printf("Ingrese valor para la celda [%i,%i]\n",i,j);
			scanf("%f",&matrix[i][j]);
			if(orden > 3)
			{
				tmp[i][j] = matrix[i][j];
			}
			 
		}
		
	}
	printf("La matriz Cargada es:");
	for (short i = 0; i < orden; i++)
	{
		for (short j = 0; j <orden; j++)
		{
			printf("%f ",matrix[i][j]);
		}
		printf("\n");
		
	}
	printf("Pulse una tecla para iniciar el calculo. El metodo es por Eliminacion Gaussiana O(n**3)\n");
	getchar();

	clock_t general_start = clock();
    // Execuatable code
	float det = 0;
	switch (orden)
	{
	case 2: //orden 2 - producto cruzado
	{	
		det = matrix[0][0] * matrix[1][1] - matrix[0][1]*matrix[1][0]; 
	}
	break;
	case 3: //orden 3 - Regla de Sarrus
	{
		det += matrix[0][0]*matrix[1][1]*matrix[2][2];
		det += matrix[1][0]*matrix[2][1]*matrix[0][2];
		det += matrix[2][0]*matrix[0][1]*matrix[1][2];
		det -= matrix[0][2]*matrix[1][1]*matrix[2][0];
		det -= matrix[1][2]*matrix[2][1]*matrix[0][0];
		det -= matrix[2][2]*matrix[0][1]*matrix[1][0]; 
	}
	break;
	default: //orden 4 o mayor
	{
		/*
		Algunas consideraciones o propiedades para el calculo de determinantes.
		
		1)permutar 'm' veces filas o columnas durante el calculo, equivale a cambiar el signo del determinante a (-1)**m*Det(Matrix)
		2)se puede triangular hacia arriba o hacia abajo, este algoritmo hace la triangulacion hacia abajo.
		3)se pueden operar sobre filas y columnas.para este algoritmo, solamente se realizan operaciones entre filas y no de columnas
		
		*/
		short signo = 1;
		
		short fila = 0;
		short columna = 0;
		while(columna <= orden)//ciclo principal que opera hasta que se haya completado la triangulacion.
		{	
			float pivot = tmp[fila][columna];
			for (short i = fila +1 ; i < orden; i++)//ciclo que opera sobre 1 columna
			{
				float k = 1;
				while (tmp[fila][columna]!=0)
				{
					/* code */
				}
				
			}
				
		}
		
	}
		break;
	}
	
	//End Excecutable code
    clock_t general_stop = clock();
    double elapsed = (double)(general_stop - general_start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);
	return(0);
}