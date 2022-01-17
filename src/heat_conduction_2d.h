#ifndef HEAT_CONDUCTION_2D_H
#define HEAT_CONDUCTION_2D_H
#include<vector>
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include"mesh.h"
#include"steady_state.h"


class heat_conduction_2d: public steady_state
{
    private:
        void print_vector(std::vector<double> v);
    public:
        void steady_state_solver();
        void result();
};

#endif 