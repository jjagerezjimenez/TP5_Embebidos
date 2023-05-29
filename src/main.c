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

    //suma

    resultado = Calcular(calculadora, "2+13");

    printf("Resultado %i\r\n", resultado);

    //resta

    resultado = Calcular(calculadora, "20-15");

    printf("Resultado %i\r\n", resultado);

    //multiplicacion

    resultado = Calcular(calculadora, "6*2");

    printf("Resultado %i\r\n", resultado);
    

}