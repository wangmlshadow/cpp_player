#include "MyStack.h"

template <typename T>
MyStack<T>::MyStack() : m_head(nullptr), m_size(0) {}
template <typename T>
MyStack<T>::MyStack(const MyStack<T>& from) {
    m_size = 0;
    m_head = nullptr;
    if (!from.empty()) {
        copy(from);
    }
}
template <typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& from) {
    if (this != &from) {
        copy(from);
    }
}

template <typename T>
MyStack<T>::~MyStack() {
    clear();
}
template <typename T>
const T& MyStack<T>::top() {
    if (empty()) {
        throw std::runtime_error("top while stack is empty");
    }
    return m_head->m_data;
}
template <typename T>
void MyStack<T>::push(T val) {
    auto node = new MyStack<T>::Node(val);
    node->m_next = m_head;
    m_head = node;
    m_size++;
}
template <typename T>
void MyStack<T>::pop() {
    if (empty()) {
        throw std::runtime_error("pop while stack is empty");
    }
    auto p = m_head;
    m_head = p->m_next;
    delete p;
    m_size--;
}
template <typename T>
void MyStack<T>::clear() {
    while (!empty()) {
        pop();
    }
}
template <typename T>
MyStack<T>::Node::~Node() {
}

template<typename T>
void MyStack<T>::copy(const MyStack<T>& from) {
    clear();
    if (!from.empty()) {
        auto node = from.m_head;
        auto tmp = new Node(node->m_data);
        m_head = tmp;
        while (node->m_next != nullptr) {
            tmp->m_next = new Node(node->m_next->m_data);
            tmp = tmp->m_next;
            node = node->m_next;
        }
        m_size = from.size();
    }
}
template class MyStack<int>;
