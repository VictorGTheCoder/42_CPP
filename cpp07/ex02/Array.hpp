#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
    public:
        Array<T>(void)
        {
            this->_data = new T[0];
            this->_size = 0;
        }
        Array<T>(unsigned int n)
        {
           	this->_data = new T[n];
            this->_size = n; 
        }
        Array<T>(const Array &t)
        {
            this->_size = t._size;
            this->_data = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; ++i) {
                this->_data[i] = t._data[i];
            }
        }
        ~Array<T>()
        {
            delete[] this->_data;
        }
        Array<T> &operator=(const Array<T> &t)
        {
            if (this != &t) {
            delete[] this->_data;
            this->_size = t._size;
            this->_data = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; ++i) {
                this->_data[i] = t._data[i];
            }
            }          
            return *this;
        }
        T &operator[](unsigned int index)
        {
            if (index >= _size) {
                throw std::exception();
            }
            return _data[index];
        }
    private:
        T *_data;
        unsigned int _size;
};
#endif