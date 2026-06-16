#include <iostream>
using namespace std;

// Este programa calcula la suma y el promedio de todos los números
// que existen entre un número inicial y un número final.
// El usuario ingresa ambos valores y el programa realiza los cálculos
// automáticamente mostrando los resultados al final.

int main() {
    int inicio, fin;
    int suma = 0;
    int cantidad = 0;
    float promedio;

    // Pedir datos al usuario
    cout << "Ingresa el numero inicial: ";
    cin >> inicio;

    cout << "Ingresa el numero final: ";
    cin >> fin;

    // Se verifica que el número inicial sea menor o igual al final.
    // Si no se cumple, el programa termina mostrando un mensaje.
    if (inicio > fin) {
        cout << "El numero inicial debe ser menor o igual al final." << endl;
        return 0;
    }

    // El ciclo for recorre todos los números desde el valor inicial
    // hasta el valor final. Cada número se suma al acumulador 'suma'
    // y también se cuenta cuántos números fueron utilizados.
    for (int i = inicio; i <= fin; i++) {
        suma += i;
        cantidad++;
    }

    // El promedio se obtiene dividiendo la suma total
    // entre la cantidad de números recorridos.
    promedio = (float)suma / cantidad;

    // Mostrar resultados
    cout << "\nLa suma de los numeros es: " << suma << endl;
    cout << "El promedio es: " << promedio << endl;

    return 0;
}