#include <iostream>
#include <cstring>

class MyString {
    friend void operator<<(std::ostream& out, const MyString& str);
public:
    MyString() : m_data(nullptr), m_length(0), m_id(++s_i) {}
    MyString(char* data, size_t len);
    MyString(char* data);
    MyString(const MyString& from);
    MyString& operator=(const MyString& from);
    ~MyString();
public:
    MyString(MyString&& from);
    MyString& operator=(MyString&& from);
private:
    void clear();
    void copy(char* data, size_t len);

private:
    char* m_data;
    size_t m_length;
    int m_id;
    static int s_i;
};
