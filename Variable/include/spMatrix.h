#pragma once
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <Eigen/Eigen>
#include "vec.h"

using namespace std;

// string type vector
using vecS = vector<string>;

// int type vector
using vec2UI = ASTem::Vec2ui;
//using vecI = vector<int>;
//using vec2UI = vector<unsigned int>;

// double type vector
using vecD = vector<double>;

// matrix
using matDE = Eigen::SparseMatrix<double>;

struct spMatrix{
  vecD diag, upper, lower;
  vector<vec2UI> matMap;
  spMatrix();
  spMatrix(unsigned int num1, unsigned int num2);
  spMatrix(unsigned int num1, unsigned int num2, const vector<vec2UI>& ma);
  void zeros();



  double dimension() const;
  double triSize() const;

  const vecD& diagonal() const;
  const vecD& getLower() const;
  const vecD& getUpper() const;
  const vector<vec2UI>& getMatMap();

  spMatrix oneDimOff(unsigned int n);

  vecD rightMultiply(const vecD& vecIn) const;
  vecD LeftMultiply(const vecD& vecIn) const;
};
