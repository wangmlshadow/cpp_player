#include <iostream>

template <typename T>
class MyStack{
public:
    MyStack();
    MyStack(const MyStack& from);
    MyStack& operator=(const MyStack& from);
    ~MyStack();
public:
    const T& top();
    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }
    void push(T val);
    void pop();
    void clear();
private:
    void copy(const MyStack& from);
private:
    class Node {
    public:
        friend class MyStack;
        Node() : m_next(nullptr) {}
        Node(const T val) : m_data(val), m_next(nullptr) {}
        Node(const Node& from)=delete;
        Node& operator=(const Node& from)=delete;
        ~Node();
    private:
        T m_data;
        Node* m_next;
    };
private:
    Node* m_head;
    size_t m_size;
};
