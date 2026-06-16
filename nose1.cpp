#include <iostream>
using namespace std;

inf main() {
    int inicio, fin;
    int suma = 0;
    int cantidad = 0;
    float promedio;

    // Pedir datos al usuario
    cout << "Ingresa el numero inicial: ";
    cin >> inicio;

    cout << "Ingresa el numero final: ";
    cin >> fin;

    // Validar que el numero inicial sea menor o igual al final
    if (inicio > fin) {
        cout << "El numero inicial debe ser menor o igual al final." << endl;
        return 0;
    }

    // Sumar numeros consecutivos
    for (int i = inicio; i <= fin; i++) {
        suma += i;
        cantidad++;
    }

    // Calcular promedio
    promedio = (float)suma / cantidad;

    // Mostrar resultados
    cout << "\nLa suma de los numeros es: " << suma << endl;
    cout << "El promedio es: " << promedio << endl;

    return 0;
}