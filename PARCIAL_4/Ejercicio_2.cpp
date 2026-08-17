/*es te programa muestra las calificasiones de los 16 estudienates de ITIID-2*/
#include <stdio.h>

int main(){
const int u = 16;// Definición de la constante para el tamaño de los arreglos (máximo 16 estudiantes)
char NOMBRES[u][30];// Matriz para almacenar los nombres de los estudiantes.
float CALIFICACIONES[u];// Arreglo unidimensional para almacenar las calificaciones de cada estudiante como números decimales.
for(int i = 0; i < u; i++){// Este ciclo 'for' se ejecuta 'u' (16) veces para solicitar la información al usuario.

    printf("Ingrese el nombre del estudiante %d: ", i + 1);// Solicita y lee el nombre del estudiante 'i + 1' (para que el usuario vea 1 en lugar de 0)
    scanf("%s", NOMBRES[i]);// No lleva '&' porque NOMBRES[i] ya es una dirección de memoria (cadena)
    printf("Ingrese la calificacion del estudiante %d: ", i + 1);// Solicita y lee la calificación del estudiante correspondiente
    scanf("%f", &CALIFICACIONES[i]);// Lleva '&' porque se está guardando en una variable de tipo float elemental
    printf("\n\n");


}
printf("==================================================");
printf("Nombres de los Estudiantes y sus calificaciones:\n");//Este ciclo recorre ambos arreglos en paralelo para mostrar la información capturada
printf("==================================================\n");
for(int i = 0; i < u; i++){// Imprime el nombre del estudiante y su calificación formateada a 2 posiciones decimales (%.2f)

    printf("Nombre: %s, Calificacion: %.2f \n", NOMBRES[i], CALIFICACIONES[i]);// Imprime el nombre del estudiante y su calificación formateada a 2 posiciones decimales (%.2f)

}
return 0;// Indica que el programa finalizó correctamente
}