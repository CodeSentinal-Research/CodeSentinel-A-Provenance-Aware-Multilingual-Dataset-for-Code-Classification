Here is the code for computing the binomial coefficient (nCr) in Python. The function `binomial_coefficient()` computes the binomial coefficient using the formula `nCr = n * (n-1) * ... * (n-r+1) / r`.

def binomial_coefficient(n, r):
    result = 1
    for i in range(r):
        result *= (n - i)
        result //= (i + 1)
    return result

n = 5
r = 2
print(binomial_coefficient(n, r))  
In this code, the `binomial_coefficient()` function first initializes `result` to 1. Then, it calculates the value of `result` in a loop that goes from 0 to `r-1`. In each iteration, it multiplies `result` by `(n - i)` and then divides it by `(i + 1)`. The function finally returns the computed value of `result`.

The test at the end of the code demonstrates how the function can be used to compute the binomial coefficient for `n = 5` and `r = 2`.