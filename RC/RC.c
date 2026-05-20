/*
Programa: 
Autor: Leonardo Torres
Descripcion: Optimizacion de produccion en una fabrica de compnentes electronicos
*/

#include <stdio.h>
#include <string.h>
void informacion(char nombres[][30], int tam, float *p, float *c);
void buscar();
int menu_pri();

int main()
{
    char productos[5][30] = {"Chips", "Capacitores", "Transistores", "Diodos", "Resistores"};//Productos que se fabricaran
    float tiempo[5] = {10.5, 4.6, 6.3, 2.1, 7.2}; //El tiempo esta en segundos osea 10.5 segundos = 10 segundos y medio.
    float dinero_producto[5] = {0.50, 0.05, 0.13, 0.30, 0.03}; //Dinero en dolares estodounidenses en orden de prodcuto.
    char recursos[10][30] = {"Ceramica", "Oro", "Carcasas-de-aluminio", "Alambre-de-Cobre", "Obleas-de-Silicio", "Carbon-pulverizado", "Agua-Ultra-Pura", "EUV", "Wafers", "DINERO-TOTAL=>"};
    float recursos_cantidad[10] = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 1000000};//Cantidades para cada recurso escrito en oreden
    float recurso_precio[10] = {10, 13.4, 5.6, 23.4, 5, 0.05, 1.6, 20.6, 0.3, 0};
    int opc = menu_pri();

    switch (opc)
    {
    case 1:
        
        break;
    case 2:
        printf("\n=================Datos de los productos=================\n");
        printf("====Producto======Costo unitario======Tiempo de produccion====\n");
        informacion(productos, 5, dinero_producto, tiempo);
        break;
    case 3:

        break;
    case 4:
        printf("========================RECURSOS========================\n");
        printf("====Recurso=============Cantidad==============Precio====\n");
        informacion(recursos, 10, recursos_cantidad, recurso_precio);
        break;
    case 5:

        break;
    default:
        break;
    }

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

int menu_pri()
{
    int sel = 0;
    printf("1) Editar informacion de productos\n");
    printf("2) Informacion de productos\n");
    printf("3) Eliminar producto\n");
    printf("-------------------------------------\n");
    printf("4) Informacion de recursos\n");
    printf("5) Producir productos\n");
    scanf("%d", &sel);
    return sel;
}

void buscar(char bus[][30], int tam)
{
    printf("Busque el producto que desea editar");
    for (int i = 0; i < tam; i++)
    {
        char tecla = _getch();
        for (int j = 0; bus[i][j] != tecla; j++)
        {
            
        }
        
    }
    
}

int menu_sec()
{
    printf("1) Editar nombre\n");
    printf("2) Editar precio\n");
    printf("3) Editar cantidad\n");
}