#include <stdio.h>

#define COSTO_COMBUSTIBLE 193.00        //Costo de combustible por litro.
#define POLIZA_DE_SEGURO 12000.00       //Costo de poliza del seguro.
#define PRECIO_DE_NEUMATICOS 7500.00    //Costo de neumaticos individual
int main()
{
    int eficiencia_min = 8;             //Eficiencia minima
    int eficiencia_max = 16;            //Eficiencia maxima
    float distancia_recorrida;          //Valor de la distancia en cuestion.
    char Nombre_del_solicitante[50];    //Nombre del solicitante
    float costo_cambio_aceite;
    float gastos_varios;
    float Cambio_filtros;
    float cambio_bandas;
    float costo_de_neumaticos;
    printf("Ingrese el nombre del solicitante: ");
    scanf("%s", &Nombre_del_solicitante);
    printf("Ingrese la distancia recorrida (en kilometros): ");
    scanf("%f", &distancia_recorrida);
    printf("Ingrese el costo del cambio de aceite: ");
    scanf("%f", &costo_cambio_aceite);
    printf("Ingrese el costo del cambio de filtros: ");
    scanf("%f", &Cambio_filtros);
    printf("Ingrese el costo del cambio de bandas: ");
    scanf("%f", &cambio_bandas);
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("Nombre del solicitante: %s \n", Nombre_del_solicitante);
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("Cantidad de Kilometros recorridos: %f \n", distancia_recorrida);
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("Eficiencia\t|\tGasto de Combustible\t|Gasto Promedio\t|\tGastos Varios\t|\tTotal\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    int eficiencia;
    for (eficiencia = eficiencia_min; eficiencia <= eficiencia_max; eficiencia++)
    {
        float gasto_combustible = (float) distancia_recorrida / eficiencia; // Caculo del gasto de combustible en litros
        float gasto_promedio = gasto_combustible * COSTO_COMBUSTIBLE; // Calculo del gasto promedio
        float gastos_varios = costo_cambio_aceite + Cambio_filtros + cambio_bandas + (POLIZA_DE_SEGURO * distancia_recorrida) + (PRECIO_DE_NEUMATICOS * 4); // Ejemplo de gastos varios
        float costo_total = gasto_promedio + gastos_varios; // Calculo del costo total
        printf("%d\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f\n", eficiencia, gasto_combustible, gasto_promedio, gastos_varios, costo_total);
    }
}
