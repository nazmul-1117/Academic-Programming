#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int pages[50], memory[20], lastUsed[20];
    int numberOfPages, numberOfFrames;
    int pageFaultCount = 0;

    cout << "Enter number of pages: ";
    cin >> numberOfPages;

    cout << "Enter the pages:\n";
    for (int i = 0; i < numberOfPages; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of frames: ";
    cin >> numberOfFrames;

    // Initialize memory frames
    for (int i = 0; i < numberOfFrames; i++) {
        memory[i] = -1;
        lastUsed[i] = -1; // tracks time when the page was last used
    }

    int time = 0; // simulate time for LRU

    cout << "\nPage Replacement Process (LRU):\n";

    for (int i = 0; i < numberOfPages; i++) {
        bool hit = false;

        // Check if page is already in memory
        for (int j = 0; j < numberOfFrames; j++) {
            if (memory[j] == pages[i]) {
                hit = true;
                lastUsed[j] = time; // update last used time
                break;
            }
        }

        if (!hit) {
            // Find least recently used page
            int lruIndex = 0;
            int minTime = 1e9;
            for (int j = 0; j < numberOfFrames; j++) {
                if (memory[j] == -1) {
                    lruIndex = j;
                    break;
                }
                if (lastUsed[j] < minTime) {
                    minTime = lastUsed[j];
                    lruIndex = j;
                }
            }

            memory[lruIndex] = pages[i];    // Replace LRU page
            lastUsed[lruIndex] = time;
            pageFaultCount++;
        }

        time++;

        // Display current memory state
        cout << "After accessing page " << pages[i] << " : ";
        for (int j = 0; j < numberOfFrames; j++) {
            if (memory[j] != -1)
                cout << memory[j] << "\t";
            else
                cout << "-\t";
        }
        if (!hit)
            cout << "\tPage Fault No: " << pageFaultCount;
        cout << endl;
    }

    cout << "\nTotal number of Page Faults (LRU) = " << pageFaultCount << endl;

    return 0;
}
