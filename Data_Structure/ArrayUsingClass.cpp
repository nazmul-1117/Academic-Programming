#include <iostream>
#include <ctime>
using namespace std;

class node{

    public:
        int public_tSize;
        int public_uSize;
        int public_data;
        int *public_array;

    private:
        int Private_tSize;
        int Private_uSize;
        int private_data;
        int *private_array;

    protected:
        int protected_tSize;
        int protected_uSize;
        int protected_data;
        int *protected_array;



    public:

        node(int &tSize, int &uSize){

            this -> public_tSize = tSize;
            this -> Private_tSize = tSize;
            this -> protected_tSize = tSize;

            this -> public_uSize = uSize;
            this -> Private_uSize = uSize;
            this -> protected_uSize = uSize;


            this -> public_array = new int[tSize];
            this -> private_array = new int[tSize];
            this -> protected_array = new int[tSize];
        }

        ~node(){
            //delete[] public_array;
            cout<<"\nDestructor Called...!"<<endl;
        }


        void public_Function(void);
        void private_Function(void);
        void protected_Function(void);

        void setData(void);
        void displayData(void);
        friend void private_setData(node*&);
};


void node :: public_Function(void){

}


void node :: private_Function(void){
    (this -> private_array[0]) = 255;

    cout<<"private_array: "<<private_array[0]<<" "<<endl;
}


void node :: protected_Function(void){
    (this -> protected_array[0]) = 301;


    cout<<"protected_array: "<<protected_array[0]<<" "<<endl;
}




void node :: setData(void){
    srand(time(0));
    for(int i=0; i<(this -> public_uSize); i++){
        public_array[i] = rand()%100;
    }
}

void node :: displayData(void){

    for(int i=0; i<(this -> public_uSize); i++){
        cout<<public_array[i]<<" ";
    }
    cout<<endl;
}



void private_setData(node* &temp){
    temp -> private_data = 10;
    cout<<temp -> private_data<<endl;
}


int main()
{
    int tSize = 100, uSize = 10;
    node *na = new node(tSize, uSize);

    (na -> setData());
    (na -> displayData());

    (na -> private_Function());
    (na -> protected_Function());



    delete na;
    return 0;
}

