/*
Autor:Leonardo Torres
Descripcion: Rotación de arreglo
    Dado un arreglo de N enteros, desplaza todos los elementos K posiciones hacia la derecha. Los elementos que salen por la derecha 
    vuelven por la izquierda.
*/

#include <stdio.h>
#include "vld.h"

float desplazamiento(int count, int tamano, float vector[],float vec[]);

int main()
{
    int n = valid_int("Ingrese el tamaño del arreglo: ", 1, 100);
    int k = valid_int("Ingrese el número de posiciones a desplazar: ", 0, n-1);
    float arreglo[n];
    float arreglof[n];
    for (int i = 0; i < n; i++)
    {
        arreglo[i] = valid_float("Ingrese los numeros que iran dentro del arreglo (-100 a 100):", -100, 100);
    }

    desplazamiento(k, n, arreglo, arreglof);
    
    printf("El vector con los numero desplazados a la derecha es: \n");
    for (int i = 0; i < n; i++)
    {
        printf("--%.1f", arreglof[i]);
    }

    printf("Vector original: \n");
    for (int i = 0; i < n; i++)
    {
        printf("--%.1f", arreglo[i]);
    }
    
    return 0;
}

float desplazamiento(int count, int tamano ,float vector[], float vec[])
{
    for (int i = 0; i < tamano; i++)
    {
        vec[(i+count)%tamano] = vector[i];
    } 
}
