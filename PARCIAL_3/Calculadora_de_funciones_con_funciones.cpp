#include <stdio.h>

//  FUNCIONES 
float calcularTriangular(float x, float a, float m, float b);
float calcularGamma(float x, float a, float m);
float calcularL(float x, float a, float m);
float calcularTrapezoidal(float x, float a, float b, float c, float d);
float calcularS(float x, float a, float c);
float calcularZ(float x, float a, float c);
float calcularPi(float x, float b, float d);


// FUNCIÓN PRINCIPAL

int main() {
    // 1. Función Triangular (parámetros: a, m, b)
    float tri_a = 2.0f, tri_m = 5.0f, tri_b = 8.0f;

    // 2. Función Gamma (parámetros: a, m)
    float gam_a = 2.0f, gam_m = 6.0f;

    // 3. Función L (parámetros: a, m)
    float l_a = 3.0f, l_m = 7.0f;

    // 4. Función Trapezoidal (parámetros: a, b, c, d)
    float trap_a = 2.0f, trap_b = 4.0f, trap_c = 7.0f, trap_d = 9.0f;

    // 5. Función S (parámetros: a, c)
    float s_a = 1.0f, s_c = 5.0f;

    // 6. Función Z (parámetros: a, c)
    float z_a = 1.0f, z_c = 5.0f;

    // 7. Función Pi (parámetros: b, d)
    float pi_b = 5.0f, pi_d = 2.0f; 

    // Variables de control del usuario
    int opcion;
    float x;
    float resultado = 0.0f;

    // MENÚ DE SELECCIÓN DE ECUACIONES
    printf("===================================================\n");
    printf("  CALCULADORA DE FUNCIONES DE MEMBRESIA   \n");
    printf("===================================================\n");
    printf("Seleccione el tipo de ecuacion a resolver:\n");
    printf("1. Funcion Triangular\n");
    printf("2. Funcion Gamma\n");
    printf("3. Funcion L\n");
    printf("4. Funcion Trapezoidal\n");
    printf("5. Funcion S\n");
    printf("6. Funcion Z\n");
    printf("7. Funcion Pi (I)\n");
    printf("Ingrese su opcion (1-7): ");
    scanf("%d", &opcion);

    // Validación rápida de la opción seleccionada
    if (opcion < 1 || opcion > 7) {
        printf("\nOpcion no valida. Saliendo del programa.\n");
        return 1;
    }

    // Solicitud del valor de X
    printf("Ingrese el valor de X: ");
    scanf("%f", &x);

    // PROCESAMIENTO LLAMANDO A LAS FUNCIONES
    switch(opcion) {
        case 1:
            printf("\n--- Funcion Triangular ---");
            printf("\nParametros: a = %.2f, m = %.2f, b = %.2f\n", tri_a, tri_m, tri_b);
            resultado = calcularTriangular(x, tri_a, tri_m, tri_b);
            break;

        case 2:
            printf("\n--- Funcion Gamma ---");
            printf("\nParametros: a = %.2f, m = %.2f\n", gam_a, gam_m);
            resultado = calcularGamma(x, gam_a, gam_m);
            break;

        case 3:
            printf("\n--- Funcion L ---");
            printf("\nParametros: a = %.2f, m = %.2f\n", l_a, l_m);
            resultado = calcularL(x, l_a, l_m);
            break;

        case 4:
            printf("\n--- Funcion Trapezoidal ---");
            printf("\nParametros: a = %.2f, b = %.2f, c = %.2f, d = %.2f\n", trap_a, trap_b, trap_c, trap_d);
            resultado = calcularTrapezoidal(x, trap_a, trap_b, trap_c, trap_d);
            break;

        case 5:
            printf("\n--- Funcion S ---");
            printf("\nParametros: a = %.2f, c = %.2f\n", s_a, s_c);
            resultado = calcularS(x, s_a, s_c);
            break;

        case 6:
            printf("\n--- Funcion Z ---");
            printf("\nParametros: a = %.2f, c = %.2f\n", z_a, z_c);
            resultado = calcularZ(x, z_a, z_c);
            break;

        case 7:
            printf("\n--- Funcion Pi ---");
            printf("\nParametros: b = %.2f, d = %.2f\n", pi_b, pi_d);
            resultado = calcularPi(x, pi_b, pi_d);
            break;
    }

    // IMPRESIÓN DEL RESULTADO
    printf("---------------------------------------------------\n");
    printf("El resultado de la membresia es: %.4f\n", resultado);
    printf("===================================================\n");

    return 0;
}


// DESARROLLO DE LAS FUNCIONES


float calcularTriangular(float x, float a, float m, float b) {
    if (x <= a) {
        return 0.0f;
    } else if (x > a && x <= m) {
        return (x - a) / (m - a);
    } else if (x > m && x <= b) {
        return (b - x) / (b - m);
    } else {
        return 0.0f;
    }
}

float calcularGamma(float x, float a, float m) {
    if (x <= a) {
        return 0.0f;
    } else if (x > a && x < m) {
        return (x - a) / (m - a);
    } else { 
        return 1.0f;
    }
}

float calcularL(float x, float a, float m) {
    // Reutiliza la función Gamma ya que L = 1 - Gamma
    return 1.0f - calcularGamma(x, a, m);
}

float calcularTrapezoidal(float x, float a, float b, float c, float d) {
    if (x <= a) {
        return 0.0f;
    } else if (x > a && x <= b) {
        return (x - a) / (b - a);
    } else if (x > b && x <= c) {
        return 1.0f;
    } else if (x > c && x <= d) {
        return (d - x) / (d - c);
    } else {
        return 0.0f;
    }
}

float calcularS(float x, float a, float c) {
    float mid = (a + c) / 2.0f;
    if (x < a) {
        return 0.0f;
    } else if (x >= a && x <= mid) {
        float term = (x - a) / (c - a);
        return 2.0f * term * term;
    } else if (x > mid && x <= c) {
        float term2 = (x - c) / (c - a);
        return 1.0f - 2.0f * term2 * term2;
    } else { 
        return 1.0f;
    }
}

float calcularZ(float x, float a, float c) {
    // Reutiliza la función S ya que Z = 1 - S
    return 1.0f - calcularS(x, a, c);
}

float calcularPi(float x, float b, float d) {
    if (x <= b) {
        // Tramo S con inicio en (b-d) y final en b
        return calcularS(x, b - d, b);
    } else {
        // Tramo Z con inicio en b y final en (b+d)
        return calcularZ(x, b, b + d);
    }
}

