#pragma once
namespace models
{

    class LinearRegression2D
    {
    public:
        LinearRegression2D(double learning_rate = 0.01, int epochs = 1000);

        void fit(const double *x, const double *y, int n);
        double predict(double x) const;

        double getSlope() const;
        double getIntercept() const;

    private:
        double m;
        double c;
        double lr;
        int epochs;

        double computeLoss(const double *x, const double *y, int n) const;
    };
}