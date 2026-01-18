#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <string>
#include "job.h"

class Scheduler {
private:
    std::vector<Job> jobs;

public:
    void loadJobsFromFile(const std::string& filename);
    void priorityScheduling();
    void roundRobinScheduling(int timeQuantum);

};

#endif
