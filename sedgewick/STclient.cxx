#include <iostream>
#include <cstdlib>
#include "Item.cxx"
#include "ST.cxx"
int main(int argc, char *argv[]) {
  int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
  ST<Item, Key> st(maxN);
  for (N = 0; N < maxN; N++) {
    Item v;

    if (sw) {
      v.rand();
    } else if (!v.scan()) {
      break;
    }

    if (!(st.search(v.key())).null()) {
      std::cout << "Key collision: " << v.key() << std::endl << std::endl;
      continue;
    }
    st.insert(v);
  }
  st.show(std::cout); std::cout << std::endl;
  std::cout << N << " keys" << std::endl;
  std::cout << st.count() << " distinct keys" << std::endl;
}
 
