#include <iostream>                 // Librería fundamental para operaciones de entrada y salida (cin, cout)
#include <string>                   // Librería para manipular cadenas de texto y usar métodos como .empty()
using namespace std;                // Evita tener que escribir "std::" antes de cout, cin, string, etc.

/* 
 * Función: recorrido
 * Propósito: Muestra los elementos almacenados actualmente en el arreglo en forma de lista.
 * Parámetros:
 *   - string A[]: El arreglo de cadenas que contiene los datos.
 *   - int n: El número actual de posiciones ocupadas/válidas en el arreglo.
 */
void recorrido(string A[], int n) {
    // Comprobación de espacio vacío: si n es 0, no hay nada que mostrar.
    if (n == 0) {
        cout << "\n[El arreglo esta vacio. No hay elementos para mostrar]\n" << endl;
        return;                     // Termina la ejecución de la función si está vacío
    }
    
    cout << endl;                   // Salto de línea para separar la salida visualmente
    for (int i = 0; i < n; i++) {   // Iterador que va desde la posición inicial (0) hasta el último elemento ocupado (n-1)
        cout << i << ". " << A[i] << endl; // Muestra la posición (índice) seguida del valor guardado
    }
    cout << endl;                   // Salto de línea al final del listado
}

/* 
 * Función: insertar
 * Propósito: Agrega un nuevo elemento en una posición específica del arreglo desplazando los existentes.
 * Parámetros:
 *   - string A[]: Arreglo donde se insertará el elemento.
 *   - string new_element: La cadena con el nuevo valor a insertar.
 *   - int P: La posición deseada para colocar el nuevo elemento.
 *   - int &n: Referencia al total de campos ocupados (se modifica dentro de main).
 *   - int limite: Capacidad máxima que puede almacenar el arreglo (N).
 */
void insertar(string A[], string new_element, int P, int &n, int limite) {
    // Validar si el arreglo ya alcanzó su límite máximo de capacidad
    if (n >= limite) {
        cout << "\nError: Capacidad maxima alcanzada (" << limite << " espacios). No se puede insertar.\n" << endl;
        return;                     // Interrumpe la inserción si el arreglo está lleno
    }

    // Validar que la posición solicitada esté dentro del rango permitido (entre 0 y n)
    if (P < 0 || P > n) {
        cout << "\nError: La posicion " << P << " es invalida para insertar. Rango valido: [0 a " << n << "].\n" << endl;
        return;                     // Interrumpe la inserción si la posición es fuera de rango
    }

    int i = n;                      // Inicializa el índice desde la última posición disponible
    // Recorre los elementos hacia la derecha a partir de la posición P
    while (i > P) {
        A[i] = A[i - 1];            // Asigna a la posición actual el valor de la casilla anterior
        i--;                        // Decrementa el iterador para continuar hacia atrás
    }

    A[P] = new_element;             // Coloca el nuevo valor en la posición seleccionada P
    n++;                            // Incrementa en 1 la cantidad de elementos ocupados

    cout << "\n>>> Elemento \"" << new_element << "\" insertado correctamente en la posicion " << P << " <<<";
    recorrido(A, n);                // Muestra el estado actualizado del arreglo
}

/* 
 * Función: borrar
 * Propósito: Elimina el elemento de la posición indicada y recorre los elementos a la izquierda.
 * Parámetros:
 *   - string A[]: Arreglo desde donde se borrará el dato.
 *   - int j: Posición (índice) del elemento a eliminar.
 *   - int &n: Referencia al total de campos ocupados (se modifica dentro de main).
 */
void borrar(string A[], int j, int &n) {
    // Comprobación de vacíos: verificar que existan elementos para borrar
    if (n == 0) {
        cout << "\nError: No se pueden eliminar elementos porque el arreglo esta vacio.\n" << endl;
        return;                     // Cancela la eliminación
    }

    // Validar que el índice a borrar esté en el rango ocupado (de 0 a n-1)
    if (j < 0 || j >= n) {
        cout << "\nError: La posicion " << j << " no existe. Rango valido para borrar: [0 a " << n - 1 << "].\n" << endl;
        return;                     // Cancela la eliminación si el índice es incorrecto
    }

    // Recorre todos los elementos siguientes una posición a la izquierda
    for (int i = j; i < n - 1; i++) {
        A[i] = A[i + 1];            // La posición actual toma el valor de la posición posterior
    }

    n--;                            // Disminuye en 1 la cantidad de elementos válidos en el arreglo

    cout << "\n>>> Elemento en la posicion " << j << " eliminado correctamente <<<";
    recorrido(A, n);                // Muestra la lista para verificar cómo quedó
}

