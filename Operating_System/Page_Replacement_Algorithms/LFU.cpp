#include<iostream>
#include<vector>
using namespace std;

int main(){

    int nPages, nFrames;
    cout << "Enter the Number of Pages: ";
    cin >> nPages;

    cout << "Enter the Number of Frames: ";
    cin >> nFrames;

    vector<int> pages(nPages);
    cout << "Enter Pages: ";
    for (int i = 0; i < nPages; i++){
        cin >> pages[i];
    }

    vector<int> frames(nFrames, -1);
    vector<int> freq(nFrames, 0);
    int pageFaults = 0;

    cout << "Steps:\n";
    for (int i=0; i<nPages; i++){
        int current = pages[i];
        bool isHit = false;

        // Check for hit
        for (int j=0; j<nFrames; j++){
            if (frames[j] == current){
                freq[j]++;
                isHit = true;
                break;
            }
        }

        if (!isHit){
            int minFreq = freq[0];
            int minFreqIndex = 0;

            // Sort the frames frequencies
            for (int j=1; j<nFrames; j++){
                if (freq[j] < minFreq){
                    minFreq = freq[j];
                    minFreqIndex = j;
                }
            }

            // Replace the frame with the current page
            frames[minFreqIndex] = current;
            freq[minFreqIndex] = 1;
            pageFaults++;
        }

        // Show frame status
        for (int j = 0; j < nFrames; j++) {
            cout << frames[j] << " ";
        }
        if (isHit)
            cout << "Page `Hit` No --> " << current << endl;
        else
            cout << "Page `Fault` No --> " << current << endl;
    }
    cout << "Total Page Faults: " << pageFaults << endl;


}