#include"temp_initialization.h"

void temp_initialization(std::vector<std::vector<double>>& Temperature, const int& nx,const int& ny,
                         const double& dx, const double& dy)
{
    double Temperature_init{300.00};
    char option{'n'};
    std::cout<<"Do you want to give initial temperatures for entire domain? (y)(n): ";
    std::cin>>option;
    if(option=='y'){
            std::cout<<"Enter the Temperature:";
            std::cin>>Temperature_init;
    }
    std::vector<double> i(ny);
    std::fill(i.begin(), i.end(), Temperature_init);
    std::fill(Temperature.begin(), Temperature.end(), i);
    // Assigning Temperatures at Boundaries 
    double Temperature_left{400}, Temperature_right{800}, Temperature_top{600}, Temperature_bottom{900};
    std::cout<<"Do you want to give temperatures for the boundaries? (y)(n): ";
    std::cin>>option;
    if(option=='y'){
            std::cout<<"Enter the Temperatures in order (Left, Right, Top, Bottom):";
            std::cin>>Temperature_left>>Temperature_right>>Temperature_top>>Temperature_bottom;
    }
    for (auto i = 0; i<nx ; i++){
            Temperature[i][0]= Temperature_left; // Left Boundary
    }
    for (auto i = 0; i<nx ; i++){
            Temperature[i][ny-1]= Temperature_right; // Right Boundary
    }
    for (auto j = 0; j<ny ; j++){
            Temperature[0][j]= Temperature_top; // Top Boundary
    }
    for (auto j = 0; j<ny ; j++){
            Temperature[nx-1][j]= Temperature_bottom; // Bottom Boundary
    }
    // Calculating Average Temp at ends
    Temperature[0][0]= (Temperature_top+Temperature_left)/2.0;
    Temperature[0][ny-1]= (Temperature_top+Temperature_right)/2.0;
    Temperature[nx-1][0]= (Temperature_bottom+Temperature_left)/2.0;
    Temperature[nx-1][ny-1]= (Temperature_bottom+Temperature_right)/2.0;
}