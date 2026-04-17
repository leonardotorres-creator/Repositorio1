#include "vld.h"

int valid_int (char* mensaje, int min, int max)
{
    int valor;
    int leido;

    while (1) {
        printf("%s", mensaje);
        leido = scanf("%f", &valor);

        if (leido != 1) {
            // Caso: El usuario ingresó letras
            printf("\nERROR: Entrada no valida. Por favor, ingresa un numero.\n");
            while (getchar() != '\n');
        } else if (valor < min || valor > max) {
            // Caso: El numero está fuera de rango
            printf("ERROR: El valor debe estar entre %d y %d.\n", min, max);
        } else {
            while (getchar() != '\n'); 
            return valor;
        }
    }
}

float valid_float (char* mensaje, float min, float max)
{
    int valor;
    int leido;

    while (1) {
        printf("%s", mensaje);
        leido = scanf("%f", &valor);

        if (leido != 1) {
            // Caso: El usuario ingresó letras
            printf("\nERROR: Entrada no valida. Por favor, ingresa un numero.\n");
            while (getchar() != '\n');
        } else if (valor < min || valor > max) {
            // Caso: El numero está fuera de rango
            printf("ERROR: El valor debe estar entre %.2f y %.2f.\n", min, max);
        } else {
            while (getchar() != '\n'); 
            return valor;
        }
    }
}