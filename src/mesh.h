#ifndef MESH_H
#define MESH_H
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<string>

class mesh{
    protected:
        double l, b; // Length and Breath of the 2d Element
        int nx, ny; // Number of nodes in x and y direction
        double tol; // Tolerance Limit
        double dx, dy; 
        std::vector<std::vector<double>> Temperature;
        double k; // Constant
    public:
        mesh();
        void setup_initialization();
        void temp_initialization();
};

#endif
