#include <iostream>
using namespace std;

class Array{
	
	public:
	int total_size;
	int used_size;
	int* myArray;
		
		Array(){}

		Array(int tSize, int uSize){
			this -> total_size = tSize;
			this -> used_size = uSize;
			myArray = new int[this -> used_size];	
		}

		~Array(){
				delete[] myArray;
				cout<<"Destructor called"<<endl;
		}


};

void setData(Array* &arr){

	for(int i=0; i<arr -> used_size; i++){
		cin>>(arr -> myArray)[i];
	}

}

void insertData(Array* &arr){

}

void bubbleSort(Array* &arr){

	for(int i=0; i<(arr -> used_size); i++){
		for(int j=0; j<(arr -> used_size) - i - 1; j++){
			int &x = (arr -> myArray)[j];
			int &y = (arr -> myArray)[j+1];

			if( x > y){
				x ^= y;
				y ^= x;
				x ^= y;

			}
		}
	}
}

int binarySearch(Array* &arr, int &data){

	if((arr -> myArray)[0] == data){
		cout<<data<<" matched on our database. index[0]"<<endl;
		return 0;
	}

	int low, high, mid;
	low = 0, high = (arr -> used_size);

	for(int i =1; i<(arr -> used_size); i++){
		mid = (high + low)/2;

		if((arr -> myArray)[i] == data){
			cout<<data<<" matched on our database. index["<<i+1<<"]"<<endl;
			return i;
		}

		if((arr -> myArray)[i] > data){
			high = mid - 1;
		}

		else{
			low = mid + 1;
		}

	}
	cout<<data<<" didn't match on our database."<<endl;

	return -1;
}

void deleteData(Array* &arr, int &data){
	int position;
	position = binarySearch(arr, data);

	if(position < 0){
		return ;
	}
	for(int i=position; i<(arr -> used_size); i++){
		(arr -> myArray)[i] = (arr -> myArray)[i+1];
	}

	(arr -> used_size)--;
}


void displayData(Array* &arr){

	for(int i=0; i< (arr -> used_size); i++){
		cout<<(arr -> myArray)[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int total_size, used_size;
	total_size = 100;
	used_size = 90;
	Array *arr = new Array(total_size, used_size);

	{
		cout<<"innitial array"<<endl;
		setData(arr);
		displayData(arr);
		cout<<endl;
	}

	{
		bubbleSort(arr);
		displayData(arr);
		cout<<endl;
	}

	int data=0, position=0;
	{
		data = 51;
		//binarySearch(arr, data);
	}

	{

		data = 0;
		deleteData(arr, data);
		data = 51;
		deleteData(arr, data);

		cout<<endl<<"Delete data"<<endl;
		displayData(arr);
		cout<<endl<<"Used Size: "<<(arr -> used_size)<<endl;
	}

	
	delete arr;
	return 0;
}
