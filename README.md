**Project Overview**  
The goal of this project is to move beyond functional "happy path" programming and explore **Functional Safety**. By simulating a real-time environment, you can analyze how a system identifies and handles faults **without requiring physical hardware** in the early stages of development.

This project demonstrates how embedded systems respond to common faults such as **sensor glitches, queue overflows, and task starvation**.

---

**Technical Features**  

- **RTOS-Style Architecture:** Modular task scheduler managing concurrent processes.  
- **Deterministic Fault Injection:** Precise, time-based triggering of system anomalies.  
- **State-Based Diagnostics:** Finite State Machine (FSM) transitions between Normal and Fault modes.  
- **Telemetry Logging:** Real-time data export to CSV for visualization and analysis.  
- **Modular Design:** Separation of concerns between scheduler, tasks, and global system state.  

---

**System Architecture**  

The firmware is divided into specialized modules:

| Module | Description |
|--------|-------------|
| `scheduler.c` | Handles task execution timing and preemption logic. |
| `monitor_task.c` | Supervisory task that injects faults and observes system behavior. |
| `sensor_task.c` | Simulates data acquisition, including glitches and anomalies. |
| `system_state.h` | Centralized structure for global system state, fault definitions, and flags. |
| `logger_task.c` | Logs system telemetry and task activity for analysis. |
| `control_task.c` | Simulates main control logic responding to sensor data. |

---

**Fault Scenarios**  

The simulator currently supports:

- **Sensor Glitch:** Introduces temporary incorrect sensor readings.  
- **Queue Overflow:** Simulates a situation where the inter-task queue exceeds its capacity.  
- **Task Starvation:** Delays or prevents a task from executing to mimic real-time scheduling issues.  

---

**Analysis & Results**  

System behavior is captured and exported to **CSV**, allowing visualization and correlation between:

- Injected fault type  
- Detection latency  
- System state transitions









