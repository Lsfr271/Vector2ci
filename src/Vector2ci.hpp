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
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        Vector2ci<T>& operator=(const Vector2ci<T>& other);
        Vector2ci<T>& operator=(Vector2ci<T>&& other);
        Vector2ci<T>& operator=(std::initializer_list<T> list);

        Vector2ci() : data(nullptr), count(0), capacity(0), typeinfo(deduce_type()) {}

        Vector2ci(std::initializer_list<T> list) : data(nullptr), count(0),
        capacity(list.size()), typeinfo(deduce_type())
        {
            if (capacity > 0){
                data = new T[capacity];

                size_t i = 0;

                for (const auto& elem : list){
                    data[i++] = elem;
                }

                count = capacity;
            }
        }

        Vector2ci(const Vector2ci& other) : data(nullptr), count(other.count),
        capacity(other.capacity), typeinfo(other.typeinfo) {
            if (capacity > 0){
                data = new T[capacity];

                for (size_t i = 0; i < count; ++i){
                    data[i] = other.data[i];
                }
            }
        }

        Vector2ci(Vector2ci&& other) noexcept : data(nullptr),
        count(other.count), capacity(other.capacity),
        typeinfo(other.typeinfo) {
            other.data = nullptr;
            other.count = 0;
            other.capacity = 0;
        }

        ~Vector2ci() {
            delete[] data;
        }

        bool empty() const;

        void addElement(const T& value);
        void reserve(size_t newCap);
        void shrink_to_fit();
        void clear();
        void popBack();

        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

        Types getType() const;

        size_t size() const;
        size_t _capacity() const;

        const char* typeToString(Types t);
};

#endif
