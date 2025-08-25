#include <iostream>
using namespace std;

int main() {
    int totalMem, used = 0, req;
    char ch = 'y';
    int processNo = 1;

    cout << "Enter the total memory available (in Bytes): ";
    cin >> totalMem;

    while (ch == 'y' || ch == 'Y') {
        cout << "Enter memory required for process " << processNo << " (in Bytes): ";
        cin >> req;

        if (req <= (totalMem - used)) {
            cout << "Memory is allocated for Process " << processNo << "\n";
            used += req;
        } else {
            cout << "Memory is not allocated for Process " << processNo
                 << " (insufficient memory)\n";
        }

        cout << "Do you want to continue(y/n): ";
        cin >> ch;
        processNo++;
    }

    cout << "\nTotal Memory = " << totalMem << " Bytes";
    cout << "\nUsed Memory  = " << used << " Bytes";
    cout << "\nFree Memory  = " << (totalMem - used) << " Bytes\n";

    return 0;
}
