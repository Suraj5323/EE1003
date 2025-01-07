#include <stdio.h>
#include <math.h>

// Function to compute the exact integral using symbolic integration
double integrate(double a, double b) {
    // Formula: 2 * (x^(3/2)) evaluated from a to b
    double result = 2 * (pow(b, 1.5) - pow(a, 1.5));
    return result;
}

// Function to compute the approximate integral using the trapezoidal rule
double calculate_area(double x0, double xN, int n) {
    double h = (xN - x0) / n; // Step size
    double area = 0.0;

    // Calculate the first term
    area += sqrt(x0);

    // Sum the intermediate terms
    for (int i = 1; i < n; i++) {
        double xi = x0 + i * h;
        area += 2 * sqrt(xi);
    }

    // Add the last term
    area += sqrt(xN);

    // Multiply by the trapezoidal coefficient
    area *= (3 * h / 2);

    return area;
}

int main() {
    double x0 = 2.0; // Start of the interval
    double xN = 4.0; // End of the interval
    int n = 100;     // Number of subintervals

    // Compute the approximate area using the trapezoidal rule
    double approx_area = calculate_area(x0, xN, n);

    // Compute the exact area using symbolic integration
    double a = 2.0; // Lower limit of integration
    double b = 4.0; // Upper limit of integration
    double exact_area = integrate(a, b);

    // Open a .dat file to save results
    FILE *file = fopen("results.dat", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write results to the .dat file
    fprintf(file, "The approximate area using the trapezoidal rule is: %lf\n", approx_area);
    fprintf(file, "The exact area under the curve is: %lf\n", exact_area);

    // Close the file
    fclose(file);

    printf("Results have been written to results.dat\n");

    return 0;
}

