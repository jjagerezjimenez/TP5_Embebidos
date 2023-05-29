
/**
 * @file main.c
 *
 * @brief Ejemplo de uso de la calculadora.
 */
#include "calculadora.h"
#include "stdio.h"

/**
 * @brief Función que realiza la suma de dos números enteros.
 *
 * @param a El primer número entero.
 * @param b El segundo número entero.
 * @return El resultado de la suma.
 */
int suma(int a, int b){
    return a + b;
}

/**
 * @brief Función que realiza la resta de dos números enteros.
 *
 * @param a El primer número entero.
 * @param b El segundo número entero.
 * @return El resultado de la resta.
 */
int resta(int a, int b){
    return a - b;
}


/**
 * @brief Función que realiza la multiplicación de dos números enteros.
 *
 * @param a El primer número entero.
 * @param b El segundo número entero.
 * @return El resultado de la multiplicación.
 */
int producto(int a, int b){
    return a * b;
}

/**
 * @brief Función que realiza la división de dos números enteros.
 *
 * @param a El primer número entero.
 * @param b El segundo número entero.
 * @return El resultado de la división.
 */
int division(int a, int b){
    return a / b;
}

/**
 * @brief Función principal del programa.
 */
int main(void){
    int resultado;

    calculadora_t calculadora = CrearCalculadora();
    
    AgregarOperacion(calculadora, '+', suma);
    AgregarOperacion(calculadora, '-', resta);
    AgregarOperacion(calculadora, '*', producto);
    AgregarOperacion(calculadora, '/', division);

    //suma

    resultado = Calcular(calculadora, "2+13");

    printf("Resultado %i\r\n", resultado);

    //resta

    resultado = Calcular(calculadora, "20-15");

    printf("Resultado %i\r\n", resultado);

    //multiplicacion

    resultado = Calcular(calculadora, "6*2");

    printf("Resultado %i\r\n", resultado);

    //division

    resultado = Calcular(calculadora, "6/2");

    printf("Resultado %i\r\n", resultado);
    

}