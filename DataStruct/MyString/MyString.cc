#include "MyString.h"

int MyString::s_i = 0;

void operator<<(std::ostream& out, const MyString& str) {
    for (int i = 0; i < str.m_length; ++i) {
        out << str.m_data[i];
    }
}

MyString::MyString(char* data, size_t len) : m_data(nullptr), m_length(0), m_id(++s_i) {
    copy(data, len);
}

MyString::MyString(char* data) : m_data(nullptr), m_length(0), m_id(++s_i) {
    copy(data, strlen(data));
}

MyString::~MyString() {
    clear();
}

MyString::MyString(const MyString& from) : m_data(nullptr), m_length(0), m_id(++s_i) {
    copy(from.m_data, from.m_length);
}

MyString& MyString::operator=(const MyString& from) {
    if (this != &from)
        copy(from.m_data, from.m_length);
}

void MyString::clear() {
    if (m_data != nullptr) {
        delete m_data;
        m_data = nullptr;
        m_length = 0;
    }
}

void MyString::copy(char* data, size_t len) {
    clear();
    if (len != 0) {
        m_data = new char[len];
        for (int i = 0; i < len; ++i) {
            m_data[i] = data[i];
        }
        m_length = len;
    }
}

MyString::MyString(MyString&& from) {
    std::swap(m_data, from.m_data);
    std::swap(m_length, from.m_length);
}

MyString& MyString::operator=(MyString&& from) {
    std::swap(m_data, from.m_data);
    std::swap(m_length, from.m_length);
    return *this;
}
