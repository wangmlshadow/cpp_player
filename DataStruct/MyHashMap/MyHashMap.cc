#include <algorithm>
#include "MyHashMap.h"

MyHashMap::MyHashMap() {
    m_bucket_array.resize(m_bucket_array_length);
}
MyHashMap::MyHashMap(const MyHashMap& from) {
    copy(from);
}
MyHashMap& MyHashMap::operator=(const MyHashMap& from) {
    copy(from);
    return *this;
}
MyHashMap::~MyHashMap() {

}
bool MyHashMap::contains(const int& key) {
    auto index = hash(key);
    auto bucket = m_bucket_array[index];
    auto iter = std::find_if(bucket.begin(), bucket.end(), [key](const value_type& value) {
        return value.first == key;
    });
    return iter != bucket.end();
}
void MyHashMap::erase(const int& key) {
    auto index = hash(key);
    auto bucket = m_bucket_array[index];
    auto iter = std::find_if(bucket.begin(), bucket.end(), [key](const value_type& value) {
        return value.first == key;
    });
    if (iter == bucket.end()) {
        std::runtime_error("unkonwn key");
    }
    bucket.erase(iter);
    m_size--;
}
std::string& MyHashMap::operator[](const int& key) {
    auto index = hash(key);
    auto bucket = m_bucket_array[index];
    auto iter = std::find_if(bucket.begin(), bucket.end(), [key](const value_type& value) {
        return value.first == key;
    });
    
    //auto iter = bucket.begin();
    //for ( ; iter != bucket.end(); ++iter) {
    //    if (iter->first == key) {
    //        break;
    //    }
    //}

    if (iter != bucket.end()) {
        //std::cout << "has..." << std::endl;
        return iter->second;
    } else {
        //std::cout << "new..." << std::endl;
        ++m_size;
        if (load_factor() > 0.8) {
            re_hash();
        }
        index = hash(key);
        m_bucket_array[index].push_back({key, std::string()});
        return m_bucket_array[index].back().second;
    }
}
MyHashMap::iterator& MyHashMap::iterator::operator++() {
    auto index = m_hashmap->hash(m_iter->first);
    auto& bucket = m_hashmap->m_bucket_array[index];
    m_iter++;

    if (m_iter == bucket.end()) {
        for (size_t i = index + 1; i < m_hashmap->m_bucket_array_length; ++i) {
            if (!m_hashmap->m_bucket_array[i].empty()) {
                m_iter = m_hashmap->m_bucket_array[i].begin();
                m_bucket_index = i;
                return *this;
            }
        }
        m_bucket_index = -1;
    }
    return *this;
}
bool MyHashMap::iterator::operator==(const iterator& iter) {
    if (m_bucket_index != iter.m_bucket_index) {
        return false;
    }
    if (m_bucket_index == -1 && iter.m_bucket_index == -1) {
        return true;
    }
    return &(*m_iter) == &(*iter.m_iter);
}
bool MyHashMap::iterator::operator!=(const iterator& iter) {
    return !(*this == iter);
}
MyHashMap::value_type& MyHashMap::iterator::operator*() {
    return *m_iter;
}
MyHashMap::iterator::iterator(MyHashMap* hashmap, size_t bucket_index, std::list<value_type>::iterator itr) {
    m_hashmap = hashmap;
    m_bucket_index = bucket_index;
    m_iter = itr;
}
MyHashMap::iterator MyHashMap::begin() {
    for (size_t i = 0; i < m_bucket_array_length; ++i) {
        if (!m_bucket_array[i].empty()) {
            return MyHashMap::iterator(this, i, m_bucket_array[i].begin());
        }
    }
    return end();
}
MyHashMap::iterator MyHashMap::end() {
    return MyHashMap::iterator(this, -1, std::list<value_type>::iterator());
}
size_t MyHashMap::hash(const int& key) const {
    size_t index = key % m_bucket_array_length;
    return index;
}
void MyHashMap::clear() {
    m_size = 0;
    m_bucket_array.clear();
}
void MyHashMap::copy(const MyHashMap& from) {
    clear();
    m_bucket_array_length = from.m_bucket_array_length;
    for (int i = 0; i < m_bucket_array_length; ++i) {
        m_bucket_array[i] = from.m_bucket_array[i];
    }
    m_size = from.m_size;
}
void MyHashMap::re_hash() {
    std::cout << "re_hash..." << std::endl;
    MyHashMap re_hashmap;
    re_hashmap.m_bucket_array_length = m_bucket_array_length * 2 + 1;
    re_hashmap.m_bucket_array.resize(re_hashmap.m_bucket_array_length);

    for (auto iter = begin(); iter != end(); ++iter) {
        auto index = re_hashmap.hash((*iter).first);
        auto bucket = re_hashmap.m_bucket_array[index];
        bucket.push_back(*iter);
    }

    re_hashmap.m_size = m_size;
    std::swap(re_hashmap.m_bucket_array, m_bucket_array);
    m_bucket_array_length = re_hashmap.m_bucket_array_length;
}
