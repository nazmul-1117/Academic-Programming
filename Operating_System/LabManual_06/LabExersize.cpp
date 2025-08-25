#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100

int main() {
    int nBlocks, nProcesses;
    int blockSize[MAX], blockAllocated[MAX] = {0};
    int processSize[MAX];
    int allocatedBlock[MAX];
    int internalFrag[MAX] = {0};

    cout << "Enter the number of Blocks: ";
    cin >> nBlocks;

    for (int i = 0; i < nBlocks; i++) {
        cout << "Block " << i + 1 << " size: ";
        cin >> blockSize[i];
    }

    cout << "Enter the number of processes: ";
    cin >> nProcesses;

    for (int i = 0; i < nProcesses; i++) {
        cout << "Enter memory required for process " << i + 1 << ": ";
        cin >> processSize[i];
        allocatedBlock[i] = -1; // Initially not allocated
    }

    // First-Fit allocation
    for (int i = 0; i < nProcesses; i++) {
        for (int j = 0; j < nBlocks; j++) {
            if (!blockAllocated[j] && blockSize[j] >= processSize[i]) {
                allocatedBlock[i] = j;
                internalFrag[i] = blockSize[j] - processSize[i];
                blockAllocated[j] = 1; // Mark block as allocated
                break;
            }
        }
    }

    // Print output table
    cout << "\n---------------------------------------------------------------------------\n";
    cout << "| Processes | Process Size | Blocks | Block Size | Allocated | Int. Frag. |\n";
    cout << "---------------------------------------------------------------------------\n";

    for (int i = 0; i < nProcesses; i++) {
        cout << "| " << setw(9) << i + 1 
             << " | " << setw(12) << processSize[i] << " | ";
        if (allocatedBlock[i] != -1) {
            int blockIdx = allocatedBlock[i];
            cout << setw(6) << blockIdx + 1
                 << " | " << setw(10) << blockSize[blockIdx]
                 << " | " << setw(8) << "YES"
                 << " | " << setw(10) << internalFrag[i] << " |\n";
        } else {
            cout << setw(6) << "--"
                 << " | " << setw(10) << "--"
                 << " | " << setw(8) << "NO"
                 << " | " << setw(10) << "-- |\n";
        }
    }

    cout << "---------------------------------------------------------------------------\n";

    return 0;
}
