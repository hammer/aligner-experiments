#include <iostream>
template <class Item, class Key>
class ST {
  private:
    Item nullItem, *st;
    int M;
  public:
    ST(int maxN) {
      M = nullItem.key();
      st = new Item[M];
    }
    int count() {
      int N = 0;
      for (int i = 0; i < M; i++)
        if (!st[i].null()) N++;
      return N;
    }

    Item search(Key v) {
      return st[v];
    }

    void insert(Item x) {
      st[x.key()] = x;
    }

    void remove(Item x) {
      st[x.key()] = nullItem;
    }

    Item select(int k) {
      for (int i = 0; i < M; i++)
        if (!st[i].null())
          if (k-- == 0) return st[i];
      return nullItem;
    }
    void show(std::ostream& os) {
      for (int i = 0; i < M; i++)
        if (!st[i].null()) st[i].show(os);
    }
};
