/*
MySListInt

*/

#include <iostream>
#include <string>

typedef int ElementType;

// 
class MySListInt {
public:
    MySListInt();
    MySListInt(const MySListInt& from);
    MySListInt& operator=(const MySListInt& from);
    ~MySListInt();
public:
    void print(std::ostream& out);
    void push_front(const ElementType& val);
    void push_back(const ElementType& val);
    ElementType pop_front();
    ElementType& front();
    const ElementType& front() const;
    ElementType& back();
    const ElementType& back() const;
    bool exist(const ElementType& e);
    bool empty() const { return m_size == 0; }
    int size() const { return m_size; }
    void clear();
private:
    class MyNodeInt {
        friend class MySListInt;
    private:
        MyNodeInt();
        MyNodeInt(const ElementType& val);
        ~MyNodeInt();

    public:
        MyNodeInt* m_next;
        ElementType m_data;
    };
private:
    void copy(const MySListInt& from);
private:
    MyNodeInt* m_head = nullptr;
    MyNodeInt* m_tail = nullptr;
    int m_size;
};
