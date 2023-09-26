#include <iostream>
using namespace std;

// array insert at Kth position;
// array sorting (bubble sort)
// array linear search;
// array binary search;
// array Kth position delation;

void insertData(int* arr, int &used_size, int data, int position){

	int i = used_size-1;

	while(i >= position){
		arr[i+1] = arr[i];

		i--;
	}

	arr[position] = data;

	used_size++;

}

void deleteValue(int* arr, int &used_size, int position){

	int i = position;

	while(i < used_size){
		arr[i] = arr[i+1];
		i++;
	}
	used_size--;
}

void linearSearch(int* arr, int &used_size, int data){
	
	cout<<"Linear Search: ";

	for(int i=0; i<used_size; i++){
		
		if(arr[i] == data){
			cout<<data<<" Data Matched..!"<<endl;
			return ;
		}
	}

	cout<<data<<" Data did Not Match..!"<<endl;
}

void bubbleSort(int* arr, int &used_size){
	int a = used_size;

	for(int i=0; i<a; i++){

		for(int j=0; j<a-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void binarySearch(int* arr, int &used_size, int &data){
	int low, mid, high;
	low = 0, high = used_size - 1;

	cout<<"Binary Search: ";
	while(low <= high){
		mid = (low + high)/2;

		if(arr[mid] == data){
			cout<<data<<" Data Matched..!"<<endl;
			return ;
		}

		if(arr[mid] < data){
			low = mid + 1;
		}

		else{
			high = mid - 1;
		}
	}
	cout<<data<<" Data did Not Match..!"<<endl;
}


void displayValue(int* arr, int &used_size){

	cout<<"Array Data: ";
	for(int i=0; i<used_size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main(){

	int Arr[20] = {12, 89, 1, 9, 25, 56, 64, 3, 4, 10};
	int used_size = 10;

	int data, position;

	{	//initial Array Display
		cout<<"Before insert value: "<<endl;
		displayValue(Arr, used_size);
		cout<<"Initial Array length: "<<used_size<<endl;
	}

	{	//insert array value at Kth position
		cout<<endl<<"After insert value: "<<endl;

		data = 100, position = 0;
		insertData(Arr, used_size, data, position);

		data = 120, position = 11;
		insertData(Arr, used_size, data, position);
	}

	{	//after insert array value
		displayValue(Arr, used_size);
		cout<<"Array length: "<<used_size<<endl;
	}

	{
		position = 1;
		deleteValue(Arr, used_size, position);
	}

	{	//after Delete array value
		cout<<endl<<"After Delete value: "<<endl;

		displayValue(Arr, used_size);
		cout<<"Array length: "<<used_size<<endl<<endl;;

	}


	{	cout<<endl<<"Bubble Sort: "<<endl;
		bubbleSort(Arr, used_size);
		displayValue(Arr, used_size);
	}

	{	//linear Search
		cout<<endl;
		data = 8;
		linearSearch(Arr, used_size, data);

	}

	
	{	//binary Search
		data = 1;
		binarySearch(Arr, used_size, data);
	}

	{
		cout<<endl<<"Happy..!\nThen Smile...";
	}

	return 0;
}
