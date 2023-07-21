#include <stdio.h>

#define COSTO_COMBUSTIBLE 296.86       //Costo de combustible por litro.
#define POLIZA_DE_SEGURO 12000       //Costo de poliza del seguro por kilometros.
#define PRECIO_DE_NEUMATICOS 7098.52   //Costo de neumaticos individual
int main()
{
    int eficiencia_min = 8;             //Eficiencia minima
    int eficiencia_max = 16;            //Eficiencia maxima
    float distancia_recorrida;          //Valor de la distancia en cuestion.
    char Nombre_del_solicitante[20];    //Nombre del solicitante
    char Apellido_del_dolicitante[20];
    char Marca_del_auto[20];
    float costo_cambio_aceite;
    float gastos_varios;
    float Cambio_filtros;
    float cambio_bandas;
    int numero_de_neumaticos;           //Numero de neumaticos a multiplicar por el valor del precio de los mismo
    printf("Ingrese el nombre del solicitante: ");
    scanf("%s", &Nombre_del_solicitante);
    printf("Ingrese el apellido del solicitante: ");
    scanf("%s", &Apellido_del_dolicitante);
    printf("Ingrese la marca del auto: ");
    scanf("%s", &Marca_del_auto);
    printf("Ingrese la distancia recorrida (en kilometros): ");
    scanf("%f", &distancia_recorrida);
    printf("Ingrese el costo del cambio de aceite: ");
    scanf("%f", &costo_cambio_aceite);
    printf("Ingrese el costo del cambio de filtros: ");
    scanf("%f", &Cambio_filtros);
    printf("Ingrese el costo del cambio de bandas: ");
    scanf("%f", &cambio_bandas);
    printf("Ingrese el numero de neumaticos: ");
    scanf("%d", &numero_de_neumaticos);
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("Nombre del solicitante: %s %s\n", Nombre_del_solicitante, Apellido_del_dolicitante);
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("Eficiencia\t|\tGasto de Combustible\t|Gasto Promedio\t|\tGastos Varios\t|\tTotal\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    int eficiencia;
    for (eficiencia = eficiencia_min; eficiencia <= eficiencia_max; eficiencia++)
    {
        float gasto_combustible = (float) distancia_recorrida / eficiencia; // Caculo del gasto de combustible en litros
        float gasto_promedio = gasto_combustible * COSTO_COMBUSTIBLE; // Calculo del gasto promedio
        float gastos_varios = costo_cambio_aceite + Cambio_filtros + cambio_bandas + (POLIZA_DE_SEGURO / distancia_recorrida) + (PRECIO_DE_NEUMATICOS / numero_de_neumaticos); // Ejemplo de gastos varios
        float costo_total = gasto_promedio + gastos_varios; // Calculo del costo total
        printf("%d\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f\n", eficiencia, gasto_combustible, gasto_promedio, gastos_varios, costo_total);
    }
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("Cantidad de Kilometros recorridos: %f \n", distancia_recorrida);
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("Marca del auto: %s \n", Marca_del_auto);
    printf("-----------------------------------------------------------------------------------------------------------\n");

}
