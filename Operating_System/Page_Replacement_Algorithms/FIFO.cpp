#include <iostream>
#include <vector>
using namespace std;

int main(){

    int nPages;
    cout << "Enter the Number of Pages: ";
    cin >> nPages;

    vector<int> pages(nPages);
    cout << "Enter the Pages: ";
    for (int i = 0; i < nPages; i++){
        cin >> pages[i];
    }

    int frames;
    cout << "Enter the number of frames: ";
    cin >> frames;

    vector<int> memory(frames);
    for (int i = 0; i < frames; i++){
        memory[i] = -1;
    }

    for (int i = 0; i < nPages; i++){
        int page = pages[i];
        int flag = 0;
        for (int j = 0; j < frames; j++){
            if (memory[j] == page){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            for (int j = 0; j < frames - 1; j++){
                memory[j] = memory[j + 1];
            }
            memory[frames - 1] = page;
        }
        for (int j = 0; j < frames; j++){
            cout << memory[j] << " -- ";
        }
        cout << endl;
    }

    return 0;
}