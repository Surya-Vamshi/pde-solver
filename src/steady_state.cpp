#include"steady_state.h"

void steady_state::jacobi(int max_iter)
{
    
    std::vector<std::vector<double>> Temp = Temperature;
    
    
    int iter{0};
    double err{1};
    double constant=k*dx*dx;

    while (err>tol && iter<max_iter)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                Temperature[i][j] = (Temp[i-1][j]+Temp[i+1][j])/constant+(Temp[i][j-1]+Temp[i][j+1])/constant;
            }
        }
        err = 0;
        if (iter%5==0){
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                double err_1= fabs(Temperature[i][j]-Temp[i][j]);
                if(err< err_1){
                    err = err_1;
                }
            }
        }}
        Temp = Temperature;
        iter++;
    }
    std::cout<<"Number of iterations took to converge for Steady State Jacobian: "<< iter<< std::endl;
}

void steady_state::gauss_seidel(int max_iter)
{
    std::vector<std::vector<double>> Temp = Temperature;
    

    int iter{0};
    double err{1};
    double constant=k*dx*dx;
    while (err>tol && iter<max_iter)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {   
                Temperature[i][j] = (Temperature[i-1][j]+Temp[i+1][j])/constant+(Temperature[i][j-1]+Temp[i][j+1])/constant;
            }
        }
        int z=iter%5==0;
        
        if (iter%5==0){
            err = 0;
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                double err_1= fabs(Temperature[i][j]-Temp[i][j]);
                if(err< err_1){
                    err = err_1;
                }
            }
        }}
        Temp = Temperature;
        iter++;
        
        
    }
    std::cout<<"Number of iterations took to converge for Steady State Gauss Seidel: "<< iter<< std::endl;
}

void steady_state::successive_over_relaxation(int max_iter)
{
    double relaxation_factor = 1.1; // Over Relaxation Factor
    std::vector<std::vector<double>> Temp = Temperature;
    
    int iter{0};
    double err{1.0};
    double term1{0.0}, term2{0.0};
    double constant=k*dx*dx;

    while (err>tol && iter<max_iter)
    {
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                term1 = (Temperature[i-1][j]+Temp[i+1][j])/constant;
                term2 = (Temperature[i][j-1]+Temp[i][j+1])/constant;
                // These two terms are actually Gauss-Seidel Temperature.
                Temperature[i][j] = Temp[i][j]*(1-relaxation_factor) + relaxation_factor*(term1 + term2);
                // This extrapolation takes the form of a weighted average between the previous iterate 
                // and the computed Gauss-Seidel iterate successively for each component.
            }
        }
        err = 0;
        if (iter%5==0){
        for (size_t i = 1; i < nx-1; i++)
        {
            for (size_t j = 1; j < ny-1; j++)
            {
                double err_1= fabs(Temperature[i][j]-Temp[i][j]);
                if(err< err_1){
                    err = err_1;
                }
            }
        }}
        Temp = Temperature;
        iter++;
    }
    std::cout<<"Number of iterations took to converge for Steady State Successive Over Relaxation: "<< iter<< std::endl;
}