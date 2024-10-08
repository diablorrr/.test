#ifndef STRING_H
#define STRING_H

#include <algorithm>
#include <memory>
#include <ostream>
#include <utility>
class String {
friend std::ostream& operator<<(std::ostream &, const String &);
    public:
        String():String("") {}
        String(const char*);
        String(const String&);
        String& operator=(const String&);
        ~String();
        
        const char* c_str() const {return elements;}
        size_t size() const{return end - elements;}
        size_t length() const {return end - elements + 1;}

        String(String &&) noexcept;
        String &operator=(String &&) noexcept;

    private:
        std::pair<char*, char*> alloc_n_copy(const char*, const char*);
        void range_initialize(const char*, const char*);
        void free();

        char *elements;
        char *end;
        std::allocator<char> alloc;

};

inline std::ostream& operator<<(std::ostream &os, const String &s) {
        char *c = const_cast<char*>(s.c_str());
        while(*c)
                os << *c++;
        return os;
}

#endif
