#include "MyDListT.h"

int main() {
    MyDListT<double> ex1;
    ex1.push_front(1.0);
    ex1.push_back(2.0);
    ex1.push_back(3.0);
    std::cout << "ex1 size: " << ex1.size() << std::endl;
    std::cout << "ex1 is empty: " << ex1.empty() << std::endl;
    std::cout << "ex1 front: " << ex1.front() << std::endl;
    std::cout << "ex1 back: " << ex1.back() << std::endl;
    std::cout << "ex1 print:";
    ex1.print(std::cout);

    MyDListT<double> ex2(ex1);
    ex2.pop_front();
    ex2.pop_back();
    std::cout << "ex2 print:";
    ex2.print(std::cout);

    MyDListT<double> ex3;
    ex3 = ex1;
    std::cout << "ex3 print";
    ex3.print(std::cout);
}
