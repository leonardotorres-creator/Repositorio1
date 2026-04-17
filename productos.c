#include "productos.h"

void cuantos_productos() {
    // Usamos función de validación vld.h
    npro = valid_int("\nCuantos productos ingresara en la sucursal:", 0, 10);
}

#include "productos.h"

void nombre_precio() {
    cuantos_productos();
    for (int i = 0; i < npro; i++) {
        printf("\n--- Producto %d ---\n", i + 1);
        printf("Nombre: ");
        scanf("%s", nombre[i]);
        
        precio[opc-1][i] = valid_float("Precio: ", 0.01f, 100000.0f);
        
        // Pedimos las unidades vendidas usando tu librería vld.h
        cantidad[opc-1][i] = valid_int("Unidades vendidas: ", 0, 10000);
    }
    printf("\nDatos registrados correctamente.\n");
}

void total_unidades_vendidas() {
    int suma_unidades = 0;
    
    for (int i = 0; i < npro; i++) {
        suma_unidades += cantidad[opc-1][i];
    }
    
    printf("\n==========================================");
    printf("\nREPORTE DE VENTAS - SUCURSAL: %s", sucursal[opc-1]);
    printf("\nTotal de unidades vendidas (global): %d", suma_unidades);
    printf("\n==========================================\n");
}
// Buscar producto
void buscar_producto() {
    char nombre_buscar[20];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%s", nombre_buscar);

    for (int i = 0; i < npro; i++) {
        if (strcmp(nombre[i], nombre_buscar) == 0) {
            printf("Precio del producto %s en sucursal %s: %.2f\n", 
                   nombre[i], sucursal[opc-1], precio[opc-1][i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

// Precio más caro y barato
void precio_mas_caro_barato() {
    float mas_caro = precio[opc-1][0];
    float mas_barato = precio[opc-1][0];
    char producto_mas_caro[20];
    char producto_mas_barato[20];

    strcpy(producto_mas_caro, nombre[0]);
    strcpy(producto_mas_barato, nombre[0]);

    for (int i = 1; i < npro; i++) {
        // Lógica para el más caro
        if (precio[opc-1][i] > mas_caro) {
            mas_caro = precio[opc-1][i];
            strcpy(producto_mas_caro, nombre[i]);
        }
        // Lógica para el más barato
        if (precio[opc-1][i] < mas_barato) {
            mas_barato = precio[opc-1][i];
            strcpy(producto_mas_barato, nombre[i]);
        }
    }

    printf("\nEl precio mas caro en la sucursal %s es: %.2f del producto: %s", 
           sucursal[opc-1], mas_caro, producto_mas_caro);
    printf("\nEl precio mas barato en la sucursal %s es: %.2f del producto: %s", 
           sucursal[opc-1], mas_barato, producto_mas_barato);
}

// Precio total y promedio 
void precio_sucursal() {
    float total = 0.0f;
    for (int i = 0; i < npro; i++) 
    {
        total += precio[opc-1][i];
    }
    float promedio = (npro > 0) ? (total / npro) : 0;

    printf("\nEl precio promedio de los productos en la sucursal %s es: %.2f", sucursal[opc-1], promedio);
    printf("\nEl precio total de los productos en la sucursal %s es: %.2f\n", sucursal[opc-1], total);
}