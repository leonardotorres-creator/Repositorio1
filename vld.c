#include "vld.h"

int valid_int ()
{
    int valor;
    int leido;

    while (1) {
        leido = scanf("%d", &valor);

        if (leido != 1) {
            // Caso: El usuario ingresó letras
            printf("\nERROR: Entrada no valida. Por favor, ingresa un numero.\n");
            while (getchar() != '\n');
        } else{
            break;
        }
    }
    return valor;
}

float valid_float ()
{
    float valor;
    int leido;

    while (1) {
        leido = scanf("%f", &valor);

        if (leido != 1) {
            // Caso: El usuario ingresó letras
            printf("\nERROR: Entrada no valida. Por favor, ingresa un numero.\n");
            while (getchar() != '\n');
        }else{
            break;
        }
    }
    return valor;
}