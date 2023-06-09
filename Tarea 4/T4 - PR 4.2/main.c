#include <stdio.h>

/*Mayor divisor
el programa al recibir como dato un numero entero
positvo, calcula su mayor divisor.*/

int mad(int);   /*prototipo de funcion*/
void main(void)
{
    int NUM, RES;
    printf("\nIngresa el numero: ");
    scanf("%d", &NUM);
    RES - mad(NUM);
    printf("\nEl mayor divisor de %d es: %d", NUM, RES);
}

int mad(int N1)
/*esta funcion calcula el mayor divisor del numero N1*/
{
    int I = (N1 / 2);
    /*I se inicializa con el maximo valor
    posible que puede ser dvisor de N1*/
    while (N1 % I)
    /*El ciclo se mantiene activo mientras (N1 % I) sea
    distinto de cero. Cuando el resultado sea 0, se detiene,
    ya que se habra encontrado el mayor divisor de N1*/
        I--;
    return I;
}
