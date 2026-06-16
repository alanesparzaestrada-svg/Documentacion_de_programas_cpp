#include <iostream>
using namespace std;

/**
 calculadora
 Programa básico de una calculadora en consola.
 Permite al usuario realizar operaciones aritméticas fundamentales 
 (suma, resta, multiplicación y división) con dos números, 
 incluyendo una validación para evitar la división entre cero.
 */

int main() {
    // Declaración de variables para almacenar los números reales y el resultado
    double num1, num2, resultado;
    
    // Variable para almacenar la opción del menú seleccionada por el usuario
    int opcion;

    // --- MENÚ DE USUARIO ---
    // Muestra en pantalla las opciones disponibles de la calculadora
    cout << "=== CALCULADORA ===" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion; // Captura la opción elegida

    // --- CAPTURA DE DATOS ---
    // Solicita al usuario los dos números para realizar la operación
    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    // --- LÓGICA DE LAS OPERACIONES ---
    // Evalúa la opción seleccionada mediante una estructura switch-case
    switch (opcion) {
        
        case 1: // Operación de Suma
            resultado = num1 + num2;
            cout << "Resultado: " << resultado << endl;
            break;

        case 2: // Operación de Resta
            resultado = num1 - num2;
            cout << "Resultado: " << resultado << endl;
            break;

        case 3: // Operación de Multiplicación
            resultado = num1 * num2;
            cout << "Resultado: " << resultado << endl;
            break;

        case 4: // Operación de División
            // Validación de seguridad: Evita la indeterminación matemática por división entre cero
            if (num2 != 0) {
                resultado = num1 / num2;
                cout << "Resultado: " << resultado << endl;
            } else {
                // Mensaje de error en caso de que el divisor sea cero
                cout << "Error: No se puede dividir entre cero." << endl;
            }
            break;

        default: // Manejo de errores para opciones fuera del rango 1-4
            cout << "Opcion no valida." << endl;
    }

    return 0; // Indica que el programa finalizó correctamente
}