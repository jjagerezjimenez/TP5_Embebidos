#include "calculadora.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef OPERACIONES											//se usa? 
#define OPERACIONES 16
#endif




typedef struct operacion_s * operacion_t;

struct operacion_s{
    char operador;
    funcion_t funcion;
    operacion_t siguiente;
};				//correccion

struct calculadora_s {
    operacion_t operaciones;
};

operacion_t BuscarOperacion(calculadora_t calculadora, char operador){
    operacion_t result = NULL;
	
    for (operacion_t actual = calculadora -> operaciones; actual -> siguiente != NULL; actual = actual -> siguiente) {					//nota: si esto esta vacio no anda, 26:20 / ver 2do arg si es actual
        if (actual -> operador == operador) {
            result = actual;
            break;
        }
    }
    return result;
}

calculadora_t CrearCalculadora(void){
    calculadora_t result = malloc(sizeof(struct calculadora_s));
    if (result) {															// != NULL?
        memset (result, 0, sizeof(struct calculadora_s));
    }
    return result;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion){
    
    //operacion_t operacion = BuscarOperacion(calculadora, '\0');
    operacion_t operacion = malloc(sizeof(struct operacion_s));

	if ((operacion) && !BuscarOperacion(calculadora, operador)){
		operacion -> operador = operador;
		operacion -> funcion = funcion;
		operacion -> siguiente = calculadora -> operaciones;
		calculadora -> operaciones = operacion;
	}
	return (operacion !=NULL);
}

int Calcular(calculadora_t calculadora, char * cadena){
	int a, b;
	char operador;
	int result = 0;

	for(int indice =0; indice < strlen(cadena); indice++){
		if(cadena[indice] < '0'){
			operador = cadena[indice];
			a = atoi(cadena);
			b = atoi(cadena + indice + 1);
			break;
		}
	}

	operacion_t operacion = BuscarOperacion(calculadora, operador);				//calcular?
	if (operacion){
		result = operacion -> funcion (a, b);
	}

	return result;
}
























