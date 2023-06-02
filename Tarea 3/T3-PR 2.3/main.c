#include <stdio.h>

/*Billete de ferrocarril.
el programa calcula el costo de un billete de ferrocarril teniendo enm
cuenta la distancia entre las dos ciudades y el tiempo de permanencia
del pasajero.

DIS y TIE: variabes de tipo entero .
BIL: variable de tipo real.*/

void main(void)
{
    int DIS, TIE;
    float BIL;
    printf("\nIngrese la distancia entre ciudades y el tiempo de estancia: ");
    scanf("%d %d", &DIS, &TIE);
    if ((DIS*2 > 500) && (TIE > 10))
        BIL = DIS * 2 * 0.19 * 0.8;
    else
        BIL = DIS * 2 * 0.19;
    printf("\nCosto del billete %7.2f", BIL);
}
