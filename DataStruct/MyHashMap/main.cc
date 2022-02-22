#include "MyHashMap.h"
#include <iostream>

int main() {
    MyHashMap hm;
    hm[1] = "aaa";
    std::cout << "hm[1] = " << hm[1] << std::endl;
    hm[2] = "bbb";
    hm[3] = "ccc";
    hm[4] = "ddd";

    if (hm.contains(1)) {
        std::cout << "hm contains 1..." << std::endl; 
    }

    hm.erase(3);
    if (hm.contains(3)) {
        std::cout << "hm contains 3..." << std::endl; 
    } else {
        std::cout << "3 not in hm..." << std::endl; 
    }

    hm[5] = "eee";
    hm[6] = "fff";
    hm[7] = "ggg";
    hm[8] = "hhh";

    std::cout << "size: " << hm.size() << std::endl;

    return 0;
}
