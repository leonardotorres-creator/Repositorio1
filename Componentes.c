/*
Autor: Leonardo Torres
Descripcion: Practica de structs y punteros
Problema: En el desarrollo de software de bajo nivel o sistemas embebidos, la optimización de memoria es crucial. 
Te han contratado para desarrollar el núcleo de un sistema de inventario para una tienda de hardware. 
Debido a que el inventario fluctúa constantemente, no puedes usar arreglos estáticos; debes gestionar la memoria de forma dinámica.
*/

#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[100];
    float precio;
    int cantidad;
}datos;


datos infocomponentes(datos *p);
void verificarlleno();
void menu1();
int valid_int();
float valid_float();


int main()
{
    printf(BLUE"Ingrese cuantos Componentes ingresara: ");
    int n = valid_int();
    int opc = 0;

    datos componentes[n];

    menu1();
    opc = valid_int();

    switch (opc)
    {
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
    for (int i = 0; i < n; i++)
    {
        infocomponentes(componentes);
    }
        break;
    default:
        break;
    }

    
    return 0;
}

void menu1()
{
    printf(YELLOW"1) Mas componentes\n2)Menos Componentes\n3)Info Componentes\n");
}
int valid_int ()
{
    int valor;
    int leido;

    while (1) {
        leido = scanf("%d", &valor);
        while (getchar() != '\n');
        if (leido != 1) {
            // Caso: El usuario ingresó letras
            printf(RED"\nERROR: Entrada no valida. Por favor, ingresa un numero."RESET);
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
        while (getchar() != '\n');
        if (leido != 1) {
            // Caso: El usuario ingresó letras
            printf(RED"\nERROR: Entrada no valida. Por favor, ingresa un numero."RESET);
            while (getchar() != '\n');
        }else{
            break;
        }
    }
    return valor;
}

datos infocomponentes(datos *p)
{
    printf(GREEN"Ingrese el id:");
    p->id = valid_int();
    printf("\nNombre:");
    scanf("%s", p->nombre);
    printf("\nCantidad en stock:");
    p->cantidad = valid_int();
    printf("\nPrecio:");
    p->precio = valid_float();
}