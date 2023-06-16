#include <stdio.h>

int main()
{
   int MT1[10][10], MTFAC[10][10]; /*Declaracion de matriz a usar y su resultado*/
   int filas, columnas, i, j;/*Identificador de filas y columnas como enteros*/

   printf("\nIngrese el numero de filas y columnas de las matrices: \n");
   scanf("%d %d", &filas, &columnas);

   printf("\nIngrese los elementos de la matriz: \n");/*Insercion de los datos de la matriz*/
   for (i = 0; i < filas; i++)
    {
      for (j = 0; j < columnas; j++)
      {
         scanf("%d", &MT1[i][j]);
      }
   }

   // Potenciacion de matrices
   for (i = 0; i < filas; i++) {
      for (j = 0; j < columnas; j++)
        {
         MTFAC[i][j] = MT1[i][j] * MT1[i][j];/*Operacion respectiva del programa, en este programa
         al ser potenciacion se multiplica la matriz por si misma*/
        }
   }

   /*Imprimir la matriz factor*/
   printf("El factor de ambas matrices es:\n");/*Impresion del factor de la potenciacion de matrices*/
   for (i = 0; i < filas; i++) {
      for (j = 0; j < columnas; j++) {
         printf("%d ", MTFAC[i][j]);
      }
   }
   return 0;
}
