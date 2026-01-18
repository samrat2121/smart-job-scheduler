import matplotlib.pyplot as plt

jobs = []
start_times = []
durations = []

with open("rr_log.txt", "r") as f:
    for line in f:
        job_id, start, end = line.split()
        jobs.append(f"Job {job_id}")
        start_times.append(int(start))
        durations.append(int(end) - int(start))

plt.figure(figsize=(10, 4))
plt.barh(jobs, durations, left=start_times)
plt.xlabel("Time")
plt.ylabel("Jobs")
plt.title("Round Robin Scheduling – Gantt Chart")
plt.tight_layout()

plt.show()
