#include "Seq.h"

int main(int argc, char *argv[]) {
  int maxN = 10;
  int N;

  char v;
  Seq<char> seq(10);
  const char* letters = "abcdefghijklmnopqrstuvwxyz";

  for (N = 0; N < maxN; N++) {
    v = letters[std::rand() % 26];

    if (seq.search(v) != NULL) {
      std::cout << "Key collision: " << v << std::endl;
      continue;
    }
    seq.insert(v);
  }
  std::cout << std::endl; seq.show(std::cout); std::cout << std::endl;
  std::cout << N << " keys" << std::endl;
  std::cout << seq.count() << " distinct keys" << std::endl;

  // Try out remove
  seq.remove(v);
  std::cout << std::endl << "Removed key " << v << std::endl;
  std::cout << std::endl; seq.show(std::cout); std::cout << std::endl;
  std::cout << seq.count() << " distinct keys" << std::endl;
}
 
