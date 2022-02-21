#include "MyVector.h"

int main() {
    MyVector<int> s1;
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);
    s1.push_back(4);
    std::cout << "second: " << s1[1] << std::endl;
    std::cout << s1.size() << " " << s1.capacity() << std::endl;
    s1.push_back(5);
    s1.push_back(6);
    std::cout << s1.size() << " " << s1.capacity() << std::endl;

    MyVector<int> s2(3, 1);
    std::cout << "second: " << s2[1] << std::endl;

    MyVector<int> s3 = s2;
    for (auto iter = s3.begin(); iter != s3.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
}
