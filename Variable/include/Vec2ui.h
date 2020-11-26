#pragma once
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

namespace ASTem {
  struct Vec2ui {
    private:
      unsigned int a_, b_;
    public:
      Vec2ui();
      Vec2ui(unsigned int val);
      Vec2ui(unsigned int a, unsigned int b);
      const unsigned int& operator()(unsigned int i) const;
      unsigned int& operator()(unsigned int i);
      const unsigned int& operator[](unsigned int i) const;
      unsigned int& operator[](unsigned int i);
      const unsigned int& at(unsigned int i) const;
      unsigned int size() const;
      void sort();
      void add(unsigned int in);
  };
}
