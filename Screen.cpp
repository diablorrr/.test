#include "Screen.h"
#include <string>

typedef string::size_type pos;

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
