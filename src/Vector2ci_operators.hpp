#include "Vector2ci.hpp"

// unary negation
template<class T>
Vector2ci<T> operator-(const Vector2ci<T>& v){
    Vector2ci<T> result;

    for (size_t i = 0; i < v.size(); ++i){
        result.addElement(-v[i]);
    }

    return result;
}

// element wise addition
template<class T>
Vector2ci<T> operator+(const Vector2ci<T>& a, const Vector2ci<T>& b){
    assert(a.size() == b.size());

    Vector2ci<T> result;

    for (size_t i = 0; i < a.size(); ++i){
        result.addElement(a[i] + b[i]);
    }

    return result;
}

template<class T>
Vector2ci<T>& operator+=(Vector2ci<T>& a, const Vector2ci<T>& b){
    assert(a.size() == b.size());

    for (size_t i = 0; i < a.size(); ++i){
        a[i] += b[i];
    }

    return a;
}

// element wise subtraction
template<class T>
Vector2ci<T> operator-(const Vector2ci<T>& a, const Vector2ci<T>& b){
    assert(a.size() == b.size());

    Vector2ci<T> result;

    for (size_t i = 0; i < a.size(); ++i){
        result.addElement(a[i] - b[i]);
    }

    return result;
}

template<class T>
Vector2ci<T>& operator -=(Vector2ci<T>& a, const Vector2ci<T>& b){
    assert(a.size() == b.size());

    for (size_t i = 0; i < a.size(); ++i){
        a[i] -= b[i];
    }

    return a;
}

// scalar multiplication
template<class T>
Vector2ci<T> operator*(const Vector2ci<T>& v, T scalar){
    Vector2ci<T> result;

    for (size_t i = 0; i < v.size(); ++i){
        result.addElement(v[i] * scalar);
    }

    return result;
}

template<class T>
Vector2ci<T>& operator*=(Vector2ci<T>& v, T scalar){
    for (size_t i = 0; i < v.size(); ++i){
        v[i] *= scalar;
    }

    return v;
}

// scalar divison
template<class T>
Vector2ci<T> operator/(const Vector2ci<T>& v, T scalar){
    Vector2ci<T> result;

    for (size_t i = 0; i < v.size(); ++i){
        result.addElement(v[i] / scalar);
    }

    return result;
}

template<class T>
Vector2ci<T>& operator/=(Vector2ci<T>& v, T scalar){
    for (size_t i = 0; i < v.size(); ++i){
        v[i] /= scalar;
    }

    return v;
}

// comparison
template<class T>
bool operator==(const Vector2ci<T>& a, const Vector2ci<T>& b){
    if (a.size() != b.size()){
        return false;
    }

    for (size_t i = 0; i < a.size(); ++i){
        if (a[i] != b[i]){
            return false;
        }
    }

    return true;
}

template<class T>
bool operator!=(const Vector2ci<T>& a, const Vector2ci<T>& b){
    return !(a == b);
}

// stream output
template<class T>
std::ostream& operator<<(std::ostream& os, const Vector2ci<T>& v){
    os << "[";

    for (size_t i = 0; i < v.size(); ++i){
        os << v[i];

        if (i != v.size() - 1){
            os << ", ";
        }
    }

    os << "]";

    return os;
}

template<class T>
T& Vector2ci<T>::operator[](size_t index){
    assert(index < count);

    return data[index];
}

template<class T>
const T& Vector2ci<T>::operator[](size_t index) const {
    assert(index < count);

    return data[index];
}

template <class T>
Vector2ci<T>& Vector2ci<T>::operator=(const Vector2ci<T> &other){
    if (this != &other){
        delete[] data;

        count = other.count;
        capacity = other.capacity;
        typeinfo = other.typeinfo;

        if (capacity > 0){
            data = new T[capacity];

            for (size_t i = 0; i < count; ++i){
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }

    return *this;
}

template <class T>
Vector2ci<T>& Vector2ci<T>::operator=(Vector2ci<T> &&other) {
    if (this != &other){
        delete[] data;

        data = other.data;
        count = other.count;
        capacity = other.capacity;
        typeinfo = other.typeinfo;

        other.data = nullptr;
        other.count = 0;
        other.capacity = 0;
    }

    return *this;
}
