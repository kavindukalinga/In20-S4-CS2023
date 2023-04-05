#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::chrono;


// Node class
class Node {
public:
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek operation
    int peek() {
        if (top == NULL) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display the stack
    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main() {
    Stack s;
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
