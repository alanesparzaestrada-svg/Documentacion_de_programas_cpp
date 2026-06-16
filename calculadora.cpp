#include <iostream>
using namespace std;

int main() {
    double num1, num2, resultado;
    int opcion;

    cout << "=== CALCULADORA ===" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    switch (opcion) {
        case 1:
            resultado = num1 + num2;
            cout << "Resultado: " << resultado << endl;
            break;

        case 2:
            resultado = num1 - num2;
            cout << "Resultado: " << resultado << endl;
            break;

        case 3:
            resultado = num1 * num2;
            cout << "Resultado: " << resultado << endl;
            break;

        case 4:
            if (num2 != 0) {
                resultado = num1 / num2;
                cout << "Resultado: " << resultado << endl;
            } else {
                cout << "Error: No se puede dividir entre cero." << endl;
            }
            break;

        default:
            cout << "Opcion no valida." << endl;
    }

    return 0;
}