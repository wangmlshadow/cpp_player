#include "MyStack.h"

int main() {
    MyStack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    std::cout << "s1 len: " << s1.size() << std::endl;

    MyStack<int> s2(s1);
    s2.pop();
    std::cout << "s2 top " << s1.top() << std::endl;

    MyStack<int> s3 = s2;
    s3.pop();
    std::cout << "s3 top " << s3.top() << std::endl;
}
