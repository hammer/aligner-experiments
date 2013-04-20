#include <iostream>
template <class Item, class Key>
class ST {
  private:
    Item nullItem, *st;
    int N;

  Item searchR(int l, int r, Key v) {
    if (l > r) return nullItem;
    int m = (l + r) / 2;
    if (v == st[m].key()) return st[m];
    if (l == r) return nullItem;
    if (v < st[m].key()) {
      return searchR(l, m - 1, v);
    } else {
      return searchR(m + 1, r, v);
    }
  }
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

    // Binary search
    // TODO(hammer): improve with interpolation search
    Item search(Key v) {
      return searchR(0, N - 1, v);
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
