#include <iostream>

// Este programa calcula el factorial de un número utilizando funciones.
// El factorial consiste en multiplicar todos los números enteros
// desde 1 hasta el número ingresado.

void pedirNumero(int &numero) {
    std::cout << "Ingrese un numero: ";
    std::cin >> numero;
}

long long calcularFactorial(int numero) { // long long es utilizado para manejar números grandes 
    long long factorial = 1;
    for (int i = 1; i <= numero; ++i) {
        factorial *= i;
    }
    return factorial;
}

int main (){
    int numero;
    pedirNumero(numero);
    long long factorial = calcularFactorial(numero);
    std::cout << "El factorial de " << numero << " es: " << factorial << std::endl;
    return 0;
}