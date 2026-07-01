#include <iostream>
// Este programa calcula la calificación final de un estudiante basado en documentación, actividades, asistencia y examen final.    

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
float calcularcalificasion(float documentacion, float actividades, float asistencia, float examen) {
    return ((documentacion * 0.30) + (actividades * 0.30) + (examen * 0.40)) / 1.0;
}
// Función principal que coordina la entrada de datos, cálculo y salida de resultados.
int main(){
    
    float documentacion, actividades, asistencia, examen;
    float calificasion;

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