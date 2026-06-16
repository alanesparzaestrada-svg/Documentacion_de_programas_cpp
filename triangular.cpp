#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int opcion;
    double x, a, b, c, d, m, resultado;

    cout << "===== FUNCIONES DE MEMBRESIA =====" << endl;
    cout << "1. Triangular" << endl;
    cout << "2. Gamma" << endl;
    cout << "3. Trapezoidal" << endl;
    cout << "4. S Funcion" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    cout << "\nIngrese el valor de x: ";
    cin >> x;

    switch(opcion) {

        case 1: // Triangular
            cout << "Ingrese a, m y b: ";
            cin >> a >> m >> b;

            if (x <= a)
                resultado = 0;
            else if (x <= m)
                resultado = (x - a) / (m - a);
            else if (x <= b)
                resultado = (b - x) / (b - m);
            else
                resultado = 0;

            cout << "Membresia Triangular = " << resultado << endl;
            break;

        case 2: // Gamma
            cout << "Ingrese a y m: ";
            cin >> a >> m;

            if (x <= a)
                resultado = 0;
            else if (x < m)
                resultado = (x - a) / (m - a);
            else
                resultado = 1;

            cout << "Membresia Gamma = " << resultado << endl;
            break;

        case 3: // Trapezoidal
            cout << "Ingrese a, b, c y d: ";
            cin >> a >> b >> c >> d;

            if (x <= a)
                resultado = 0;
            else if (x <= b)
                resultado = (x - a) / (b - a);
            else if (x <= c)
                resultado = 1;
            else if (x <= d)
                resultado = (d - x) / (d - c);
            else
                resultado = 0;

            cout << "Membresia Trapezoidal = " << resultado << endl;
            break;

        case 4: // S Funcion
            cout << "Ingrese a y c: ";
            cin >> a >> c;

            if (x < a)
                resultado = 0;
            else if (x <= (a + c) / 2.0)
                resultado = 2 * pow((x - a) / (c - a), 2);
            else if (x <= c)
                resultado = 1 - 2 * pow((x - c) / (c - a), 2);
            else
                resultado = 1;

            cout << "Membresia S = " << resultado << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
    }

    return 0;
}