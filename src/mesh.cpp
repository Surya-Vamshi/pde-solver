#include"mesh.h"

mesh::mesh()
{
    std::cout<<"Default Values:"<<std::endl;
    std::cout<<"Lenght = 1m; Breath = 1m;"<<std::endl;
    std::cout<<"Number of nodes in x direction = 10 ; Number of nodes in y direction = 10;"<<std::endl;
    std::cout<<"Tolerance limit = 0.0001"<<std::endl<<std::endl;
    
    

    char option{'n'};
    std::cout<<"Do you want to enter your own dimensions of the domain, mesh size and Tolerance? (y)(n): ";
    label4:
    std::cin>>option;
    
    if(option=='y'){
            std::cout<<"Enter the Lenght and Breath:";
            std::cin>>l>>b;
            std::cout<<"Enter the number of nodes desired along Lenght and Breath:";
            std::cin>>ny>>nx;
            std::cout<<"Enter the Tolerance:";
            std::cin>>tol;
    } else if (option!='n'){
            std::cerr<<"Error: (y)(n)!"<<std::endl;
            goto label4;
    }
    dx = l/(nx-1); 
    dy = b/(ny-1);
    k = 2*(1/(dx*dx)+1/(dy*dy)); 
    Temperature.resize(nx);
    for (int i = 0; i < ny; ++i)
        Temperature[i].resize(ny);
}

void mesh::temp_initialization(){
    double Temperature_init{300.00};
    char option{'n'};
    std::cout<<"Do you want to give initial temperatures for entire domain? (y)(n): ";
    label2:
    std::cin>>option;
    
    if(option=='y'){
            std::cout<<"Enter the Temperature:";
            std::cin>>Temperature_init;
    } else if (option!='n'){
            std::cerr<<"Error: (y)(n)!"<<std::endl;
            goto label2;
    }
    std::vector<double> i(ny);
    std::fill(i.begin(), i.end(), Temperature_init);
    std::fill(Temperature.begin(), Temperature.end(), i);
    // Assigning Temperatures at Boundaries 
    double Temperature_left{400}, Temperature_right{800}, Temperature_top{600}, Temperature_bottom{900};
    std::cout<<"Do you want to give temperatures for the boundaries? (y)(n): ";
    label3:
    std::cin>>option; 
   
    if(option=='y'){
            std::cout<<"Enter the Temperatures in order (Left, Right, Top, Bottom):";
            std::cin>>Temperature_left>>Temperature_right>>Temperature_top>>Temperature_bottom;
    }else if (option!='n'){
            std::cerr<<"Error: (y)(n)!"<<std::endl;
            goto label3;
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
    // Printing initialized Temperatures.
    std::cout<<std::endl<<"Initializated Temperatures:"<<std::endl;
    mesh::print(Temperature);

    std::cout<<"Initialization Done"<<std::endl<<std::endl;  
}

void mesh::print(std::vector<std::vector<double>> temp){
        for(auto elem: temp){
                std::cout.precision(2);
                for(auto x: elem){
                        std::cout<< x<< ' ';
                }
         std::cout<<"\n";
         }
}