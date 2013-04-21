#include "ST.h"

template <class T, class U>
class ST<T, U>::STImpl {
  public:
    struct node {
      T item;
      node *l, *r;
      node(T x) {
        item = x;
        l = 0;
        r = 0;
      }
    };
  typedef node *link;

  link head;
  T nullItem;
  int N;

  T searchR(link h, U v) {
    if (h == 0) return nullItem;
    U t = h->item.key();
    if (v == t) return h->item;
    if (v < t) {
      return searchR(h->l, v);
    } else {
      return searchR(h->r, v);
    }
  }

  void insertR(link& h, T x) {
    if (h == 0) {
      h = new node(x);
      N++;
      return;
    }
    if (x.key() < h->item.key()) {
      insertR(h->l, x);
    } else {
      insertR(h->r, x);
    }
  }

  // in-order traversal
  void showR(link h, std::ostream& os) {
    if (h == 0) return;
    showR(h->l, os);
    h->item.show(os);
    showR(h->r, os);
  }
};

template<>
ST<Item, Key>::ST(int maxN) : mSTImpl(new ST<Item, Key>::STImpl()) {
  mSTImpl->head = 0;
  mSTImpl->N = 0;
}

template<>
ST<Item, Key>::~ST() {
  delete mSTImpl;
  mSTImpl = NULL;
}

template<>
int ST<Item, Key>::count() {
  return mSTImpl->N;
}

template<>
void ST<Item, Key>::insert(Item x) {
  mSTImpl->insertR(mSTImpl->head, x);
}

template<>
Item ST<Item, Key>::search(Key v) {
  return mSTImpl->searchR(mSTImpl->head, v);
}

// TODO(hammer): implement
template<>
void ST<Item, Key>::remove(Item x) {
  return;
}

// TODO(hammer): implement
template<>
Item ST<Item, Key>::select(int k) {
  return mSTImpl->nullItem;
}

template<>
void ST<Item, Key>::show(std::ostream& os) {
  mSTImpl->showR(mSTImpl->head, os);
}


