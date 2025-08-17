#include <iostream>
#include <vector>
using namespace std;

int main(){

    int frameIndex = 0;
    int pageFaults = 0;

    int nPages;
    cout << "Enter the Number of Pages: ";
    cin >> nPages;

    int nFrames;
    cout << "Enter the Number of Frames: ";
    cin >> nFrames;

    vector <int> pages(nPages);
    cout << "Enter Pages: " ;

    // Take Pages input
    for (int i=0; i<nPages; i++){
        cin >> pages[i];
    }

    vector <int> frames(nFrames);
    // cout << "Enter Frames: ";

    // Reset Frames
    for (int i=0; i<nFrames; i++){
        frames[i] = -1;
    }

    cout << "Steps: " << endl;
    for (int i = 0; i < nPages; i++){

        bool isHit = false;
        // Calculate Page Hits
        for (int j=0; j<nFrames; j++){
            if(frames[j] == pages[i]){
                isHit = true;
                break;
            }
        }  

        // Page Fault Calculate
        if (!isHit){
            frames[frameIndex] = pages[i];
            ++frameIndex;
            if (frameIndex == nFrames){
                frameIndex = 0;
            }
            ++pageFaults;
        }

        // Stapes
        for (int j=0; j<nFrames; j++){
            cout << frames[j] << " ";
        }
        if(isHit){
            cout << "Page `Hit` No --> " << pages[i] << endl;
        }else{
            cout << "Page `Fault` No --> " << pages[i] << endl;
        }
    }

    cout << "Page Faults: " << pageFaults << endl;
}