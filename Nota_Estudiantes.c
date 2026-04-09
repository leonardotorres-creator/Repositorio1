/*
Autor: Leonardo Torres
Descripcion: Una escuela desea implementar un programa en C que le permita gestionar las calificaciones de un grupo de estudiantes
en varias asignaturas. Además de gestionar las calificaciones, el programa debe calcular y mostrar información relevante 
como el promedio de calificaciones por estudiante y por asignatura, la calificación más alta y baja, y cuántos estudiantes
aprobaron cada asignatura.
HORAS INVERTIDAS: 6 horas
*/

#include <stdio.h>

float estudiante_materia[5][3], promedio[5], promedio_asignatura[3];
int opc=0, opc2=(-1), reprobados=0, aprobados=0;
char *nombres_estudiantes[5] = {"Pablo", "Maria", "Jose", "Luis", "Victoria"};//punteros para los nombres de los estudiantes
char *nombres_asignaturas[3] = {"Matematicas", "Ciencias", "Literatura"};//punteros para los nombres de las asignaturas
int estado_estudiantes[5] = {0, 0, 0, 0, 0}; // Todos empiezan en 0 (pendiente)
void matriznotas();
void resultados();


int main(){
    do
    {
        printf("Seleccione a cual estudiante le asignara la nota\n");

        // Recorremos los 5 estudiantes
        for (int i = 0; i < 5; i++) {
            printf("%d)%s", i + 1, nombres_estudiantes[i]);
    
            // Si el estado es 1, dibujamos el visto
            if (estado_estudiantes[i] == 1) {
            printf(" ✔"); 
            }
            printf("\n");
        }
        printf("6)SALIR\n");
        scanf("%d", &opc);
        printf("\n===================================================\n");
        opc2 = opc2 + 1;
        switch (opc)
        {
        case 1:
            printf("Ingrese las Notas de %s:\n", nombres_estudiantes[opc2]);
            matriznotas();
            estado_estudiantes[opc2] = 1; // <-- ¡Aquí marcamos el visto!
            break;
        
        case 2:
            printf("Ingrese las Notas de %s:\n", nombres_estudiantes[opc2]);
            matriznotas();
            estado_estudiantes[opc2] = 1; // <-- ¡Aquí marcamos el visto!)
            break;

        case 3:
            printf("Ingrese las Notas de %s:\n", nombres_estudiantes[opc2]);
            matriznotas();
            estado_estudiantes[opc2] = 1; // <-- ¡Aquí marcamos el visto!)
            break;

        case 4:
            printf("Ingrese las Notas de %s:\n", nombres_estudiantes[opc2]);
            matriznotas();
            estado_estudiantes[opc2] = 1; // <-- ¡Aquí marcamos el visto!)
            break;

        case 5:
            printf("Ingrese las Notas de %s:\n", nombres_estudiantes[opc2]);
            matriznotas();
            estado_estudiantes[opc2] = 1; // <-- ¡Aquí marcamos el visto!)
            break;

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Ingrese una opcion valida\n");
            break;
        }
        
    } while (opc!=6);

    if (opc==6)
    {
        printf("===================================================\n");
        printf("RESULTADOS FINALES:\n");
        printf("===================================================\n");

        //Calcula el promedio por estudiante
        printf("Promedio de calificaciones por estudiante:\n");
        for (int i = 0; i < 5; i++)
        {
            printf("Estudiante %s: %.2f\n", nombres_estudiantes[i], promedio[i]);
        }
        printf("\nCantidad de estudiantes aprobados: %d\n", aprobados);
        printf("Cantidad de estudiantes reprobados: %d\n", reprobados);
        
        //Calcula el promedio por asignatura
        printf("------------------------------\n");
        printf("Promedio de calificaciones por asignatura:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                promedio_asignatura[i] += estudiante_materia[j][i];
            }
            promedio_asignatura[i] /= 5;
            printf("Asignatura %d: %.2f\n", i+1, promedio_asignatura[i]);
        }

        //Nota mas alta y baja por estudiante
        printf("------------------------------\n");
        printf("\nNota mas alta y baja por estudiante:\n");
        for (int i = 0; i < 5; i++)
        {
            float nota_alta = estudiante_materia[i][0], nota_baja = estudiante_materia[i][0];
            for (int j = 1; j < 3; j++)
            {
                if (estudiante_materia[i][j] > nota_alta)
                {
                    nota_alta = estudiante_materia[i][j];
                }
                if (estudiante_materia[i][j] < nota_baja)
                {
                    nota_baja = estudiante_materia[i][j];
                }
            }
            printf("Estudiante %s - Nota mas alta: %.2f, Nota mas baja: %.2f\n", nombres_estudiantes[i], nota_alta, nota_baja);
        }

        //Nota mas alta y baja por asignatura
        printf("------------------------------\n");
        printf("\nNota mas alta y baja por asignatura:\n");
        for (int i = 0; i < 3; i++)
        {
            float nota_alta = estudiante_materia[0][i], nota_baja = estudiante_materia[0][i];
            for (int j = 1; j < 5; j++)
            {
                if (estudiante_materia[j][i] > nota_alta)
                {
                    nota_alta = estudiante_materia[j][i];
                }
                if (estudiante_materia[j][i] < nota_baja)
                {
                    nota_baja = estudiante_materia[j][i];
                }
            }
            printf("Asignatura %s - Nota mas alta: %.2f, Nota mas baja: %.2f\n", nombres_asignaturas[i], nota_alta, nota_baja);
        }

    }
    
}

//Funcion para recoger notas
void matriznotas(){
    //Para identificar a que estudiante se escogio
    for (int i = 0; i < 3; i++)
    {
        //Recoge notas en una matriz
        do
        {
            int valido = scanf("%f", &estudiante_materia[opc2][i]);

            //verifica si es un numero
            if (valido != 1)
            {
                //Fuerza que la repeticion se ejecute de nuevo y limpia el buffer
                printf("Error: Ingrese un numero\n-------------------------------\n");
                while (getchar() != '\n');
                estudiante_materia[opc2][i] = -1; 
            }else if (estudiante_materia[opc2][i]>10 || estudiante_materia[opc2][i]<0)
            {
                printf("Ingrese una nota valida\n -------------------------------\n");
            }
        } while (estudiante_materia[opc2][i]>10 || estudiante_materia[opc2][i]<0); 
        
        //Calcula el promedio de cada estudiante
        promedio[opc2] += estudiante_materia[opc2][i];
    }
    promedio[opc2] = promedio[opc2] / 3;
    if (promedio[opc2]<6)
        {
            reprobados++;
        }else
        {
            aprobados++;
        }
    printf("Notas registradas:\n%.2f\n%.2f\n%.2f\n-------------------\n", estudiante_materia[opc2][0], estudiante_materia[opc2][1], estudiante_materia[opc2][2]);
}