#include "steady_state_successive_over_relaxation.h"

void steady_state_successive_over_relaxation(std::vector<std::vector<double>>& Temp, const int& nx,const int& ny,
                            const double& dx,const double& dy,const double& tol,const double& k)
{
    double rf = 1.1; // Over Relaxation Factor
    std::vector<std::vector<double>> Temp_new = Temp;
    int iter{1};
    double err{1.0};
    double term1{0.0}, term2{0.0};

    while (err>tol)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                term1 = (Temp_new[i-1][j]+Temp[i+1][j])/(k*dx*dx);
                term2 = (Temp_new[i][j-1]+Temp[i][j+1])/(k*dy*dy);
                Temp_new[i][j] = Temp[i][j]*(1-rf) + rf*(term1 + term2);
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
    std::cout<<"Number of iterations took to converge for Steady State Successive Over Relaxation: "<< iter<< std::endl;
}
