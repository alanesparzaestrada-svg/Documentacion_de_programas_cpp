#include <iostream>
// Este programa calcula la calificación final de un estudiante basado en documentación, actividades, asistencia y examen final.    


// pedirDatos: Solicita al usuario las notas de cada criterio por consola utilizando paso por referencia (&).
// - &documentacion: Referencia a la variable que almacenará la nota de entregas/documentos (0-10).
// - &actividades: Referencia a la variable que almacenará la nota de tareas o prácticas (0-10).
// - &asistencia: Referencia a la variable que almacenará el puntaje o porcentaje de asistencia (0-10).
// - &examen: Referencia a la variable que almacenará la nota del examen de evaluación final (0-10).
void pedirDatos(float &documentacion, float &actividades, float &asistencia, float &examen) {
    std::cout << "Ingresa la calificación de documentación (0-10): ";
    std::cin >> documentacion;
    std::cout << "Ingresa la calificación de actividades (0-10): ";
    std::cin >> actividades;
    std::cout << "Ingresa la calificación de asistencia (0-10) :";
    std::cin >> asistencia;
    std::cout << "Ingresa la calificación del examen (0-10): ";
    std::cin >> examen;
}
// Esta función calcula la calificación final basada en los pesos de cada componente.

// calcularcalificasion: Aplica la ponderación correspondiente a cada criterio evaluativo.
// - documentacion: Calificación final de la documentación (aporta el 30%).
// - actividades: Calificación acumulada de las actividades (aporta el 30%).
// - asistencia: Nota de asistencia (no se suma directamente en la fórmula, pero se recibe en los parámetros).
// - examen: Calificación obtenida en el examen (aporta el 40%).
float calcularcalificasion(float documentacion, float actividades, float asistencia, float examen) {
    return ((documentacion * 0.30) + (actividades * 0.30) + (examen * 0.40)) / 1.0;
}
// Función principal que coordina la entrada de datos, cálculo y salida de resultados.
int main(){
    
    float documentacion, actividades, asistencia, examen;
    float calificasion;
      // documentacion;   Almacena el valor decimal de la nota de documentación.
     //actividades;     Almacena el valor decimal de la nota de actividades.
    // asistencia;      Almacena el valor de asistencia ingresado por el alumno.
   //examen;          Almacena el valor decimal de la nota del examen final.
  // calificasion;    Guarda el promedio ponderado calculado a partir de los pesos establecidos.

    pedirDatos(documentacion, actividades, asistencia, examen);
// Verificación de asistencia mínima requerida para tener derecho al examen.
    if (asistencia < 0.40) {
        std::cout << "Estas reprobado, no tienes derecho al examen por faltas." << std::endl;
    } else {
        calificasion = calcularcalificasion(documentacion, actividades, asistencia, examen);
        std::cout << "Tu calificasion final es: " << calificasion << std::endl;
        return 0;
    }
// Cálculo de la calificación final si el estudiante tiene derecho al examen.
    calificasion = calcularcalificasion(documentacion, actividades, asistencia, examen);

    return 0;


    
}
