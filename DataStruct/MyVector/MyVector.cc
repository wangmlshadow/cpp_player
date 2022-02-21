#include <cstring>
#include <cassert>
#include <cstdint>
#include "MyVector.h"

template <typename T>
MyVector<T>::MyVector(const MyVector& from) {
    if (from.empty()) {
        m_size = 0;
        m_capacity = 0;
        m_data = nullptr;
    } else {
        m_size = from.size();
        m_capacity = from.size();
        m_data = new T[m_size+1];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = from[i];
        }
    }
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& from) {
    clear();
    if (!from.empty()) {
        m_size = from.size();
        m_capacity = from.size();
        m_data = new T[m_size+1];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = from[i];
        }
    }
}
template <typename T>
MyVector<T>::~MyVector() {
    clear();
}
template <typename T>
MyVector<T>::MyVector(int cnt, T val) {
    m_size = cnt;
    m_capacity = cnt;
    m_data = new T[cnt+1];
    for (int i = 0; i < cnt; ++i) {
        m_data[i] = val;    
    }
}
template <typename T>
MyVector<T>::MyVector(T* start, T* end) {
    assert(start != nullptr && end != nullptr);
    m_size = (end - start) / sizeof(T);
    m_capacity = m_size;
    assert(m_size > 0);
    m_data = new T[m_size+1];
    //std::memcpy(m_data, start, m_size);
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = start[i];
    }
}
template <typename T>
void MyVector<T>::push_back(const T& val) {
    if (m_size < m_capacity) {
        m_data[m_size] = val;
        m_size++;
    } else {
        if (m_size == 0) {
            m_data = new T[DEFAULTSIZE+1];
            m_data[m_size] = val;
            m_size = 1;
            m_capacity = DEFAULTSIZE;
        } else {
            auto data = new T[m_capacity * 2 + 1];
            //std::memcpy(data, m_data, m_size);
            for (int i = 0; i < m_size; ++i) {
                data[i] = m_data[i];
            }
            delete m_data;
            m_data = data;
            data[m_size] = val;
            m_size++;
            m_capacity *= 2;
        }
    }
}
template <typename T>
void MyVector<T>::clear() {
    m_size = 0;
    m_capacity = 0;
    delete m_data;
    m_data = nullptr;
}
template class MyVector<int>;
