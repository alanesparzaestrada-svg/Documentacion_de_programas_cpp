#include <iostream>
// Este programa calcula la suma y el promedio de dos números ingresados por el usuario.

// Función para pedir los datos al usuario
void pedirDatos(int &num1, int &num2) {
    std::cout << "Ingresa el numero primer numero: ";
    std::cin >> num1;
    std::cout << "Ingresa el numero segundo numero: ";
    std::cin >> num2;
}
// Función para calcular la suma de dos números
int calcularsuma(int num1, int num2) {
    int suma = 0;

    suma = num1 + num2;
    return suma;
}

// Función para calcular el promedio de dos números
float calcularPromedio(int suma, int num1, int num2) {
    float promedio = 0.0;
    promedio = (float)suma / 2;
    return promedio;
}
// Función para mostrar los resultados
void mostrarResultados(int suma, float promedio) {
    std::cout << "La suma de los numeros es: " << suma << std::endl;
    std::cout << "El promedio es: " << promedio << std::endl;
}

// funcion principal del programa 
// En esta función se llama a las funciones definidas anteriormente para realizar el cálculo de la suma y el promedio de dos números ingresados por el usuario. 
int main() {
    int num1, num2;
    int suma;
    float promedio;

    pedirDatos(num1, num2);
 //aqui se verifica que el primer numero ingresado sea mayor o igual al segundo numero ingresado pr el ususario
 // si no se cumple esta condicion, el programa mostrara un mensaje de error y terminar la ejecuicion del programa.
    if (num1 >= num2) {
        std::cout << "El primer numero debe ser menor o igual al segundo." << std::endl;
        return 0;
    }

    suma = calcularsuma(num1, num2);
    promedio = calcularPromedio(suma, num1, num2);

    mostrarResultados(suma, promedio);

    return 0;
}
