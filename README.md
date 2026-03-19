📌 Project Overview

The goal of this project is to move beyond functional "happy path" programming and explore Functional Safety. By simulating a real-time environment, I can analyze how a system identifies and handles faults without requiring physical hardware in the early stages of development.
---
Key Features:
RTOS-Style Architecture: Uses a modular task scheduler to manage concurrent processes.

Deterministic Fault Injection: Precise, time-based triggering of system anomalies.

State-Based Diagnostics: Implements a Finite State Machine (FSM) to transition the system between Normal, Warning, and Fault modes.

Telemetry Logging: Exports real-time system data to CSV for external analysis and visualization.
---
🏗️ System Architecture
The firmware is divided into several specialized modules:

-- scheduler.c: Manages task execution and timing.

-- monitor_task.c: Acts as the system supervisor and fault injector.

-- sensor_task.c: Simulates data acquisition with injected noise/glitches.

-- system_state.h: Defines the global state and fault types (Task Starvation, Queue Overflow, etc.).
---
📊 Performance & Visualization
System behavior is captured in real-time. Below is a trace showing the correlation between sensor data, running state, and fault detection.
