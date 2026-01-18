#ifndef JOB_H
#define JOB_H

struct Job {
    int jobId;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime; //NEW--For Round Robin
};

#endif
