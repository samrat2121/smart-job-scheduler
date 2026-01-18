import matplotlib.pyplot as plt

jobs = []
start = []
duration = []

with open("schedule_log.txt") as f:
    for line in f:
        _, job, s, e = line.split()
        jobs.append(job)
        start.append(int(s))
        duration.append(int(e) - int(s))

fig, ax = plt.subplots()

ax.barh(jobs, duration, left=start)
ax.set_xlabel("Time")
ax.set_ylabel("Jobs")
ax.set_title("Priority Scheduling - Gantt Chart")

plt.show()
