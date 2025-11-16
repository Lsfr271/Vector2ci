#include "Vector2ci.hpp"

template<class T>
void Vector2ci<T>::addElement(const T& value){
    if (count >= capacity) {
        size_t newCap = capacity == 0 ? 1 : capacity * 2;
        T* nData = new T[newCap];

        for (size_t i = 0; i < count; ++i){
            nData[i] = data[i];
        }

        delete[] data;

        data = nData;
        capacity = newCap;
    }
    data[count++] = value;
}

template<class T>
size_t Vector2ci<T>::size() const {
    return count;
}

template<class T>
size_t Vector2ci<T>::_capacity() const {
    return capacity;
}

template <class T>
bool Vector2ci<T>::empty() const {
    return count == 0;
}

template<class T>
void Vector2ci<T>::reserve(size_t newCap){
    if (newCap <= capacity){
        return;
    }

    T* n_mData = new T[newCap];

    for (size_t i = 0; i < count; ++i){
        n_mData[i] = data[i];
    }

    delete[] data;

    data = n_mData;
    capacity = newCap;
}

template<class T>
void Vector2ci<T>::shrink_to_fit() {
    if (count == capacity){
        return;
    }

    T* newData = nullptr;

    if (count > 0){
        newData = new T[count];

        for (size_t i = 0; i < count; ++i){
            newData[i] = data[i];
        }
    }

    delete[] data;

    data = newData;
    capacity = count;
}

template<class T>
Types Vector2ci<T>::getType() const {
    return typeinfo;
}

template<class T>
const char* Vector2ci<T>::typeToString(Types t) {
    switch (t){
        case IS_INT:
            return "IS_INT";
        case IS_DOUBLE:
            return "IS_DOUBLE";
        case IS_FLOAT:
            return "IS_FLOAT";
        case IS_STRING:
            return "IS_STRING";
        case IS_CHAR:
            return "IS_CHAR";
    }

    return nullptr;
}


template class Vector2ci<int>;
template class Vector2ci<double>;
template class Vector2ci<float>;
template class Vector2ci<char>;
template class Vector2ci<std::string>;
