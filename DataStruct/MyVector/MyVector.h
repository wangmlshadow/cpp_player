#include <iostream>

const size_t DEFAULTSIZE = 4;

template <typename T>
class MyVector {
public:
    MyVector() : m_size(0), m_capacity(0), m_data(nullptr) {}
    MyVector(const MyVector& from);
    MyVector& operator=(const MyVector& from);
    ~MyVector();
    MyVector(int cnt, T val);
    MyVector(T* start, T* end);
public:
    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    T& operator[](size_t pos) const { return m_data[pos]; }
    T& operator[](size_t pos) { return m_data[pos]; }
    void push_back(const T& val);
    void clear();
public:
    class iterator : std::iterator<std::random_access_iterator_tag, T> {
        friend class MyVector;
        friend bool operator==(const iterator& lhs, const iterator& rhs) { return lhs.m_hold == rhs.m_hold; }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) { return !(lhs == rhs); }
        friend bool operator>(const iterator& lhs, const iterator& rhs) { return lhs.m_hold > rhs.m_hold; }
        friend bool operator<(const iterator& lhs, const iterator& rhs) { return lhs.m_hold < rhs.m_hold; }
        friend bool operator>=(const iterator& lhs, const iterator& rhs) { return !(lhs < rhs); }
        friend bool operator<=(const iterator& lhs, const iterator& rhs) { return !(lhs > rhs); }
        friend size_t operator-(const iterator& lhs, const iterator& rhs) { return lhs.m_hold - rhs.m_hold; }
        friend iterator operator+(const iterator& lhs, size_t n) { iterator itr; itr.m_hold = lhs.m_hold + n; return itr; }
        friend iterator operator-(const iterator& lhs, size_t n) { iterator itr; itr.m_hold = lhs.m_hold - n; return itr; }
    public:
        iterator& operator++() { m_hold = m_hold + 1; return *this; }
        iterator& operator--() { m_hold = m_hold - 1; return *this; }
        iterator& operator++(int) { iterator itr; itr.m_hold = m_hold; m_hold = m_hold + 1; return itr; }
        iterator& operator--(int) { iterator itr; itr.m_hold = m_hold; m_hold = m_hold - 1; return itr; }
        T operator*() { return *m_hold; }
    private:
        T* m_hold;
    };
public:
    iterator begin() const noexcept {
        iterator itr;
        itr.m_hold = empty() ? nullptr : &(m_data[0]);
        return itr;
    }
    iterator begin() noexcept {
        iterator itr;
        itr.m_hold = empty() ? nullptr : &(m_data[0]);
        return itr;
    }
    iterator end() const noexcept {
        iterator itr;
        itr.m_hold = empty() ? nullptr : &(m_data[m_size]);
        return itr;
    }
    iterator end() noexcept {
        iterator itr;
        itr.m_hold = empty() ? nullptr : &(m_data[m_size]);
        return itr;
    }
private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;
};
