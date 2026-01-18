#include "scheduler.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

/* ---------- FILE LOADING ---------- */
void Scheduler::loadJobsFromFile(const string& filename) {
    ifstream file(filename);
    jobs.clear();

    if (!file) {
        cout << "ERROR: Could not open " << filename << endl;
        return;
    }

    Job job;
    while (file >> job.jobId >> job.arrivalTime >> job.burstTime >> job.priority) {
        job.remainingTime = job.burstTime;
        jobs.push_back(job);
    }

    file.close();
    cout << "Loaded " << jobs.size() << " jobs from file.\n";
}

/* ---------- PRIORITY SCHEDULING ---------- */
struct ComparePriority {
    bool operator()(const Job& a, const Job& b) {
        return a.priority > b.priority;
    }
};

void Scheduler::priorityScheduling() {
    if (jobs.empty()) {
        cout << "No jobs to schedule.\n";
        return;
    }

    priority_queue<Job, vector<Job>, ComparePriority> pq;
    for (auto job : jobs) pq.push(job);

    ofstream log("priority_log.txt"); // overwrite each run

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int completedJobs = 0;

    cout << "\n--- Priority Scheduling ---\n";

    while (!pq.empty()) {
        Job job = pq.top();
        pq.pop();

        int startTime = currentTime;
        int completionTime = startTime + job.burstTime;

        log << job.jobId << " "
            << startTime << " "
            << completionTime << "\n";

        cout << "Job " << job.jobId
             << " | Start: " << startTime
             << " | End: " << completionTime << endl;

        int turnaroundTime = completionTime - job.arrivalTime;
        int waitingTime = turnaroundTime - job.burstTime;

        totalWaitingTime += waitingTime;
        totalTurnaroundTime += turnaroundTime;
        completedJobs++;

        currentTime = completionTime;
    }

    log.close();

    cout << "Average Waiting Time: "
         << (float)totalWaitingTime / completedJobs << endl;

    cout << "Average Turnaround Time: "
         << (float)totalTurnaroundTime / completedJobs << endl;
}

/* ---------- ROUND ROBIN SCHEDULING ---------- */
void Scheduler::roundRobinScheduling(int timeQuantum) {
    if (jobs.empty()) {
        cout << "No jobs to schedule.\n";
        return;
    }

    queue<Job> q;
    for (auto job : jobs) q.push(job);

    ofstream log("rr_log.txt"); // overwrite each run

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int completedJobs = 0;

    cout << "\n--- Round Robin Scheduling (TQ = "
         << timeQuantum << ") ---\n";

    while (!q.empty()) {
        Job job = q.front();
        q.pop();

        int execTime = min(timeQuantum, job.remainingTime);
        int startTime = currentTime;
        int endTime = startTime + execTime;

        log << job.jobId << " "
            << startTime << " "
            << endTime << "\n";

        cout << "Job " << job.jobId
             << " executed from t=" << startTime
             << " to t=" << endTime << endl;

        currentTime = endTime;
        job.remainingTime -= execTime;

        if (job.remainingTime > 0) {
            q.push(job);
        } else {
            int turnaroundTime = currentTime - job.arrivalTime;
            int waitingTime = turnaroundTime - job.burstTime;

            totalWaitingTime += waitingTime;
            totalTurnaroundTime += turnaroundTime;
            completedJobs++;
        }
    }

    log.close();

    cout << "Average Waiting Time: "
         << (float)totalWaitingTime / completedJobs << endl;

    cout << "Average Turnaround Time: "
         << (float)totalTurnaroundTime / completedJobs << endl;
}
