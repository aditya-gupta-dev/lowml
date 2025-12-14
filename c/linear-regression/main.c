#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10
#define LEARNING_RATE 0.01
#define EPOCS 1000
#define DEBUG_MODE 0

typedef struct
{
    float intercept;
    float slope;
} LinearRegression2D;

float predict(float x, LinearRegression2D *regression)
{
    return regression->slope * x + regression->intercept;
}

float compute_interept_gradient(float *error_rate, int start, int end)
{
    float k = 2.0 / (end - start);
    float summation = 0;

    for (int i = start; i < end; i++)
    {
        float err = *(error_rate + i);
        summation += err;
    }

    return k * summation;
}

float compute_slope_gradient(float *x_axis, float *error_rate, int start, int end)
{
    // bug fix: dividing integer with another integer throws away decimal part
    // instead of getting 2 / (10 - 0) => 0.2 we get 0 part always making the
    // compute gradient 0
    // float k = 2 / (end - start);
    float k = 2.0 / (end - start);
    float summation = 0;
    for (int i = start; i < end; i++)
    {
        float x = *(x_axis + i);
        float err = *(error_rate + i);
        summation += err * x;
    }
    return k * summation;
}

void debug_values(float *val, int start, int end, char *label)
{
    printf("\n%s\n", label);
    for (int i = start; i < end; i++)
    {
        printf("%.3f, ", *(val + i));
    }
    printf("\n");
}

void debug(int epoc, float m_grad, float i_grad, float m, float c)
{
    printf("\tEPOCH no.%d\n", epoc);
    printf("slope              = %.3f   | intercept      = %.3f\n", c, m);
    printf("intercept_gradient = %.3f | slope_gradient = %.3f\n\n", i_grad, m_grad);
}

LinearRegression2D train(float *x_axis, float *y_axis, int start, int end, float learning_rate, int max_epocs)
{
    LinearRegression2D regression = {.intercept = 0, .slope = 0};
    float error_rate[end - start];

    for (int epoc = 1; epoc <= max_epocs; epoc++)
    {
        for (int i = start; i < end; i++)
        {
            float x = *(x_axis + i);
            float y = *(y_axis + i);
            float predicted_y = predict(x, &regression);
            error_rate[i] = predicted_y - y;
        }
        float intercept_gradient = compute_interept_gradient(error_rate, start, end);
        float slope_gradient = compute_slope_gradient(x_axis, error_rate, start, end);
        
        regression.slope = regression.slope - learning_rate * slope_gradient; 
        regression.intercept = regression.intercept - learning_rate * intercept_gradient; 

        if(DEBUG_MODE == 1)
        {
            debug(epoc, slope_gradient, intercept_gradient, regression.slope, regression.intercept);
        }
    }

    return regression;  
}

int main()
{
    FILE *file = fopen("data.csv", "r");
    if (file == NULL)
    {
        perror("opening file error");
        return EXIT_FAILURE;
    }

    char buffer[MAX_LINES * 10];
    float x_axis[MAX_LINES];
    float y_axis[MAX_LINES];
    int counter = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (sscanf(buffer, "%f,%f", &x_axis[counter], &y_axis[counter]) == 2)
        {
            counter += 1;
        }
        else
        {
            printf("error invalid line: %s at counter %d", buffer, counter);
            return EXIT_FAILURE;
        }
    }
    fclose(file);

    LinearRegression2D regression = train(x_axis, y_axis, 0, MAX_LINES, LEARNING_RATE, EPOCS);

    printf("slope :%.3f\n", regression.slope);
    printf("intercept :%.3f\n", regression.intercept);

    return EXIT_SUCCESS;
};