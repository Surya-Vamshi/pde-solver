#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<string>
#include"mesh.h"
#include"steady_state.h"
#include"heat_conduction_2d.h"


int main(){
    heat_conduction_2d example;
    example.setup_initialization();
    example.temp_initialization();
    example.steady_state_solver();
    example.result();
    return 0;
}