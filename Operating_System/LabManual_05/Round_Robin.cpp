#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int burst[n], remaining[n], waiting[n] = {0}, turnaround[n] = {0}, process[n];
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter Burst Time for Process P" << process[i] << ": ";
        cin >> burst[i];
        remaining[i] = burst[i]; // Initially remaining time = burst time
    }

    int quantum;
    cout << "Enter Time Quantum: ";
    cin >> quantum;

    int t = 0; // current time
    bool done;

    // Round Robin calculation
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = false;
                if (remaining[i] > quantum) {
                    t += quantum;
                    remaining[i] -= quantum;
                } else {
                    t += remaining[i];
                    waiting[i] = t - burst[i];
                    remaining[i] = 0;
                    turnaround[i] = waiting[i] + burst[i];
                }
            }
        }
    } while (!done);

    // Calculate total waiting and turnaround times
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        totalWT += waiting[i];
        totalTAT += turnaround[i];
    }

    // Output table
    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    cout << "------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << process[i] << "\t"
             << setw(10) << burst[i] << "\t"
             << setw(12) << waiting[i] << "\t"
             << setw(15) << turnaround[i] << "\n";
    }

    cout << "\nAverage Waiting Time     -> " << totalWT / n;
    cout << "\nAverage Turnaround Time  -> " << totalTAT / n << "\n";

    return 0;
}
