#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::chrono;

#include <iostream>

using namespace std;

// Stack class
class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Push operation
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    // stackTop operation
    int stackTop() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == (capacity-1);
    }

    // Display the stack
    void display() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Stack s(10);
    auto start_time1 = high_resolution_clock::now();
    
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    auto end_time1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end_time1 - start_time1);
    cout << endl << endl <<"  Time taken for the program: " << duration1.count() << " nanoseconds" << endl;

   
   return 0;
}
