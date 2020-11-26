/*#include "../include/vec.h"

using namespace std;
namespace ASTem{
  vector<double> subVec(vector<double>& value, unsigned int iStart, unsigned int iEnd) {
    vector<double> sub(iEnd - iStart + 1);
    #pragma omp simd
    for (unsigned int i = iStart; i <= iEnd; i ++) {
      sub[i] = value[i];
    }
    return sub;
  }

  void vecPatch(vector<double>& object, vector<double>& in, unsigned int iStart) {
    #pragma omp simd
    for (unsigned int i = iStart; i < in.size(); i ++) {
      object[i] = in[i - iStart];
    }
  }
}
*/
