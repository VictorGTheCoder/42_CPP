#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
private:
    T* data;
    unsigned int n;

public:
    Array() : data(0), n(0) {}

    Array(unsigned int count) : n(count) {
        data = new T[count];
        for(unsigned int i = 0; i < count; ++i)
            data[i] = T();
    }
    Array(const Array& other) : n(other.n) {
        data = new T[n];
        for(unsigned int i = 0; i < n; ++i)
            data[i] = other.data[i];
    }
    ~Array() {
        delete[] data;
    }
    Array& operator=(const Array& other) {
        if(this == &other)
            return *this;

        delete[] data;

        n = other.n;
        data = new T[n];
        for(unsigned int i = 0; i < n; ++i)
            data[i] = other.data[i];

        return *this;
    }

    T& operator[](unsigned int index) {
        if(index >= n)
            throw std::exception();
        return data[index];
    }

    unsigned int size() const {
        return n;
    }
};
#endif