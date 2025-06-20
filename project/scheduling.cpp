#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Process structure
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
};

// Function to simulate FCFS scheduling algorithm
void FCFS(vector<Process>& processes) {
    queue<Process> readyQueue;

    int currentTime = 0;
    float totalWaitingTime = 0;
    int n = processes.size();

    for (int i = 0; i < n; ++i) {
        while (currentTime < processes[i].arrivalTime)
            currentTime++;

        processes[i].remainingTime = processes[i].burstTime;

        cout << "Process " << processes[i].id << " is running from " << currentTime << " to ";
        currentTime += processes[i].burstTime;
        cout << currentTime << endl;

        totalWaitingTime += currentTime - processes[i].arrivalTime - processes[i].burstTime;
    }

    cout << "Average Waiting Time (FCFS): " << totalWaitingTime / n << endl;
}

// Function to simulate SJN scheduling algorithm
void SJN(vector<Process>& processes) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> readyQueue;

    int currentTime = 0;
    float totalWaitingTime = 0;
    int n = processes.size();
    int idx = 0;

    while (idx < n || !readyQueue.empty()) {
        if (!readyQueue.empty()) {
            auto [burstTime, id] = readyQueue.top();
            readyQueue.pop();

            cout << "Process " << id << " is running from " << currentTime << " to ";
            currentTime += burstTime;
            cout << currentTime << endl;

            totalWaitingTime += currentTime - processes[id].arrivalTime - burstTime;

            while (idx < n && processes[idx].arrivalTime <= currentTime) {
                readyQueue.push({processes[idx].burstTime, processes[idx].id});
                idx++;
            }
        } else {
            readyQueue.push({processes[idx].burstTime, processes[idx].id});
            currentTime = processes[idx].arrivalTime;
            idx++;
        }
    }

    cout << "Average Waiting Time (SJN): " << totalWaitingTime / n << endl;
}

// Function to simulate Round Robin scheduling algorithm
void RoundRobin(vector<Process>& processes, int quantum) {
    queue<Process> readyQueue;

    int currentTime = 0;
    float totalWaitingTime = 0;
    int n = processes.size();
    int idx = 0;

    while (idx < n || !readyQueue.empty()) {
        while (idx < n && processes[idx].arrivalTime <= currentTime) {
            readyQueue.push(processes[idx]);
            idx++;
        }

        if (!readyQueue.empty()) {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();

            cout << "Process " << currentProcess.id << " is running from " << currentTime << " to ";
            int executeTime = min(quantum, currentProcess.remainingTime);
            currentTime += executeTime;
            cout << currentTime << endl;

            currentProcess.remainingTime -= executeTime;

            if (currentProcess.remainingTime > 0) {
                readyQueue.push(currentProcess);
            } else {
                totalWaitingTime += currentTime - currentProcess.arrivalTime - currentProcess.burstTime;
            }
        } else {
            currentTime++;
        }
    }

    cout << "Average Waiting Time (Round Robin): " << totalWaitingTime / n << endl;
}

int main() {
    // Define processes
    vector<Process> processes = {
        {1, 0, 5},
        {2, 1, 3},
        {3, 2, 8},
        {4, 3, 6},
        {5, 4, 4}
    };

    // Simulate FCFS scheduling
    cout << "FCFS Scheduling:" << endl;
    FCFS(processes);
    cout << endl;

    // Simulate SJN scheduling
    cout << "SJN Scheduling:" << endl;
    SJN(processes);
    cout << endl;

    // Simulate Round Robin scheduling with time quantum of 2
    cout << "Round Robin Scheduling (Quantum = 2):" << endl;
    RoundRobin(processes, 2);

    return 0;
}
