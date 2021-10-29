#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>

#include "ComputeTask.h"
#include "IOTask.h"

typedef enum OP
{
    COMPUTE_TASK = 1,
    IO_TASK
} OP_t;

typedef struct task
{
    struct task* next;
    OP_t taskType;
} task_t;

int getTaskCount(task_t* taskList)
{
    task_t* temp = taskList;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main(int argc, char* argv[])
{
    // Initialize Task List Node
    task_t computeTask, ioTask;
    task_t* curTask = &computeTask;
    computeTask.taskType = COMPUTE_TASK;
    computeTask.next = &ioTask;
    ioTask.taskType = IO_TASK;
    ioTask.next = NULL;


    double timeElapse = 0;                                                  // Time Elapse
    struct timeval taskStartTime, taskEndTime;                              // Time Moment
    int flagInitialProcess = 1;                                             // A flag indicating if it is a initial process.
    pid_t* fpids = (pid_t*)malloc(getTaskCount(curTask) * sizeof(pid_t));   // fpid list


    gettimeofday(&taskStartTime, NULL);                                     // Start timing, including parent process and child processes.
    for (int i = 0; curTask != NULL; i++)                                   // Distribute child tasks.
    {
        fpids[i] = fork();                                                  // Copy a new child process.
        // isSubProcess
        if (fpids[i] == 0)                                                  // If a child process.
        {
            flagInitialProcess = 0;                                         // Make the flag zero.
            break;                                                          // Break the distribution.
        }
        else
        {
            printf("Generate child process with pid: %d\n", fpids[i]);      // Print generated information.
        }
        curTask = curTask->next;                                            // Goto the next List Node.
    }


    if (flagInitialProcess == 0)
    {
        if (curTask->taskType == IO_TASK)
        {
            gettimeofday(&taskStartTime, NULL);                                                 // Start child process timing.
            executeIOTask();
            printf("This is a IO task, pid: %d parent pid: %d\n", getpid(), getppid());         // Print process ID and parent process ID
            gettimeofday(&taskEndTime, NULL);
            timeElapse = (double)(taskEndTime.tv_sec - taskStartTime.tv_sec) * 1000.0 + (double)(taskEndTime.tv_usec - taskStartTime.tv_usec) / 1000.0;
            printf("IO Time Consume: %fms\n", timeElapse);
        }
        if (curTask->taskType == COMPUTE_TASK)
        {
            gettimeofday(&taskStartTime, NULL);                                                 // Start child process timing.
            executeComputeTask();
            printf("This is a compute task, pid: %d parent pid: %d\n", getpid(), getppid());    // Print process ID and parent process ID
            gettimeofday(&taskEndTime, NULL);
            timeElapse = (double)(taskEndTime.tv_sec - taskStartTime.tv_sec) * 1000.0 + (double)(taskEndTime.tv_usec - taskStartTime.tv_usec) / 1000.0;
            printf("Compute Time Consume: %fms\n", timeElapse);
        }
    }
    else if (flagInitialProcess == 1)
    {
        while (wait(NULL) != -1);

        gettimeofday(&taskEndTime, NULL);
        timeElapse = (double)(taskEndTime.tv_sec - taskStartTime.tv_sec) * 1000.0 + (double)(taskEndTime.tv_usec - taskStartTime.tv_usec) / 1000.0;
        printf("Total Time Consume: %fms\n", timeElapse);
    }
    return 0;
}