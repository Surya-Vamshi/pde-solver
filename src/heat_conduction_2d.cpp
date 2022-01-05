#include "heat_conduction_2d.h"

void heat_conduction_2d::steady_state_solver()
{
    std::string method = "None";
    std::cout<<"Steady State Methods:";
    std::cout<<"Jacobian Method (jac); Gauss Seidel (gs); Successive Over Relaxation(sor);"<<std::endl;
    std::cout<<"Select an iterative method: ";
    std::cin>>method;
    if(method == "jac"){
        jacobi();
    }else if(method == "gs"){
                gauss_seidel();
    }else if(method == "sor"){
                successive_over_relaxation();
    }else{
        std::cerr<<"Error: Method is not choosen from the available list!"<<std::endl;
    }
}

void heat_conduction_2d::print_vector(std::vector<double> v){
    std::cout.precision(7);
    for(auto &elem: v){
        std::cout<< elem<< ' ';
    }
    std::cout<<"\n";
}

void heat_conduction_2d::result()
{
    std::cout<<std::endl<<"Solution of the 2D Heat Conduction:"<<std::endl;
    for(auto &elem: Solution){
        print_vector(elem);
    }
    std::cout<<std::endl;
}
