#include <iostream>
using namespace std;

int main() {
    int pages[50], memory[20];
    int pageFaultCount = 0, memoryIndex = 0;
    int numberOfPages, numberOfFrames;

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
    }

    cout << "\nPage Replacement Process (FIFO):\n";

    for (int i = 0; i < numberOfPages; i++) {
        int j;
        // Check if page is already in memory
        for (j = 0; j < numberOfFrames; j++) {
            if (memory[j] == pages[i])
                break;
        }

        // Page fault occurs if page not found in memory
        if (j == numberOfFrames) {
            memory[memoryIndex] = pages[i]; // Replace oldest page
            memoryIndex = (memoryIndex + 1) % numberOfFrames; // Circular index
            pageFaultCount++;
        }

        // Display current memory state
        cout << "After accessing page " << pages[i] << " : ";
        for (int k = 0; k < numberOfFrames; k++) {
            if (memory[k] != -1)
                cout << memory[k] << "\t";
            else
                cout << "-\t";
        }

        if (j == numberOfFrames)
            cout << "\tPage Fault No: " << pageFaultCount;
        cout << endl;
    }

    cout << "\nTotal number of Page Faults (FIFO) = " << pageFaultCount << endl;

    return 0;
}
