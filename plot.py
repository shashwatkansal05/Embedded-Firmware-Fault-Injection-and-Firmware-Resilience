import matplotlib.pyplot as plt
import numpy as np

# 1. Load Data
time_raw = []
sensor_raw = []
running_raw = []
fault_raw = []

fault_names = {
    0: "No Fault",
    1: "Sensor Glitch",
    2: "Queue Overflow",
    3: "Task Starvation"
}

with open("log.csv", "r") as f:
    for line in f:
        if not line.strip(): continue
        try:
            t, s, r, fl = line.strip().split(",")
            time_raw.append(int(t))
            sensor_raw.append(int(s))
            running_raw.append(int(r))
            fault_raw.append(int(fl))
        except ValueError:
            continue

# 2. Data Cleaning (The "Anti-Rectangle" Logic)
time = np.array(time_raw)
sensor = np.array(sensor_raw)
running = np.array(running_raw)
fault = np.array(fault_raw)

# Sort by time to prevent "wrap-around" lines
idx = np.argsort(time)
time, sensor, running, fault = time[idx], sensor[idx], running[idx], fault[idx]

# Remove duplicate timestamps that cause the "box" at the start
# This keeps only the LAST entry for any given timestamp
_, unique_indices = np.unique(time, return_index=True)
time = time[unique_indices]
sensor = sensor[unique_indices]
running = running[unique_indices]
fault = fault[unique_indices]

# 3. Plotting
# We use a subplot layout to keep all 3 graphs in one professional view
fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(10, 12), sharex=True)

# Graph 1: Sensor (Analog-style)
ax1.plot(time, sensor, color='blue', linewidth=1, label="Sensor Value")
ax1.set_title("System Analysis: Sensor Data", fontweight='bold')
ax1.set_ylabel("Value (0-100)")
ax1.grid(True, linestyle='--', alpha=0.6)

# Graph 2: Running State (Digital-style)
# 'where=post' ensures sharp vertical transitions
ax2.step(time, running, color='green', where='post', linewidth=2)
ax2.set_title("Logic State: System Power", fontweight='bold')
ax2.set_ylabel("1=ON / 0=OFF")
ax2.set_ylim(-0.2, 1.2)
ax2.set_yticks([0, 1])
ax2.grid(True, linestyle='--', alpha=0.6)

# Graph 3: Fault Type (Categorical-style)
ax3.step(time, fault, color='red', where='post', linewidth=2)
ax3.set_title("Diagnostics: Fault Injection Log", fontweight='bold')
ax3.set_ylabel("Fault Category")
ax3.set_yticks(list(fault_names.keys()))
ax3.set_yticklabels(list(fault_names.values()))
ax3.set_ylim(-0.5, 3.5)
ax3.grid(True, linestyle='--', alpha=0.6)

plt.xlabel("Time (ms)")
plt.tight_layout()
plt.show()
