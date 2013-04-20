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
    Item() {
      keyval = maxKey;
    }
    Key key() {
      return keyval;
    }
    // Null Item indicated by keyval == maxKey
    int null() {
      return keyval == maxKey;
    }
    // Generate random Item (keyval, info)
    void rand() {
      keyval = (int)(1000*(std::rand()/(float)RAND_MAX));
      info = 1.0*std::rand()/RAND_MAX;
    }
    // Read new item from stdin
    int scan(std::istream& is = std::cin) {
      return (is >> keyval >> info) != 0;
    }
    // Print Item
    void show(std::ostream& os = std::cout) {
      os << keyval << " " << info << std::endl;
    }
};

