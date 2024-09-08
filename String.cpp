#include "String.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::range_initialize(const char *first, const char *last) {
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char* s) {
    char *s1 = const_cast<char*>(s);
    while(*s1) {
        ++s1;
    }
    range_initialize(s, ++s1);
}

String::String(const String &rhs) {
    range_initialize(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

void String::free() {
    if (elements) {
        std::for_each(elements, end, [this](char &c){alloc.destroy(&c);});
        alloc.deallocate(elements, end - elements);
    }
}

String::~String() {
    free();
}

String& String::operator=(const String &rhs) {
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}


String::String(String &&s) noexcept
: elements(s.elements), end(s.end)
{
    s.elements = nullptr;
    s.end = nullptr;
    std::cout << "move construct --" << std::endl;
}

String& String::operator=(String &&rhs) noexcept {
    std::cout << "move-assignment operator -- " << std::endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = nullptr;
        rhs.end = nullptr;
    }
    return *this;
}
