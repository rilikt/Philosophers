# 🍝 Philosophers – Threaded Dining Simulation in C

This project is a classic concurrency problem: the **Dining Philosophers**. It explores the use of **threads** and **mutexes** in C to simulate philosophers sharing forks while avoiding starvation, deadlocks, and race conditions.

It was my introduction to multithreading and synchronization. Understanding the race conditions and building a deadlock-free implementation made this both an educational and satisfying project.

---

## 🧠 Problem Summary

- Philosophers sit at a round table with forks placed between them
- They alternate between **thinking**, **eating**, and **sleeping**
- A philosopher must pick up both forks to eat
- If a philosopher does not eat within `time_to_die` ms, they die
- Simulation ends either on death or when all have eaten the required number of times

---

## ⚙️ Program Arguments

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Number of philosophers and forks
- `time_to_die`: Time (ms) a philosopher can go without eating
- `time_to_eat`: Time (ms) spent eating (must hold 2 forks)
- `time_to_sleep`: Time (ms) spent sleeping
- `number_of_times_each_philosopher_must_eat` (optional): Ends simulation when all have eaten this many times

---

## 🔩 Core Concepts

- Each philosopher is a **thread**
- Each fork is protected by a **mutex**
- No **global variables** allowed
- States and events must be **synchronized** and **accurately logged**
- Messages:
  ```
  timestamp_in_ms X is eating
  timestamp_in_ms X has taken a fork
  timestamp_in_ms X is sleeping
  timestamp_in_ms X is thinking
  timestamp_in_ms X died
  ```

---
