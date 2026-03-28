#include <stdio.h>
#include <string.h>

int main() {
    int id, stock, ventasRealizadas = 0;
    char nombre[50];
    float precio, gananciasTotal = 0.0;
    int opcion, cantidad;
    float descuento, precioFinal, ganancia;
    
    // 1. REGISTRO DEL PRODUCTO
    printf("=== REGISTRO DEL PRODUCTO ===\n");
    printf("Ingrese ID del producto: ");
    scanf("%d", &id);
    
    printf("Ingrese nombre del producto: ");
    scanf("%s", nombre);
    
    printf("Ingrese stock inicial: ");
    scanf("%d", &stock);
    
    printf("Ingrese precio unitario: ");
    scanf("%f", &precio);
    
    printf("\n¡Producto registrado exitosamente!\n\n");
    
    // 2. MENÚ INTERACTIVO
    do {
        printf("=== MENÚ PRINCIPAL ===\n");
        printf("1. Vender\n");
        printf("2. Reabastecer\n");
        printf("3. Consultar información\n");
        printf("4. Ver ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione opción: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1: // VENTA
                printf("\n--- REALIZAR VENTA ---\n");
                printf("Cantidad a vender: ");
                scanf("%d", &cantidad);
                
                // Validación de cantidad negativa
                if(cantidad < 0) {
                    printf("ERROR: No puede vender cantidad negativa.\n\n");
                    break;
                }
                
                // Validación de stock suficiente
                if(cantidad > stock) {
                    printf("ERROR: Stock insuficiente. Disponible: %d unidades.\n\n", stock);
                } else {
                    printf("Descuento opcional (%%): ");
                    scanf("%f", &descuento);
                    
                    // Validación descuento
                    if(descuento < 0 || descuento > 100) {
                        printf("ERROR: Descuento debe estar entre 0 y 100.\n\n");
                        break;
                    }
                    
                    // Calcular ganancia con descuento
                    precioFinal = precio * (1 - descuento / 100);
                    ganancia = precioFinal * cantidad;
                    
                    // Actualizar stock y ganancias
                    stock -= cantidad;
                    gananciasTotal += ganancia;
                    ventasRealizadas++;
                    
                    printf("✓ Venta realizada:\n");
                    printf("  Precio final/unidad: %.2f\n", precioFinal);
                    printf("  Total ganancia: %.2f\n\n", ganancia);
                }
                break;
                
            case 2: // REABASTECIMIENTO
                printf("\n--- REABASTECIMIENTO ---\n");
                printf("Unidades a agregar: ");
                scanf("%d", &cantidad);
                
                if(cantidad < 0) {
                    printf("ERROR: No puede ingresar cantidad negativa.\n\n");
                } else {
                    stock += cantidad;
                    printf("✓ Stock actualizado a: %d unidades\n\n", stock);
                }
                break;
                
            case 3: // CONSULTAR
                printf("\n--- INFORMACIÓN DEL PRODUCTO ---\n");
                printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
                printf("-\t\t------\t\t-----\t\t------\n");
                printf("%d\t\t%s\t\t%d\t\t%.2f\n\n", id, nombre, stock, precio);
                break;
                
            case 4: // GANANCIAS
                printf("\n--- RESUMEN DE GANANCIAS ---\n");
                printf("Ventas realizadas: %d\n", ventasRealizadas);
                printf("Ganancias totales: $%.2f\n\n", gananciasTotal);
                break;
                
            case 5: // SALIR
                printf("\n¡Hasta luego!\n");
                break;
                
            default:
                printf("ERROR: Opción no válida.\n\n");
        }
    } while(opcion != 5);
    
    return 0;
}