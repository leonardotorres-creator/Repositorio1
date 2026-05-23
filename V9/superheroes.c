/*
Descripcion: Supo (Superheroes Organizacion)
*/

#include <stdio.h>
#include <string.h>
#include "colors.h"


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

void registro(super heroe[], int tam);
void buscar_por_id(super personajes[], int cantidad);
void mensajes();
void mado();//estado en letritas
int valid_int();
float valid_float();
void iterar_borde(const char* c, int longitud);
void imprimir_tabla_super(super personajes[], int cantidad);

int main()
{   
    int opc=0;
    int n=0;
    printf(YELLOW"Cuantos superheroes ingresara (MAX 10)"RESET);
    do
    {
        n = valid_int();
        if (n < 1 || n > 10)
        {
            printf(RED"El rango de superheroes es 1-10"RESET);
        }
        
    } while (n < 1 || n > 10);
    super pe[n];
    registro (pe, n);

    mensajes();
    opc = valid_int();
    do
    {
        switch (opc)
        {
        case 1:
            imprimir_tabla_super(pe, n);
            break;
        case 2:
            buscar_por_id(pe, n);
            break;
        case 0:
            return 0;
            break;
        default:
            printf(RED"Opcion ingresada no existente\n"RESET);
            break;
        }
    } while (opc != 0);
}


void mensajes()
{
    printf(YELLOW"Ingrese la opcion que desee: \n");
    printf("1) Lista de superheroes\n");
    printf("2) Editar vigencia de superheroe\n");
    printf("0) SALIR\n"RESET);
}

//Funcion para registro de superheroes
void registro(super heroe[],int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf(GREEN"============================================");
        printf("\nRegistre al Superheroe:\n");
        printf("============================================");

        printf("\nID: ");
        heroe[i].ID = valid_int();
        getchar();

        printf("\nNombre: ");
        fgets(heroe[i].nombre, 80, stdin);
        heroe[i].nombre[strcspn(heroe[i].nombre, "\n")] = '\0'; //borra el enter que lee el fgets

        printf("\nPeso: ");
        heroe[i].peso = valid_float();
        getchar();
        
        printf("\nAltura: ");
        heroe[i].altura = valid_float();
        getchar();

        printf("\nSaga: ");
        fgets(heroe[i].saga, 10, stdin);
        heroe[i].saga[strcspn(heroe[i].saga, "\n")] = '\0'; //borra el enter que lee el fgets
        printf(RESET BLUE"\n+++++++++++++++++++++++++++++++++++++++++++");
        printf("\nAhora llenemos la Ficha tecnica:\n");

        printf("Origen: ");
        fgets(heroe[i].ficha.Origen, 50, stdin);
        heroe[i].ficha.Origen[strcspn(heroe[i].ficha.Origen, "\n")] = '\0'; //borra el enter que lee el fgets

        printf("\nPoderes: ");
        fgets(heroe[i].ficha.poderes, 100, stdin);
        heroe[i].ficha.poderes[strcspn(heroe[i].ficha.poderes, "\n")] = '\0'; //borra el enter que lee el fgets

        printf("\nDebilidades: ");
        fgets(heroe[i].ficha.debilidades, 100, stdin);
        heroe[i].ficha.debilidades[strcspn(heroe[i].ficha.debilidades, "\n")] = '\0'; //borra el enter que lee el fgets

        printf("\nArchienemigo: ");
        fgets(heroe[i].ficha.archienemigo, 80, stdin);
        heroe[i].ficha.archienemigo[strcspn(heroe[i].ficha.archienemigo, "\n")] = '\0'; //borra el enter que lee el fgets

        do
        {
            printf("\nEsta Habilitado? 1)Si 0)No\n");
            heroe[i].estado = valid_int();
            if (heroe[i].estado != 1 && heroe[i].estado != 0)
            {
                printf(RESET RED"\nOpcion no existente\n"RESET);
            }
            
        } while (heroe[i].estado != 1 && heroe[i].estado != 0);
    }
}

