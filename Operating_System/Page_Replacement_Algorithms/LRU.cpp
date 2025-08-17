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

    for (int i=0; i<nPages; i++){
        bool isHit = false;
        for (int j=0; j<nFrames; j++){
            if (frames[j] == pages[i]){
                isHit = true;
                break;
            }
        }

        if (!isHit){
            frames[frameIndex] = pages[i];
            
        }
    }


}