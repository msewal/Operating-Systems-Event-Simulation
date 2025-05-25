# 📚 Operating-Systems-Event-Simulation

This is an event-driven process simulation project written in C++ for the **Operating Systems** course.  
The program simulates the lifecycle of multiple processes, including events like arrival, execution, suspension, garbage collection (optional), and exit.  
Each event is generated with randomized timing and validated against allowed transitions.

---

## Features

- Process-based simulation with multiple event types
- Time-randomized event scheduling
- State transition validation
- Chronological event output
- Clean, modular C++ structure

---

## Event Types

Each process goes through a sequence of events:

1. **Surec geldi** (Process arrived)
2. **Surec calismaya basladi** (Started running)
3. **Surec calismayi birakti** (Paused)
4. **Surec GC istedi** (Requested Garbage Collection) *(optional)*
5. **GC bitti** (GC completed)
6. **Surec cikti** (Exited)

Events follow strict rules of valid transitions, enforced by the simulation logic.

---

## Example Output

```bash
Simulasyon basladi
zaman: 002 s: Surec 1 Surec geldi.
zaman: 004 s: Surec 1 Surec calismaya basladi.
zaman: 006 s: Surec 1 Surec calismayi birakti.
zaman: 012 s: Surec 1 Surec cikti.
```

Each line represents a valid state transition in time order.

---

## Technologies & Libraries

- **C++ STL Containers**
  - `<vector>` → Dynamic event list
  - `<map>` → Olay türleri ve geçiş kuralları
  - `<algorithm>` → `std::sort` for chronological ordering
- **Utility Libraries**
  - `<cstdlib>` and `<ctime>` → Random number generation
  - `<iomanip>` → Formatted output (e.g., `003 s`)
  - `<iostream>` → Standard input/output

---

## Project Structure

```
.
├── main.cpp           # Main simulation logic
├── README.md          # Project description
```

---

## Academic Context

This project was developed as part of a university Operating Systems course to demonstrate:

- Event-driven architecture
- Process lifecycle modeling
- Use of standard C++ features for simulation

---

## Future Improvements

- Add optional GC event randomness
- Track and report statistics (average lifetime, GC usage, etc.)
- Export event log to file

---

