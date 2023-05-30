#include "calculadora.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef OPERACIONES											//se usa? 
#define OPERACIONES 16
#endif



/**
 * @brief Estructura de datos para representar una operación.
 *
 * Esta estructura contiene un operador, una función correspondiente a la operación
 * y un puntero a la siguiente operación en la lista enlazada.
 */
typedef struct operacion_s * operacion_t;

/**
 * @brief Estructura de datos para representar una operación.
 *
 * Esta estructura contiene información sobre una operación matemática, incluido el operador,
 * la función correspondiente a la operación y un puntero a la siguiente operación en la lista enlazada.
 */
struct operacion_s {
    char operador; /**< El operador de la operación. */
    funcion_t funcion; /**< Puntero a la función que realiza la operación. */
    operacion_t siguiente; /**< Puntero a la siguiente operación en la lista enlazada. */
};

/**
 * @brief Estructura de datos para representar una calculadora.
 *
 * Esta estructura contiene un puntero a la lista de operaciones disponibles.
 */
struct calculadora_s {
    operacion_t operaciones;
};

/**
 * @brief Función que busca una operación en la calculadora.
 *
 * @param calculadora La calculadora en la que se buscará la operación.
 * @param operador El operador de la operación buscada.
 * @return Puntero a la operación encontrada o NULL si no se encuentra.
 */
operacion_t BuscarOperacion(calculadora_t calculadora, char operador){
    operacion_t result = NULL;
	if (calculadora != NULL){
		for (operacion_t actual = calculadora -> operaciones; actual != NULL; actual = actual -> siguiente) {					
        if (actual -> operador == operador) {
            result = actual;
            break;
		}
    
        }
    }
    return result;
}

/**
 * @brief Función que crea una nueva instancia de calculadora.
 *
 * @return Puntero a la nueva instancia de calculadora creada o NULL si ocurre un error.
 */
calculadora_t CrearCalculadora(void){
    calculadora_t result = malloc(sizeof(struct calculadora_s));			//calculadora?
    if (result) {															// != NULL?
        memset (result, 0, sizeof(struct calculadora_s));
    }
    return result;
}

/**
 * @brief Función que agrega una nueva operación a la calculadora.
 *
 * @param calculadora La calculadora a la que se agregará la operación.
 * @param operador El operador de la nueva operación.
 * @param funcion La función correspondiente a la operación.
 * @return true si se agrega la operación correctamente, false si ocurre un error o si la operación ya existe.
 */
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

/**
 * @brief Función que realiza un cálculo utilizando la calculadora.
 *
 * @param calculadora La calculadora utilizada para el cálculo.
 * @param cadena La cadena que contiene la expresión a calcular.
 * @return El resultado del cálculo.
 */
int Calcular(calculadora_t calculadora, char * cadena){
	int a, b;
	char operador;
	int result = 0;

	for(int indice = 0; indice < strlen(cadena); indice++){
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
























