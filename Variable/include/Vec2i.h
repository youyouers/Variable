#pragma once
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

namespace ASTem {
  struct Vec2i {
    private:
      int a_, b_;
    public:
      Vec2i();
      Vec2i(int val);
      Vec2i(int a, int b);

      const int& operator()(unsigned int i) const;
      int& operator()(unsigned int i);
      const int& operator[](unsigned int i) const;
      int& operator[](unsigned int i);

      const int& at(unsigned int i) const;
      int size() const;
  };
}
