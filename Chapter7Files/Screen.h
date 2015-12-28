#ifndef SCREEN
#define SCREEN
#include <string>

//There is a problem in EX7.32, where it wants me to declare a member function as a friend while also
//having a vector of that class type. The only way to solve this inter-relationship is to have nested class types or
//by just declaring the class Window_mgr as a friend.

using namespace std;

class Screen{
    friend class Window_mgr;
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wt): height(ht), width(wt), contents(ht*wt, ' ') { }
    Screen(pos ht, pos wt, char c): height(ht), width(wt), contents(ht*wt, c) { }
    char get() const { return contents[cursor];}
    char get(pos row, pos col) const;
    Screen& move(pos row, pos col);
    Screen& set(char c){ contents[cursor] = c; return *this;}
    Screen& set(pos row, pos col, char c){ contents[row*width + col] = c; return *this;}
    Screen& display(ostream& os){to_display(os); return *this;}
    const Screen& display(ostream& os) const {to_display(os); return *this;}
private:
    pos height = 0, width = 0;
    pos cursor = 0;
    string contents;
    void to_display(ostream& os) const {os << contents;}

};

class Window_mgr{
public:
    typedef vector<Screen>::size_type screenindex;
    void clear(screenindex);
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

inline char Screen::get(pos row, pos col) const {

    pos temp = row*width;
    return contents[temp + col];

}

inline Screen& Screen::move(pos row, pos col) {

    cursor = row*width + col;
    return *this;

}

inline void Window_mgr::clear(screenindex i){
    Screen& s = screens[i];
    s.contents = string(s.height*s.width, ' ');
}

#endif // SCREEN
