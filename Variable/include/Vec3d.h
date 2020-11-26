#pragma once
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
// 3 dimension vector: x, y, z
namespace ASTem{
struct Vec3d {
  private:
    double x_, y_, z_;

  public:
    // constructor
    Vec3d();
    Vec3d(const double val);
    Vec3d(const double x, const double y, const double z);


    // access
    const double& operator()(unsigned int i) const;
    double& operator()(unsigned int i);
    const double& operator[](unsigned int i) const;
    double& operator[](unsigned int i);
    void operator+=(const double b);
    void operator+=(const Vec3d& b);

    const double& at(unsigned int i) const;
    // set
    void setVal(const double val);
    void setVal(const double x, const double y, const double z);

    // arithmetic functions
    Vec3d add(const double b) const;
    Vec3d add(const Vec3d& b) const;
    Vec3d sub(const double b) const;
    Vec3d sub(const Vec3d& b) const;
    Vec3d mul(const double b) const;
    Vec3d mul(const Vec3d& b) const;
    Vec3d div(const double b) const;
    Vec3d div(const Vec3d& b) const;
    Vec3d rdiv(const double b) const;

    // min and max
    double max3d() const;
    double min3d() const;
    unsigned int size() const;

    // vector operation
    double length() const;
    void normalized();
    void sort();
};

// operations of Vec3d
Vec3d operator+(const Vec3d& a, const double b);
Vec3d operator+(const double a, const Vec3d& b);
Vec3d operator+(const Vec3d& a, const Vec3d& b);

Vec3d operator-(const Vec3d& a);
Vec3d operator-(const Vec3d& a, const double b);
Vec3d operator-(const double a, const Vec3d& b);
Vec3d operator-(const Vec3d& a, const Vec3d& b);

Vec3d operator*(const Vec3d& a, const double b);
Vec3d operator*(const double a, const Vec3d& b);
//Vec3d operator*(const Vec3d& a, const Vec3d& b);
Vec3d operator%(const Vec3d& a, const Vec3d& b);

Vec3d operator/(const Vec3d& a, const double b);
Vec3d operator/(const double a, const Vec3d& b);
Vec3d operator/(const Vec3d& a, const Vec3d& b);
//#pragma omp declare simd
double dot(const Vec3d& a, const Vec3d& b);
//#pragma omp declare simd
double norm(const Vec3d& a);

Vec3d cross(const Vec3d& a, const Vec3d& b);

Vec3d normalise(const Vec3d& a);
//#pragma omp declare simd
double sum(const Vec3d& a);
}
