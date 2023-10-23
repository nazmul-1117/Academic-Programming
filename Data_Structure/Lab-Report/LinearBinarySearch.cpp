#include <iostream>
using namespace std;
/**
*  @author Md. Nazmul Hossain
*   @ID: 223002089
**/

void displayData(int *arr, int &usedSize){
	for(int i=0; i<usedSize; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void linearSearch(int *arr, int &usedSize, int &item){
    for(int i=0; i<usedSize; i++){
        if(arr[i] == item){
            cout<<item<<" is Located in position[index] "<<i<<endl;
            return ;
        }
    }
    cout<<item<<" Data is not found"<<endl;
}

void binarySearch(int *arr, int &usedSize, int &item){
    int Beg, Mid, End;
    Beg = 0;
    End = usedSize - 1;

    while(Beg <= End){
        Mid = (Beg+End)/2;

        if(arr[Mid] == item){
            cout<<item<<" is Located in position[index] "<<Mid<<endl;
            return ;
        }

        else if(arr[Mid] > item){
            End = Mid - 1;
        }

        else{
            Beg = Mid + 1;
        }
    }
    cout<<item<<" Data Not Found"<<endl;
}

int main(){
	int totalSize = 100, usedSize, position, data;
	int *arr = new int[totalSize];

	cout<<endl<<"Enter Array size: ";
	cin>>usedSize;

    cout<<"Enter your Array Elements(for Binary Search, Please Insert Sorted Way): ";
	for(int i=0; i<usedSize; i++){
		cin>>arr[i];
	}

	cout<<"Your Array Elements are: ";
	displayData(arr, usedSize);
	cout<<"Array Size is: "<<usedSize<<endl<<endl;

	int sItem;
	cout<<"Enter Your Linear Search Item: ";
	cin>>sItem;
	linearSearch(arr, usedSize, sItem);

	cout<<endl<<"Enter Your Binary Search Item: ";
	cin>>sItem;
	binarySearch(arr, usedSize, sItem);

	}
