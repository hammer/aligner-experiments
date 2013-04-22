#include "Seq.h"

template <class T>
class Seq<T>::SeqImpl {
  public:
    T* seq;
    int N;
};

template<class T>
Seq<T>::Seq(int maxN) : mSeqImpl(new typename Seq<T>::SeqImpl()) {
  mSeqImpl->seq = new T[maxN + 1]; // why + 1?
  mSeqImpl->N = 0;
}

template<class T>
Seq<T>::~Seq() {
  delete mSeqImpl;
  mSeqImpl = NULL;
}

template<class T>
int Seq<T>::count() {
  return mSeqImpl->N;
}

template<class T>
void Seq<T>::insert(T x) {
  // Eagerly maintain count()
  int i = mSeqImpl->N++;
  while (i > 0 && x < mSeqImpl->seq[i - 1]) {
    mSeqImpl->seq[i] = mSeqImpl->seq[i - 1];
    i--;
  }
  mSeqImpl->seq[i] = x;
}

// Sequential search
// TODO(hammer): improve with binary or interpolation search
// TODO(hammer): consider returning position of hit
// TODO(hammer): consider returning multiple hits
template<class T>
T* Seq<T>::search(T v) {
  int i;
  for (i = 0; i < mSeqImpl->N; i++)
    if (!(mSeqImpl->seq[i] < v)) break;
  if (v == mSeqImpl->seq[i]) return &(mSeqImpl->seq[i]);
  return NULL;
}

// For duplicate keys, removes only first item
template<class T>
void Seq<T>::remove(T x) {
  T* y = search(x);
  if (y != NULL) {
    int i = 0;
    while (i < mSeqImpl->N) {
      if (mSeqImpl->seq[i] == *y) break;
      i++;
    }
    for (; i < mSeqImpl->N-1; i++) {
      mSeqImpl->seq[i] = mSeqImpl->seq[i+1];
    }
    mSeqImpl->N--;
  }
}

template<class T>
T* Seq<T>::select(int k) {
  if (k < mSeqImpl->N) {
    return &(mSeqImpl->seq[k]);
  } else {
    return NULL;
  }
}

template<class T>
void Seq<T>::show(std::ostream& os) {
  for (int i = 0; i < mSeqImpl->N; i++)
    os << mSeqImpl->seq[i] << std::endl;
}

template class Seq<int>;
template class Seq<char>;
