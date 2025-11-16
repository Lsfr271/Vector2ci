#ifndef VECTOR2CI
#define VECTOR2CI

#pragma once

#include <iostream>
#include <cmath>
#include <limits>
#include <cassert>

enum Types {
    IS_INT,
    IS_DOUBLE,
    IS_FLOAT,
    IS_STRING,
    IS_CHAR
};

template<class T>
struct Vector2ci {
    private:
        T* data; // pointer to the array
        size_t count; // nums of elements
        size_t capacity; // alloc space

        Types typeinfo; // the type

        // function to determine the type
        static constexpr Types deduce_type() {
            if constexpr (std::is_same_v<T, int>){
                return IS_INT;
            }

            if constexpr (std::is_same_v<T, double>){
                return IS_DOUBLE;
            }

            if constexpr (std::is_same_v<T, float>){
                return IS_FLOAT;
            }

            if constexpr (std::is_same_v<T, std::string>){
                return IS_STRING;
            }

            if constexpr (std::is_same_v<T, char>){
                return IS_CHAR;
            }

            return IS_INT;
        }

    public:
        Vector2ci() : data(nullptr), count(0), capacity(0), typeinfo(deduce_type()) {}

        template<class... Args>
        Vector2ci(Args&&... args) : data(nullptr), count(0), capacity(sizeof...(args)),
        typeinfo(deduce_type<T>()) {
            data = new T[capacity];
            T temp[] = {(T)args...};

            for (size_t i = 0; i < capacity; ++i){
                data[i] = temp[i];

                ++count;
            }
        }

        ~Vector2ci() {
            delete[] data;
        }

        bool empty() const;

        void addElement(const T& value);
        void reserve(size_t newCap);
        void shrink_to_fit();

        Types getType() const;

        size_t size() const;
        size_t _capacity() const;

        const char* typeToString(Types t);
};

#endif
