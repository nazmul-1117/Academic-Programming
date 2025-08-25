#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> bt(n);  // Burst time
    vector<int> wt(n);  // Waiting time
    vector<int> tat(n); // Turnaround time

    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter the Burst Time for process " << i + 1 << ": ";
        cin >> bt[i];
    }

    // FCFS calculation
    wt[0] = 0;
    tat[0] = bt[0];
    float wtavg = 0, tatavg = bt[0];

    for (int i = 1; i < n; i++) {
        wt[i] = tat[i - 1]; 
        tat[i] = bt[i] + wt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Output table
    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    cout << "---------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << setw(10) << bt[i] << "\t"
             << setw(12) << wt[i] << "\t"
             << setw(15) << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time     -> " << wtavg / n;
    cout << "\nAverage Turnaround Time  -> " << tatavg / n << "\n";

    return 0;
}
