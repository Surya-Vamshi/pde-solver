#include"steady_state.h"

void steady_state::jacobi(int max_iter)
{
    
    std::vector<std::vector<double>> Temp = Temperature;
    Solution = Temperature;
    
    int iter{1};
    double err{1};

    while (err>tol || iter<max_iter)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                Solution[i][j] = (Temp[i-1][j]+Temp[i+1][j])/(k*dx*dx)+(Temp[i][j-1]+Temp[i][j+1])/(k*dy*dy);
            }
        }
        err = 0;
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                if(err<fabs(Solution[i][j]-Temp[i][j])){
                    err = fabs(Solution[i][j]-Temp[i][j]);
                }
            }
        }
        Temp = Solution;
        iter++;
    }
    std::cout<<"Number of iterations took to converge for Steady State Jacobian: "<< iter<< std::endl;
}

void steady_state::gauss_seidel(int max_iter)
{
    std::vector<std::vector<double>> Temp = Temperature;
    Solution = Temperature;

    int iter{1};
    double err{1};

    while (err>tol || iter<max_iter)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                Solution[i][j] = (Solution[i-1][j]+Temp[i+1][j])/(k*dx*dx)+(Solution[i][j-1]+Temp[i][j+1])/(k*dy*dy);
            }
        }
        err = 0;
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                if(err<fabs(Solution[i][j]-Temp[i][j])){
                    err = fabs(Solution[i][j]-Temp[i][j]);
                }
            }
        }
        Temp = Solution;
        iter++;
    }
    std::cout<<"Number of iterations took to converge for Steady State Gauss Seidel: "<< iter<< std::endl;
}

void steady_state::successive_over_relaxation(int max_iter)
{
    double relaxation_factor = 1.1; // Over Relaxation Factor
    std::vector<std::vector<double>> Temp = Temperature;
    Solution = Temperature;
    int iter{1};
    double err{1.0};
    double term1{0.0}, term2{0.0};

    while (err>tol || iter<max_iter)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                term1 = (Solution[i-1][j]+Temp[i+1][j])/(k*dx*dx);
                term2 = (Solution[i][j-1]+Temp[i][j+1])/(k*dy*dy);
                // These two terms are actually Gauss-Seidel Solution.
                Solution[i][j] = Temp[i][j]*(1-relaxation_factor) + relaxation_factor*(term1 + term2);
                // This extrapolation takes the form of a weighted average between the previous iterate 
                // and the computed Gauss-Seidel iterate successively for each component.
            }
        }
        err = 0;
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                if(err<fabs(Solution[i][j]-Temp[i][j])){
                    err = fabs(Solution[i][j]-Temp[i][j]);
                }
            }
        }
        Temp = Solution;
        iter++;
    }
    std::cout<<"Number of iterations took to converge for Steady State Successive Over Relaxation: "<< iter<< std::endl;
}