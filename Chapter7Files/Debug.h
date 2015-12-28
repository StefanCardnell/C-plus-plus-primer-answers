#ifndef DEBUG
#define DEBUG

class Debug{
public:
  constexpr Debug(bool b = false): Debug(b,b,b) { }
  constexpr Debug(bool a, bool b, bool c): ht(a), io(b), other(c) { }
  Debug(int x, int y): Debug(false) { }
  constexpr bool any() { return ht || io || other; }
  void set_ht(bool b) { ht = b;}
  void set_io(bool b) { io = b;}
  void set_other(bool b) { other = b;}
private:
    bool ht;
    bool io;
    bool other;

};

#endif // DEBUG
