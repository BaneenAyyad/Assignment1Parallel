include <stdio.h>
#include <math.h>
#include <time.h> // Library to measure time

// Function to evaluate the curve (y = f(x))
float f(float x) {
    return x * x; // Example: y = x^2
}

// Function to compute the area of a trapezoid
float trapezoid_area(float a, float b, int n) {
    float area = 0;
    float d = (b - a) / n; // delta (interval size)

    for (float x = a; x < b; x += d) {
        area += f(x) + f(x + d);
    }

    return area * d / 2.0f;
}

int main() {
    float a = 0.0f, b = 1.0f;  // Limits of integration
    int n;
    float total_area;
    
    // Get the number of intervals from the user
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    // Start measuring time
    clock_t start_time = clock();
 // Calculate the total area under the curve
    total_area = trapezoid_area(a, b, n);

    // End measuring time
    clock_t end_time = clock();

    // Calculate execution time in seconds
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the result
    printf("The total area under the curve is: %f\n", total_area);
    printf("Execution time: %f seconds\n", execution_time);
    
    return 0;
}

