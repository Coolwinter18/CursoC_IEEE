#include <stdio.h>

int main()
{
	int inicioComplementarios = 3;
	int finComplementarios = 5;
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
		printf("%i) Salir\n",(finComplementarios));

		printf("Ingrese el numero para seleccionar el ejercicio \n");
		scanf("%d",&op);
	
	}while(op < 1 || op > (finComplementarios + 1));
	switch (op)
	
	{
	case 1: //Ejercicio 1

		printf("Ejercicio 1: Recorrer matriz, cargando valores incrementales desde abajo hacia arriba y de izquierda a derecha.");
	
		//Codigo


	case 2: //Ejercicio 2

		printf("Ejercicio 2: Realizar el producto de 2 matrices, comprobando primero si es posible realizarlo.\n\n");

		int m, n, p, q, c, d, k, sum = 0;
  		int first[10][10], second[10][10], multiply[10][10];
 
		printf("Enter number of rows and columns of first matrix\n");
		scanf("%d%d", &m, &n);
		printf("Enter elements of first matrix\n");
		
		for (c = 0; c < m; c++)
			for (d = 0; d < n; d++)
			scanf("%d", &first[c][d]);
		
		printf("Enter number of rows and columns of second matrix\n");
		scanf("%d%d", &p, &q);
		
		if (n != p)
			printf("The multiplication isn't possible.\n");
		else
		{
			printf("Enter elements of second matrix\n");
		
			for (c = 0; c < p; c++)
			for (d = 0; d < q; d++)
				scanf("%d", &second[c][d]);
		
			for (c = 0; c < m; c++) {
			for (d = 0; d < q; d++) {
				for (k = 0; k < p; k++) {
				sum = sum + first[c][k]*second[k][d];
				}
		
				multiply[c][d] = sum;
				sum = 0;
			}
			}
		
			printf("Product of the matrices:\n");
		
			for (c = 0; c < m; c++) {
			for (d = 0; d < q; d++)
				printf("%d\t", multiply[c][d]);
		
			printf("\n");
			}
  }
  break;
  default:

  break;
	}

	return (0);
}