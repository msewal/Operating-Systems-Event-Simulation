
# Operating-Systems-Event-Simulation

This is a simple event-driven simulation project written in C++ for the Operating Systems course.  
The program randomly generates events within a fixed time range (1 to 20 seconds) and prints them in a time-ordered format using a queue data structure.
---
## Features
- Random event generation
- Time-based simulation (zaman: 001 s - 020 s)
- Formatted output with leading zeros
- FIFO queue usage for event scheduling
---
## Output Example
```bash
Simülasyon başladı 
zaman: 003 s: olay oldu. 
zaman: 007 s: olay oldu. 
zaman: 015 s: olay oldu.
```
---
## Technologies & Libraries

- **C++ Standard Library**
  - `<iostream>` → Input/output operations (e.g., `std::cout`)
  - `<queue>` → FIFO (first-in, first-out) structure to manage events
  - `<cstdlib>` → For generating random numbers (`rand()`)
  - `<ctime>` → To seed the random number generator with current time
  - `<iomanip>` → To format the output (e.g., `setw`, `setfill` for `003` format)

---
