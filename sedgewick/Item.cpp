#include "Item.h"

// Ctor
Item::Item() {
  keyval = maxKey;
}

Key Item::key() {
  return keyval;
}

// Null Item indicated by keyval == maxKey
int Item::null() {
  return keyval == maxKey;
}

// Generate random Item (keyval, info)
void Item::rand() {
  keyval = (int)(1000*(std::rand()/(float)RAND_MAX));
  info = 1.0*std::rand()/RAND_MAX;
}

// Read new item from stdin
int Item::scan(std::istream& is) {
  return (is >> keyval >> info) != 0;
}

// Print Item
void Item::show(std::ostream& os) {
  os << keyval << " " << info << std::endl;
}


