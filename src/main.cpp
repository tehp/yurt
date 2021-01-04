#include <iostream>
#include <string>
#include <list>
#include "bencode.h"

int main() {
    std::cout << encode_string("test text") << std::endl;
    std::cout << encode_integer(-12) << std::endl;

    std::list<int> l;
    l.push_back(1);
    l.push_back(666);
    l.push_back(3);
    std::cout << encode_list(l) << std::endl;
}