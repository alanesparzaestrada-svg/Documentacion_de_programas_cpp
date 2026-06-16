#include <stdio.h>

/**
 * Programa para calcular el promedio final de un alumno
 * basado en documentación, actividades, asistencia y examen.
 */
int main() {
    // Declaración de variables para las calificaciones y asistencia
    float documentacion, actividades, examen, asistencia;
    float promedio;

    // Solicitar y capturar la calificación de documentación
    printf("Ingresa la calificacion de documentacion (0-10): ");
    scanf("%f", &documentacion);

    // Solicitar y capturar la calificación de actividades
    printf("Ingresa la calificacion de actividades (0-10): ");
    scanf("%f", &actividades);

    // Solicitar y capturar el porcentaje de asistencia
    printf("Ingresa el porcentaje de asistencia (0-100): ");
    scanf("%f", &asistencia);

    // --- Validación de derecho a examen ---
    // Si la asistencia es menor al 50%, el alumno reprueba automáticamente
    if (asistencia < 50) {
        printf("\nEstas reprobado, no tienes derecho al examen por faltas.\n");
    } 
    else {
        // Si tiene 50% o más de asistencia, se le permite ingresar la nota del examen
        printf("Ingresa la calificacion del examen (0-10): ");
        scanf("%f", &examen);

        // --- Cálculo del promedio final ---
        // Se aplica el peso correspondiente: 30% doc, 30% act, y 50% examen.
        // Como la suma de los pesos da 110% (1.1), se divide entre 1.1 para normalizar a base 10.
        promedio = ((documentacion * 0.30) + (actividades * 0.30) + (examen * 0.50)) / 1.1;

        // Mostrar el resultado final con dos decimales
        printf("\nTu promedio final es: %.2f\n", promedio);
    }

    return 0; // Indica que el programa finalizó con éxito
}