#include "MySharePtr.h"

template <typename T>
MySharePtr<T>::MySharePtr(T* ptr) {
    m_data = ptr;
    m_sharecnt = new MySharePtr<T>::ShareCnt();
}
template <typename T>
MySharePtr<T>::MySharePtr(const MySharePtr<T>& from) {
    copy(from);
}
template <typename T>
MySharePtr<T>& MySharePtr<T>::operator=(const MySharePtr& from) {
    if (this == &from) {
        return *this;
    }
    decrease();
    copy(from);
    return *this;
}
template <typename T>
MySharePtr<T>::~MySharePtr() {
    decrease();
}
template <typename T>
T* MySharePtr<T>::get() const {
    return m_data;
}
template <typename T>
T& MySharePtr<T>::operator*() {
    if (m_data != nullptr) {
     return *m_data;
    } else {
        std::runtime_error("empty m_data");
    }
}
template <typename T>
T* MySharePtr<T>::operator->() {
    if (m_data != nullptr) {
        return m_data;
    } else {
        return nullptr;
    }
}
template <typename T>
void MySharePtr<T>::decrease() {
    if (m_data != nullptr) {
        m_sharecnt->decreaseCnt();
        if (m_sharecnt->haveToDelete()) {
            delete m_data;
            m_data = nullptr;
            delete m_sharecnt;
            m_sharecnt = nullptr;
        }
    }
}
template <typename T>
void MySharePtr<T>::copy(const MySharePtr& from) {
    if (from.get() != nullptr) {
        m_data = from.get();
        m_sharecnt = from.m_sharecnt;
        m_sharecnt->addCnt();
    }
}

template class MySharePtr<Test>;
