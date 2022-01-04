#include "steady_state_successive_over_relaxation.h"

void steady_state_successive_over_relaxation(std::vector<std::vector<double>>& Temperature, const int& nx,const int& ny,
                            const double& dx,const double& dy,const double& tol,const double& k)
{
    double relaxation_factor = 1.1; // Over Relaxation Factor
    std::vector<std::vector<double>> Solution = Temperature;
    int iter{1};
    double err{1.0};
    double term1{0.0}, term2{0.0};

    while (err>tol)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                term1 = (Solution[i-1][j]+Temperature[i+1][j])/(k*dx*dx);
                term2 = (Solution[i][j-1]+Temperature[i][j+1])/(k*dy*dy);
                // These two terms are actually Gauss-Seidel Solution.
                Solution[i][j] = Temperature[i][j]*(1-relaxation_factor) + relaxation_factor*(term1 + term2);
                // This extrapolation takes the form of a weighted average between the previous iterate 
                // and the computed Gauss-Seidel iterate successively for each component.
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
    std::cout<<"Number of iterations took to converge for Steady State Successive Over Relaxation: "<< iter<< std::endl;
}
