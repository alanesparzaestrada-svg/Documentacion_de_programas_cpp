#include <stdio.h>

int main() {
    // ==========================================
    // VARIABLES PREINICIALIZADAS (PARAMETROS)
    // ==========================================
    // 1. Función Triangular (parámetros: a, m, b)
    float tri_a = 2.0f;
    float tri_m = 5.0f;
    float tri_b = 8.0f;

    // 2. Función Gamma (parámetros: a, m)
    float gam_a = 2.0f;
    float gam_m = 6.0f;

    // 3. Función L (parámetros: a, m)
    float l_a = 3.0f;
    float l_m = 7.0f;

    // 4. Función Trapezoidal (parámetros: a, b, c, d)
    float trap_a = 2.0f;
    float trap_b = 4.0f;
    float trap_c = 7.0f;
    float trap_d = 9.0f;

    // 5. Función S (parámetros: a, c)
    float s_a = 1.0f;
    float s_c = 5.0f;

    // 6. Función Z (parámetros: a, c)
    float z_a = 1.0f;
    float z_c = 5.0f;

    // 7. Función Pi (parámetros: b, d) -> Centro b y ancho de transiciones d
    float pi_b = 5.0f;
    float pi_d = 2.0f; 

    // Variables de control del usuario
    int opcion;
    float x;
    float resultado = 0.0f;

    // ==========================================
    // MENÚ DE SELECCIÓN DE ECUACIONES
    // ==========================================
    printf("===================================================\n");
    printf("  CALCULADORA DE FUNCIONES DE MEMBRESIA (DIFUSA)  \n");
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

    // ==========================================
    // PROCESAMIENTO CON SWITCH-CASE
    // ==========================================
    switch(opcion) {
        case 1: // Función Triangular
            printf("\n--- Funcion Triangular ---");
            printf("\nParametros: a = %.2f, m = %.2f, b = %.2f\n", tri_a, tri_m, tri_b);
            if (x <= tri_a) {
                resultado = 0.0f;
            } else if (x > tri_a && x <= tri_m) {
                resultado = (x - tri_a) / (tri_m - tri_a);
            } else if (x > tri_m && x <= tri_b) {
                resultado = (tri_b - x) / (tri_b - tri_m);
            } else {
                resultado = 0.0f;
            }
            break;

        case 2: // Función Gamma
            printf("\n--- Funcion Gamma ---");
            printf("\nParametros: a = %.2f, m = %.2f\n", gam_a, gam_m);
            if (x <= gam_a) {
                resultado = 0.0f;
            } else if (x > gam_a && x < gam_m) {
                resultado = (x - gam_a) / (gam_m - gam_a);
            } else { // x >= m
                resultado = 1.0f;
            }
            break;

        case 3: // Función L (L = 1 - Gamma)
            printf("\n--- Funcion L ---");
            printf("\nParametros: a = %.2f, m = %.2f\n", l_a, l_m);
            float g_val;
            if (x <= l_a) {
                g_val = 0.0f;
            } else if (x > l_a && x < l_m) {
                g_val = (x - l_a) / (l_m - l_a);
            } else {
                g_val = 1.0f;
            }
            resultado = 1.0f - g_val;
            break;

        case 4: // Función Trapezoidal
            printf("\n--- Funcion Trapezoidal ---");
            printf("\nParametros: a = %.2f, b = %.2f, c = %.2f, d = %.2f\n", trap_a, trap_b, trap_c, trap_d);
            if (x <= trap_a) {
                resultado = 0.0f;
            } else if (x > trap_a && x <= trap_b) {
                resultado = (x - trap_a) / (trap_b - trap_a);
            } else if (x > trap_b && x <= trap_c) {
                resultado = 1.0f;
            } else if (x > trap_c && x <= trap_d) {
                // Nota matemática: Corrección estándar de la fórmula de descenso del trapecio
                resultado = (trap_d - x) / (trap_d - trap_c);
            } else {
                resultado = 0.0f;
            }
            break;

        case 5: // Función S
            printf("\n--- Funcion S ---");
            printf("\nParametros: a = %.2f, c = %.2f\n", s_a, s_c);
            float mid_s;
            mid_s = (s_a + s_c) / 2.0f;
            
            if (x < s_a) {
                resultado = 0.0f;
            } else if (x >= s_a && x <= mid_s) {
                float term = (x - s_a) / (s_c - s_a);
                resultado = 2.0f * term * term;
            } else if (x > mid_s && x <= s_c) {
                float term2 = (x - s_c) / (s_c - s_a);
                resultado = 1.0f - 2.0f * term2 * term2;
            } else { // x > c
                resultado = 1.0f;
            }
            break;

        case 6: // Función Z (Z = 1 - S)
            printf("\n--- Funcion Z ---");
            printf("\nParametros: a = %.2f, c = %.2f\n", z_a, z_c);
            float s_val;
            float mid_z;
            mid_z = (z_a + z_c) / 2.0f;

            if (x < z_a) {
                s_val = 0.0f;
            } else if (x >= z_a && x <= mid_z) {
                float term = (x - z_a) / (z_c - z_a);
                s_val = 2.0f * term * term;
            } else if (x > mid_z && x <= z_c) {
                float term2 = (x - z_c) / (z_c - z_a);
                s_val = 1.0f - 2.0f * term2 * term2;
            } else {
                s_val = 1.0f;
            }
            resultado = 1.0f - s_val;
            break;

        case 7: // Función Pi
            printf("\n--- Funcion Pi ---");
            printf("\nParametros: b = %.2f, d = %.2f\n", pi_b, pi_d);
            // Compuesta por un tramo S (izquierda de b) y un tramo Z (derecha de b)
            if (x <= pi_b) {
                // Tramo S con inicio en (b-d) y final en b
                float local_a = pi_b - pi_d;
                float local_c = pi_b;
                float mid = (local_a + local_c) / 2.0f;
                if (x < local_a) {
                    resultado = 0.0f;
                } else if (x >= local_a && x <= mid) {
                    float term = (x - local_a) / (local_c - local_a);
                    resultado = 2.0f * term * term;
                } else {
                    float term2 = (x - local_c) / (local_c - local_a);
                    resultado = 1.0f - 2.0f * term2 * term2;
                }
            } else {
                // Tramo Z con inicio en b y final en (b+d)
                float local_a = pi_b;
                float local_c = pi_b + pi_d;
                float mid = (local_a + local_c) / 2.0f;
                float s_val2;
                if (x < local_a) {
                    s_val2 = 0.0f;
                } else if (x >= local_a && x <= mid) {
                    float term = (x - local_a) / (local_c - local_a);
                    s_val2 = 2.0f * term * term;
                } else if (x > mid && x <= local_c) {
                    float term2 = (x - local_c) / (local_c - local_a);
                    s_val2 = 1.0f - 2.0f * term2 * term2;
                } else {
                    s_val2 = 1.0f;
                }
                resultado = 1.0f - s_val2;
            }
            break;
    }

    // ==========================================
    // IMPRESIÓN DEL RESULTADO
    // ==========================================
    printf("---------------------------------------------------\n");
    printf("El resultado de la membresia es: %.4f\n", resultado);
    printf("===================================================\n");

    return 0;
}