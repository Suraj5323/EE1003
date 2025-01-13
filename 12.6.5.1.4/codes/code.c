#include <math.h>
#include <stdlib.h>

// f(x) = x^3 + 1
double func(double x) {
    return x * x * x + 1;
}

// f'(x) = 3x^2
double func_deriv(double x) {
    return 3 * x * x;
}

// Generate points for given function
void points_gen(double x_start, double x_end, double* x_vals, double* y_vals, double h, double (*func)(double)) {
    int i = 0;
    for (double x_i = x_start; x_i < x_end; x_i += h) {
        x_vals[i] = x_i;
        y_vals[i] = func(x_i);
        i++;
    }
}

void gradient_method(double x0, double learning_rate, double tol, double extremum[2], double (*func)(double), double (*func_deriv)(double)) {
    double x1 = x0 + learning_rate * func_deriv(x0);
    
    while (fabs(x1 - x0) >= tol) {
        x0 = x1;
        x1 = x0 + learning_rate * func_deriv(x0);
    }
    
    extremum[0] = x1;
    extremum[1] = func(x1);
}

