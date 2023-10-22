#include <iostream>
#include <ctime>
using namespace std;

class Array{
	public:
        int total_size;
        int used_size;
        int* myArray;

            Array(){}
            Array(int tSize, int uSize){
                this  ->  total_size = tSize;
                this  ->  used_size = uSize;
                myArray  =  new int[this  ->  used_size];
            }

            ~Array(){
                    delete[]  myArray;
                    cout<<"Destructor called..!"<<endl;
            }
};

void setData(Array* &arr){
    srand(time(0));
	for(int i=0; i<(arr -> used_size); i++){
		(arr -> myArray)[i]  = rand()%100;
	}
}

void insertData(Array* &arr, int &data, int &position){

        if(position == (arr -> used_size)){
            cout<<"yndyhn";
        (arr -> myArray)[position] = data;
        (arr -> used_size)++;

        return ;
    }

    for(int i = (arr -> used_size); i>=position; i--){
        (arr -> myArray)[i] = (arr -> myArray)[i-1];
    }
    (arr -> myArray)[position] = data;
     (arr -> used_size)++;
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

void insertionSort(void){

}

void selectionSort(Array* &arr){
    int minAddress;
        for(int i=0; i<(arr -> used_size); i++){
            minAddress = i;
                for(int j=i+1; j<(arr -> used_size); j++){
                    if((arr -> myArray)[j] < (arr -> myArray)[minAddress]){
                        minAddress = j;
                    }
                }
                swap((arr -> myArray)[i], (arr -> myArray)[minAddress]);
        }
}

void linearSearch(Array* &arr, int &data){
    for(int i=0; i<(arr -> used_size); i++){

        if((arr -> myArray)[i] == data){
            cout<<data<<" matched on our database. index["<<i<<"]"<<endl;
			return ;
        }
    }
    cout<<data<<" didn't match on our database."<<endl;
}

void binarySearch(Array* &arr, int &data){

	if((arr -> myArray)[0] == data){
		cout<<data<<" matched on our database. index[0]"<<endl;
		return ;
	}

	int low, high, mid;
	low = 0, high = (arr -> used_size);

	for(int i =1; i<(arr -> used_size); i++){
		mid = (high + low)/2;

		if((arr -> myArray)[i] == data){
			cout<<data<<" matched on our database. index["<<i<<"]"<<endl;
			return ;
		}

		if((arr -> myArray)[i] > data){
			high = mid - 1;
		}

		else{
			low = mid + 1;
		}

	}
	cout<<data<<" didn't match on our database."<<endl;
}

void deleteData(Array* &arr, int &position){
	if(position < 0 || position >= (arr -> used_size)){
            system("cls");
            cout<<"Sorry, Index not Found, Please Input Valid Index."<<endl;
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
	int total_size, used_size, data, position;
	total_size = 100;

	   //Dynamic Array Create
        cout<<"How much Array Data You Want: ";
        cin>> used_size;
        Array *arr = new Array(total_size, used_size);


	{   //array initials
		setData(arr);
		cout<<"Your Initial Array is: ";
		displayData(arr);
		cout<<"Use Size is: "<<used_size;
	}
	cout<<endl;

	{
	    cout<<"Enter a Data you want to Insert: ";
	    cin>>data;
	    cout<<"Enter a Position where you wanna Add: ";
	    cin>>position;
	    insertData(arr, data, position);
	    cout<<"After Insert, Your Data is: ";
	    displayData(arr);
	}
	cout<<endl;

	{   //Bubble Sort
		//bubbleSort(arr);
		//cout<<"After Bubble Sort, Your Array is: ";
		//displayData(arr);
	}
	cout<<endl;

	{   //Selection Sort
		selectionSort(arr);
		cout<<"After Selection Sort, Your Array is: ";
		displayData(arr);
	}
	cout<<endl;

	{   //Linear Search
	    cout<<"For Linear Search, Input Search ITEM: ";
	    cin>>data;
	    linearSearch(arr, data);
	}
	cout<<endl;

	{   //binary search
	    cout<<"For Binary Search, Input Search ITEM: ";
	    cin>>data;
		binarySearch(arr, data);
	}
	cout<<endl;

	{   //delete Data
		cout<<"Enter a Index you want to delete: " ;
		cin>>position;
		deleteData(arr, position);
		cout<<"After Delete, Your Data is: ";
		displayData(arr);
		cout<<"Used Size: "<<(arr -> used_size)<<endl;
	}
	cout<<endl;


	delete arr;
	return 0;
}
