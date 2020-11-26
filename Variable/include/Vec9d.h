#pragma once
#include <cstdlib>
#include <cmath>
#include "Vec3d.h"
// 3 dimension vector: x, y, z
namespace ASTem{
struct Vec9d {
  private:
    Vec3d x_, y_, z_;

  public:
    // constructor
    Vec9d();
    Vec9d(const Vec3d& val);
    Vec9d(const Vec3d& x, const Vec3d& y, const Vec3d& z);


    // access
    const Vec3d& operator()(unsigned int i) const;
    Vec3d& operator()(unsigned int i);

    const Vec3d& operator[](unsigned int i) const;
    Vec3d& operator[](unsigned int i);

    // set
    void setVal(const Vec3d& val);
    void setVal(const Vec3d& x, const Vec3d& y, const Vec3d& z);

    double strainRate() const;

    // arithmetic functions
    void operator+=(const double b) const;
    void operator+=(const Vec3d& b) const;
    void operator+=(const Vec9d& b) const;
    Vec9d add(const double b) const;
    Vec9d add(const Vec3d& b) const;
    Vec9d add(const Vec9d& b) const;
    Vec9d sub(const double b) const;
    Vec9d sub(const Vec3d& b) const;
    Vec9d sub(const Vec9d& b) const;
    Vec9d mul(const double b) const;
    Vec9d mul(const Vec3d& b) const;
    Vec9d mul(const Vec9d& b) const;
    Vec9d div(const double b) const;
    Vec9d div(const Vec3d& b) const;
    Vec9d div(const Vec9d& b) const;

    // min and max
    double max3d() const;
    double min3d() const;

   // func
   Vec3d col(unsigned int i) const;

};

// operations of Vec3d
Vec9d operator+(const Vec9d& a, const double b);
Vec9d operator+(const double a, const Vec9d& b);
Vec9d operator+(const Vec9d& a, const Vec3d& b);
Vec9d operator+(const Vec3d& a, const Vec9d& b);
Vec9d operator+(const Vec9d& a, const Vec9d& b);

Vec9d operator-(const Vec9d& a, const double b);
//Vec9d operator-(const double a, const Vec9d& b);
Vec9d operator-(const Vec9d& a, const Vec3d& b);
//Vec9d operator-(const Vec3d& a, const Vec9d& b);
Vec9d operator-(const Vec9d& a, const Vec9d& b);

Vec9d operator*(const Vec9d& a, const double b);
Vec9d operator*(const double a, const Vec9d& b);
Vec9d operator%(const Vec9d& a, const Vec3d& b);
Vec9d operator%(const Vec3d& a, const Vec9d& b);
Vec9d operator%(const Vec9d& a, const Vec9d& b);

Vec9d operator/(const Vec9d& a, const double b);
Vec9d operator/(const double a, const Vec9d& b);
Vec9d operator/(const Vec9d& a, const Vec3d& b);
Vec9d operator/(const Vec3d& a, const Vec9d& b);
Vec9d operator/(const Vec9d& a, const Vec9d& b);
}
