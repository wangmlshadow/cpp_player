#include <iostream>
#include <cassert>

typedef int ElementType;

class MyDListInt {
public:
    MyDListInt();
    ~MyDListInt();
    MyDListInt(const MyDListInt& from);
    MyDListInt& operator=(const MyDListInt& from);
public:
    void push_front(const ElementType& val);
    void push_back(const ElementType& val);
    ElementType pop_front();
    ElementType pop_back();
    ElementType& front();
    const ElementType& front() const;
    ElementType& back();
    const ElementType& back() const;

    bool empty() const;
    size_t size() const;
    void clear();

    class iterator;

    void erase(iterator i);
    void insert(iterator i, const ElementType& val);
    void print(std::ostream& out);
public:
    iterator begin() const noexcept;
    iterator begin() noexcept;
    iterator end() const noexcept;
    iterator end() noexcept;
public:
    class MyNodeInt;
    class iterator {
        friend class MyDListInt;
        friend bool operator == (const iterator& lhs, const iterator& rhs) { return lhs.m_hold == rhs.m_hold; }
        friend bool operator != (const iterator& lhs, const iterator& rhs) { return lhs.m_hold != rhs.m_hold; }
    public:
        iterator() : m_hold(nullptr) {}
        iterator& operator++();
        ElementType& operator*() { return this->m_hold->m_data; }
    private:
        MyNodeInt* m_hold;
    };
public:
    class MyNodeInt {
        friend class MyDListInt;
    private:
        MyNodeInt();
        MyNodeInt(const ElementType& value);
        ~MyNodeInt();
    private:
        MyNodeInt* m_prev;
        ElementType m_data;
        MyNodeInt* m_next;
    };

    void copy(const MyDListInt& from);
private:
    MyNodeInt* m_first;
    MyNodeInt* m_last;
    size_t m_size;
};
