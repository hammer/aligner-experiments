#include <iostream>
template <class Item, class Key>
class ST {
  private:
    Item nullItem;
    struct node {
      Item item;
      node* next;
      node(Item x, node* t) {
        item = x;
        next = t;
      }
    };
    typedef node *link;
    int N;
    link head;
    Item searchR(link t, Key v) {
      if (t == 0) return nullItem;
      if (t->item.key() == v) return t->item;
      return searchR(t->next, v);
    }
  void showR(link t, std::ostream& os) {
      if (t == 0) return;
      t->item.show(os);
      showR(t->next, os);
    }
  public:
    ST(int maxN) {
      head = 0;
      N = 0;
    }

    int count() {
      return N;
    }

    Item search(Key v) {
      return searchR(head, v);
    }

    void insert(Item x) {
      head = new node(x, head);
      N++;
    }

    // remove(Item) not implemented because carrying around a reference to the previous link is hard

    // select(int) not implemented; hard without a sorted list

    void show(std::ostream& os) {
      showR(head, os);
    }
};
