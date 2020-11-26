#include "Vec3d.h"
// 3 dimension vector: x, y, z
namespace ASTem{
    // constructor
    Vec3d::Vec3d(){x_=0.0; y_=0.0; z_=0.0;}
    Vec3d::Vec3d(const double val){x_=val; y_=val; z_=val;}
    Vec3d::Vec3d(const double x, const double y, const double z){x_=x; y_=y; z_=z;}


    // access
    const double& Vec3d::operator()(unsigned int i) const {
      return (&x_)[i];
    }
    double& Vec3d::operator()(unsigned int i) {
      return (&x_)[i];
    }
    const double& Vec3d::operator[](unsigned int i) const {
      return (&x_)[i];
    }
    double& Vec3d::operator[](unsigned int i) {
      return (&x_)[i];
    }
    void Vec3d::operator+=(const double b) {
      x_ += b;
      y_ += b;
      z_ += b;
    }
    void Vec3d::operator+=(const Vec3d& b) {
      x_ += b(0);
      y_ += b(1);
      z_ += b(2);
    }

    const double& Vec3d::at(unsigned int i) const {
      return (&x_)[i];
    }
    // set
    void Vec3d::setVal(const double val) {
      x_ = y_ = z_ = val;
    }
    void Vec3d::setVal(const double x, const double y, const double z) {
      x_ = x;
      y_ = y;
      z_ = z;
    }

    // arithmetic functions
    Vec3d Vec3d::add(const double b) const {
      return Vec3d(x_+b, y_+b, z_+b);
    }
    Vec3d Vec3d::add(const Vec3d& b) const{
      return Vec3d(x_+b(0), y_+b(1), z_+b(2));
    }
    Vec3d Vec3d::sub(const double b) const{
      return Vec3d(x_-b, y_-b, z_-b);
    }
    Vec3d Vec3d::sub(const Vec3d& b) const{
      return Vec3d(x_-b(0), y_-b(1), z_-b(2));
    }
    Vec3d Vec3d::mul(const double b) const{
      return Vec3d(x_*b, y_*b, z_*b);
    }
    Vec3d Vec3d::mul(const Vec3d& b) const{
      return Vec3d(x_*b(0), y_*b(1), z_*b(2));
    }
    Vec3d Vec3d::div(const double b) const{
      return Vec3d(x_/b, y_/b, z_/b);
    }
    Vec3d Vec3d::div(const Vec3d& b) const{
      return Vec3d(x_/b(0), y_/b(1), z_/b(2));
    }
    Vec3d Vec3d::rdiv(const double b) const{
      return Vec3d(b/x_, b/y_, b/z_);
    }
    // min and max
    double Vec3d::max3d() const {
      return std::max(std::max(x_,y_),z_);
    }
    double Vec3d::min3d() const {
      return std::min(std::min(x_,y_),z_);
    }
    unsigned int Vec3d::size() const {
      return 3;
    }
    // vector operation
    double Vec3d::length() const {return sqrt(x_*x_ + y_*y_ + z_*z_);}
    void Vec3d::normalized() {
      double l = length();
      if (l > 0.0) {x_ /= l; y_ /= l; z_ /= l;}
    }
    void Vec3d::sort() {
      double x = x_, y = y_, z = z_;

      if (x > y) {
        x = y_; y = x_;
      }
      if (y > z) {
        double ch = z;
        z = y; y = ch;
      }
      if (x > y) {
        double ch = x;
        x = y; y = ch;
      }
      x_ = x;
      y_ = y;
      z_ = z;
    }

// operations of Vec3d
Vec3d operator+(const Vec3d& a, const double b) {
  return a.add(b);
}
Vec3d operator+(const double a, const Vec3d& b) {
  return b.add(a);
}
Vec3d operator+(const Vec3d& a, const Vec3d& b) {
  return b.add(a);
}

Vec3d operator-(const Vec3d& a) {
  return a.mul(-1.0);
}
Vec3d operator-(const Vec3d& a, const double b) {
  return a.sub(b);
}
Vec3d operator-(const double a, const Vec3d& b) {
  return (-b).add(a);
}
Vec3d operator-(const Vec3d& a, const Vec3d& b) {
  return a.sub(b);
}

Vec3d operator*(const Vec3d& a, const double b) {
  return a.mul(b);
}
Vec3d operator*(const double a, const Vec3d& b) {
  return b.mul(a);
}

//Vec3d operator*(const Vec3d& a, const Vec3d& b) {
//  return b.mul(a);
//}

Vec3d operator%(const Vec3d& a, const Vec3d& b) {
  return b.mul(a);
}


Vec3d operator/(const Vec3d& a, const double b) {
  return a.div(b);
}
Vec3d operator/(const double a, const Vec3d& b) {
  return b.rdiv(a);
}
Vec3d operator/(const Vec3d& a, const Vec3d& b) {
  return a.div(b);
}
//#pragma omp declare simd
double dot(const Vec3d& a, const Vec3d& b) {
  return (a(0)*b(0) + a(1)*b(1) + a(2)*b(2));
}
//#pragma omp declare simd
double norm(const Vec3d& a) {
  return sqrt(a(0)*a(0) + a(1)*a(1) + a(2)*a(2));
}

Vec3d cross(const Vec3d& a, const Vec3d& b) {
  return Vec3d(a(1)*b(2)-a(2)*b(1), a(2)*b(0)-a(0)*b(2), a(0)*b(1)-a(1)*b(0));
}

Vec3d normalise(const Vec3d& a) {
  double l = a.length();
  if (l > 0.0) {return Vec3d(a(0)/l, a(1)/l, a(2)/l);}
  return Vec3d();
}
//#pragma omp declare simd
double sum(const Vec3d& a) {
  return a(0) + a(1) + a(2);
}
}
