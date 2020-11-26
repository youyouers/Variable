#pragma once
#include <cmath>
#include <cstdlib>
#include <deque>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <Eigen/Eigen>
#include <iostream>
#include <fstream>
#include "spMatrix.h"
#include "vec.h"
#define ZEROVAL 1.0E-14
#define SMALLVAL 1.0E-6;
#define INFINITEVAL 1.0E6;

using namespace std;


//############## VARIABLES ############
// string type vector
using vecS = vector<string>;

// int type vector
using vecI = vector<int>;
using vecUI = vector<unsigned int>;

using deqI = deque<int>;
using deqUI = deque<unsigned int>;

using listI = list<int>;
using listUI = list<unsigned int>;

// double type vector
using vecD = vector<double>;
using deqD = deque<double>;
using vecDE = Eigen::VectorXd;

// for 2 dimension vector
using vec2D = ASTem::Vec2d;
using vec2UI = ASTem::Vec2ui;
//using vec2D = vector<double>;
//using vec2UI = vector<unsigned int>;

// for 3 dimension vector
//using vec3I = ASTem::Vec2i;
//using vec3D = ASTem::Vec3d;
using vec3DA = ASTem::Vec3d;
using vec9DA = ASTem::Vec9d;
//using vec3I = vector<int>;
//using vec3D = vector<double>;
//using vec3DA = arma::Col<double>;
//using vec9DA = vector<arma::Col<double>>;

using tripDE = Eigen::Triplet<double>;
using vecTripDE = vector<Eigen::Triplet<double>>;

using listD = list<double>;

// map
using uMapSD = unordered_map<string, double>;
using uMapSI = unordered_map<string, int>;
using uMapSUI = unordered_map<string, unsigned int>;


// matrix
using matDE = Eigen::SparseMatrix<double>;
using matD = spMatrix;
//############## VARIABLES END ############


