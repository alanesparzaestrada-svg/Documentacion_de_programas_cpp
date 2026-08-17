#include <stdio.H>
/*
En una tienda de abarrotes se quieren registrar 15 productos con 
sus respectivos precios.

utilizar dos arreglos: uno para los nombres de los productos y 
otro para sus precios para realizar el registro de ambos arreglos manualmente (ingresar los datos de la terminal)

alfinan del registro mostrar todos los productos con sus respectivos precios correpondientes
*/

int main(){
       // Definición de la constante para el tamaño de los arreglos (máximo 15 productos)
    const int u = 15;// la u es una variable que almacena el tamaño de los arreglos, 
                    //en este caso 15, que es el número máximo de productos que se pueden registrar.

      // Matriz para almacenar los nombres de los productos.
    // Almacena hasta 'u' (15) productos, y cada nombre puede tener hasta 29 caracteres + el carácter nulo '\0'.
    char PRODUCTOS[u][30];// Matriz para almacenar los nombres de los productos.
    // aqui el 30 es el tamaño máximo de cada nombre de producto, incluyendo el carácter nulo 
    //'\0' que indica el final de la cadena.
    
    // Arreglo unidimensional para almacenar los precios de cada producto como números decimales.
    float PRECIOS[u];

     // --- BLOQUE DE LECTURA DE DATOS ---
    // Este ciclo 'for' se ejecuta 'u' (15) veces para solicitar la información al usuario.
    for(int i = 0; i < u; i++){
         // Solicita y lee el nombre del producto 'i + 1' (para que el usuario vea 1 en lugar de 0)


        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", PRODUCTOS[i]);// No lleva '&' porque PRODUCTOS[i] ya es una dirección de memoria (cadena)
        printf("Ingrese el precio del producto %d: ", i + 1);
        // Solicita y lee el precio del producto correspondiente
        scanf("%f", &PRECIOS[i]);
         // Lleva '&' porque se está guardando en una variable de tipo float elemental
    }

    // --- BLOQUE DE MUESTRA DE DATOS ---

    printf("\nProductos y sus precios:\n");
    //Este ciclo recorre ambos arreglos en paralelo para mostrar la información capturada
    for(int i = 0; i < u; i++){
        
        // Imprime el nombre del producto y su precio formateado a 2 posiciones decimales (%.2f)
        
        printf("Producto: %s, Precio: %.2f\n", PRODUCTOS[i], PRECIOS[i]);
    }

    return 0;
    // Indica que el programa finalizó correctamente
}

