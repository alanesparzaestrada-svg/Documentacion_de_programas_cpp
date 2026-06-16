#include<iostream>
using namespace std;

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

        // Calcular factorial
        while (i <= numero) {

            factorial = factorial * i;

            i++;
        }

        cout << "El factorial es: " << factorial;
    }

    return 0;
}