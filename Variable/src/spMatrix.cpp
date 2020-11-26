#include "spMatrix.h"
spMatrix::spMatrix(){};
spMatrix::spMatrix(unsigned int num1, unsigned int num2) {
  diag.resize(num1);
  upper.resize(num2);
  lower.resize(num2);
  matMap.resize(num2);;
}
spMatrix::spMatrix(unsigned int num1, unsigned int num2, const vector<vec2UI>& ma) {
  diag.resize(num1);
  upper.resize(num2);
  lower.resize(num2);
  matMap = ma;
}
void spMatrix::zeros() {
  //#pragma omp parallel for simd
  for (unsigned int i =0; i < diag.size(); i ++) {
    diag[i] = 0.0;
  }
  //#pragma omp parallel for simd
  for (unsigned int i =0; i < upper.size(); i ++) {
    upper[i] = 0.0;
    lower[i] = 0.0;
  }
}



double spMatrix::dimension() const {return diag.size();}
double spMatrix::triSize() const {return upper.size();}

const vecD& spMatrix::diagonal() const {return diag;}
const vecD& spMatrix::getLower() const {return lower;}
const vecD& spMatrix::getUpper() const {return upper;}
const vector<vec2UI>& spMatrix::getMatMap() {return matMap;}

spMatrix spMatrix::oneDimOff(unsigned int n) {
  unsigned int eleNum = diag.size(),
               faceNum = upper.size();
  unsigned int num1, num2 = 0;
  //#pragma omp parallel for reduction(+: num2)
  for (unsigned int i = 0; i < faceNum; i++) {
    unsigned int ii = matMap[i][0] - 1, jj = matMap[i][1] - 1;
    if ((ii == n-1) || (jj == n-1)) { continue;}
    num2 ++ ;
  }
  num1 = eleNum - 1;
  spMatrix matrix(num1, num2);
  unsigned int index = 0;
  //#pragma omp parallel for reduction(+: index)
  for (unsigned int i = 0; i < eleNum; i++) {
    if (i == n-1) { continue;}
    matrix.diag[index] = diag[i];
    index ++;
  }
  index = 0;
  //#pragma omp parallel for simd reduction(+: index)
  for (unsigned int i = 0; i < faceNum; i++) {
    unsigned int ii = matMap[i][0] - 1, jj = matMap[i][1] - 1;
    if ((ii == n-1) || (jj == n-1)) { continue;}
    matrix.upper[index] = lower[i];
    matrix.lower[index] = upper[i];
    matrix.matMap[index] = matMap[i];
    index ++;
  }
  return matrix;
}

vecD spMatrix::rightMultiply(const vecD& vecIn) const {
  vecD value(dimension());
  //#pragma omp simd
  for (unsigned int i = 0; i < dimension(); i ++){
    value[i] = diag[i] * vecIn[i];
  }
  //#pragma omp parallel for simd
  for (unsigned int i = 0; i < triSize(); i++) {
    unsigned int ii = matMap[i][0] - 1,
                 jj = matMap[i][1] - 1;
    if (ii < jj) {
      value[ii] += upper[i] * vecIn[jj];
      value[jj] += lower[i] * vecIn[ii];
    } else {
      value[jj] += upper[i] * vecIn[ii];
      value[ii] += lower[i] * vecIn[jj];
    }
  }
  return value;
}

vecD spMatrix::LeftMultiply(const vecD& vecIn) const {
  vecD value(dimension());
  //#pragma omp simd
  for (unsigned int i = 0; i < dimension(); i ++){
    value[i] = diag[i] * vecIn[i];
  }
  for (unsigned int i = 0; i < triSize(); i++) {
    unsigned int ii = matMap[i][0] - 1,
                 jj = matMap[i][1] - 1;
    if (ii > jj) {
      value[ii] += upper[i] * vecIn[jj];
      value[jj] += lower[i] * vecIn[ii];
    } else {
      value[jj] += upper[i] * vecIn[ii];
      value[ii] += lower[i] * vecIn[jj];
    }
  }
  return value;
}


