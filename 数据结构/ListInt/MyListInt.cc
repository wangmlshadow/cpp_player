#include "MyListInt.h"

MyListInt::MyNodeInt::MyNodeInt() :m_next(nullptr) {
    std::cout << "Init Node with nothing." << std::endl;
}

MyListInt::MyNodeInt::MyNodeInt(const ElementType& val) 
    : m_next(nullptr), m_data(val) {
    std::cout << "Init Node with Int." << std::endl;
}

MyListInt::MyNodeInt::~MyNodeInt() {
    std::cout << "Destory Node." << std::endl;
}

MyListInt::MyListInt() : m_size(0) {
    std::cout << "Init List nothing." << std::endl;
}

MyListInt::MyListInt(const MyListInt& rhv) {
    if (!rhv.empty()) {
        copy(rhv);
    }
    std::cout << "Init List with List." << std::endl;
}

MyListInt::MyListInt& operator=(const MyListInt& rhv) {
    std::cout << "operator = for List." << std::endl;

    if (this == &rhv) {
        return *this;
    } else {
        copy(rhv);
        return *ythis;
    }
}

MyListInt::~MyListInt() {
    std::cout << "Destory List." << std::endl;
    clear();
}

void MyListInt::print(std::ostream& out) {
    auto p = m_head;
    while (p != nullptr) {
        out << p->m_data << " ";
        p = p->m_next;
    }
    out << std::endl;
}

void MyListInt::push_front(const ElementType& val) {
    if (empty()) {
        push_back(val);
    } else {
        auto p = new MyNodeInt(val);
        p->m_next = m_head;
        m_head = p;
        ++m_size;
    }
}

void MyListInt::push_back(const ElementType& val) {
    if (empty()) {
        m_head = new MyNodeInt(val);
    } else {
        m_tail->m_next = new MyNodeInt(val);
        m_tail = m_tail->m_next;
    }
    ++m_size;
}

ElementType MyListInt::pop_front() {
    if (empty()) {
        throw std::runtime_error("MyListInt::pop_front while list is empty");
    }
    auto next = m_head->m_next;
    auto front = m_head;
    m_head = next;
    int res = front->m_data;
    delete front;
    --m_size;

    if (m_size == 0) {
        m_tail = nullptr;
    }

    return res;
}

ElementType& MyListInt::front() {
    if (empty()) {
        throw std::runtime_error("MyListInt::front while list is empty");
    }
    return m_head->m_data;
}

const ElementType& MyListInt::front() const {
    if (empty()) {
        throw std::runtime_error("MyListInt::front while list is empty");
    }
    return m_head->m_data;
}

ElementType& MyListInt::back() {
    if (empty()) {
        throw std::runtime_error("MyListInt::back while list is empty");
    }
    return m_tail->m_data;
}

const ElementType& MyListInt::back() const {
    if (empty()) {
        throw std::runtime_error("MyListInt::back while list is empty");
    }
    return m_tail->m_data;
}

bool MyListInt::exist(const ElementType& e) {
    auto p = m_head;
    while (p != nullptr) {
        if (p->m_data == e) {
            return true;
        }
        p = p->m_next;
    }
    return false;
}


void MyListInt::clear() {
    while (!empty()) {
        pop_front();
    }
}

void MyListInt::copy(const MyListInt& rhv) {
    clear();
    auto p = rhv.m_head;
    while (p != nullptr) {
        push_back(p->m_data);
        p = p->m_next;
    }
}