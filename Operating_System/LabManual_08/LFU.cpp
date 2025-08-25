#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int pages[50], memory[20], freq[20], timeStamp[20];
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

    // Initialize memory, frequency and timestamp
    for (int i = 0; i < numberOfFrames; i++) {
        memory[i] = -1;
        freq[i] = 0;
        timeStamp[i] = -1;
    }

    int time = 0; // to break ties using FIFO order

    cout << "\nPage Replacement Process (LFU):\n";

    for (int i = 0; i < numberOfPages; i++) {
        bool hit = false;

        // Check if page is already in memory
        for (int j = 0; j < numberOfFrames; j++) {
            if (memory[j] == pages[i]) {
                hit = true;
                freq[j]++;           // increase frequency
                timeStamp[j] = time; // update timestamp
                break;
            }
        }

        if (!hit) {
            int replaceIndex = -1;
            int minFreq = 1e9;

            // Find the LFU page
            for (int j = 0; j < numberOfFrames; j++) {
                if (memory[j] == -1) {
                    replaceIndex = j; // empty frame found
                    break;
                }
                if (freq[j] < minFreq) {
                    minFreq = freq[j];
                    replaceIndex = j;
                } else if (freq[j] == minFreq) {
                    // Tie-breaker using FIFO
                    if (timeStamp[j] < timeStamp[replaceIndex])
                        replaceIndex = j;
                }
            }

            memory[replaceIndex] = pages[i];
            freq[replaceIndex] = 1; // new page frequency = 1
            timeStamp[replaceIndex] = time;
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

    cout << "\nTotal number of Page Faults (LFU) = " << pageFaultCount << endl;

    return 0;
}
