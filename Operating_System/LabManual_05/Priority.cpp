#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int burst[n], priority[n], waiting[n], turnaround[n], process[n];

    // Input burst time and priority
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter Burst Time for Process P" << process[i] << ": ";
        cin >> burst[i];
        cout << "Enter Priority for Process P" << process[i] << ": ";
        cin >> priority[i];
    }

    // Sort processes by priority (lower number = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                swap(priority[i], priority[j]);
                swap(burst[i], burst[j]);
                swap(process[i], process[j]);
            }
        }
    }

    // Calculate waiting time and turnaround time
    waiting[0] = 0;
    turnaround[0] = burst[0];
    float totalWT = 0, totalTAT = turnaround[0];

    for (int i = 1; i < n; i++) {
        waiting[i] = turnaround[i - 1];
        turnaround[i] = waiting[i] + burst[i];
        totalWT += waiting[i];
        totalTAT += turnaround[i];
    }

    // Output table
    cout << "\nPROCESS\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n";
    cout << "---------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << process[i] << "\t"
             << setw(10) << burst[i] << "\t"
             << setw(8) << priority[i] << "\t"
             << setw(12) << waiting[i] << "\t"
             << setw(15) << turnaround[i] << "\n";
    }

    cout << "\nAverage Waiting Time     -> " << totalWT / n;
    cout << "\nAverage Turnaround Time  -> " << totalTAT / n << "\n";

    return 0;
}
