#include "Vec9d.h"
// 3 dimension vector: x, y, z
namespace ASTem{
    // constructor
    Vec9d::Vec9d(){x_=Vec3d(); y_=Vec3d(); z_=Vec3d();}
    Vec9d::Vec9d(const Vec3d& val){x_=val; y_=val; z_=val;}
    Vec9d::Vec9d(const Vec3d& x, const Vec3d& y, const Vec3d& z){x_=x; y_=y; z_=z;}


    // access
    const Vec3d& Vec9d::operator()(unsigned int i) const {
      return (&x_)[i];
    }
    Vec3d& Vec9d::operator()(unsigned int i) {
      return (&x_)[i];
    }
    const Vec3d& Vec9d::operator[](unsigned int i) const {
      return (&x_)[i];
    }
    Vec3d& Vec9d::operator[](unsigned int i) {
      return (&x_)[i];
    }


    void Vec9d::operator+=(const Vec9d& b) const {
      (*this).add(b);
    }
    // set
    void Vec9d::setVal(const Vec3d& val) {
      x_ = y_ = z_ = val;
    }
    void Vec9d::setVal(const Vec3d& x, const Vec3d& y, const Vec3d& z) {
      x_ = x;
      y_ = y;
      z_ = z;
    }

    double Vec9d::strainRate() const {
      return sqrt(
                  (x_(0)*x_(0) + y_(1)*y_(1) + z_(2)*z_(2)) * 2.0 +
                  (x_(1) + y_(0))*(x_(1) + y_(0)) +
                  (z_(1) + y_(2))*(z_(1) + y_(2)) +
                  (x_(2) + z_(0))*(x_(2) + z_(0))
                 );
    }
    // arithmetic functions

    Vec9d Vec9d::add(const double b) const {
      return Vec9d(x_+b, y_+b, z_+b);
    }
    Vec9d Vec9d::add(const Vec3d& b) const {
      return Vec9d(x_+b, y_+b, z_+b);
    }
    Vec9d Vec9d::add(const Vec9d& b) const {
      return Vec9d(x_+b(0), y_+b(1), z_+b(2));
    }
    Vec9d Vec9d::sub(const double b) const {
      return Vec9d(x_-b, y_-b, z_-b);
    }
    Vec9d Vec9d::sub(const Vec3d& b) const {
      return Vec9d(x_-b, y_-b, z_-b);
    }
    Vec9d Vec9d::sub(const Vec9d& b) const {
      return Vec9d(x_-b(0), y_-b(1), z_-b(2));
    }
    Vec9d Vec9d::mul(const double b) const {
      return Vec9d(x_*b, y_*b, z_*b);
    }
    Vec9d Vec9d::mul(const Vec3d& b) const {
      return Vec9d(x_%b, y_%b, z_%b);
    }
    Vec9d Vec9d::mul(const Vec9d& b) const {
      return Vec9d(x_%b(0), y_%b(1), z_%b(2));
    }
    Vec9d Vec9d::div(const double b) const {
      return Vec9d(x_/b, y_/b, z_/b);
    }
    Vec9d Vec9d::div(const Vec3d& b) const {
      return Vec9d(x_/b, y_/b, z_/b);
    }
    Vec9d Vec9d::div(const Vec9d& b) const {
      return Vec9d(x_/b(0), y_/b(1), z_/b(2));
    }

    // min and max
    double Vec9d::max3d() const {
      return std::max(std::max(x_.max3d(), y_.max3d()), z_.max3d());
    }
    double Vec9d::min3d() const {
      return std::min(std::min(x_.min3d(), y_.min3d()), z_.min3d());
    }

   Vec3d Vec9d::col(unsigned int i) const { return Vec3d(x_(i), y_(i), z_(i));}
// operations of Vec9d
Vec9d operator+(const Vec9d& a, const double b) {
  return a.add(b);
}
Vec9d operator+(const double a, const Vec9d& b) {
  return b.add(a);
}
Vec9d operator+(const Vec9d& a, const Vec3d& b) {
  return a.add(b);
}
Vec9d operator+(const Vec3d& a, const Vec9d& b) {
  return b.add(a);
}
Vec9d operator+(const Vec9d& a, const Vec9d& b) {
  return b.add(a);
}
/*
Vec9d operator+=(const Vec9d& a, const Vec9d& b) {
  return b.add(a);
}
*/
Vec9d operator-(const Vec9d& a, const double b) {
  return a.sub(b);
}
/*
Vec9d operator-(const double a, const Vec9d& b) {
  return b.sub(a);
}
*/
Vec9d operator-(const Vec9d& a, const Vec3d& b) {
  return a.sub(b);
}
/*
Vec9d operator-(const Vec3d& a, const Vec9d& b) {
  return b.sub(a);
}
*/
Vec9d operator-(const Vec9d& a, const Vec9d& b) {
  return a.sub(b);
}
/*
Vec9d operator-=(const Vec9d& a, const Vec9d& b) {
  return a.sub(b);
}
*/

Vec9d operator*(const Vec9d& a, const double b) {
  return a.mul(b);
}
Vec9d operator*(const double a, const Vec9d& b) {
  return b.mul(a);
}
Vec9d operator%(const Vec9d& a, const Vec3d& b) {
  return a.mul(b);
}
Vec9d operator%(const Vec3d& a, const Vec9d& b) {
  return b.mul(a);
}
Vec9d operator%(const Vec9d& a, const Vec9d& b) {
  return b.mul(a);
}



Vec9d operator/(const Vec9d& a, const double b) {
  return a.div(b);
}
Vec9d operator/(const double a, const Vec9d& b) {
  return Vec9d(b(0).rdiv(a), b(1).rdiv(a), b(2).rdiv(a));
}
Vec9d operator/(const Vec9d& a, const Vec3d& b) {
  return a.div(b);
}
Vec9d operator/(const Vec3d& a, const Vec9d& b) {
  return Vec9d(a.div(b(0)), a.div(b(1)), a.div(b(2)));
}
Vec9d operator/(const Vec9d& a, const Vec9d& b) {
  return a.div(b);
}
}
