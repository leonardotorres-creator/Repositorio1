#include <stdio.h>
#include <string.h>
#include <ctype.h> //isdigit() para validar que el ID sea numérico
#include <stdlib.h> //atoi() para convertir string a entero

int main() {
    int ventasRealizadas = 0, esValido=1;
    char nombre[50], id[10], stock[10], precio[10];
    float preciofloat, gananciasTotal = 0.0;
    int opcion, cantidad, stockInt;
    float descuento, precioFinal, ganancia;
    
    // 1. REGISTRO DEL PRODUCTO
    printf("\n=== REGISTRO DE PRODUCTO ===");
    do
    {
        printf("\nIngrese ID del producto: ");
        scanf("%s", &id);
        // Validar que el ID sea un número positivo y no contenga letras
        for (int i = 0; i < 10; i++)
            {
                if(!isdigit(id[i])) {// Verificar si el carácter no es un dígito
                    if(atoi(id) <= 0) {// Si el primer carácter no es un dígito, mostrar mensaje de error
                        printf("ID no valido. Debe ser un número positivo.\n");
                        break;
                    }else if (!isdigit(id[0])){
                        printf("ID no valido. Debe contener solo números.\n");
                        break;
                    }
                }    
            }
    } while (atoi(id) <= 0 || !isdigit(id[0]));
    
    printf("✓ ID válido.\n");
    
    while(getchar() != '\n'); // Limpiar reciduos del ID
    
    printf("Ingrese nombre del producto: ");
    scanf("%s", nombre);

    while(getchar() != '\n');//Limpia todo despues de un espacio en el nombre del producto

    // Validar que el stock no sea negativo
    do
    {
        printf("Ingrese stock inicial: ");
        scanf("%s", &stock);
        for(int i = 0; stock[i] != '\0'; i++)
            {
                //Vlidar que el stock sea un número positivo y no contenga letras
                if(!isdigit(stock[i])) {
                    // Si el primer carácter no es un dígito, mostrar mensaje de error
                    if(atoi(stock) <= 0) {
                        printf("Stock no valido. Debe ser un número positivo.\n");
                        break;
                    }else if (!isdigit(stock[0])){
                        printf("Stock no valido. Debe contener solo números.\n");
                        break;
                    }
                }    
            }
    } while (atoi(stock) <= 0 || !isdigit(stock[0]));

    stockInt = atoi(stock); // Convertir stock a entero para operaciones posteriores
    
    //Validar que el precio pueda ser decimal, positivo y no contenga letras
    do{
        printf("Ingrese precio unitario: ");
        scanf("%s", precio);

        int puntos = 0;
        for (int i = 0; precio[i] != '\0'; i++) {
            // Permitir dígitos
            if (isdigit(precio[i])) {
                continue;
            }
            // Permitir 1 solo punto decimal (pero que no sea el primer caracter)
            else if (precio[i] == '.' && puntos == 0 && i > 0) {
                puntos++;
            }
            else {
                esValido = 0;
                break;
            }
        }
        if (!esValido) {//se encontro un caracter no valido
            printf("Precio no valido. Debe ser un numero positivo.\n");
        } else {
            // Convertir el precio a float
            preciofloat = atof(precio);
                // Validar que el precio sea mayor a cero
            if (preciofloat <= 0) {
                printf("El precio debe ser mayor a cero.\n");
                esValido = 0;
            }
        }
    } while (!esValido);
    
    printf("\n¡Producto registrado exitosamente!\n\n");
    while(getchar() != '\n');
    
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
                if(cantidad > stockInt) {
                    printf("ERROR: Stock insuficiente. Disponible: %d unidades.\n\n", stockInt);
                } else {
                    printf("Descuento opcional (%%): ");
                    scanf("%f", &descuento);
                    
                    // Validación descuento
                    if(descuento < 0 || descuento > 100) {
                        printf("ERROR: Descuento debe estar entre 0 y 100.\n\n");
                        break;
                    }
                    
                    // Calcular ganancia con descuento
                    precioFinal = preciofloat * (1 - descuento / 100);
                    ganancia = precioFinal * cantidad;
                    
                    // Actualizar stock y ganancias
                    stockInt -= cantidad;
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
                    stockInt += cantidad;
                    printf("✓ Stock actualizado a: %d unidades\n\n", stockInt);
                }
                break;
                
            case 3: // CONSULTAR
                printf("\n--- INFORMACIÓN DEL PRODUCTO ---\n");
                printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
                printf("-\t\t------\t\t-----\t\t------\n");
                printf("%s\t\t%s\t\t%d\t\t%.2f\n\n", id, nombre, stockInt, preciofloat);
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