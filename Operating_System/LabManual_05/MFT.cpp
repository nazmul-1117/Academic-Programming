#include <iostream>
#include <vector>
using namespace std;

int main() {
    int totalSize;
    cout << "Enter the total size: ";
    cin >> totalSize;

    int blockSize;
    cout << "Enter the block size: ";
    cin >> blockSize;

    int nBlocks = totalSize / blockSize;
    int exFrag = totalSize % blockSize;

    int nProcess;
    cout << "Enter Number of Processes: ";
    cin >> nProcess;

    vector<int> processes(nProcess, -1);

    for (int i = 0; i < nProcess; i++) {
        cout << "Enter memory required for process " << i + 1 << " (in Bytes): ";
        cin >> processes[i];
    }

    cout << "\nNo. of Blocks available in memory = " << nBlocks;
    cout << "\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION\n";

    int allocatedProcess = 0;
    int inFrag = 0;

    for (int i = 0; i < nProcess && allocatedProcess < nBlocks; i++) {
        cout << i + 1 << "\t" << processes[i];

        if (processes[i] > blockSize) {
            cout << "\t\tNO\t\t---\n";
        } else {
            cout << "\t\tYES\t\t" << (blockSize - processes[i]) << "\n";
            allocatedProcess++;
            inFrag += (blockSize - processes[i]);
        }
    }

    if (allocatedProcess < nProcess) {
        cout << "\nMemory is Full, Remaining Processes cannot be accommodated\n";
    }

    cout << "\nTotal Internal Fragmentation = " << inFrag;
    cout << "\nTotal External Fragmentation = " << exFrag << "\n";

    return 0;
}
