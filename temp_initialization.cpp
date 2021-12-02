#include"temp_initialization.h"

void temp_initialization(std::vector<std::vector<double>>& Temp, const int& nx,const int& ny,
                         const double& dx, const double& dy)
{
    double Temp_init{300};
    char option{'n'};
    std::cout<<"Do you want to give initial temperatures for entire domain? (y)(n): ";
    std::cin>>option;
    if(option=='y'){
            std::cout<<"Enter the Temperature:";
            std::cin>>Temp_init;
    }
    for(auto i = 0; i<nx ;i++){
        for (auto j = 0; j<ny ; j++){
            Temp[i].push_back(Temp_init);
        }
    }
    // Assigning Temperatures at Boundaries 
    double Temp_left{400}, Temp_right{800}, Temp_top{600}, Temp_bottom{900};
    std::cout<<"Do you want to give temperatures for the boundaries? (y)(n): ";
    std::cin>>option;
    if(option=='y'){
            std::cout<<"Enter the Temperatures in order (Left, Right, Top, Bottom):";
            std::cin>>Temp_left>>Temp_right>>Temp_top>>Temp_bottom;
    }
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