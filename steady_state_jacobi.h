#ifndef STEADY_STATE_JACOBI_H
#define STEADY_STATE_JACOBI_H
#include<vector>
#include<iostream>
#include<cmath>
#include<iomanip>
void steady_state_jacobi(std::vector<std::vector<double>>& Temperature, const int& nx,const int& ny,
                            const double& dx,const double& dy,const double& tol,const double& k);

#endif