// Función principal del programa
int main() {
    const int N = 9;                // Constante entera que define la capacidad máxima total del arreglo
    string CARS[N] = {              // Declaración del arreglo de tipo string con capacidad N (9)
        "Alfa_Romeo", 
        "Fiat", 
        "Ford", 
        "Lancia", 
        "Renault", 
        "Seat"
    };                              // Se inicializa con 6 nombres de marcas de automóviles
    
    int n = 6;                      // Variable para rastrear la cantidad actual de lugares ocupados (inicialmente 6)
    int opcion = 0;                 // Variable para capturar la opción seleccionada por el usuario en el menú

    // Estructura repetitiva do-while para mantener activo el menú interactivo hasta seleccionar salir
    do {
        // Despliegue visual de opciones del menú
        cout << "========================================" << endl;
        cout << "            MENU DE OPCIONES            " << endl;
        cout << "========================================" << endl;
        cout << "1. Mostrar elementos (Recorrido)" << endl;
        cout << "2. Insertar un nuevo elemento" << endl;
        cout << "3. Borrar un elemento" << endl;
        cout << "4. Salir del programa" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opcion (1-4): ";
        cin >> opcion;               // Lectura de la respuesta enviada por teclado

        // Evalúa la opción elegida por el usuario
        switch (opcion) {
            case 1:
                // Llamada a la función recorrido para visualizar los datos
                recorrido(CARS, n);
                break;

            case 2: {
                // Validación previa antes de pedir información al usuario
                if (n >= N) {
                    cout << "\n[!] Atencion: El arreglo esta lleno (" << N << "/" << N << "). No hay espacio libre.\n" << endl;
                    break;          // Regresa directamente al menú
                }

                string nuevo_carro; // Variable local para almacenar la cadena ingresada
                int pos;            // Variable local para la posición deseada

                cout << "Ingrese el nombre del automovil a agregar: ";
                cin >> nuevo_carro; // Captura el texto ingresado

                // Uso de la librería string: Método .empty() para verificar si la cadena recibida está vacía
                if (nuevo_carro.empty()) {
                    cout << "Error: La cadena ingresada esta vacia." << endl;
                    break;
                }

                cout << "Ingrese la posicion donde desea insertarlo (0 a " << n << "): ";
                cin >> pos;         // Captura el índice deseado

                // Ejecuta la función de inserción con los parámetros recolectados
                insertar(CARS, nuevo_carro, pos, n, N);
                break;
            }

            case 3: {
                // Validación previa: comprobar si hay datos para eliminar antes de preguntar
                if (n == 0) {
                    cout << "\n[!] Atencion: No hay elementos para borrar (el arreglo esta vacio).\n" << endl;
                    break;          // Regresa al menú
                }

                int pos_borrar;     // Variable local para la posición a borrar
                cout << "Ingrese la posicion del elemento que desea borrar (0 a " << n - 1 << "): ";
                cin >> pos_borrar;  // Captura el índice suministrado por el usuario

                // Ejecuta la función para borrar en la posición dada
                borrar(CARS, pos_borrar, n);
                break;
            }

            case 4:
                // Mensaje final cuando se opta por salir
                cout << "\nSaliendo del programa... ¡Hasta luego!\n" << endl;
                break;

            default:
                // Manejo de opción no reconocida en el switch
                cout << "\nOpcion invalida. Por favor, introduzca un numero entre 1 y 4.\n" << endl;
                break;
        }

    } while (opcion != 4);          // El ciclo se repite mientras la opción seleccionada sea distinta de 4

    return 0;                       // Finalización exitosa de la función main
}