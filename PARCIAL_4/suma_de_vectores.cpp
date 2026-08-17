/*este programa permite realisar la suma y multiplicasion de vectores , por medio de arreglos unidimensionales, 
el usuario podra elegir la operacion que desea realizar, ingresar los valores de los vectores y el programa realizara las operaciones correspondientes, mostrando los resultados en la terminal. 
*/ 
#include <stdio.h>
int main(){
    
    // Definición de la constante para el tamaño de los arreglos (máximo 4 elementos)
    const int u = 4; // La variable 'u' almacena el tamaño de los arreglos, en este caso 4, que es el número máximo de elementos que se pueden registrar.

    // Arreglos unidimensionales para almacenar los valores de los vectores.
    float vector1[u]; // Primer vector
    float vector2[u]; // Segundo vector
    float suma[u];    // Vector para almacenar la suma de los vectores
    float multiplicacion[u]; // Vector para almacenar la multiplicación de los vectores

    int opcion; // Variable para almacenar la opción del usuario

    // Solicita al usuario que elija la operación a realizar
    printf("Seleccione la operacion a realizar:\n");
    printf("1. Suma de vectores\n");
    printf("2. Multiplicacion de vectores\n");
    printf("Ingrese su opcion (1 o 2): ");
    scanf("%d", &opcion);

    // Solicita al usuario que ingrese los valores del primer vector
    printf("Ingrese los valores del primer vector (maximo %d elementos):\n", u);
    for(int i = 0; i < u; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vector1[i]);
    }

    // Solicita al usuario que ingrese los valores del segundo vector
    printf("Ingrese los valores del segundo vector (maximo %d elementos):\n", u);
    for(int i = 0; i < u; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vector2[i]);
    }

    // Realiza la operación seleccionada por el usuario
    if(opcion == 1){
        // Suma de vectores
        for(int i = 0; i < u; i++){
            suma[i] = vector1[i] + vector2[i];
        }
        // Muestra el resultado de la suma
        printf("Resultado de la suma de vectores:\n");
        for(int i = 0; i < u; i++){
            printf("Elemento %d: %.2f\n", i + 1, suma[i]);
        }
    } else if(opcion == 2){
        // Multiplicación de vectores
        for(int i = 0; i < u; i++){
            multiplicacion[i] = vector1[i] * vector2[i];
        }
        // Muestra el resultado de la multiplicación
        printf("Resultado de la multiplicacion de vectores:\n");
        for(int i = 0; i < u; i++){
            printf("Elemento %d: %.2f\n", i + 1, multiplicacion[i]);
        }
    }
    printf("desea realizar otra operacion? (1 para si, 0 para no): ");
    scanf("%d", &opcion);
    if(opcion == 1){
        main(); // Llama a la función main() para reiniciar el programa
    } else {
        printf("Gracias por usar el programa.\n");
    }

    return 0;
}