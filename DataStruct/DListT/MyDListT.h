#include <iostream>
#include <cassert>

template<typename T>
class MyDListT {
public:
    MyDListT();
    ~MyDListT();
    MyDListT(const MyDListT& from);
    MyDListT& operator=(const MyDListT& from);
public:
    void push_front(const T& val);
    void push_back(const T& val);
    T pop_front();
    T pop_back();
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    bool empty() const;
    size_t size() const;
    void clear();

    class iterator;

    void erase(iterator i);
    void insert(iterator i, const T& val);
    void prT(std::ostream& out);
public:
    iterator begin() const noexcept;
    iterator begin() noexcept;
    iterator end() const noexcept;
    iterator end() noexcept;
public:
    class MyNodeT;
    class iterator {
        friend class MyDListT;
        friend bool operator == (const iterator& lhs, const iterator& rhs) { return lhs.m_hold == rhs.m_hold; }
        friend bool operator != (const iterator& lhs, const iterator& rhs) { return lhs.m_hold != rhs.m_hold; }
    public:
        iterator() : m_hold(nullptr) {}
        iterator& operator++();
        T& operator*() { return this->m_hold->m_data; }
    private:
        MyNodeT* m_hold;
    };
public:
    class MyNodeT {
        friend class MyDListT;
    private:
        MyNodeT();
        MyNodeT(const T& value);
        ~MyNodeT();
    private:
        MyNodeT* m_prev;
        T m_data;
        MyNodeT* m_next;
    };

    void copy(const MyDListT& from);
    void print(std::ostream& out);
private:
    MyNodeT* m_first;
    MyNodeT* m_last;
    size_t m_size;
};
