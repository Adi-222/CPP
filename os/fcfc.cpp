#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;

    Process(int pid, int arrival_time, int burst_time) : pid(pid), arrival_time(arrival_time), burst_time(burst_time), completion_time(0) {}
};

void calculateWaitingTimeTurnaroundTime(vector<Process>& processes, vector<int>& waiting_time, vector<int>& turnaround_time) {
    int n = processes.size();

    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].completion_time - processes[i].arrival_time;
    }
}

void printResults(vector<Process>& processes, vector<int>& waiting_time, vector<int>& turnaround_time) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int n = processes.size();

    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        cout << processes[i].pid << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].burst_time << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << "\t\t" << processes[i].completion_time << endl;
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    cout << "\nAverage Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main() {
    vector<Process> processes;

    processes.emplace_back(1, 0, 10);
    processes.emplace_back(2, 6, 4);
    processes.emplace_back(3, 8, 2);
    processes.emplace_back(4, 10, 5);

    int n = processes.size();

    vector<int> waiting_time(n);
    vector<int> turnaround_time(n);

    calculateWaitingTimeTurnaroundTime(processes, waiting_time, turnaround_time);

    printResults(processes, waiting_time, turnaround_time);

    return 0;
}
