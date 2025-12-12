#include<iostream>
#include<fstream>
#include<string>
#include<models/linear_regression.hpp>

int main() 
{
    std::ifstream file("datasets/demo.csv");
    std::string line;

    // skipping header 
    std::getline(file, line);
    if(file.is_open()) {
        while(std::getline(file, line)) { 

        }
    }

    file.close();
    models::LinearRegression2D* linear = new models::LinearRegression2D();
    std::cout << "this is working\n";
    return 0;
}