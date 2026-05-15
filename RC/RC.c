/*
Programa: 
Autor: Leonardo Torres
Descripcion: Optimizacion de produccion en una fabrica de compnentes electronicos
*/

#include <stdio.h>
#include <string.h>
void informacion(char nombres[][30], int tam, float *p, float *c);

int main()
{
    char productos[5][30] = {"Chips", "Capacitores", "Transistores", "Diodos", "Resistores"};//Productos que se fabricaran
    float tiempo[5] = {10.5, 4.6, 6.3, 2.1, 7.2}; //El tiempo esta en segundos osea 10.5 segundos = 10 segundos y medio.
    float dinero_producto[5] = {0.50, 0.05, 0.13, 0.30, 0.03}; //Dinero en dolares estodounidenses en orden de prodcuto.
    char recursos[10][30] = {"Ceramica", "Oro", "Carcasas-de-aluminio", "Alambre-de-Cobre", "Obleas-de-Silicio", "Carbon-pulverizado", "Agua-Ultra-Pura", "EUV", "Wafers", "DINERO-TOTAL=>"};
    float recursos_cantidad[10] = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 1000000};//Cantidades para cada recurso escrito en oreden
    float recurso_precio[10] = {10, 13.4, 5.6, 23.4, 5, 0.05, 1.6, 20.6, 0.3, 0};

    printf("\n=================Datos de los productos=================\n");
    printf("====Producto======Costo unitario======Tiempo de produccion====\n");
    informacion(productos, 5, dinero_producto, tiempo);

    printf("=================RECURSOS=================\n");
    printf("====Recurso=============Cantidad==============Precio====\n");
    informacion(recursos, 10, recursos_cantidad, recurso_precio);
}

void informacion(char nombres[][30], int tam, float *p, float *c)
{
    for (int i = 0; i < tam; i++)//Detecta el porte de las palabras y dependindo de eso imprime los tab necesarios para que los valorres se centren
    {
        int contador = 0;
        for (int j = 0; nombres[i][j] != '\0'; j++)
        {
            contador++;
        }
        
        if (contador < 7)
        {
            printf("%s\t\t\t", (nombres[i]));
        }else if (contador > 15)
        {
            printf("%s\t", (nombres[i]));
        }else
        {
            printf("%s\t\t", (nombres[i]));
        }
        printf("%.2f\t\t", *(p+i));
        printf("%.2f\n", *(c+i));
    }
}