// Función para buscar un personaje por ID y mostrarlo como ficha técnica vertical
void buscar_por_id(super personajes[], int cantidad) {
    printf("INGRESE EL ID: \n");
    int id_buscado = valid_int();
    int indice_encontrado = -1;

    // Búsqueda secuencial
    for (int i = 0; i < cantidad; i++) {
        if (personajes[i].ID == id_buscado) {
            indice_encontrado = i;
            break;
        }
    }

    // Si no se encuentra
    if (indice_encontrado == -1) {
        printf("\n[Error]: No se encontro ningun personaje con el ID %d.\n", id_buscado);
        return;
    }

    // Alias para acortar el código
    super p = personajes[indice_encontrado];

    // Imprimir la ficha con bordes lineales limpios
    printf("\n┌────────────────────────────────────────────────────────┐\n");
    printf("│                FICHA DE SUPERHÉROE                     │\n");
    printf("├────────────────────────────────────────────────────────┤\n");
    printf("│ ID:          %-41d │\n", p.ID);
    printf("│ Nombre:      %-41s │\n", p.nombre);
    printf("│ Saga:        %-41s │\n", p.saga);
    printf("│ Estado:      %-41s │\n", p.estado);
    printf("│ Peso:        %-38.2f kg │\n", p.peso);
    printf("│ Altura:      %-39.2f m │\n", p.altura);
    printf("├────────────────────────────────────────────────────────┤\n");
    printf("│ Origen:      %-41s │\n", p.ficha.Origen);
    printf("│ Poderes:     %-41s │\n", p.ficha.poderes);
    printf("│ Debilidades: %-41s │\n", p.ficha.debilidades);
    printf("│ Enemigo:     %-41s │\n", p.ficha.archienemigo);
    printf("└────────────────────────────────────────────────────────┘\n");
    
    printf("Desea editar este personaje?\n1)Estado\n2)Borrar");
    int opc2 = valid_int();
    if (opc2 == 1)//para editar estado
    {
        int nuevo_estado;
        printf("Ingrese el nuevo estado para %s: ", p.nombre);
        nuevo_estado = valid_int();
        
        // Asignamos el nuevo valor usando el puntero
        p.estado = nuevo_estado; 
        printf("\n[Exito]: ¡El estado ha sido actualizado correctamente a %d!\n", p.estado);
    }else if(opc2 == 2)//para borrar superheroe
    {
        char nombre_borrado[80];
        strcpy(nombre_borrado, personajes[indice_encontrado].nombre);

        // 2. Desplazamiento de elementos (Eliminación lógica)
        // Movemos todos los personajes que están a la derecha del eliminado una posición a la izquierda
        for (int i = indice_encontrado; i < (cantidad) - 1; i++) {
            personajes[i] = personajes[i + 1];
        }

        // 3. Decrementar la cantidad total de personajes
        (cantidad)--;

        printf("\n[Exito]: El superheroe \"%s\" (ID: %d) ha sido eliminado correctamente.\n", nombre_borrado, id_buscado);
    }else
    {
        
    }
}

float valid_float ()
{
    float valor;
    int leido = 0;

    while (leido != 1) {
        leido = scanf("%f", &valor);

        if (leido != 1) {
            // Caso: El usuario ingresó letras
            printf(RED"\nERROR: Entrada no valida. Por favor, ingresa un numero.\n"RESET);
            while (getchar() != '\n');
        }
    }
    return valor;
}

int valid_int ()
{
    int valor;
    int leido = 0;

    while (leido != 1) {
        leido = scanf("%d", &valor);

        if (leido != 1) {
            // Caso: El usuario ingresó letras
            printf(RED"\nERROR: Entrada no valida. Por favor, ingresa un numero.\n"RESET);
            while (getchar() != '\n');
        }
    }
    return valor;
}

// Función para imprimir líneas repetidas cómodamente
void iterar_borde(const char* c, int longitud) {
    for (int i = 0; i < longitud; i++) printf("%s", c);
}

