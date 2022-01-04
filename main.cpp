#include"temp_initialization.h"
#include"steady_state_jacobi.h"
#include"steady_state_gauss_seidel.h"
#include"steady_state_successive_over_relaxation.h"
#include<string>
// Print Vector And Matrix Funtion just to check the values
template <typename V>
void print_vector(const V& v){
    std::cout.precision(7);
    for(auto &elem: v){
        std::cout<< elem<< ' ';
    }
    std::cout<<"\n";
}
template <typename M>
void print_matrix(const M& a){
    for(auto &elem: a){
        print_vector(elem);
    }
}


int main(){
    double l{1}, b{1}; // Length and Breath of the 2d Element
    int nx{10}, ny{10}; // Number of nodes in x and y direction
    double tol{0.0001}; // Tolerance Limit
    char option{'n'};
    std::cout<<"Default Values:"<<std::endl;
    std::cout<<"Lenght = 1m; Breath = 1m;"<<std::endl;
    std::cout<<"Number of nodes in x direction = 10 ; Number of nodes in y direction = 10;"<<std::endl;
    std::cout<<"Tolerance limit = 0.0001"<<std::endl;
    
    std::cout<<"Do you want to enter your own dimensions of the domain, mesh size and Tolerance? (y)(n): ";
    std::cin>>option;
    if(option=='y'){
            std::cout<<"Enter the Lenght and Breath:";
            std::cin>>l>>b;
            std::cout<<"Enter the number of nodes desired along Lenght and Breath:";
            std::cin>>ny>>nx;
            std::cout<<"Enter the Tolerance:";
            std::cin>>tol;
    }
    double dx = l/(nx-1); 
    double dy = b/(ny-1); 
    // Assigining Temperature 
    std::vector<std::vector<double>> Temperature(nx);
    temp_initialization(Temperature,nx,ny,dx,dy);
    double k = 2*(1/(dx*dx)+1/(dy*dy)); // Constant
    std::string method = "None";
    std::cout<<"Steady State Methods:";
    std::cout<<"Jacobian Method (jac); Gauss Seidel (gs); Successive Over Relaxation(sor);"<<std::endl;
    std::cout<<"Select an iterative method: ";
    std::cin>>method;
    if(method == "jac"){
        steady_state_jacobi(Temperature,nx,ny,dx,dy,tol,k);
        print_matrix(Temperature);
    }else if(method == "gs"){
                steady_state_gauss_seidel(Temperature,nx,ny,dx,dy,tol,k);
                print_matrix(Temperature);
    }else if(method == "sor"){
                steady_state_successive_over_relaxation(Temperature,nx,ny,dx,dy,tol,k);
                print_matrix(Temperature);
    }else{
        std::cerr<<"Error: Method is not choosen from the available list!"<<std::endl;
    }
    return 0;
}