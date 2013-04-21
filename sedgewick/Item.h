#include <cstdlib>
#include <iostream>

static int maxKey = 1000;
typedef int Key;

class Item {
  private:
    Key keyval;
    float info;
  public:
    // Ctor
    Item();
    Key key();
    int null();
    void rand();
    int scan(std::istream& = std::cin);
    void show(std::ostream& = std::cout);
};

