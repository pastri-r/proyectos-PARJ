#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estructura 3
El programa muestra la manera en que se declara una estructura anidada asi
como la forma de acceso de los campos de las variables o apuntadores de tipo
estructura tanto lara la lectura como para la escritura. Se utilixa ademas una
funcion que recibe como parametro un apuntador de tipo estructura.*/

typedef struct /*Declaracion de la estructura domicilio utilizando un typedef*/
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;
struct empleado /*Delclaracion de la estructura anudada empleado*/
{
  char nombre[20];
  char departamento[20];
  float sueldo;
        domicilio direccion;  /*direccion es un campo de tipo estructura
                                domicilio de la estructura empleado*/
};
void Lectura(struct empleado *a)
/*Funcion que permite leer los campos de un puntero de tpo estructura empleado*/
{
    printf("\nIngrese el nombre del empleado: ");
    gets(a->nombre);
    fflush(stdin);
    printf("\nIngrese el departamento de la empresa: ");
    gets(a->departamento);
    printf("\nIngrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    fflush(stdin);
    printf("\n—-Ingrese la dirección del empleado—-");
    printf("\n\tCalle: ");
    gets(a->direccion.calle);
    printf("\tNúmero: ");
    scanf("%d", &a->direccion.numero);
    printf("\tCódigo Postal: ");
    scanf("%d", &a->direccion.cp);
    fflush(stdin);
    printf("\tLocalidad: ");
    gets(a->direccion.localidad);
}

void main(void)
{
    struct empleado e0 = {"Arturo", "Compras", 15500.75, "San Jeronimo", 120, 3490, "Toluca"};
    struct empleado *e1, *e2, *e3, *e4;
    /*Se declaran diferentes variables y apuntadores de la estructura empleado
    para que el lector puede apreciar tambien las diferentes formas en que los
    campos reciben valores.*/

    /* En el programa principal se leen los campos de una variable, e3, y un
    apuntador de tipo estructura, *e1. */

    e1 = &e0;
    printf("\nIngrese el nombre del empleado 1: ");
    scanf("%s", &(*e1).nombre);
    fflush(stdin);
    printf("\nIngrese el departamento de la empresa: ");
    gets(e1->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    printf("\n—-Ingrese la dirección del empleado—-");
    printf("\n\tCalle: ");
    fflush(stdin);
    gets(e1->direccion.calle);
    printf("\tNúmero: ");
    scanf("%d", &e1->direccion.numero);
    printf("\tCódigo Postal: ");
    scanf("%d", &e1->direccion.cp);
    printf("\tLocalidad: ");
    fflush(stdin);
    gets(e1->direccion.localidad);

      e3 = &e0;
    printf("\nIngrese el nombre del empleado 1: ");
    scanf("%s", &(*e3).nombre);
    fflush(stdin);
    printf("\nIngrese el departamento de la empresa: ");
    gets(e3->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3->sueldo);
    printf("\n—-Ingrese la dirección del empleado—-");
    printf("\n\tCalle: ");
    fflush(stdin);
    gets(e3->direccion.calle);
    printf("\tNúmero: ");
    scanf("%d", &e3->direccion.numero);
    printf("\tCódigo Postal: ");
    scanf("%d", &e3->direccion.cp);
    printf("\tLocalidad: ");
    fflush(stdin);
    gets(e3->direccion.localidad);

    /*En la funcion Lectura se leen los campos de una variable e4, y un apuntador
    de tipo estructura *e2*/

    e2 = &e0;
    Lectura(e2);

    Lectura(&e4);

    printf("\nDatos del empleado 1\n");
    printf("%d\t%s\t%.2f\t%s", e1->nombre, e1->departamento, e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);
    printf("\nDatos del empleado 4n");
    printf("%d\t%s\t%.2f\t%s", e4->nombre, e4->departamento, e4->direccion.calle, e4->direccion.numero, e4->direccion.cp, e4->direccion.localidad);
}
