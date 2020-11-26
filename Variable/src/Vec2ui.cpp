#include "Vec2ui.h"

namespace ASTem {
  Vec2ui::Vec2ui():a_(0), b_(0){};
  Vec2ui::Vec2ui(unsigned int val):a_(val), b_(val){};
  Vec2ui::Vec2ui(unsigned int a, unsigned int b):a_(a), b_(b){};

  const unsigned int& Vec2ui::operator()(unsigned int i) const {return (&a_)[i];}
  unsigned int& Vec2ui::operator()(unsigned int i) {return (&a_)[i];}
  const unsigned int& Vec2ui::operator[](unsigned int i) const {return (&a_)[i];}
  unsigned int& Vec2ui::operator[](unsigned int i) {return (&a_)[i];}

  const unsigned int& Vec2ui::at(unsigned int i) const {return (&a_)[i];}
  unsigned int Vec2ui::size() const {
    if (b_ == 0) {
      return 1;
    }
    return 2;
  };
  void Vec2ui::sort() {
    if (b_ != 0) {
      if (a_ > b_) {
        unsigned int ch = b_;
        b_ = a_;
        a_ = ch;
      }
    }
  }
  void Vec2ui::add(const unsigned int in) {
    if (a_ == 0) {
      a_ = in;
    } else if (b_ == 0){
      b_ = in;
    } else {
      cout << "Owner exceeds limit"<<endl;
    }
  }
}
