#include "MathVec.h"

vecD vecMinus(const vecD& va, const vecD& vb) {
  unsigned int num = va.size();
  vecD val(num);
  #pragma omp parallel for simd
  for (unsigned int i = 0; i < num; i ++) {
    val[i] = va[i] - vb[i];
  }
  return val;
};

vecD vecAdd(const vecD& va, const vecD& vb) {
  vecD val(va.size());
  #pragma omp parallel for simd
  for (unsigned int i = 0; i < va.size(); i ++) {
    val[i] = va[i] + vb[i];
  }
  return val;
};

vecD vecMul(const vecD& va, const vecD& vb) {
  vecD val(va.size());
  #pragma omp parallel for simd
  for (unsigned int i = 0; i < va.size(); i ++) {
    val[i] = va[i] * vb[i];
  }
  return val;
};

vecD vecDiv(const vecD& va, const vecD& vb) {
  vecD val(va.size());
  #pragma omp parallel for simd
  for (unsigned int i = 0; i < va.size(); i ++) {
    val[i] = va[i] / vb[i];
  }
  return val;
};

vecD operator/(const vecD& va, const double b) {
  vecD val(va.size());
  #pragma omp parallel for simd
  for (unsigned int i = 0; i < va.size(); i ++) {
    val[i] = va[i] / b;
  }
  return val;
}

vecD vecFabs(const vecD& vecIn) {
  vecD val(vecIn.size());
  #pragma omp parallel for simd
  for (unsigned int i = 0; i < vecIn.size(); i ++) {
    val[i] = fabs(vecIn[i]);
  }
  return val;
};

double vecNorm(const vecD& vecIn) {
  double val = 0;
  #pragma omp parallel for simd reduction(+: val)
  for (unsigned int i = 0; i < vecIn.size(); i ++) {
    val += vecIn[i] * vecIn[i];
  }
  return sqrt(val);
};

double vecMax(const vecD& vecIn) {
  double val = vecIn[0];
  for (unsigned int i = 1; i < vecIn.size(); i ++) {
    if (val < vecIn[i]) {val = vecIn[i];}
  }
  return val;
}

double vecABSMax(const vecD& vecIn) {
  double val = fabs(vecIn[0]);
  for (unsigned int i = 1; i < vecIn.size(); i ++) {
    if (val < fabs(vecIn[i])) {val = fabs(vecIn[i]);}
  }
  return val;
}

void zeroVec(vecD& vecIn) {
  for (unsigned int i = 0; i < vecIn.size(); i ++) {
    vecIn[i] = 0.0;
  }
}


void patchVec(vecD& ob, unsigned int iStart, const vecD& in) {
  for (unsigned int i = 0; i < in.size(); i ++) {
    ob[i + iStart] = in[i];
  }
}

vecD subVec(const vecD& vecIn, unsigned int iStart, unsigned int iEnd) {
  vecD val(iEnd - iStart);
  for (unsigned int i = iStart; i < iEnd; i ++) {
    val[i - iStart] = vecIn[i];
  }
  return val;
}

vecD vecOneOff(const vecD& vecIn, unsigned int n) {
  unsigned int num = vecIn.size();
  vecD val(num - 1);
  unsigned int j = 0;
  for (unsigned int i = 0; i < num; i ++) {
    if(i == n - 1) {
      j = j + 1;
      continue;
    }
    val[i - j] = vecIn[i];
  }
  return val;
}
