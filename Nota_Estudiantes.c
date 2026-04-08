/*
Autor: Leonardo Torres
Descripcion: Una escuela desea implementar un programa en C que le permita gestionar las calificaciones de un grupo de estudiantes
en varias asignaturas. Además de gestionar las calificaciones, el programa debe calcular y mostrar información relevante 
como el promedio de calificaciones por estudiante y por asignatura, la calificación más alta y baja, y cuántos estudiantes
aprobaron cada asignatura.
*/

#include <stdio.h>

float estudiante_materia[5][3], promedio[5];
int opc=0, opc2=0, reprobados=0, aprobados;
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
            printf("Ingrese una opcion valida");
            break;
        }
        
    } while (opc==6);

    aprobados = 5 - reprobados;
    
}

//Funcion para recoger notas
void matriznotas(){
    for (int i = 0; i < 3; i++)
    {
        do
        {
            scanf("%f", &estudiante_materia[opc2][i]);
        } while (estudiante_materia[opc2][i]>=10 && estudiante_materia[opc2][i]<=0);
        if (estudiante_materia[opc2][i]<6)
        {
            reprobados++;
        }
        promedio[opc2] += estudiante_materia[opc2][i];
    }
    printf("Notas registradas");
}