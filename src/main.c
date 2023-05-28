#include "calculadora.h"
#include "stdio.h"

int suma(int a, int b){
    return a + b;
}

int resta(int a, int b){
    return a - b;
}

int producto(int a, int b){
    return a * b;
}

int main(void){
    int resultado;

    calculadora_t calculadora = CrearCalculadora();
    
    AgregarOperacion(calculadora, '+', suma);
    AgregarOperacion(calculadora, '-', resta);
    AgregarOperacion(calculadora, '*', producto);

    resultado = Calcular(calculadora, "2+13");

    printf("Resultado %i\r\n", resultado);
    

}