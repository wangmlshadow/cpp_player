#include "MySListInt.h"

MySListInt::MyNodeInt::MyNodeInt() :m_next(nullptr) {
    std::cout << "Init Node with nothing." << std::endl;
}

MySListInt::MyNodeInt::MyNodeInt(const ElementType& val) 
    : m_next(nullptr), m_data(val) {
    std::cout << "Init Node with Int." << std::endl;
}

MySListInt::MyNodeInt::~MyNodeInt() {
    std::cout << "Destory Node." << std::endl;
}

MySListInt::MySListInt() : m_size(0) {
    std::cout << "Init List nothing." << std::endl;
}

MySListInt::MySListInt(const MySListInt& from) {
    m_size = 0;
    if (!from.empty()) {
        copy(from);
    }
    std::cout << "Init List with List." << std::endl;
}

MySListInt& MySListInt::operator=(const MySListInt& from) {
    std::cout << "operator = for List." << std::endl;

    if (this == &from) {
        return *this;
    } else {
        copy(from);
        return *this;
    }
}

MySListInt::~MySListInt() {
    std::cout << "Destory List." << std::endl;
    clear();
}

void MySListInt::print(std::ostream& out) {
    auto p = m_head;
    while (p != nullptr) {
        out << p->m_data << " ";
        p = p->m_next;
    }
    out << std::endl;
}

void MySListInt::push_front(const ElementType& val) {
    if (empty()) {
        push_back(val);
    } else {
        auto p = new MyNodeInt(val);
        p->m_next = m_head;
        m_head = p;
        ++m_size;
    }
}

void MySListInt::push_back(const ElementType& val) {
    if (empty()) {
        m_head = new MyNodeInt(val);
        m_tail = m_head;
    } else {
        m_tail->m_next = new MyNodeInt(val);
        m_tail = m_tail->m_next;
    }
    ++m_size;
}

ElementType MySListInt::pop_front() {
    if (empty()) {
        throw std::runtime_error("MySListInt::pop_front while list is empty");
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

ElementType& MySListInt::front() {
    if (empty()) {
        throw std::runtime_error("MySListInt::front while list is empty");
    }
    return m_head->m_data;
}

const ElementType& MySListInt::front() const {
    if (empty()) {
        throw std::runtime_error("MySListInt::front while list is empty");
    }
    return m_head->m_data;
}

ElementType& MySListInt::back() {
    if (empty()) {
        throw std::runtime_error("MySListInt::back while list is empty");
    }
    return m_tail->m_data;
}

const ElementType& MySListInt::back() const {
    if (empty()) {
        throw std::runtime_error("MySListInt::back while list is empty");
    }
    return m_tail->m_data;
}

bool MySListInt::exist(const ElementType& e) {
    auto p = m_head;
    while (p != nullptr) {
        if (p->m_data == e) {
            return true;
        }
        p = p->m_next;
    }
    return false;
}


void MySListInt::clear() {
    while (!empty()) {
        pop_front();
    }
}

void MySListInt::copy(const MySListInt& from) {
    std::cout << "MySListInt::copy" << std::endl;
    clear();
    auto p = from.m_head;
    while (p != nullptr) {
        push_back(p->m_data);
        p = p->m_next;
    }
}
