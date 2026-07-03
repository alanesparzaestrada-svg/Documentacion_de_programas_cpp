#include <iostream> // Permite la entrada y salida de datos (escribir en pantalla y leer el teclado).
using namespace std; // Nos evita tener que escribir "std::" antes de cada comando como cout o cin.

// =======================================================================================
// ¿PARA QUÉ SIRVE EL PROTOTIPO AQUÍ?
// Como C++ lee de arriba a abajo, si llamamos a "calcularFactorial" dentro del main sin 
// este prototipo, el compilador diría: "No sé qué significa esa palabra".
// El prototipo es el aviso que dice: "Oye, abajo hay una función con este nombre que
// recibe un entero (int) y devuelve un número súper grande (long long). Déjame usarla".
// =======================================================================================

// --- PROTOTIPO DE LA FUNCIÓN ---
long long calcularFactorial(int n); 

// El "main" es el bloque principal, el motor donde inicia la ejecución del programa.
int main() {
    int numero; // Creamos una "cajita" en memoria para guardar el número entero que elija el usuario.

    cout << "Ingrese un numero: "; // Imprime el mensaje en la pantalla pidiendo el número.
    cin >> numero; // Detiene el programa y espera a que el usuario teclee el número, guardándolo en 'numero'.

    // --- 1. VALIDACIÓN ---
    // El 'main' se encarga de revisar si el dato es correcto antes de mandar a hacer cálculos.
    // Los factoriales de números negativos no existen, así que usamos un 'if' para revisar eso.
    if (numero < 0) {
        // Si el usuario metió un número menor a 0 (como -5), entra aquí y le avisa del error.
        cout << "No se puede calcular el factorial de un numero negativo." << endl;
    } 
    else {
        // Si el número es 0 o positivo, el programa entra a este 'else'.
        
        // --- 2. LLAMADA A LA FUNCIÓN ---
        // Creamos una cajita llamada 'resultado' de tipo 'long long' (para que quepan números gigantes).
        // En esta línea, el programa da un "salto" directo hasta la definición que está abajo del todo,
        // pasándole como copia el valor de 'numero'. Cuando la función termina, regresa aquí con el valor final.
        long long resultado = calcularFactorial(numero);
        
        // Imprime en la pantalla el resultado final que nos devolvió la función.
        cout << "El factorial es: " << resultado << endl;
    }

    return 0; // Le avisa al sistema operativo que el programa terminó de manera exitosa y sin errores.
}

// =======================================================================================
// --- DEFINICIÓN DE LA FUNCIÓN ---
// Aquí abajo está el "manual de instrucciones" real. Es la receta de cómo se calcula un factorial.
// Ponemos las definiciones aquí para que el código principal (el main) no se sature de líneas.
// =======================================================================================

long long calcularFactorial(int n) {
    // Creamos una cajita para ir acumulando las multiplicaciones. Empieza en 1 porque si empezara en 0,
    // cualquier multiplicación daría cero (1 * 2 * 3...).
    long long factorial = 1; 
    
    int i = 1; // Creamos un contador llamado 'i' que empezará en 1 e irá subiendo de uno en uno.

    // El ciclo 'while' (mientras) se va a repetir una y otra vez mientras nuestro contador 'i'
    // sea menor o igual al número 'n' que nos mandó el usuario.
    // NOTA: Si el usuario metió un 0, la condición (1 <= 0) es falsa desde el inicio, el ciclo no se hace,
    // lo cual es perfecto porque el factorial de 0 es 1, que es justo lo que vale nuestra variable.
    while (i <= n) {
        // Multiplica lo que ya teníamos guardado en 'factorial' por el número actual de 'i'
        // y el nuevo resultado lo vuelve a guardar en la misma cajita 'factorial'.
        // Ejemplo con 3: (1 * 1 = 1) -> (1 * 2 = 2) -> (2 * 3 = 6).
        factorial = factorial * i; 
        
        i++; // Le suma 1 al contador 'i' para pasar al siguiente número en la próxima vuelta.
    }

    // La palabra 'return' es como el camión de entregas: toma el valor final que quedó acumulado
    // en la cajita 'factorial' (por ejemplo, el 6) y lo manda de regreso al 'main'.
    return factorial; 
}
