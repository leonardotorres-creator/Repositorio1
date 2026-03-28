#include <stdio.h>
#include <string.h>

char ID[10], nombre[20];
int producto_stock;
float precio_unitario;

int main (){
    //Se piden el ID, nombre, stock y precio unitario del producto
    
    do
    {
        printf("Ingrese el ID del producto, ID de 10 caracteres \n");
        fgets(ID, sizeof(ID), stdin);
        ID[strcspn(ID, "\n")] = '\0';// Eliminar el salto de línea al final del ID 
    } while (strlen(ID) == 0 || strlen(ID) > 10); // Verificar que el ID no esté vacío y no exceda los 10 caracteres
    
    printf("Ingrese el nombre del producto \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;// Eliminar el salto de línea al final del nombre 

    printf("Ingrese el stock del producto \n");
    //Para verificar si el stock ingresado es positivo, no existe el stock negativo-
    while ((scanf("%d", &producto_stock) != 1) || producto_stock<0)
    {
        while(getchar() != '\n'); //limpiar bufer de entrada
        printf("No puede existir esa cantidad de stock \n");
        printf("Ingresar de nuevo el stock del producto \n");
    }

    while(getchar() != '\n');
    
    printf("Ingrese el precio unitario del producto \n");
    //Para verificar si el precio es el adecuado, comparando si el valor es positivo o si el valor es un numero
    while ((scanf("%f", &precio_unitario) != 1) || precio_unitario<0)
    {
        while(getchar() != '\n');  //limpiar el buffer de entrada
        printf("Error el valor ingresado es incorrecto \n");
        printf("Ingresar de nuevo el precio unitario del producto \n");
    }
    
}