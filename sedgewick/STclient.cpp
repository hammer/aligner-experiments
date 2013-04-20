#include <iostream>
#include <cstdlib>
#include "Item.cpp"
#include "ST.cpp"
int main(int argc, char *argv[]) {
  int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
  ST<Item, Key> st(maxN);
  Item v;

  for (N = 0; N < maxN; N++) {
    if (sw) {
      v.rand();
    } else if (!v.scan()) {
      break;
    }

    if (!(st.search(v.key())).null()) {
      std::cout << "Key collision: " << v.key() << std::endl;
      continue;
    }
    st.insert(v);
  }
  std::cout << std::endl; st.show(std::cout); std::cout << std::endl;
  std::cout << N << " keys" << std::endl;
  std::cout << st.count() << " distinct keys" << std::endl;

  // Try out remove
  st.remove(v);
  std::cout << std::endl << "Removed key " << v.key() << std::endl;
  std::cout << std::endl; st.show(std::cout); std::cout << std::endl;
  std::cout << st.count() << " distinct keys" << std::endl;
}
 
