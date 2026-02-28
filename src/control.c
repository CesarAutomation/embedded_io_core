#include <stdio.h>
#include <stdbool.h>
#include "control.h"

// Inicializa la estructura de control
void control_init(ControlData *ctrl, float sp) {
    ctrl->setpoint = sp;
    ctrl->measurement = 0.0f;
    ctrl->error = 0.0f;
}

// Actualiza la medición
void control_update(ControlData *ctrl, float measurement) {
    ctrl->measurement = measurement;
}

// Calcula el error (setpoint - measurement)
float control_compute_error(ControlData *ctrl) {
    ctrl->error = ctrl->setpoint - ctrl->measurement;
    return ctrl->error;
}

// Determina el siguiente estado según el estado actual y las entradas
SystemState update_state(SystemState current, Inputs in) {
    switch(current) {
        case STATE_IDLE:
            if(in.button_pressed)
                return STATE_RUNNING;
            break;

        case STATE_RUNNING:
            if(in.error_detected) 
                return STATE_ERROR;
            break;

        case STATE_ERROR:
            if(!in.error_detected)
                return STATE_IDLE;
            break;
    }
    return current;
}

// Ejecuta la acción correspondiente al estado actual del sistema.
void execute_action(SystemState state) {
    static bool led_toggle = false;

    switch(state) {
        case STATE_IDLE:
            printf("Sistema en IDLE\n");
            break;  
        
        case STATE_RUNNING:
            led_toggle = !led_toggle;
            printf("RUNNING - LED %s\n", led_toggle ? "ON" : "OFF");
            break;

        case STATE_ERROR:
            printf("ERROR!!!\n");
            break;
    }
}
