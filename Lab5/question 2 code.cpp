#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


float median1(int arr[], int n)
{
    insertionSort(arr,n);
    float mediaN;
    if (n==1) mediaN=arr[0];
    
    else if (n%2==1) mediaN=arr[(n/2)] ;
    else {
        mediaN= (arr[(n/2)] + arr[(n/2)-1] )*0.5;
    }
    return mediaN;
}


int main() {
    cout<<setprecision(1) <<fixed;

    
    // Generate Random Array
    const int length1 = 5;
    int arr1[length1];
    for (int i = 0; i < length1; i++) {
        arr1[i] = rand() % 10; 
    }  
    cout << "Test Case 01 : [ " ;
     for (int x=0; x<length1 ;x++){
        cout << arr1[x] << " " ;
     } cout<<" ]"<< endl;

    for (int j=0;j<length1;j++){ 
        cout<<median1(arr1,j+1)<<endl;
    }

    const int length2 = 10;
    int arr2[length2];
    for (int i = 0; i < length2; i++) {
        arr2[i] = rand() % 10; 
    }  
    cout << "Test Case 02 : [ " ;
     for (int x=0; x<length2 ;x++){
        cout << arr2[x] << " " ;
     } cout<<" ]"<< endl;

    for (int j=0;j<length2;j++){ 
        cout<<median1(arr2,j+1)<<endl;
    }

    const int length3 = 20;
    int arr3[length3];
    for (int i = 0; i < length3; i++) {
        arr3[i] = rand() % 10; 
    }  
    cout << "Test Case 03 : [ " ;
     for (int x=0; x<length3 ;x++){
        cout << arr3[x] << " " ;
     } cout<<" ]"<< endl;

    for (int j=0;j<length3;j++){ 
        cout<<median1(arr3,j+1)<<endl;
    }



}
    