#include <iostream>
#include <ctime>
using namespace std;

void displayData(int *arr, int &usedSize){
	for(int i=0; i<usedSize; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void setData(int *arr, int &usedSize){
    srand(time(0));
    for(int i=0; i<usedSize; i++){
        arr[i] = rand()%100;
    }
}

void bubbleSort(int *arr, int &usedSize){
    for(int i=0; i<usedSize; i++){
        for(int j=0; j<usedSize-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int *arr, int &usedSize){
    int minAddress;
    for(int i=0; i<usedSize; i++){
        minAddress = i;
        for(int j=i+1; j<usedSize; j++){
            if(arr[j] < arr[minAddress]){
                minAddress = j;
            }
        }
        swap(arr[i], arr[minAddress]);
    }
}

void insertionSort(int *arr, int &usedSize){
    for(int i=1; i<usedSize; i++){
        int key = arr[i], j = i-1;
        while(arr[j] > key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int usedSize;
    cout<<endl<<"\tEnter Array Element Size: ";
    cin>>usedSize;
    int *arr = new int[usedSize];

    setData(arr, usedSize);
    cout<<"\tYour Array's elements are: ";
    displayData(arr, usedSize);

    cout<<"\tAfter Bubble Sort, Your Array elements are:";
    bubbleSort(arr, usedSize);
    displayData(arr, usedSize);

    setData(arr, usedSize);
    cout<<endl<<"\tYour Second Array's elements are: ";
    displayData(arr, usedSize);

    cout<<"\tAfter Selection Sort, Your Array elements are: ";
    selectionSort(arr, usedSize);
    displayData(arr, usedSize);

    setData(arr, usedSize);
    cout<<endl<<"\tYour Third Array's elements are: ";
    displayData(arr, usedSize);

    cout<<"\tAfter Insertion Sort, Your Array's elements are: ";
    insertionSort(arr, usedSize);
    displayData(arr, usedSize);

    delete[] arr;
}
