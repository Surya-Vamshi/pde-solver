#ifndef MESH_H
#define MESH_H
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<string>

class mesh{
    protected:
        double l=1, b=1; // Length and Breath of the 2d Element
        int nx=10, ny=10; // Number of nodes in x and y direction
        double tol=0.0001; // Tolerance Limit
        double dx=1/9, dy=1/9; 
        std::vector<std::vector<double>> Temperature;
        double k=0.04; // Constant
    public:
        mesh();
        void temp_initialization();
        void print(std::vector<std::vector<double>> temp);
};


#endif
