#include "unity.h"
#include "calculadora.h"

void test_crear_calculadora(void) {
    TEST_ASSERT_TRUE(CrearCalculadora() != NULL);
}

int suma(int a, int b) {
    return (a + b);
}


void test_AgregarOperacion(void) {

    calculadora_t calculadora = CrearCalculadora();

    TEST_ASSERT_TRUE(AgregarOperacion(calculadora, '+', suma));
}


void test_suma(void) {

    calculadora_t calculadora = CrearCalculadora();

    AgregarOperacion(calculadora, '+', suma);

    TEST_ASSERT_EQUAL(15, Calcular(calculadora, "2+13"));
    TEST_ASSERT_EQUAL(17, Calcular(calculadora, "2+14"));
}