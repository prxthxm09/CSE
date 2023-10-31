#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int current_queue;  // The current queue the process is in
};

typedef struct Process Process;

// Function to initialize a process
Process* createProcess(int id, int arrival_time, int burst_time, int current_queue) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->arrival_time = arrival_time;
    process->burst_time = burst_time;
    process->current_queue = current_queue;
    return process;
}

// Function to perform Multilevel Feedback Queue scheduling for a queue
// Function to perform Multilevel Feedback Queue scheduling for a queue
void multilevelFeedbackQueue(Process** queue, int num_processes, int num_queues, int time_quantum[]) {
    int time = 0;
    int completed_processes = 0;
    int current_queue = 0;
   
    while (completed_processes < num_processes) {
        int remaining = 0;
        for (int i = 0; i < num_processes; i++) {
            Process* process = queue[i];
           
            if (process->burst_time > 0) {
                remaining = 1;
                int quantum = time_quantum[process->current_queue];
                if (process->burst_time > quantum) {
                    time += quantum;
                    process->burst_time -= quantum;
                } else {
                    time += process->burst_time;
                    printf("Process %d completed (Queue %d) at time %d\n", process->id, process->current_queue, time);
                    completed_processes++;
                    process->burst_time = 0;
                }
            }
           
            // Demote the process to a lower priority queue
            if (process->burst_time > 0 && process->current_queue < num_queues - 1) {
                process->current_queue++;
            }
        }
       
        if (remaining == 0) {
            // No process remaining in the current queue, move to the next queue
            printf("Queue %d is empty at time %d\n", current_queue, time);
            current_queue = (current_queue + 1) % num_queues;
        }
    }
}


int main() {
    int num_processes = 5;
    int num_queues = 3;
    Process* processes[5];

    // Create sample processes
    processes[0] = createProcess(1, 0, 20, 0);
    processes[1] = createProcess(2, 2, 8, 0);
    processes[2] = createProcess(3, 4, 76, 0);
    processes[3] = createProcess(4, 6, 7, 0);
    processes[4] = createProcess(5, 8, 5, 0);

    // Define time quantum for each queue
    int time_quantum[] = {4, 8, 16};

    printf("Processes scheduled using Multilevel Feedback Queue:\n");
    multilevelFeedbackQueue(processes, num_processes, num_queues, time_quantum);

    // Free allocated memory
    for (int i = 0; i < num_processes; i++) {
        free(processes[i]);
    }

    return 0;
} 


/*
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;
    int priority; // Priority of the process
    int burst_time; // Burst time of the process
};

typedef struct Process Process;

// Function to initialize a process
Process* createProcess(int id, int priority, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->priority = priority;
    process->burst_time = burst_time;
    return process;
}

int main() {
    int num_processes = 5;
    Process* processes[5];

    // Create sample processes
    processes[0] = createProcess(1, 2, 10);
    processes[1] = createProcess(2, 1, 8);
    processes[2] = createProcess(3, 0, 6);
    processes[3] = createProcess(4, 2, 7);
    processes[4] = createProcess(5, 1, 5);

    // Implement your scheduling policies here
    // You can have three separate queues for different policies
    // and schedule processes accordingly.

    // For simplicity, we'll just print the processes in their current order.
    printf("Processes in the order they were created:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d (Priority %d, Burst Time %d)\n", processes[i]->id, processes[i]->priority, processes[i]->burst_time);
    }

    // Free allocated memory
    for (int i = 0; i < num_processes; i++) {
        free(processes[i]);
    }

    return 0;
}
*/