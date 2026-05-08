/*
Autor: Leonardo Torres
Descripcion: Eliminar numeros repetidos de un vector
*/

#include<stdio.h>

int repetidos(int original[], int porte, int cambio[]);

int main(int argc, char const *argv[])
{
    int n=0;
    printf("Porte del vector:");
    scanf("%d", &n);
    int vector[n];
    int final[n];
    printf("Numeros en el vector:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
        final[i]=vector[i];
    }

    printf("El vector original:");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", vector[i]);
    }

    repetidos(vector, n, final);
    
    printf("El vector sin repeticiones:");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", final[i]);
    }
    
    return 0;
}

int repetidos(int original[], int porte, int cambio[])
{
    for (int i = 0; i < porte; i++)
    {
        for (int j = 1; j < porte; j++)
        {
            if (cambio[i]==original[i+j])
            {
                cambio[j+i] = 0;
            }else
            {
                continue;
            }
            
        }
        
    }
}