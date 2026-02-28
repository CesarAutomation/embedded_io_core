# EMBEDDED_IO_CORE

## Objetivo del Proyecto
Este proyecto tiene como objetivo principal desarrollar un **sistema de control embebido industrial** completo, combinando:

- MCU (Arduino) para lectura de sensores, control PID y ejecución de FSM.
- Raspberry Pi para logging, visualización de datos y comunicación con el MCU.

Se busca construir **firmware real y profesional**, no un prototipo de hobby, con énfasis en:

- Modularidad
- Determinismo temporal
- Documentación clara
- Preparación para integración industrial

---

## Qué NO hará este sistema
- No se trata de un proyecto académico sin aplicación real.  
- No incluye desarrollo web, interfaces gráficas complejas ni dependencias externas innecesarias.  
- No usaremos funciones de bloqueo (`delay()`) en MCU ni código monolítico en `main`.

---

## Arquitectura General
[Sensores] --> [MCU / Arduino] --> [Actuadores] --> [Raspberry Pi] --> [Logging / Visualización]

**Módulos principales:**

1. **MCU (Arduino)**
   - Lectura de sensores analógicos y digitales
   - Control PID en tiempo real
   - FSM para lógica de control
   - Comunicación UART/I2C/SPI con Raspberry Pi

2. **Raspberry Pi**
   - Recepción de datos del MCU
   - Logging y almacenamiento
   - Visualización de resultados
   - Banco de pruebas remoto simulado

---

## Principios de Diseño

- Código modular, con separación clara entre módulos (`control.c`, `main.c`, etc.)  
- Determinismo temporal: evitar bloqueos y delays  
- Separación de responsabilidades MCU / Pi  
- Documentación clara para facilitar mantenimiento y revisión profesional  

---

## Próximos Pasos

- Implementación de la estructura de datos y funciones básicas en C
- Simulación de loop de control sin hardware
- Preparación para integración con GPIO y comunicación UART
- Documentación detallada de arquitectura y decisiones técnicas
- Plan establecido por **bloques**

---

## Estado Actual (Bloque N1: Embedded IO Core)

- Carpeta de proyecto creada
- Estructura de módulos definida:

```
    embedded_io_core/
    │
    ├── src/
    │   ├── main.c
    │   └── control.c
    ├── include/
    │   └── control.h
    ├── docs/
    │   └── architecture.md
    ├── README.md 
    └── .gitignore
```

- Funcionalidad implementada:  
  - Loop principal de simulación (`main.c`)  
  - FSM (`update_state`) y actuación simulada (`execute_action`)  
  - Control básico y cálculo de error (`control_update` y `control_compute_error`)  
- Código comentado profesionalmente  
- Preparado para subir a GitHub como **checkpoint v0.1**  

---

## Próximos Pasos (Bloque N2: Embedded PID)

- Implementar PID en C sobre MCU  
- Integrar cálculo de control con mediciones simuladas  
- Documentar decisiones de discretización y tuning  
- Preparar logging extendido y visualización de resultados