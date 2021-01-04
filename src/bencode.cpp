#include <iostream>
#include <string>
#include <list>
#include "bencode.h"

// An integer is encoded as i<integer encoded in base ten ASCII>e.
// Leading zeros are not allowed (although the number zero is
// still represented as "0"). Negative values are encoded by
// prefixing the number with a hyphen-minus. The number 42 would
// thus be encoded as i42e, 0 as i0e, and -42 as i-42e. Negative
// zero is not permitted.
std::string encode_integer(int input) {
    return "i" + std::to_string(input) + "e";
}

// A byte string (a sequence of bytes, not necessarily characters)
// is encoded as <length>:<contents>. The length is encoded in
// base 10, like integers, but must be non-negative (zero is
// allowed); the contents are just the bytes that make up the
// string. The string "spam" would be encoded as 4:spam. The
// specification does not deal with encoding of characters outside
// the ASCII set; to mitigate this, some BitTorrent applications
// explicitly communicate the encoding (most commonly UTF-8) in
// various non-standard ways. This is identical to how netstrings
// work, except that netstrings additionally append a comma suffix
// after the byte sequence.
std::string encode_string(std::string input) {
    uint length = input.length();
    std::string n = std::to_string(length) + ":" + input;
    return n;
}


std::string encode_list(std::list<int> input) {
    std::string ret = "";

    for (auto const& i : input) {
        ret += encode_integer(i);
    }

    return "l" + ret + "e";
}