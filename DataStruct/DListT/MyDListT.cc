#include "MyDListT.h"

template<typename T>
MyDListT<T>::MyDListT() : m_first(nullptr), m_last(nullptr), m_size(0) {
    std::cout << "Init with nothing." << std::endl;
}

template<typename T>
MyDListT<T>::~MyDListT() {
    clear();
}

template<typename T>
MyDListT<T>::MyDListT(const MyDListT& from) {
    std::cout << "Init with another List." << std::endl;
    m_size = 0;
    m_first = nullptr;
    m_last = nullptr;

    if (this != &from) {
        copy(from);
    }
}

template<typename T>
MyDListT<T>& MyDListT<T>::operator=(const MyDListT& from) {
    std::cout << "operator=." << std::endl;
    if (this != &from) {
        copy(from);
    }
    return *this;
}

template<typename T>
void MyDListT<T>::push_front(const T& val) {
    MyNodeT* node = new MyNodeT(val);
    if (empty()) {
        m_first = node;
        m_last = node;
    } else {
        node->m_next = m_first;
        m_first->m_prev = node;
        m_first = node;
    }
    m_size++;
}

template<typename T>
void MyDListT<T>::push_back(const T& val) {
    MyNodeT* node = new MyNodeT(val);
    if (empty()) {
        m_first = node;
        m_last = node;
    } else {
        node->m_prev = m_last;
        m_last->m_next = node;
        m_last = node;
    }
    m_size++;
}

template<typename T>
T MyDListT<T>::pop_front() {
    if (empty()) {
        throw std::runtime_error("MySListT<T>::pop_front while list is empty");
    }
    T res = m_first->m_data;
    auto p = m_first;
    m_first = m_first->m_next;
    m_size--;
    if (m_first == nullptr) {
        m_last = nullptr;
    } else {
        m_first->m_prev = nullptr;
    }
    delete p;

    return res;
}

template<typename T>
T MyDListT<T>::pop_back() {
    if (empty()) {
        throw std::runtime_error("MySListT<T>::pop_front while list is empty");
    }
    T res = m_last->m_data;
    auto p = m_last;
    m_last = m_last->m_prev;
    m_size--;
    if (m_last == nullptr) {
        m_first = nullptr;
    } else {
        m_last->m_next = nullptr;
    }
    delete p;

    return res;
}

template<typename T>
T& MyDListT<T>::front() {
    return m_first->m_data;
}

template<typename T>
const T& MyDListT<T>::front() const {
    return m_first->m_data;
}

template<typename T>
T& MyDListT<T>::back() {
    return m_last->m_data;
}

template<typename T>
const T& MyDListT<T>::back() const {
    return m_last->m_data;
}

template<typename T>
bool MyDListT<T>::empty() const {
    return m_size == 0;
}

template<typename T>
size_t MyDListT<T>::size() const {
    return m_size;
}

template<typename T>
void MyDListT<T>::clear() {
    auto p = m_first;
    while (p != nullptr) {
        auto next = p->m_next;
        delete p;
        p = next;
    }
    m_size = 0;
}

template<typename T>
void MyDListT<T>::erase(iterator i) {
    auto pre = i.m_hold->m_prev;
    auto next = i.m_hold->m_next;
    if (pre == nullptr) {
        pop_front();
    } else if (next == nullptr) {
        pop_back();
    } else {
        pre->m_next = next;
        next->m_prev = pre;
        delete i.m_hold;
    }
}

template<typename T>
void MyDListT<T>::insert(iterator i, const T& val) {
    if (empty() || i.m_hold->m_prev == nullptr) {
        push_front(val);
    } else {
        auto node = new MyNodeT(val);
        i.m_hold->m_prev->m_next = node;
        node->m_next = i.m_hold;
        i.m_hold->m_prev = node;
    }
}

template<typename T>
typename MyDListT<T>::iterator MyDListT<T>::begin() const noexcept {
    MyDListT<T>::iterator itr;
    itr.m_hold = m_first;
    return itr;
}

template<typename T>
typename MyDListT<T>::iterator MyDListT<T>::begin() noexcept {
    MyDListT<T>::iterator itr;
    itr.m_hold = m_first;
    return itr;
}

template<typename T>
typename MyDListT<T>::iterator MyDListT<T>::end() const noexcept {
    MyDListT<T>::iterator itr;
    return itr;
}

template<typename T>
typename MyDListT<T>::iterator MyDListT<T>::end() noexcept {
    MyDListT<T>::iterator itr;
    return itr;
}

template<typename T>
typename MyDListT<T>::iterator& MyDListT<T>::iterator::operator++() {
    this->m_hold = this->m_hold->m_next;
    return *this;
}

template<typename T>
MyDListT<T>::MyNodeT::MyNodeT() : m_next(nullptr), m_prev(nullptr) {}
template<typename T>
MyDListT<T>::MyNodeT::MyNodeT(const T& value) : m_next(nullptr), m_data(value), m_prev(nullptr) {}
template<typename T>
MyDListT<T>::MyNodeT::~MyNodeT() {}

template<typename T>
void MyDListT<T>::copy(const MyDListT& from) {
    if (this != &from) {
        clear();
        for (auto itr : from) {
            push_back(itr);
        }
    }
}

template<typename T>
void MyDListT<T>::print(std::ostream& out) {
    for (auto itr : *this) {
        std::cout << itr << " ";
    }
    out << std::endl;
}

template class MyDListT<double>;
