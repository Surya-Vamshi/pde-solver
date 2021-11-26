#include<vector>
#include<iostream>
#include<cmath>
#include<iomanip>
void temp_initialization(std::vector<std::vector<double>>& Temp, const int& nx,const int& ny,
                         const double& dx, const double& dy)
{
    for(auto i = 0; i<nx ;i++){
        for (auto j = 0; j<ny ; j++){
            Temp[i].push_back(300);
        }
    }
    // Assigning Temperatures at Boundaries 
    double Temp_left{400}, Temp_right{800}, Temp_top{600}, Temp_bottom{900};
    for (auto i = 0; i<nx ; i++){
            Temp[i][0]= Temp_left; // Left Boundary
    }
    for (auto i = 0; i<nx ; i++){
            Temp[i][ny-1]= Temp_right; // Right Boundary
    }
    for (auto j = 0; j<ny ; j++){
            Temp[0][j]= Temp_top; // Top Boundary
    }
    for (auto j = 0; j<ny ; j++){
            Temp[nx-1][j]= Temp_bottom; // Bottom Boundary
    }
    // Calculating Average Temp at ends
    Temp[0][0]= (Temp_top+Temp_left)/2.0;
    Temp[0][ny-1]= (Temp_top+Temp_right)/2.0;
    Temp[nx-1][0]= (Temp_bottom+Temp_left)/2.0;
    Temp[nx-1][ny-1]= (Temp_bottom+Temp_right)/2.0;
}