#include <bits/stdc++.h>
using namespace std;
#ifndef __VECTOR__
#define __VECTOR__

template <class T>
class Vector {
private:
    T *data;    
    int size;   
    int space;  
public:
    Vector() : size(0), space(1) {
        data = new T[space];
    }
    Vector(int n, T value) : size(n), space(n) {
        data = new T[space];
        for (int i = 0; i < n; i++) {
            data[i] = value;
        }
    }
    ~Vector(){
        if (data != nullptr) {
            delete[] data;
        }
    }
    int get_size() {
        return size;
    }
    bool empty() {
        return size == 0;
    }   
    int capacity() {
        return space;
    }
    void pop_back() {
        if (size > 0) {
            size--;
        } else {
            cout << "Khong co phan tu nao!";
        }
    }
    T &back() {
        if (size == 0) cout << "Phan tu cuoi khong ton tai!";
        return data[size - 1];
    }
    T &front() {
        if (size == 0) cout << "Phan tu dau khong ton tai!";
        return data[0];
    }
    void reserve(int new_space) {
        if (new_space <= space) return;  
        space = new_space;
        T *tmp = new T[space];
        for (int i = 0; i < size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;  
        data = tmp;     
    }
    void push_back(T value) {
        if (size == space) {
            reserve(space * 2); 
        }
        data[size] = value;
        ++size;
    }
    void insert(int pos, T x) {
        if (size == space) {
            reserve(space * 2);
        }
        for (int i = size - 1; i >= pos; i--) {
            data[i + 1] = data[i];
        }
        data[pos] = x;
        ++size;
    }
    void erase(int pos) {
        if (pos < 0 || pos >= get_size()) {
            cout << "Chi so khong hop le!";
            return;
        }
        for (; pos < size - 1; pos++){ 
            data[pos] = data[pos + 1];
        }
        size--;
    }
    T &operator[](int i) {
        if (i < 0 || i >= size) {
            cout << "Chi so khong hop le!";
        }
        return data[i];
    }
    
    const T& operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return data[index];
	}
    Vector &operator=(const Vector<T> &other) {
        if (this != &other) { 
            delete[] data;  
            size = other.size;
            space = other.space;
            data = new T[space];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    void resize(int new_size, const T &default_value = T()) {
        if (new_size > space) {
            reserve(new_size);
        }
        for (int i = size; i < new_size; i++) {
            data[i] = default_value;  
        }
        size = new_size; 
    }
    typedef T *iterator;
    iterator begin() {
        return data;
    }
    iterator end() {
        return data + size;
    }
};
#endif
