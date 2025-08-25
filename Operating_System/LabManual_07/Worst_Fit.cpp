#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 25

int main() {
    int b[MAX] = {0}, f[MAX] = {0};       // block sizes and file sizes
    int bf[MAX] = {0}, ff[MAX] = {0};     // block allocation flag, file to block mapping
    int frag[MAX] = {0};
    int nb, nf;

    cout << "Enter the number of blocks: ";
    cin >> nb;

    cout << "Enter the number of files: ";
    cin >> nf;

    cout << "\nEnter the size of the blocks:\n";
    for (int i = 1; i <= nb; i++) {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }

    cout << "\nEnter the size of the files:\n";
    for (int i = 1; i <= nf; i++) {
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    // Worst-Fit allocation
    for (int i = 1; i <= nf; i++) {
        int highest = -1;  // largest block difference
        for (int j = 1; j <= nb; j++) {
            if (bf[j] != 1) { // block not allocated
                int temp = b[j] - f[i];
                if (temp >= 0 && temp > highest) {
                    highest = temp;
                    ff[i] = j; // allocate this block to file i
                }
            }
        }
        frag[i] = highest;
        if (highest != -1) bf[ff[i]] = 1; // mark block as allocated
    }

    // Output table
    cout << "\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 1; i <= nf; i++) {
        cout << i << "\t"
             << f[i] << "\t\t"
             << ff[i] << "\t\t"
             << b[ff[i]] << "\t\t"
             << frag[i] << "\n";
    }

    return 0;
}
