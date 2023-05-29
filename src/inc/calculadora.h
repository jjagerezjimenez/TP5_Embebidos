#include <stdint.h>
#include <stdbool.h>


typedef struct calculadora_s * calculadora_t;

typedef int(*funcion_t)(int, int);

//operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

calculadora_t CrearCalculadora(void);

bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion);

int Calcular(calculadora_t calculadora, char * cadena);