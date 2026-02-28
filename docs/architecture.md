# Embedded IO Core - Bloque N1

## Estructura del proyecto
- `src/` → Código fuente (main.c, control.c)
- `include/` → Headers públicos (control.h)
- `docs/` → Documentación
- `build/` → Ejecutables compilados (ignored en git)

## Flujo principal
1. `main.c`:
   - Inicializa controlador
   - Simula entradas externas
   - Llama al loop principal
   - Actualiza FSM y ejecuta acciones
   - Calcula y muestra error

2. `control.c` / `control.h`:
   - `ControlData` → manejo de setpoint, medición y error
   - `update_state()` → determina próximo estado
   - `execute_action()` → simula actuación de LEDs o alertas
   - `control_update()` y `control_compute_error()` → actualiza medición y calcula error

## FSM
- Estados: `IDLE`, `RUNNING`, `ERROR`
- Transiciones básicas:
  - IDLE → RUNNING → ERROR → IDLE

## Notas
- Proyecto preparado para simular embedded real sin hardware
- Próximos pasos:
  - Integrar logs o visualización
  - Preparar Bloque N2: Embedded PID