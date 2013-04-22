#include <iostream>

template <class T>
class Seq {
  public:
    explicit Seq(int);
    ~Seq();

    void insert(T);
    void remove(T);

    int count();

    T* search(T);
    T* select(int);

    // implements both sort() and <<
    void show(std::ostream& = std::cout);
  private:
    class SeqImpl;
    SeqImpl *mSeqImpl;
 };


