/*
Autor:Leonardo Torres
Descripcion: Rotación de arreglo
    Dado un arreglo de N enteros, desplaza todos los elementos K posiciones hacia la derecha. Los elementos que salen por la derecha 
    vuelven por la izquierda.
*/

#include <stdio.h>
#include "vld.h"

int main(int argc, char const *argv[])
{
    int n = valid_int("Ingrese el tamaño del arreglo: ", 1, 100);
    int k = valid_int("Ingrese el número de posiciones a desplazar: ", 0, n-1);
    float arreglo[n];
    for (int i = 0; i < n-1; i++)
    {
        arreglo[i] = float_int("Ingrese los numeros que iran dentro del arreglo (-100 a 100)", -100, 100);
    }
    

    return 0;
}


