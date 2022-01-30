#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<string>
#include"mesh.h"
#include"steady_state.h"
#include"heat_conduction_2d.h"


int main(){
    std::cout.setf(std::ios::fixed, std::ios::floatfield);

    heat_conduction_2d example;
    
    example.temp_initialization();
    example.steady_state_solver();
    example.result();
    return 0;
}