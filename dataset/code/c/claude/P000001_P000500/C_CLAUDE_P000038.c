#include <math.h>

double compoundInterest(double principal, double rate, double time) {
    double amount = principal * pow(1.0 + rate / 100.0, time);
    return amount - principal;
}
