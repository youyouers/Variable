#include "Vec2d.h"

namespace ASTem {
  Vec2d::Vec2d():a_(0.0), b_(0.0){};
  Vec2d::Vec2d(double val):a_(val), b_(val){};
  Vec2d::Vec2d(double a, double b):a_(a), b_(b){};

  const double& Vec2d::operator()(unsigned int i) const {return (&a_)[i];}
  double& Vec2d::operator()(unsigned int i) {return (&a_)[i];}
  const double& Vec2d::operator[](unsigned int i) const {return (&a_)[i];}
  double& Vec2d::operator[](unsigned int i) {return (&a_)[i];}

  const double& Vec2d::at(unsigned int i) const {return (&a_)[i];}
  unsigned int Vec2d::size() const {
    if (b_ == 0.0) {
      return 1;
    }
    return 2;
  };
  void Vec2d::sort() {
    if (b_ != 0.0) {
      if (a_ > b_) {
        double ch = b_;
        b_ = a_;
        a_ = ch;
      }
    }
  }
  void Vec2d::add(const double in) {
    if (a_ == 0.0) {
      a_ = in;
    } else if (b_ == 0.0){
      b_ = in;
    } else {
      cout << "Owner exceeds limit"<<endl;
    }
  }
}
