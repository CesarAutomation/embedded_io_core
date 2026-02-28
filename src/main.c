#include <stdio.h>
#include "control.h"

#define MAX_ITERATIONS 20   // Número de ciclos simulados del loop principal

/*
 * main()
 * ------
 * Punto de entrada del Embedded IO Core.
 * Simula un entorno de ejecución determinista donde:
 *  - Se generan mediciones simuladas
 *  - Se actualiza la capa de control
 *  - Se ejecuta la máquina de estados
 *  - Se realiza la actuación correspondiente
 */
int main() {

    // Inicialización de la capa de control con setpoint fijo
    ControlData ctrl;
    control_init(&ctrl, 50.0f);

    // Estado inicial del sistema
    SystemState current_state = STATE_IDLE;

    // Estructura de entradas simuladas
    Inputs in = {false, false};

    int iteration = 0;

    while(iteration < MAX_ITERATIONS) {

        // Simulación de medición creciente
        float sensor_value = iteration * 4.0f;

        // Simulación de eventos externos
        if(iteration == 8)  in.button_pressed = true;
        if(iteration == 16) in.error_detected = true;

        // Actualización del modelo de control
        control_update(&ctrl, sensor_value);

        // Calcular el error actual;
        float error = control_compute_error(&ctrl);

        // Actualización del estado del sistema
        current_state = update_state(current_state, in);

        // Ejecución de acción asociada al estado
        execute_action(current_state);

        // Información de debug / log
        printf("|Iter: %02d|State: %d|Measurement: %.2f|Error: %.2f\n",
                iteration,
                current_state,
                sensor_value,
                error);

        iteration++;
    }

    return 0;
}