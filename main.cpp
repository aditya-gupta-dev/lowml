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
    delete &file; 

    models::LinearRegression2D* linear = new models::LinearRegression2D();
    return 0;
}