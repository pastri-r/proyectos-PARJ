#include <stdio.h>
#include <math.h>
/*Pares e impares.
El programa al recibir como datos N numeros enteros, obtiene la suma de los numeros pare y calcula el promedio de los impares
I, N, NUM, SPA, SIM, CIM: variables de tipo entero.*/

void main(void)
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;
    printf("\nIngrese el numero de los datos que se van a procesar:\t");
    scanf("%d", &N);
    if (N > 0)
    {
        for(I=1; I <= N; I++)
        {
            printf("\nIngrese el numero de %d: ", I);
            scanf("%d", &NUM);
            if(NUM)
                if(pow(- 1, NUM) > 0)
                    SPA = SPA + NUM;
            else
            {
                SIM = SIM + NUM;
                CIM++;
            }
        }
        printf("\nLa suma de los numeros pares es de: %d", SPA);
        printf("\nEl promedio de los numeros impares es: %5.2f", (float)(SIM / CIM));
    }
    else
        printf("\nEl valor de N es incorrecto");
}
