#pragma once
#include "VaraType.h"
#include "spMatrix.h"

using namespace std;

vecD vecMinus(const vecD& va, const vecD& vb);

vecD vecAdd(const vecD& va, const vecD& vb);

vecD vecMul(const vecD& va, const vecD& vb);

vecD vecDiv(const vecD& va, const vecD& vb);

vecD operator/(const vecD& va, const double b);

vecD vecFabs(const vecD& vecIn);

double vecNorm(const vecD& vecIn);

double vecMax(const vecD& vecIn);

double vecABSMax(const vecD& vecIn);

void zeroVec(vecD& vecIn);

void patchVec(vecD& ob, unsigned int iStart, const vecD& in);

vecD subVec(const vecD& vecIn, unsigned int iStart, unsigned int iEnd);

vecD vecOneOff(const vecD& vecIn, unsigned int n);
