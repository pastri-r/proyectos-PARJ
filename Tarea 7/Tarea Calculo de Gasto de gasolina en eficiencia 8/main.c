#include <stdio.h>

#define COSTO_COMBUSTIBLE 4.5  // Costo de combustible por litro

int main() {
    int eficiencia_min = 8;  // Eficiencia m�nima
    int eficiencia_max = 16; // Eficiencia m�xima

    int distancia_recorrida;

    printf("Ingrese la distancia recorrida (en kilometros): ");
    scanf("%d", &distancia_recorrida);

    printf("Eficiencia\tGasto de Combustible\tGasto Promedio\tGastos Varios\tTotal\n");
    printf("------------------------------------------------------------------------\n");

    int eficiencia;
    for (eficiencia = eficiencia_min; eficiencia <= eficiencia_max; eficiencia++) {
        float gasto_combustible = (float) distancia_recorrida / eficiencia; // C�lculo del gasto de combustible en litros
        float gasto_promedio = gasto_combustible * COSTO_COMBUSTIBLE; // C�lculo del gasto promedio
        float gastos_varios = 10.0; // Ejemplo de gastos varios
        float costo_total = gasto_promedio + gastos_varios; // C�lculo del costo total

        printf("%d\t\t%.2f\t\t\t%.2f\t\t%.2f\t\t%.2f\n", eficiencia, gasto_combustible, gasto_promedio, gastos_varios, costo_total);
    }

    return 0;
}
