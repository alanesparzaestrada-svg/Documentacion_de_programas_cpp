#include <iostream>
//menu de opcciones de la calculadora
void mostrarMenu() {
    std::cout << "\n=== CALCULADORA ===" << std::endl;
    std::cout << "1. Sumar" << std::endl;
    std::cout << "2. Restar" << std::endl;
    std::cout << "3. Multiplicar" << std::endl;
    std::cout << "4. Dividir" << std::endl;
    std::cout << "5. Salir" << std::endl;
}

// funciones para las operaciones matemáticas
double suma(double num1, double num2) { return num1 + num2; }
// esta funcion suma el numero 1 + el numero 2
double resta(double num1, double num2) { return num1 - num2; }
// esta funcion resta  el numero 1 - el numero 2
double multiplicacion(double num1, double num2) { return num1 * num2; }
// esta funcion multiplica  el numero 1   * el numero 2
double division(double num1, double num2) { return num1 / num2; }
// esta funcion divide  el numero 1 / el numero 2

// función principal
int main() {
    double num1, num2, resultado;
    //la funcion num1 garda el primer valor ingrsado por el usuario
     //la funcion num1 garda el segundo  valor ingrsado por el usuario
    //la funcion resultado Guarda el valor final de la operación aritmética ejecutada.
    int opcion;

    // ciclo do-while para mantener el programa en ejecución hasta que el usuario decida salir
    do {
        mostrarMenu();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        // Si la opción es de operaciones (1 a 4), pedimos los números
        if (opcion >= 1 && opcion <= 4) {
            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> num2;
        }

        switch (opcion) {//
            case 1:
                resultado = suma(num1, num2); 
                std::cout << "Resultado: " << resultado << std::endl;
                break;
            case 2:
                resultado = resta(num1, num2);
                std::cout << "Resultado: " << resultado << std::endl;
                break;
            case 3:
                resultado = multiplicacion(num1, num2);
                std::cout << "Resultado: " << resultado << std::endl;
                break;
            case 4:
                if (num2 != 0) {
                    resultado = division(num1, num2);
                    std::cout << "Resultado: " << resultado << std::endl;
                } else {
                    std::cout << "Error: No se puede dividir entre cero." << std::endl;
                }
                break;
            case 5:
                std::cout << "Saliendo del programa. ¡Adios!" << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
        }

    } while (opcion != 5); // El ciclo se repite MIENTRAS la opción NO sea 5

    return 0;
}
