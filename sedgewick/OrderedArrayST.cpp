#include "ST.h"

template <class T, class U>
class ST<T, U>::STImpl {
  public:
    T nullItem, *st;
    int N;
};

template<>
ST<Item, Key>::ST(int maxN) : mSTImpl(new ST<Item, Key>::STImpl()) {
  mSTImpl->st = new Item[maxN+1];
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
  // Eagerly maintain count()
  int i = mSTImpl->N++;
  Key v = x.key();
  while (i > 0 && v < mSTImpl->st[i-1].key()) {
    mSTImpl->st[i] = mSTImpl->st[i-1];
    i--;
  }
  mSTImpl->st[i] = x;
}

// Sequential search
// TODO(hammer): improve with binary or interpolation search
template<>
Item ST<Item, Key>::search(Key v) {
  int i;
  for (i = 0; i < mSTImpl->N; i++)
    if (!(mSTImpl->st[i].key() < v)) break;
  if (v == mSTImpl->st[i].key()) return mSTImpl->st[i];
  return mSTImpl->nullItem;
}

// For duplicate keys, removes only first item
template<>
void ST<Item, Key>::remove(Item x) {
  Key v = x.key();
  Item y = search(v);
  if (!y.null()) {
    int i = 0;
    while (i < mSTImpl->N) {
      if (mSTImpl->st[i].key() == y.key()) break;
      i++;
    }
    for (; i < mSTImpl->N-1; i++) {
      mSTImpl->st[i] = mSTImpl->st[i+1];
    }
    mSTImpl->N--;
  }
}

template<>
Item ST<Item, Key>::select(int k) {
  return mSTImpl->st[k];
}

template<>
void ST<Item, Key>::show(std::ostream& os) {
  for (int i = 0; i < mSTImpl->N; i++)
    mSTImpl->st[i].show(os);
}


