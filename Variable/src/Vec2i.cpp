#include "Vec2i.h"

namespace ASTem {
  Vec2i::Vec2i():a_(0), b_(0){};
  Vec2i::Vec2i(int val):a_(val), b_(val){};
  Vec2i::Vec2i(int a, int b):a_(a), b_(b){};

  const int& Vec2i::operator()(unsigned int i) const {return (&a_)[i];}
  int& Vec2i::operator()(unsigned int i) {return (&a_)[i];}
  const int& Vec2i::operator[](unsigned int i) const {return (&a_)[i];}
  int& Vec2i::operator[](unsigned int i) {return (&a_)[i];}

  const int& Vec2i::at(unsigned int i) const {return (&a_)[i];}
  int Vec2i::size() const {
    if (b_ == 0) {
      return 1;
    }
    return 2;
  };
}
