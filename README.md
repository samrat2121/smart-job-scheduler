# Smart Job Scheduler (C++ and Python)

A CPU scheduling simulator built in **C++** that implements and compares  
**Priority Scheduling** and **Round Robin Scheduling**, with performance metrics and **Python-based Gantt chart visualization**.

---

## 📌 Features
- Priority Scheduling (non-preemptive)
- Round Robin Scheduling (preemptive, time-sliced)
- Waiting Time & Turnaround Time calculation
- File-based job input
- Execution timeline logging
- Gantt chart visualization using Python (matplotlib)

---

## 🧠 Motivation
I wanted to go beyond textbook explanations of CPU scheduling algorithms and understand  
how different schedulers behave in practice — in terms of fairness, waiting time, and execution order.

This project focuses on **systems thinking and implementation**, not UI abstractions.

---

## ⚙️ Tech Stack
- **C++** – core scheduling logic
- **STL** – priority queue, queue, vectors
- **Python** – matplotlib for visualization

---

## 📂 Input Format (`jobs.txt`)
```
jobId arrivalTime burstTime priority
1 0 5 2
2 0 4 1
3 0 6 3
```

Each row represents a job with its arrival time, CPU burst time, and scheduling priority.

---

## 📊 Output & Visualization
- Execution timelines are logged during scheduling
- Separate logs are generated for:
  - Priority Scheduling
  - Round Robin Scheduling
- Python scripts read these logs and generate **Gantt charts** to visualize CPU execution

  ---

## 🚀 How to Run

### Compile & Run (C++)
```bash
g++ -std=c++17 main.cpp scheduler.cpp -o scheduler
./scheduler
```

### Generate Visualizations (Python)
```bash
python visualize_priority.py
python visualize_rr.py
```

---

## 📈 Key Learnings
- Practical differences between preemptive and non-preemptive scheduling
- Impact of time quantum on fairness and response time
- Use of priority queues and queues in real scheduling problems
- Instrumenting C++ systems code for performance analysis
- Bridging low-level C++ logic with Python-based visualization





