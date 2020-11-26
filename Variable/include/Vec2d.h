#pragma once
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

namespace ASTem {
  struct Vec2d {
    private:
      double a_, b_;
    public:
      Vec2d();
      Vec2d(double val);
      Vec2d(double a, double b);

      const double& operator()(unsigned int i) const;
      double& operator()(unsigned int i);
      const double& operator[](unsigned int i) const;
      double& operator[](unsigned int i);
     
      const double& at(unsigned int i) const;
      unsigned int size() const;
      void sort();
      void add(double in);
  };
}
