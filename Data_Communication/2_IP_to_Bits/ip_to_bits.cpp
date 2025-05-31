#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


// Breakdown this problem into some steps
// Step_1: Slice ipAddress by .(dot)
vector<string> sliceIP(const string& ipAddress); 

// Step_2: Convert sliced string to integers
vector<int> stringToInteger(const vector<string>& slicedIP);

// Step_3: Convert integer octet to decimal octet. ex: 168, 192 ..etc
vector<int> convertDecimalOctetToBinaryOctet(vector<int>& decimalIP);

// Step_4: Convert actual decimal to binary
int decimalToBinary(int n); //returns 7 -> 111

// --------------------------------MAIN CODE START FROM HERE-------------------------------


// simple decimal to binary method
int decimalToBinary(int n){
    int reminder =0;
    int sum=0;
    int place = 1;

    while (n > 0){
        reminder = n%2;
        sum += reminder*place;
        n /= 2;
        place *= 10;     
    }
    return sum;
}

// slice octect by . using stringstream class
vector<string> sliceIP(const string& ipAddress) {
    vector<string> octets;
    stringstream ss(ipAddress);
    string octet;

    // slice ip address 3 times with help of '.'
    while (getline(ss, octet, '.')) {
        octets.push_back(octet);
    }

    return octets;
}

// string to decimal using stoi(string to integer) method
vector<int> stringToInteger(const vector<string>& slicedIP){
    vector<int> decimalIP;

    for (auto e: slicedIP){
       decimalIP.push_back(stoi(e));
    }
    return decimalIP;
}

// decimal octet to binary octet using decimalToBinary method
vector<int> convertDecimalOctetToBinaryOctet(vector<int>& decimalIP){
    vector<int> binaryOctet;
    for(auto e: decimalIP){
        binaryOctet.push_back(decimalToBinary(e));
    }
    return binaryOctet;
} 

int main(){
    string ipAddress = "10.16.8.8";

    //it slice the ip address
    vector<string> slicedIP = sliceIP(ipAddress);

    // it convert string to decimal
    vector<int> decimalIP = stringToInteger(slicedIP);

    // it convert decimal to binary and print
    vector<int> binaryOctet = convertDecimalOctetToBinaryOctet(decimalIP);
    
    cout << ipAddress << " = ";
    for(auto i: binaryOctet){
        cout << i << ".";
    }
}