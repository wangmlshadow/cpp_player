#include "MyBTree.h"

int main() {
    MyBTree<int> m1;
    std::cout << m1.size() << "  " << m1.empty() << std::endl;

    std::vector<int> init = {1, 3, 2, 5, 8, 4, 10, 6};
    MyBTree<int> m2(init);
    std::cout << m2.high() << "  " << m2.exists(5) << std::endl;
    m2.print(std::cout);

    MyBTree<int> m3(m2);
    std::cout << m2.equal(m3) << std::endl;
}
