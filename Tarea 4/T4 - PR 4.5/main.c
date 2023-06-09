#include <stdio.h>

/*Rango de calificaciones
El programa al recibir como dato una serie de calificacions, obtiente
el rango en el que se encuentran.*/

void rango(int); /*Prototipo de funcion*/
int RA1 = 0;
int RA2 = 0;
int RA3 = 0;
int RA4 = 0;
int RA5 = 0;
/*El uso de variables lobales no es muy recomendable. En estos
problemas se utilizan unicamente con el objetivos de que el lector
pueda observar ;a firma en que se aplican.*/

void main(void)
{
    float CAL;
    printf("\nIngresa la primera calificacion del alumno: ");
    scanf("%f", &CAL);
    while (CAL != -1)
    {
        rango(CAL); /*Llamada a la funcion rango. Se pasa un parametro por valor*/
        printf("\nIngresa la siguiente calificacion del alumno: ");
        scanf("%f", CAL);
    }
    printf("\0..3.99 = %d", RA1);
    printf("\n4..5.99 = %d", RA2);
    printf("\n6..7.99 = %d", RA3);
    printf("\n8..8.99 = %d", RA4);
    printf("\n9..10   = %d", RA5);
}

void rango(int VAL)
/*La funcion incrementa una variante dependiendo del valor del paramtro VAL*/
{
    if (VAL < 4)
        RA1++;
    else
        if (VAL < 6)
            RA2++;
        else
            if (VAL < 8)
                RA3++;
            else
                if (VAL < 9)
                    RA4++;
                else
                    RA5++;

}
