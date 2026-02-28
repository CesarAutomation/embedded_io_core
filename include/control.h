#ifndef CONTROL_H
#define CONTROL_H
#include <stdbool.h>

typedef struct {
    float setpoint;     //Valor deseado
    float measurement;  //Medición actual
    float error;        // Error calculado
} ControlData;

typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_ERROR
} SystemState;

typedef struct {
    bool button_pressed;
    bool error_detected;
} Inputs;

// Inicializa la estructura de control
void control_init(ControlData *ctrl, float sp);

// Actualiza la medición
void control_update(ControlData *ctrl, float measurement);

// Calcula el error actual
float control_compute_error(ControlData *ctrl);

// Determina el siguiente estado según el estado actual y las entradas
SystemState update_state(SystemState current, Inputs in);

// Ejecuta la acción correspondiente al estado actual del sistema.
void execute_action(SystemState state);

#endif