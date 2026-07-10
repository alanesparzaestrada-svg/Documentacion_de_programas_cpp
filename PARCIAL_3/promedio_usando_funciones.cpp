#include <iostream>
// Este programa calcula la suma y el promedio de dos números ingresados por el usuario.

// Función para pedir los datos al usuario

// pedirDatos: Solicita por consola los límites del rango numérico utilizando paso por referencia (&).
// - &num1: Referencia a la variable que almacenará el límite inferior (primer número).
// - &num2: Referencia a la variable que almacenará el límite superior (segundo número).
void pedirDatos(int &num1, int &num2) {
    std::cout << "Ingresa el numero primer numero: ";
void pedirDatos(int &num1, int &num2) {
    std::cout << "Ingresa el numero primer numero: ";
    std::cin >> num1;
    std::cout << "Ingresa el numero segundo numero: ";
    std::cin >> num2;
}
// Función para calcular la suma de dos números

// calcularsuma: Función recursiva que calcula la suma consecutiva de todos los enteros en el rango [num1, num2].
// - num1: Valor actual en el ciclo de la recursión (límite inferior inicial que va incrementando).
// - num2: Límite superior fijo donde se detiene la suma.
int calcularsuma(int num1, int num2) {
    if (num1 > num2) {
        return 0;// Caso base: cuando el contador supera al límite superior, detiene la recursión.
    }
    else {
        return num1 + calcularsuma(num1 + 1, num2);
    }
}

// Función para calcular el promedio de dos números

// calcularPromedio: Obtiene la media aritmética dividiendo la suma total entre la cantidad de elementos sumados.
// - suma: El resultado acumulado obtenido previamente de la función recursiva.
// - num1: El límite inferior original ingresado por el usuario.
// - num2: El límite superior original ingresado por el usuario.
float calcularPromedio(int suma, int num1, int num2) {
    float promedio = 0.0;// Variable local para almacenar el cálculo flotante del promedio.
    // Se divide la suma entre el total de elementos calculados con la fórmula: ((LímiteSuperior - LímiteInferior) + 1)
    promedio = (float)suma / ((num2 - num1) + 1);
    return promedio;
}
// Función para mostrar los resultados
// mostrarResultados: Imprime en pantalla de manera clara el valor final de la suma y del promedio.
// - suma: Valor entero que representa la suma total acumulada.
// - promedio: Valor flotante que representa el promedio final del rango.
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
    if (num1 > num2) {
        std::cout << "El primer numero debe ser menor o igual al segundo." << std::endl;
        return 0;
    }

    suma = calcularsuma(num1, num2);
    promedio = calcularPromedio(suma, num1, num2);

    mostrarResultados(suma, promedio);

    return 0;
}
