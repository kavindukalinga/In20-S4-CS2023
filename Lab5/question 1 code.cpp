#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::chrono;

// Partition function to divide the array into two parts
int partition(vector<int>arr, int low, int high)
{
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSortRecur(vector<int>arr, int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);  // pi is partitioning index
        quickSortRecur(arr, low, pi - 1);
        quickSortRecur(arr, pi + 1, high);
    }
}

void quickSortItter(vector<int>& arr, int low, int high)
{
    int stack[high - low + 1];

    int top = -1;
    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Partition the array and push subarrays into stack
        int pi = partition(arr, low, high);
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}


int main() {

    const int length1 = 500;
    vector<int>arr1(length1);
    for (int i = 0; i < length1; i++) {
        arr1[i] = rand() % 100; // Generate random number between 0 and 99
    }

    const int length2 = 1000;
    vector<int> arr2(length2);
    for (int i = 0; i < length2; i++) {
        arr2[i] = rand() % 100; // Generate random number between 0 and 99
    }

    const int length3 = 5000;
    vector<int>arr3(length3);
    for (int i = 0; i < length3; i++) {
        arr3[i] = rand() % 100; // Generate random number between 0 and 99
    }

    const int length4 = 10000;
    vector<int>arr4(length4);
    for (int i = 0; i < length4; i++) {
        arr4[i] = rand() % 100; // Generate random number between 0 and 99
    }

    const int length5 = 20000;
    vector<int>arr5(length5);
    for (int i = 0; i < length5; i++) {
        arr5[i] = rand() % 100; // Generate random number between 0 and 99
    }

    vector<int>New1(length1);
    vector<int>New2(length2);
    vector<int>New3(length3);
    vector<int>New4(length4);
    vector<int>New5(length5);


    for (int i=0;i<length1;i++){
        New1[i]=arr1[i];
    }
    for (int i=0;i<length1;i++){
        New2[i]=arr2[i];
    }
    for (int i=0;i<length1;i++){
        New3[i]=arr3[i];
    }
    for (int i=0;i<length1;i++){
        New4[i]=arr4[i];
    }
    for (int i=0;i<length1;i++){
        New5[i]=arr5[i];
    }

    auto start_time1 = high_resolution_clock::now();
    quickSortRecur(arr1, 0, length1-1);
    auto end_time1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end_time1 - start_time1);
    cout << "Total elements in quickSortRecur array: " << length1;
    cout << "  Time taken: " << duration1.count() << " nanoseconds" << endl;

    auto start_time2 = high_resolution_clock::now();
    quickSortRecur(arr2,0, length2-1);
    auto end_time2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end_time2 - start_time2);
    cout << "Total elements in quickSortRecur array: " << length2;
    cout << "  Time taken: " << duration2.count() << " nanoseconds" << endl;

    auto start_time3 = high_resolution_clock::now();
    quickSortRecur(arr3,0, length3-1);
    auto end_time3 = high_resolution_clock::now();
    auto duration3 = duration_cast<nanoseconds>(end_time3 - start_time3);
    cout << "Total elements in quickSortRecur array: " << length3;
    cout << "  Time taken: " << duration3.count() << " nanoseconds" << endl;

    auto start_time4 = high_resolution_clock::now();
    quickSortRecur(arr4, 0,length4-1 );
    auto end_time4 = high_resolution_clock::now();
    auto duration4 = duration_cast<nanoseconds>(end_time4 - start_time4);
    cout << "Total elements in mquickSortRecur array: " << length4;
    cout << "  Time taken: " << duration4.count() << " nanoseconds" << endl;

    auto start_time5 = high_resolution_clock::now();
    quickSortRecur(arr5,0, length5-1);
    auto end_time5 = high_resolution_clock::now();
    auto duration5 = duration_cast<nanoseconds>(end_time5 - start_time5);
    cout << "Total elements in quickSortRecur array: " << length5;
    cout << "  Time taken: " << duration5.count() << " nanoseconds" << endl;

    cout<<endl<<endl;

 // for next one
    auto start_time11 = high_resolution_clock::now();
    quickSortItter(New1,  0, length1-1);
    auto end_time11 = high_resolution_clock::now();
    auto duration11 = duration_cast<nanoseconds>(end_time11 - start_time11);
    cout << "Total elements in quickSortItter array: " << length1;
    cout << "  Time taken: " << duration11.count() << " nanoseconds" << endl;

    auto start_time21 = high_resolution_clock::now();
    quickSortItter(New2, 0,length2-1);
    auto end_time21 = high_resolution_clock::now();
    auto duration21 = duration_cast<nanoseconds>(end_time21 - start_time21);
    cout << "Total elements in quickSortItter array: " << length2;
    cout << "  Time taken: " << duration21.count() << " nanoseconds" << endl;

    auto start_time31 = high_resolution_clock::now();
    quickSortItter(New3,0, length3-1);
    auto end_time31 = high_resolution_clock::now();
    auto duration31 = duration_cast<nanoseconds>(end_time31 - start_time31);
    cout << "Total elements in quickSortItter array: " << length3;
    cout << "  Time taken: " << duration31.count() << " nanoseconds" << endl;

    auto start_time41 = high_resolution_clock::now();
    quickSortItter(New4, 0,length4-1);
    auto end_time41 = high_resolution_clock::now();
    auto duration41= duration_cast<nanoseconds>(end_time41 - start_time41);
    cout << "Total elements in quickSortItter array: " << length4;
    cout << "  Time taken: " << duration41.count() << " nanoseconds" << endl;

    auto start_time51 = high_resolution_clock::now();
    quickSortItter(New5,0, length5-1);
    auto end_time51 = high_resolution_clock::now();
    auto duration51 = duration_cast<nanoseconds>(end_time51 - start_time51);
    cout << "Total elements in quickSortIttersion array: " << length5;
    cout << "  Time taken: " << duration51.count() << " nanoseconds" << endl;

   return 0;
}
