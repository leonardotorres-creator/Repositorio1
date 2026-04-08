#include <stdio.h>
#include <stdlib.h>

int main() {
    system("COLOR 5C"); // Fondo rojo, letras blancas

    int ventasRealizadas = 0;
    int stockInt;
    float preciofloat, gananciasTotal = 0.0;
    int opcion, cantidad;
    float descuento, precioFinal, ganancia;

    char id[10];
    char nombre[50];
    char extra;

    int valido, i;

    printf("\n\t=== REGISTRO DE PRODUCTO ===\n");

    // VALIDAR ID (SOLO NÚMEROS)
    do {
        valido = 1;
        printf("\tIngrese ID del producto: ");
        scanf("%s", id);

        for(i = 0; id[i] != '\0'; i++){
            if(id[i] < '0' || id[i] > '9'){
                valido = 0;
                break;
            }
        }

        if(!valido){
            printf("\tID invalido. Solo numeros.\n");
        }

    } while(!valido);

    // VALIDAR NOMBRE (SOLO LETRAS)
    do {
        valido = 1;
        printf("\tIngrese nombre del producto: ");
        scanf("%s", nombre);

        for(i = 0; nombre[i] != '\0'; i++){
            if( (nombre[i] < 'A' || nombre[i] > 'Z') &&
                (nombre[i] < 'a' || nombre[i] > 'z') ){
                valido = 0;
                break;
            }
        }

        if(!valido){
            printf("\tNombre invalido. Solo letras.\n");
        }

    } while(!valido);

    // STOCK
    do {
        printf("\tIngrese stock inicial: ");
        if (scanf("%d", &stockInt) != 1) {
            printf("\tError: Ingrese un numero entero.\n");
            while(getchar() != '\n'); 
            stockInt = -1; 
        } else {
            scanf("%c", &extra);
            if (extra != '\n') {
                printf("\tError: No se admiten decimales en el stock.\n");
                while(getchar() != '\n');
                stockInt = -1;
            }
        }
    } while(stockInt < 0);

    // PRECIO
    do {
        printf("\tIngrese precio unitario: ");
        if (scanf("%f", &preciofloat) != 1) {
            printf("\tPrecio invalido.\n");
            while(getchar() != '\n');
            preciofloat = 0;
        } else if(preciofloat <= 0){
            printf("\tPrecio invalido.\n");
        }
    } while(preciofloat <= 0);

    printf("\n\t¡Producto registrado!\n\n");

    // MENÚ
    do {
        printf("\t=== MENU PRINCIPAL ===\n");
        printf("\t1. Vender\n");
        printf("\t2. Reabastecer\n");
        printf("\t3. Consultar\n");
        printf("\t4. Ganancias\n");
        printf("\t5. Salir\n");
        printf("\tOpcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            printf("\tOpcion invalida\n\n");
            while(getchar() != '\n');
            continue;
        }

        switch(opcion) {

            case 1:
                printf("\n\t--- VENTA ---\n");
                printf("\tCantidad a vender: ");

                if (scanf("%d", &cantidad) != 1) {
                    printf("\tError: Ingrese solo numeros enteros.\n\n");
                    while(getchar() != '\n');
                    break;
                }

                scanf("%c", &extra);
                if (extra != '\n' && extra != ' ') {
                    printf("\tError: No se permiten decimales.\n\n");
                    while(getchar() != '\n');
                    break;
                }

                if(cantidad <= 0){
                    printf("\tCantidad invalida.\n\n");
                }
                else if(cantidad > stockInt){
                    printf("\tStock insuficiente.\n\n");
                }
                else{
                    printf("\tDescuento (%%): ");
                    scanf("%f", &descuento);

                    if(descuento < 0 || descuento > 100){
                        printf("\tDescuento invalido.\n\n");
                        break;
                    }

                    precioFinal = preciofloat * (1 - descuento/100);
                    ganancia = precioFinal * cantidad;

                    stockInt -= cantidad;
                    gananciasTotal += ganancia;
                    ventasRealizadas++;

                    printf("\tVenta realizada.\n");
                    printf("\tTotal: %.2f\n\n", ganancia);
                }
                break;

            case 2:
                printf("\n\t--- REABASTECER ---\n");
                printf("\tCantidad a agregar: ");

                if (scanf("%d", &cantidad) != 1) {
                    printf("\tError: Ingrese solo numeros enteros.\n\n");
                    while(getchar() != '\n');
                    break;
                }

                scanf("%c", &extra);
                if (extra != '\n' && extra != ' ') {
                    printf("\tError: No se permiten decimales.\n\n");
                    while(getchar() != '\n');
                    break;
                }

                if(cantidad < 0){
                    printf("\tCantidad invalida.\n\n");
                } else {
                    stockInt += cantidad;
                    printf("\tStock actual: %d\n\n", stockInt);
                }
                break;

            case 3:
                printf("\n\t--- PRODUCTO ---\n");
                printf("\tID:\t\t%s\n", id);
                printf("\tNombre:\t\t%s\n", nombre);
                printf("\tStock:\t\t%d\n", stockInt);
                printf("\tPrecio:\t\t%.2f\n\n", preciofloat);
                break;

            case 4:
                printf("\n\t--- GANANCIAS ---\n");
                printf("\tVentas:\t\t%d\n", ventasRealizadas);
                printf("\tGanancias:\t%.2f\n\n", gananciasTotal);
                break;

            case 5:
                printf("\n\tSaliendo...\n");
                break;

            default:
                printf("\tOpcion invalida\n\n");
        }

    } while(opcion != 5);

    return 0;
}
