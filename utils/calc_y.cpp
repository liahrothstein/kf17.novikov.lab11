#include <math.h>

double calculateY(double x) {
    // Y(x) = 1 / (x^2 + x + 1)
    return 1.0 / (pow(x, 2) + x + 1);
}