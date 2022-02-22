#include <iostream>
#include <vector>
#include <list>
#include <string>

class MyHashMap {
public:
    MyHashMap();
    MyHashMap(const MyHashMap& from);
    MyHashMap& operator=(const MyHashMap& from);
    ~MyHashMap();
public:
    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }
    bool contains(const int& key);
    void erase(const int& key);
    std::string& operator[](const int& key);
public:
    using value_type = std::pair<int, std::string>;
public:
    class iterator {
        friend class MyHashMap;
    public:
        iterator& operator++();
        bool operator==(const iterator& iter);
        bool operator!=(const iterator& iter);
        value_type& operator*();
    private:
        iterator(MyHashMap* hashmap, size_t bucket_index, std::list<value_type>::iterator itr);
    private:
        std::list<value_type>::iterator m_iter;
        size_t m_bucket_index;
        MyHashMap* m_hashmap;
    };
public:
    iterator begin();
    iterator end();
private:
    size_t hash(const int& key) const;
    void clear();
    void copy(const MyHashMap& from);
    double load_factor() const { return (double)m_size / m_bucket_array_length; }
    void re_hash();
private:
    std::vector<std::list<value_type>> m_bucket_array;
    size_t m_size = 0;
    size_t m_bucket_array_length = 8;
};
