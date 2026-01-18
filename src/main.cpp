#include "scheduler.h"
#include <iostream>

int main() {
    Scheduler scheduler;

    scheduler.loadJobsFromFile("C:\\Users\\Samrat\\Desktop\\Graphics\\Smart Job Scheduler\\jobs.txt");
    scheduler.priorityScheduling();
    scheduler.roundRobinScheduling(2);

    return 0;
}
