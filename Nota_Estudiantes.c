/*
Autor: Leonardo Torres
Descripcion: Una escuela desea implementar un programa en C que le permita gestionar las calificaciones de un grupo de estudiantes
en varias asignaturas. Además de gestionar las calificaciones, el programa debe calcular y mostrar información relevante 
como el promedio de calificaciones por estudiante y por asignatura, la calificación más alta y baja, y cuántos estudiantes
aprobaron cada asignatura.
*/

#include <stdio.h>

float estudiante_materia[5][3], promedio[5], promedio_asignatura[3];
int opc=0, opc2=0, reprobados=0, aprobados=0;
void matriznotas();


int main(){
    do
    {
        printf("Seleccione a cual estudiante le asignara la nota\n");
        printf("1)Pablo\n2)Maria\n3)Jose\n4)Luis\n5)Victoria\n6)SALIR\n");
        scanf("%d", &opc);
        printf("\n===================================================\n");
        
        switch (opc)
        {
        case 1:
            printf("Ingrese las Notas de Pablo:\n");
            opc2=0;
            matriznotas();
            break;
        
        case 2:
            printf("Ingrese las Notas de Maria:\n");
            opc2=1;
            matriznotas();
            break;

        case 3:
            printf("Ingrese las Notas de Jose:\n");
            opc2=2;
            matriznotas();
            break;

        case 4:
            printf("Ingrese las Notas de Luis:\n");
            opc2=3;
            matriznotas();
            break;

        case 5:
            printf("Ingrese las Notas de Victoria:\n");
            opc2=4;
            matriznotas();
            break;

        default:
            printf("Ingrese una opcion valida\n");
            break;
        }
        
    } while (opc!=6);

    if (opc==6)
    {
        //Calcula el promedio por estudiante
        printf("Promedio de calificaciones por estudiante:\n");
        for (int i = 0; i < 5; i++)
        {
            printf("Estudiante %d: %.2f\n", i+1, promedio[i]);
        }
        printf("\nCantidad de estudiantes aprobados: %d\n", aprobados);
        printf("Cantidad de estudiantes reprobados: %d\n", reprobados);
        
        //Calcula el promedio por asignatura
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
    }
    

}

//Funcion para recoger notas
void matriznotas(){
    for (int i = 0; i < 3; i++)
    {
        //Recoge notas en una matriz
        do
        {
            scanf("%f", &estudiante_materia[opc2][i]);
            //verifica si es un numero
            if (scanf("%f", &estudiante_materia[opc2][i]) != 1)
            {
                printf("Error: Ingrese un numero\n-------------------------------\n");
                //limpia el buffer
                while(getchar() != '\n');
            }
            //verifica si la nota es valida
            if (estudiante_materia[opc2][i]>10 || estudiante_materia[opc2][i]<0)
            {
                printf("Ingrese una nota valida\n -------------------------------\n");
                while(getchar() != '\n');
            }
            
        } while (estudiante_materia[opc2][i]>10 || estudiante_materia[opc2][i]<0); 
        
        //Calcula el promedio de cada estudiante
        promedio[opc2] += estudiante_materia[opc2][i];
        promedio[opc2] /= 3;

        //Cuenta los reprobados y aprobados
        if (promedio[opc2]<6)
        {
            reprobados++;
        }else
        {
            aprobados++;
        }
    }
    printf("Notas registradas:\n%.2f\n%.2f\n%.2f\n-------------------\n", estudiante_materia[opc2][0], estudiante_materia[opc2][1], estudiante_materia[opc2][2]);
}