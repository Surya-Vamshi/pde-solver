#include "steady_state_gauss_seidel.h"

void steady_state_gauss_seidel(std::vector<std::vector<double>>& Temperature, const int& nx,const int& ny,
                                 const double& dx, const double& dy,const double& tol,const double& k)
{
    std::vector<std::vector<double>> Solution = Temperature;
    int iter{1};
    double err{1};

    while (err>tol)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                Solution[i][j] = (Solution[i-1][j]+Temperature[i+1][j])/(k*dx*dx)+(Solution[i][j-1]+Temperature[i][j+1])/(k*dy*dy);
            }
        }
        err = 0;
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                if(err<fabs(Solution[i][j]-Temperature[i][j])){
                    err = fabs(Solution[i][j]-Temperature[i][j]);
                }
            }
        }
        Temperature = Solution;
        iter++;
    }
    std::cout<<"Number of iterations took to converge for Steady State Gauss Seidel: "<< iter<< std::endl;
}
