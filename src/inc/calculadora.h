
/**
 * @file calculadora.h
 *
 * @brief Interfaz de la calculadora.
 */
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Puntero a una estructura que representa una calculadora.
 */
typedef struct calculadora_s * calculadora_t;

/**
 * @brief Tipo de puntero a función para las operaciones de la calculadora.
 *
 * Este tipo representa una función que toma dos enteros como parámetros y devuelve un entero como resultado.
 */
typedef int(*funcion_t)(int, int);


//operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/**
 * @brief Crea una nueva instancia de calculadora.
 * 
 * @return Un puntero a la calculadora creada. 
 */
calculadora_t CrearCalculadora(void);

/**
 * @brief Agrega una nueva operación a la calculadora.
 *
 * @param calculadora La instancia de calculadora.
 * @param operador El carácter del operador que representa la operación.
 * @param funcion El puntero a función que implementa la operación.
 *
 * @return `true` si la operación se agregó correctamente, `false` en caso contrario.
 */
bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion);

/**
 * @brief Calcula el resultado de una expresión usando la calculadora.
 *
 * @param calculadora La instancia de calculadora.
 * @param cadena La cadena de expresión a evaluar.
 *
 * @return El resultado calculado de la expresión.
 */
int Calcular(calculadora_t calculadora, char * cadena);