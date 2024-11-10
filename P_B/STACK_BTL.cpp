#include <bits/stdc++.h>
#ifndef __STACK__
#define __STACK__ 
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;        
    int capacity;  
    int top;       

public:
    Stack() {
        capacity = 1;
        arr = new T[capacity];
        top = -1;
    }

    void push(T element) {
        if (top == capacity - 1) {
            resize(2 * capacity);  
        }
        arr[++top] = element;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return T();  
        }
        return arr[top--];
    }
    
    T Top() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return T();  
        }
        return arr[top];
    }
    

    T peek() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return T();  
        }
        return arr[top];
    }
	
    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }

    void resize(int newCapacity) {
        T* newArr = new T[newCapacity];
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;  
        arr = newArr;
        capacity = newCapacity;
    }
     

    ~Stack() {
        delete[] arr;
    }
};
#endif
