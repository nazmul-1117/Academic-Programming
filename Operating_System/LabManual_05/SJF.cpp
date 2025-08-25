#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> bt(n);  // Burst times
    vector<int> p(n);   // Process IDs
    vector<int> wt(n);  // Waiting times
    vector<int> tat(n); // Turnaround times

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        cout << "Enter Burst Time for Process P" << p[i] << ": ";
        cin >> bt[i];
    }

    // Sort processes by burst time (non-preemptive SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) {
                swap(bt[i], bt[k]);
                swap(p[i], p[k]);
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0;
    tat[0] = bt[0];
    float wtavg = 0, tatavg = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = tat[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Display table
    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t"
             << setw(10) << bt[i] << "\t"
             << setw(12) << wt[i] << "\t"
             << setw(15) << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time     -> " << wtavg / n;
    cout << "\nAverage Turnaround Time  -> " << tatavg / n << "\n";

    return 0;
}
