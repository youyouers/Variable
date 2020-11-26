#pragma once
#include "VaraType.h"
#include "MathVec.h"

using namespace std;

//############## for solutionsystem ############
struct FVMDEMSolverSetup {
  string solverType = "FVM";
  string solutionType = "transient";
  bool isMultiPhase = false;
  string multiphase = "single";
  vec3DA gravity;
  double convergenceMomentum = 1.0E-4;
  double convergenceContinuity = 1.0E-4;
  bool isConverged = false;
};

struct FVMStepSetup {
  // basic parameters
  double timeStep = 0.001;
  double finalTime = 1.0;
  double time = 0.0;
  unsigned int maxIteration;
  unsigned int iteration;
  // for dynamic time step size
  bool isFixedSize = true;
  double courantNumber = 2.0;
  double minSize = 1.0E-6;
  double maxSize = 1.0;
  double minChangeFactor = 0.5;
  double maxChangeFactor = 2.0;
  int fixedTimeStepNumber = 5;
  int currentStepNumber = 0;
  // for tabular-input step size
  bool isStepSizeTabular = false;
  vecD timeStepList;
  vecUI stepNumberList;
};

struct DEMStepSetup {
  unsigned int stepSizeRatio = 20;
  double stepSize = 1.0E-6;
};

struct FVMRelaxation {
  double momentumRelax = 0.7;
  double pressureRelax = 0.3;
  double indicatorRelax = 0.5;
};

struct OutputSetup {
  int autoSaveSteps;
  int dataSaveSteps;
};

struct ElementPatch {
  vecD indicator;
  vecD pressure;
  vecD volumeFraction;
};

//############## for solutionsystem ############


struct FvmData {
  vector<vec3DA> elementVelocity;
  vecD viscosity;
  vecD density;
  vecI element;
  vector<vec3DA> pressureGradient;
  vecD elementVolumeFraction;
};

struct Spring {
  vec3DA length;
  string state;
};


//############## Interpolation ###############
struct GreenGauss{
  vecD faceValue;
  vector<vec3DA> elementGradient;
};
//############ Interpolation END #############

//using namespace arma;
//using namespace ASTem;
