#include <iostream>
#include "Item.h"

template <class T, class U>
class ST {
  public:
    explicit ST(int);
    ~ST();

    int count();
    void insert(T);
    T search(U);
    void remove(T);
    T select(int);
    void show(std::ostream& = std::cout);
  private:
    class STImpl;
    STImpl *mSTImpl;
};


