#ifndef STEADY_STATE_H
#define STEADY_STATE_H
#include<vector>
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include"mesh.h"

class steady_state: public mesh
{
    protected:
        std::vector<std::vector<double>> Solution;
        void jacobi();
        void gauss_seidel();
        void successive_over_relaxation();
    public:

};

#endif