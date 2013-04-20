#include <iostream>
template <class Item, class Key>
class ST {
  private:
    Item nullItem, *st;
    int N;
  public:
    ST(int maxN) {
      st = new Item[maxN+1];
      N = 0;
    }

    int count() {
      return N;
    }

    void insert(Item x) {
      // Eagerly maintain count()
      int i = N++;
      Key v = x.key();
      while (i > 0 && v < st[i-1].key()) {
        st[i] = st[i-1];
        i--;
      }
      st[i] = x;
    }

    // Sequential search
    // TODO(hammer): improve with binary or interpolation search
    Item search(Key v) {
      int i;
      for (i = 0; i < N; i++)
        if (!(st[i].key() < v)) break;
      if (v == st[i].key()) return st[i];
      return nullItem;
    }

    // For duplicate keys, removes only first item
    void remove(Item x) {
      Key v = x.key();
      Item y = search(v);
      if (!y.null()) {
        for (int i = y.key(); i < N-1; i++) {
          st[i] = st[i+1];
	}
        N--;
      }
    }

    Item select(int k) {
      return st[k];
    }

    void show(std::ostream& os) {
      for (int i = 0; i < N; i++)
        st[i].show(os);
    }
};
