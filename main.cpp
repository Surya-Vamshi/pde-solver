#include<iostream>
#include<vector>

// Print Vector And Matrix Funtion just to check the values
template <typename V>
void print_vector(const V& v){
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
    std::vector<double> x(nx,0), y(ny,0); // Grid along x and y direction
    double tol{0.0001}; // Tolerance Limit
    double dx = l/(nx-1); 
    for (int i=0; i<nx; ++i){
            x[i]=0 + (i*dx);
    }
    double dy = b/(ny-1); 
    for (int i=0; i<ny; ++i){
            y[i]=0 + (i*dy);
    }
    // Assigining Temperature 
    std::vector<std::vector<double>> Temp(nx);
    for(auto i = 0; i<nx ;i++){
        for (auto j = 0; j<ny ; j++){
            Temp[i].push_back(300);
        }
    }
    for (auto i = 0; i<nx ; i++){
            Temp[i][0]= 400; // Left Boundary
    }
    for (auto i = 0; i<nx ; i++){
            Temp[i][ny-1]= 800; // Right Boundary
    }
    for (auto j = 0; j<ny ; j++){
            Temp[0][j]= 600; // Top Boundary
    }
    for (auto j = 0; j<ny ; j++){
            Temp[nx-1][j]= 900; // Top Boundary
    }
    // Calculating Average Temp at ends
    Temp[0][0]= (600+400)/2.0;
    Temp[0][ny-1]= (600+800)/2.0;
    Temp[nx-1][0]= (900+400)/2.0;
    Temp[nx-1][ny-1]= (900+800)/2.0;

    
    print_matrix(Temp);

    return 0;
}