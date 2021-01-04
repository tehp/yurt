#ifndef BENCODE_H
#define BENCODE_H

#include <iostream>
#include <list>
#include <string>

std::string encode_string(std::string input);
std::string encode_integer(int input);
std::string encode_list(std::list<int> input);

#endif