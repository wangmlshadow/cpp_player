#include "MyDListInt.h"

MyDListInt::MyDListInt() : m_first(nullptr), m_last(nullptr), m_size(0) {
    std::cout << "Init with nothing." << std::endl;
}

MyDListInt::~MyDListInt() {
    clear();
}

MyDListInt::MyDListInt(const MyDListInt& from) {
    std::cout << "Init with another List." << std::endl;
    m_size = 0;
    m_first = nullptr;
    m_last = nullptr;

    if (this != &from) {
        copy(from);
    }
}

MyDListInt& MyDListInt::operator=(const MyDListInt& from) {
    std::cout << "operator=." << std::endl;
    if (this != &from) {
        copy(from);
    }
    return *this;
}

void MyDListInt::push_front(const ElementType& val) {
    MyNodeInt* node = new MyNodeInt(val);
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

void MyDListInt::push_back(const ElementType& val) {
    MyNodeInt* node = new MyNodeInt(val);
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

ElementType MyDListInt::pop_front() {
    if (empty()) {
        throw std::runtime_error("MySListInt::pop_front while list is empty");
    }
    ElementType res = m_first->m_data;
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

ElementType MyDListInt::pop_back() {
    if (empty()) {
        throw std::runtime_error("MySListInt::pop_front while list is empty");
    }
    ElementType res = m_last->m_data;
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

ElementType& MyDListInt::front() {
    return m_first->m_data;
}

const ElementType& MyDListInt::front() const {
    return m_first->m_data;
}

ElementType& MyDListInt::back() {
    return m_last->m_data;
}

const ElementType& MyDListInt::back() const {
    return m_last->m_data;
}

bool MyDListInt::empty() const {
    return m_size == 0;
}

size_t MyDListInt::size() const {
    return m_size;
}

void MyDListInt::clear() {
    auto p = m_first;
    while (p != nullptr) {
        auto next = p->m_next;
        delete p;
        p = next;
    }
    m_size = 0;
}

void MyDListInt::erase(iterator i) {
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

void MyDListInt::insert(iterator i, const ElementType& val) {
    if (empty() || i.m_hold->m_prev == nullptr) {
        push_front(val);
    } else {
        auto node = new MyNodeInt(val);
        i.m_hold->m_prev->m_next = node;
        node->m_next = i.m_hold;
        i.m_hold->m_prev = node;
    }
}

MyDListInt::iterator MyDListInt::begin() const noexcept {
    MyDListInt::iterator itr;
    itr.m_hold = m_first;
    return itr;
}

MyDListInt::iterator MyDListInt::begin() noexcept {
    MyDListInt::iterator itr;
    itr.m_hold = m_first;
    return itr;
}

MyDListInt::iterator MyDListInt::end() const noexcept {
    MyDListInt::iterator itr;
    return itr;
}

MyDListInt::iterator MyDListInt::end() noexcept {
    MyDListInt::iterator itr;
    return itr;
}

MyDListInt::iterator& MyDListInt::iterator::operator++() {
    this->m_hold = this->m_hold->m_next;
    return *this;
}

MyDListInt::MyNodeInt::MyNodeInt() : m_next(nullptr), m_prev(nullptr) {}
MyDListInt::MyNodeInt::MyNodeInt(const ElementType& value) : m_next(nullptr), m_data(value), m_prev(nullptr) {}
MyDListInt::MyNodeInt::~MyNodeInt() {}

void MyDListInt::copy(const MyDListInt& from) {
    if (this != &from) {
        clear();
        for (auto itr : from) {
            push_back(itr);
        }
    }
}

void MyDListInt::print(std::ostream& out) {
    for (auto itr : *this) {
        std::cout << itr << " ";
    }
    out << std::endl;
}
