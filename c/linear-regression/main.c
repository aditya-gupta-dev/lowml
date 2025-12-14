#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10
#define LEARNING_RATE 0.01
#define EPOCS 1000

typedef struct
{
    float intercept;
    float slope;
} LinearRegression2D;

float predict(float x, LinearRegression2D *regression)
{
    return regression->slope * x + regression->intercept;
}

LinearRegression2D train(float *x_axis, float *y_axis, int max_epocs)
{
    LinearRegression2D regression = {.intercept = 0, .slope = 0};
    for (int epoc = 1; epoc <= max_epocs; epoc++)
    {

    }
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

    LinearRegression2D regression = train(x_axis, y_axis, EPOCS);
    return EXIT_SUCCESS;
};