// Función principal que se encarga de calcular e imprimir la tabla
void imprimir_tabla_super(super personajes[], int cantidad) {
    // Definimos los títulos de las columnas
    char t1[] = "ID"; char t2[] = "Nombre"; char t3[] = "Peso"; 
    char t4[] = "Altura"; char t5[] = "Saga"; char t6[] = "Estado";
    char t7[] = "Origen"; char t8[] = "Poderes"; char t9[] = "Debilidades"; 
    char t10[] = "Archienemigo";

    // Inicializamos el ancho mínimo basado en el tamaño de los títulos (+2 por espacios de margen)
    int a1 = strlen(t1) + 2; int a2 = strlen(t2) + 2; int a3 = strlen(t3) + 2;
    int a4 = strlen(t4) + 2; int a5 = strlen(t5) + 2; int a6 = strlen(t6) + 2;
    int a7 = strlen(t7) + 2; int a8 = strlen(t8) + 2; int a9 = strlen(t9) + 2;
    int a10 = strlen(t10) + 2;

    // Calculamos el ancho máximo real revisando cada personaje
    char buffer[128];
    for (int i = 0; i < cantidad; i++) {
        sprintf(buffer, "%d", personajes[i].ID);
        if ((int)strlen(buffer) + 2 > a1) a1 = strlen(buffer) + 2;
        
        if ((int)strlen(personajes[i].nombre) + 2 > a2) a2 = strlen(personajes[i].nombre) + 2;
        
        sprintf(buffer, "%.2f kg", personajes[i].peso);
        if ((int)strlen(buffer) + 2 > a3) a3 = strlen(buffer) + 2;
        
        sprintf(buffer, "%.2f m", personajes[i].altura);
        if ((int)strlen(buffer) + 2 > a4) a4 = strlen(buffer) + 2;
        
        if ((int)strlen(personajes[i].saga) + 2 > a5) a5 = strlen(personajes[i].saga) + 2;
        
        sprintf(buffer, "%d", personajes[i].estado);
        if ((int)strlen(buffer) + 2 > a6) a6 = strlen(buffer) + 2;
        
        if ((int)strlen(personajes[i].ficha.Origen) + 2 > a7) a7 = strlen(personajes[i].ficha.Origen) + 2;
        if ((int)strlen(personajes[i].ficha.poderes) + 2 > a8) a8 = strlen(personajes[i].ficha.poderes) + 2;
        if ((int)strlen(personajes[i].ficha.debilidades) + 2 > a9) a9 = strlen(personajes[i].ficha.debilidades) + 2;
        if ((int)strlen(personajes[i].ficha.archienemigo) + 2 > a10) a10 = strlen(personajes[i].ficha.archienemigo) + 2;
    }

    // 1. BORDE SUPERIOR ┌───┬───┐
    printf("┌");
    iterar_borde("─", a1); printf("┬"); iterar_borde("─", a2); printf("┬");
    iterar_borde("─", a3); printf("┬"); iterar_borde("─", a4); printf("┬");
    iterar_borde("─", a5); printf("┬"); iterar_borde("─", a6); printf("┬");
    iterar_borde("─", a7); printf("┬"); iterar_borde("─", a8); printf("┬");
    iterar_borde("─", a9); printf("┬"); iterar_borde("─", a10); printf("┐\n");

    // 2. ENCABEZADOS
    printf("│ %-*s │ %-*s │ %-*s │ %-*s │ %-*s │ %-*s │ %-*s │ %-*s │ %-*s │ %-*s │\n",
           a1-2, t1, a2-2, t2, a3-2, t3, a4-2, t4, a5-2, t5, a6-2, t6, a7-2, t7, a8-2, t8, a9-2, t9, a10-2, t10);

    // 3. BORDE INTERMEDIO ├───┼───┤
    printf("├");
    iterar_borde("─", a1); printf("┼"); iterar_borde("─", a2); printf("┼");
    iterar_borde("─", a3); printf("┼"); iterar_borde("─", a4); printf("┼");
    iterar_borde("─", a5); printf("┼"); iterar_borde("─", a6); printf("┼");
    iterar_borde("─", a7); printf("┼"); iterar_borde("─", a8); printf("┼");
    iterar_borde("─", a9); printf("┼"); iterar_borde("─", a10); printf("┤\n");

    // 4. FILAS DE DATOS (Mapeando las estructuras y las subestructuras anidadas)
    for (int i = 0; i < cantidad; i++) {
        // Formateamos los floats temporalmente en un string con su unidad de medida
        char p_str[20], a_str[20];
        sprintf(p_str, "%.2f kg", personajes[i].peso);
        sprintf(a_str, "%.2f m", personajes[i].altura);

        printf("│ %-*d │ %-*s │ %-*s │ %-*s │ %-*s │ %-*d │ %-*s │ %-*s │ %-*s │ %-*s │\n",
               a1-2, personajes[i].ID,
               a2-2, personajes[i].nombre,
               a3-2, p_str,
               a4-2, a_str,
               a5-2, personajes[i].saga,
               a6-2, personajes[i].estado,
               a7-2, personajes[i].ficha.Origen,
               a8-2, personajes[i].ficha.poderes,
               a9-2, personajes[i].ficha.debilidades,
               a10-2, personajes[i].ficha.archienemigo);
    }

    // 5. BORDE INFERIOR └───┴───┘
    printf("└");
    iterar_borde("─", a1); printf("┴"); iterar_borde("─", a2); printf("┴");
    iterar_borde("─", a3); printf("┴"); iterar_borde("─", a4); printf("┴");
    iterar_borde("─", a5); printf("┴"); iterar_borde("─", a6); printf("┴");
    iterar_borde("─", a7); printf("┴"); iterar_borde("─", a8); printf("┴");
    iterar_borde("─", a9); printf("┴"); iterar_borde("─", a10); printf("┘\n");
}