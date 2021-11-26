#include <vector>
#include<iostream>
#include<cmath>
#include<iomanip>
void steady_state_jacobi(std::vector<std::vector<double>>& Temp, const int& nx,const int& ny,
                            const double& dx,const double& dy,const double& tol,const double& k)
{
    std::vector<std::vector<double>> Temp_new = Temp;
    int iter{1};
    double err{1};

    while (err>tol)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                Temp_new[i][j] = (Temp[i-1][j]+Temp[i+1][j])/(k*dx*dx)+(Temp[i][j-1]+Temp[i][j+1])/(k*dy*dy);
            }
        }
        err = 0;
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                if(err<fabs(Temp_new[i][j]-Temp[i][j])){
                    err = fabs(Temp_new[i][j]-Temp[i][j]);
                }
            }
        }
        Temp = Temp_new;
        iter++;
    }
    std::cout<<"Number of iterations took to converge for Steady State Jacobian: "<< iter<< std::endl;
}
