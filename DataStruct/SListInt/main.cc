#include "MySListInt.h"

int main() {
    MySListInt list_sample1;
    if (list_sample1.empty()) {
        std::cout << "list_sample1 is empty." << std::endl;
    }

    MySListInt list_sample2;
    list_sample2.push_back(1);
    list_sample2.push_back(2);
    list_sample2.push_back(3);
    std::cout << "list_sample2 size: " << list_sample2.size() << std::endl;

    MySListInt list_sample3(list_sample2);
    std::cout << "list_sample3: pop_front: " << list_sample3.pop_front() << std::endl;
    list_sample3.push_front(10);
    list_sample3.push_front(100);
    std::cout << "print list_sample3:" << std::endl;
    list_sample3.print(std::cout);

    list_sample1 = list_sample3;
    std::cout << "list_sample1 front: " << list_sample2.front() << std::endl;
    std::cout << "list_sample1 back: " << list_sample2.back() << std::endl;

    return 0;
}