#include "heat_conduction_2d.h"

void heat_conduction_2d::steady_state_solver()
{
    std::cout<<"Maximum iterations = 1000"<<std::endl;
    std::cout<<"do you want to change max iterations (y,n) ";
    char opt;
    int max_iter=1000;
    label6:
    std::cin>>opt;
    if (opt=='y'){
        std::cout<<"enter new max iteration: ";
        std::cin>> max_iter;
    } else if (opt!='n'){
        std::cerr<<"Error: Enter (y,n)!"<<std::endl;
        goto label6;
    }
    std::string method = "None";
    std::cout<<"Steady State Methods:";
    std::cout<<"Jacobian Method (jac); Gauss Seidel (gs); Successive Over Relaxation(sor);"<<std::endl;
    label1:
    std::cout<<"Select an iterative method: ";
    std::cin>>method;
    if(method == "jac"){
        jacobi(max_iter);
    }else if(method == "gs"){
                gauss_seidel(max_iter);
    }else if(method == "sor"){
                successive_over_relaxation(max_iter);
    }else{
        std::cerr<<"Error: Method is not choosen from the available list!"<<std::endl;
        goto label1;
    }

    
}

void heat_conduction_2d::result()
{
    std::cout<<std::endl<<"Solution of the 2D Heat Conduction:"<<std::endl;
    mesh::print(Solution);
}
