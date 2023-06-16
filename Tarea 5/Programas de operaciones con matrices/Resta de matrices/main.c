#include <stdio.h>

int main()
{
   int MT1[10][10], MT2[10][10], MTRES[10][10];/*Declaracion de Matrices 1, 2  y el resultado de estas*/
   int filas, columnas, i, j;/*Identificador de filas y columnas como enteros*/

   printf("\nIngrese el numero de filas y columnas de las matrices: \n");
   scanf("%d %d", &filas, &columnas);

   printf("\nIngrese los elementos de la primera matriz: \n");/*Insercion de los datos de la primera matriz*/
   for (i = 0; i < filas; i++)
    {
      for (j = 0; j < columnas; j++)
      {
         scanf("%d", &MT1[i][j]);
      }
   }
   printf("Ingrese los elementos de la segunda matriz:\n");/*Insercion de los datos de la segunda matriz*/
   for (i = 0; i < filas; i++)
    {
      for (j = 0; j < columnas; j++)
      {
         scanf("%d", &MT2[i][j]);
      }
   }

   // Resta de matrices
   for (i = 0; i < filas; i++) {
      for (j = 0; j < columnas; j++)
        {
         MTRES[i][j] = MT1[i][j] - MT2[i][j];/*Operacion respectiva del programa*/
        }
   }

   /*Imprimir la matriz resultado*/
   printf("La resta de ambas matrices es:\n");/*Impresion del resultado de la resta de matrices*/
   for (i = 0; i < filas; i++) {
      for (j = 0; j < columnas; j++) {
         printf("%d ", MTRES[i][j]);
      }
   }
   return 0;
}
