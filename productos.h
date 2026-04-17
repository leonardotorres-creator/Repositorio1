#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <stdio.h>
#include <string.h>
#include "vld.h" // Incluimos librería de validación 

// Declaración externa de variables (compartidas)
extern char *sucursal[3];
extern float precio[3][10];
extern char nombre[10][20];
extern int opc;
extern int npro;
extern int cantidad[3][10]; 

// Prototipos de funciones
void nombre_precio();
void cuantos_productos();
void precio_sucursal();
void buscar_producto();
void precio_mas_caro_barato();
void total_unidades_vendidas();

#endif