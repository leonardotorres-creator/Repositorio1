/*
Descripcion: Supo (Superheroes Organizacion)
*/

#include <stdio.h>
#include <string.h>
#include "colors.h"

void registro (int tam);
void buscar ();

typedef struct{
    char Origen[50];
    char poderes[100];
    char debilidades[100];
    char archienemigo[80];
}ficha_tecnica;

typedef struct{
    int ID;
    char nombre[80];
    float peso;
    float altura;
    char saga[10];
    int estado;
    ficha_tecnica ficha;
}super;

int main()
{   
    int opc=0;
    int n=0;
    printf(YELLOW"Cuantos superheroes ingresara (MAX 10)"RESET);
    do
    {
        scanf("%d", &n);
        if (n < 1 || n > 10)
        {
            printf(RED"El rango de superheroes es 1-10"RESET);
        }
        
    } while (n < 1 || n > 10);
    registro (n);
    
}

void registro(int tam)
{
    super heroe[tam];
    for (int i = 0; i < tam; i++)
    {
        printf(GREEN"============================================");
        printf("\nRegistre al Superheroe:\n");
        printf("============================================");
        printf("\nID: ");
        scanf("%d", &heroe[i].ID);
        getchar();

        printf("\nNombre: ");
        fgets(heroe[i].nombre, 80, stdin);

        printf("\nPeso: ");
        scanf("%f", &heroe[i].peso);
        getchar();
        
        printf("\nAltura: ");
        scanf("%f", &heroe[i].altura);
        getchar();

        printf("\nSaga: ");
        fgets(heroe[i].saga, 10, stdin);
        printf(RESET BLUE"\n+++++++++++++++++++++++++++++++++++++++++++");
        printf("\nAhora llenemos la Ficha tecnica:\n");

        printf("Origen: ");
        fgets(heroe[i].ficha.Origen, 50, stdin);

        printf("\nPoderes: ");
        fgets(heroe[i].ficha.poderes, 100, stdin);

        printf("\nDebilidades: ");
        fgets(heroe[i].ficha.debilidades, 100, stdin);

        printf("\nArchienemigo: ");
        fgets(heroe[i].ficha.archienemigo, 80, stdin);

        do
        {
            printf("\nEsta Habilitado? 1)Si 0)No\n");
            scanf("%d", &heroe[i].estado);
            if (heroe[i].estado != 1 && heroe[i].estado != 0)
            {
                printf(RESET RED"\nOpcion no existente\n"RESET);
            }
            
        } while (heroe[i].estado != 1 && heroe[i].estado != 0);
    }
}

int vld()
{
    int leido = 1;
}
void buscar()
{

}