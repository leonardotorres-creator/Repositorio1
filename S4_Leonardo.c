/*
Autor: Leonardo Torres
Fecha: 14/04/2025
Descripcion: Para registrar los 10 producctos de una empresa en tres surcursales
*/
#include <stdio.h>
#include <string.h>
#include "productos.h"

// Definición de variables globales
char *sucursal[3] = {"1) Norte", "2) Sur", "3) Centro"};
float precio[3][10];
char nombre[10][20];
int opc;
int npro = 0;
int cantidad[3][10];

int main() {
    int menu_opc;

    printf("--- SISTEMA DE GESTION DE INVENTARIO ---\n");
    printf("Escoja la sucursal para trabajar:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", sucursal[i]);
    }
    printf("Seleccion: ");
    scanf("%d", &opc);

    // Validamos que la sucursal sea correcta antes de seguir
    if (opc < 1 || opc > 3) {
        printf("Sucursal no valida. Saliendo del programa...\n");
        return 1;
    }

    do {
        printf("\n--- MENU SUCURSAL: %s ---\n", sucursal[opc-1]);
        printf("1. Registrar productos y precios\n");
        printf("2. Buscar un producto por nombre\n");
        printf("3. Ver precio total y promedio\n");
        printf("4. Ver producto mas caro y mas barato\n");
        printf("5. Cambiar de sucursal\n");
        printf("0. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &menu_opc);

        switch (menu_opc) {
            case 1:
                nombre_precio();
                break;
            case 2:
                if (npro > 0) buscar_producto();
                else printf("Error: Primero debe registrar productos.\n");
                break;
            case 3:
                if (npro > 0) precio_sucursal();
                else printf("Error: No hay datos registrados.\n");
                break;
            case 4:
                if (npro > 0) precio_mas_caro_barato();
                else printf("Error: No hay datos registrados.\n");
                break;
            case 5:
                printf("\nSeleccione nueva sucursal (1-3): ");
                scanf("%d", &opc);
                break;
            case 6: 
                if (npro > 0) total_unidades_vendidas();
                else printf("Error: No hay datos registrados.\n");
                break;
            case 0:
                printf("Cerrando sistema...\n");
                break;
            default:
                printf("Opcion no reconocida.\n");
        }
    } while (menu_opc != 0);

    return 0;
}