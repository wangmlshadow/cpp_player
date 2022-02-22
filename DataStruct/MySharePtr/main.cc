#include "MySharePtr.h"
#include <string>


void test1() {
    MySharePtr<Test> ptr(new Test);
}

void test2(Test* from) {
    MySharePtr<Test> ptr(from);
}

void test3(MySharePtr<Test>& from) {
    MySharePtr<Test> ptr(from);
}

int main() {
    Test* t = new Test();
    test1();
    test2(t);
    MySharePtr<Test> ptr(new Test());
    MySharePtr<Test> ptr2(ptr);
}
