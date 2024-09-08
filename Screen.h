#ifndef SCREEN_H
#define SCREEN_H
#include "Window_mgr.h"
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::ostream;



class Screen {

        friend void Window_mgr::clear(ScreenIndex);

public:
        typedef string::size_type pos;

        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd,' ') { }
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }

        char get() const {return contents[cursor];}
        inline char get(pos ht, pos wd) const;

        Screen &move(pos r, pos c);
        Screen &set(char c);

        Screen &display(ostream &os) {
            do_display(os);
            return *this;
        }
        const Screen &display(ostream &os) const {
            do_display(os);
            return *this;
        }

private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;

        void do_display(ostream &os) const {os << contents;}
};


char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

#endif
