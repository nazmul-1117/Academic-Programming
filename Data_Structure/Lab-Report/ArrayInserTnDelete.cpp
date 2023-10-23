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

int main(){
	int totalSize = 100, usedSize, position, data;
	int *arr = new int[totalSize];

	cout<<endl<<"Enter Array size: ";
	cin>>usedSize;

	cout<<"Enter Array Elements: ";
	for(int i=0; i<usedSize; i++){
		cin>>arr[i];
	}

	cout<<"Your Array Elements are: ";
	displayData(arr, usedSize);
	cout<<"Array Size is: "<<usedSize<<endl<<endl;

	cout<<"Enter a Location[index] for inserting the data: ";
	cin>>position;

	cout<<"Enter a Data for inserting: ";
	cin>>data;

	for(int i=usedSize-1; i>=position; i--){
		arr[i+1] = arr[i];
	}
	arr[position] = data;
	usedSize++;

	cout<<"After Inserting, Your array elements are: ";
	displayData(arr, usedSize);
	cout<<"Array Size is: "<<usedSize<<endl<<endl;

	cout<<"Enter a Location[index] for Deleting the Data: ";
	cin>>position;

	for(int i=position; i<usedSize; i++){
		arr[i] = arr[i+1];
	}
	usedSize--;

	cout<<"After Deleting, Your array elements are: ";
	displayData(arr, usedSize);
	cout<<"Array Size is: "<<usedSize<<endl<<endl;

	delete[] arr;
	return 0;
}
