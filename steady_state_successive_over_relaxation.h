#ifndef STEADY_STATE_SUCCESSIVE_OVER_RELAXATION_H
#define STEADY_STATE_SUCCESSIVE_OVER_RELAXATION_H
#include<vector>
#include<iostream>
#include<cmath>
#include<iomanip>
void steady_state_successive_over_relaxation(std::vector<std::vector<double>>& Temperature, const int& nx,const int& ny,
                            const double& dx,const double& dy,const double& tol,const double& k);

#endif