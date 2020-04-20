#include <stdio.h>
// Dimension of input square matrix 
#define N 4
  
// Function to get cofactor of mat[p][q] in temp[][]. n is current 
// dimension of mat[][] 
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
  
    // Looping for each element of the matrix 
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            //  Copying into temporary matrix only those element 
            //  which are not in given row and column 
            if (row != p && col != q) 
            { 
                temp[i][j++] = mat[row][col]; 
  
                // Row is filled, so increase row index and 
                // reset col index 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
  
/* Recursive function for finding determinant of matrix. 
   n is current dimension of mat[][]. */
int determinantOfMatrix(int mat[N][N], int n) 
{ 
    int D = 0; // Initialize result 
  
    //  Base case : if matrix contains single element 
    if (n == 1) 
        return mat[0][0]; 
  
    int temp[N][N]; // To store cofactors 
  
    int sign = 1;  // To store sign multiplier 
  
     // Iterate for each element of first row 
    for (int f = 0; f < n; f++) 
    { 
        // Getting Cofactor of mat[0][f] 
        getCofactor(mat, temp, 0, f, n); 
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1); 
  
        // terms are to be added with alternate sign 
        sign = -sign; 
    } 
  
    return D; 
}
/* function for displaying the matrix */
void display(int mat[N][N], int row, int col) 
{ 
    for (int i = 0; i < row; i++) 
    { 
        for (int j = 0; j < col; j++) 
            printf("  %d", mat[i][j]); 
        printf("n"); 
    } 
} 
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
	{
		printf("Ejercicio 1: Recorrer matriz, cargando valores incrementales desde abajo hacia arriba y de izquierda a derecha.");
	
		//Codigo
		int k = 0;
		int matrix[3][3];
		for (size_t i =strlen(matrix); i >= 0 ; i--)
			for (size_t j = 0; j < strlen(matrix[0]); j++)
				matrix[i][j]= k++;
		for (size_t i = 0; i < strlen(matrix); i++)
		{
			for (size_t j = 0; j < strlen(matrix[0]); j++)
			{
				printf("%i",&matrix[i][j]);
			}
			printf("\n");
		}
			
	}
	break;
	case 2: //Ejercicio 2 SOURCE: https://www.programmingsimplified.com/c-program-multiply-matrices

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
	case 3: //Ejercicio Comp 1 SOURCE: https://www.geeksforgeeks.org/determinant-of-a-matrix/
	{
		printf("Ejercicio Complementario 1: Calcular el determinante de una matriz de tamaño cualquiera. \
		(Este ejercicio puede afrontarse de muchas maneras posibles, debido a los diversos algoritmos existentes para alcanzar una respuesta).");
		//Codigo
		// Driver program to test above functions 
		/* int mat[N][N] = {{6, 1, 1}, 
                     {4, -2, 5}, 
                     {2, 8, 7}}; */
  
    int mat[N][N] = {{1, 0, 2, -1}, 
                     {3, 0, 0, 5}, 
                     {2, 1, 4, -3}, 
                     {1, 0, 5, 0} 
                    }; 
  
    printf("Determinant of the matrix is : %d", 
            determinantOfMatrix(mat, N));


	}
	break;
	case 4: //Ejercicio Comp 2
	{
		printf("Ejercicio Complementario 2: Realizar el clásico juego de “ta-te-ti”,\
		 mostrar el juego mediante una matriz. Es a elección si se desea que sea de dos jugadores o contra la computadora.");
	}
	break;
  	default:
	{
		
	}
  	break;
	}; //end switch
return (0);
}