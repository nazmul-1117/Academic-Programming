#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 25

int main() {
    int b[MAX] = {0}, f[MAX] = {0};       // block sizes and file sizes
    int bf[MAX] = {0}, ff[MAX] = {0};     // block allocation flags, file to block mapping
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

    // First-Fit allocation
    for (int i = 1; i <= nf; i++) {
        ff[i] = -1; // initialize as not allocated
        for (int j = 1; j <= nb; j++) {
            if (bf[j] != 1 && b[j] >= f[i]) {
                ff[i] = j;      // allocate this block
                frag[i] = b[j] - f[i]; 
                bf[j] = 1;      // mark block as allocated
                break;          // move to next file
            }
        }
        if (ff[i] == -1) frag[i] = -1; // file could not be allocated
    }

    // Output table
    cout << "\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 1; i <= nf; i++) {
        if (ff[i] != -1)
            cout << i << "\t"
                 << f[i] << "\t\t"
                 << ff[i] << "\t\t"
                 << b[ff[i]] << "\t\t"
                 << frag[i] << "\n";
        else
            cout << i << "\t"
                 << f[i] << "\t\t"
                 << "--\t\t--\t\t--\n"; // file not allocated
    }

    return 0;
}
