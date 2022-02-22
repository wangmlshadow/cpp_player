#include <iostream>
#include <vector>

template <typename T>
class MySharePtr {
public:
    MySharePtr() : m_data(nullptr), m_sharecnt(nullptr) {}
    MySharePtr(T* ptr);
    MySharePtr(const MySharePtr& from);
    MySharePtr& operator=(const MySharePtr& from);
    ~MySharePtr();
    T* get() const;
    T& operator*();
    T* operator->();
private:
    void decrease();
    void copy(const MySharePtr& from);
private:
    class ShareCnt {
    public:
        ShareCnt() : m_cnt(1) {}
        void addCnt() { m_cnt++; }
        void decreaseCnt() { m_cnt--; }
        long count() const { return m_cnt; }
        bool haveToDelete() const { return m_cnt == 0; }
    private:
        long m_cnt;
    };
private:
    T* m_data;
    ShareCnt* m_sharecnt;
};

class Test {                                                                                                                                                                                                
public:                                                                                                                                                                                                     
    Test() {                                                                                                                                                                                                
        std::cout << "create Test" << std::endl;                                                                                                                                                            
    }                                                                                                                                                                                                       
    ~Test() {                                                                                                                                                                                               
        std::cout << "destory Test" << std::endl;                                                                                                                                                           
    }                                                                                                                                                                                                       
private:                                                                                                                                                                                                    
    int i;                                                                                                                                                                                                  
    std::string str;                                                                                                                                                                                        
};                                                                                                                                                                                                          
                                                                                                                                                                                                            
