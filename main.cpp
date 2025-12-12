#include<iostream> 
#include<models/linear_regression.hpp>

int main() 
{
    models::LinearRegression2d* linear = new models::LinearRegression2d();
    std::cout << "this is working\n";
    return 0;
}