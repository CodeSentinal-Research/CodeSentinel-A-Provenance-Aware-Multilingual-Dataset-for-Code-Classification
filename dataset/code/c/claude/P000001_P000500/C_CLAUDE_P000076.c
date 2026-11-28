#include <math.h>

void findRoots(double a, double b, double c, double* r1, double* r2) {
    double d = b * b - 4 * a * c;
    if (d >= 0) {
        *r1 = (-b + sqrt(d)) / (2 * a);  // write through pointer
        *r2 = (-b - sqrt(d)) / (2 * a);  // write through pointer
    } else {
        *r1 = -b / (2 * a);  // write through pointer
        *r2 = sqrt(-d) / (2 * a);  // write through pointer
    }
}
