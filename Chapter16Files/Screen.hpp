#ifndef SCREEN
#define SCREEN

#include <string>

template <unsigned, unsigned> class Screen;

template <unsigned H, unsigned W> std::ostream& operator<<(std::ostream&, const Screen<H,W>&);
template <unsigned H, unsigned W> std::istream& operator>>(std::istream&, Screen<H,W>&);

template <unsigned H, unsigned W> class Screen{
    friend std::ostream& operator<< <H,W>(std::ostream&, const Screen<H,W>&);
    friend std::istream& operator>> <H,W>(std::istream&, Screen<H,W>&);
public:
    typedef std::string::size_type pos;
    Screen(): contents(H*W, ' ') { }
    Screen(char c): contents(H*W, c) { }
    Screen(const std::string& s): contents(s) { }

    char get() const { return contents[cursor];}
    char get(pos row, pos col) const { return contents[(row*W) + col]; }
    Screen& move(pos row, pos col){ cursor = row*W + col; return *this;}
    Screen& set(char c){ contents[cursor] = c; return *this;}
    Screen& set(pos row, pos col, char c){ contents[row*W + col] = c; return *this;}

private:
    pos cursor = 0;
    std::string contents;
};

template <unsigned H, unsigned W> std::ostream& operator<<(std::ostream& os, const Screen<H,W>& s){
    os << s.contents;
    return os;
}

template <unsigned H, unsigned W> std::istream& operator>>(std::istream& is, Screen<H,W>& s){
    is >> s.contents;
    return is;
}

#endif // SCREEN
