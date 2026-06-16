#include<iostream>
using namespace std;

// Este programa calcula el factorial de un número.
// El factorial consiste en multiplicar todos los números enteros
// desde 1 hasta el número ingresado.
// Por ejemplo: 5! = 5 × 4 × 3 × 2 × 1 = 120.
// El programa también verifica que el número no sea negativo,
// ya que los factoriales negativos no están definidos.

int main() {

    int numero;
    long long factorial = 1;
    int i = 1;

    cout << "Ingrese un numero: ";
    cin >> numero;

    // Verificar si es negativo
    if (numero < 0) {

        cout << "No se puede calcular el factorial de un numero negativo.";

    }
    else {

        // Caso especial: 0! = 1
        if (numero == 0) {
            factorial = 1;
        }

        // El ciclo while multiplica todos los números
        // desde 1 hasta el número ingresado.
        // El resultado se va guardando en la variable factorial.
        while (i <= numero) {

            factorial = factorial * i;

            i++;
        }

        cout << "El factorial es: " << factorial;
    }

    return 0;
}