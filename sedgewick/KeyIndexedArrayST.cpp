#include "ST.h"

template <class T, class U>
class ST<T, U>::STImpl {
  public:
    T nullItem, *st;
    int M;
};

template<>
ST<Item, Key>::ST(int maxN) : mSTImpl(new ST<Item, Key>::STImpl()) {
  mSTImpl->M = mSTImpl->nullItem.key();
  mSTImpl->st = new Item[mSTImpl->M];
}

template<>
ST<Item, Key>::~ST() {
  delete mSTImpl;
  mSTImpl = NULL;
}

template<>
int ST<Item, Key>::count() {
  int N = 0;
  for (int i = 0; i < mSTImpl->M; i++)
    if (!mSTImpl->st[i].null()) N++;
  return N;
}

template<>
void ST<Item, Key>::insert(Item x) {
  mSTImpl->st[x.key()] = x;
}

template<>
Item ST<Item, Key>::search(Key v) {
  return mSTImpl->st[v];
}

// For duplicate keys, removes only first item
template<>
void ST<Item, Key>::remove(Item x) {
  mSTImpl->st[x.key()] = mSTImpl->nullItem;
}

template<>
Item ST<Item, Key>::select(int k) {
  for (int i = 0; i < mSTImpl->M; i++)
    if (!mSTImpl->st[i].null())
      if (k-- == 0) return mSTImpl->st[i];
  return mSTImpl->nullItem;
}

template<>
void ST<Item, Key>::show(std::ostream& os) {
  for (int i = 0; i < mSTImpl->M; i++)
    if (!mSTImpl->st[i].null()) mSTImpl->st[i].show(os);
}


