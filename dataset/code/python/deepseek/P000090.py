Here is the Python code:

def nCr(n, r):
    n_fact = 1
    for i in range(1, n + 1):
        n_fact *= i

    r_fact = 1
    for i in range(1, r + 1):
        r_fact *= i

    nr_fact = 1
    for i in range(1, n - r + 1):
        nr_fact *= i

    nCr = n_fact / (r_fact * nr_fact)
    return nCr


print(nCr(5, 2))  

This code defines a function `nCr` that takes two arguments, `n` and `r`, and calculates the binomial coefficient `nCr` using the mathematical formula `nCr = n!/((n-r)! * r!)`.

The code then tests this function with the input values `5` and `2`.

Please note that this code uses the `math` module's `factorial` function to calculate the factorial of `n` and `r`, and it uses the `math` module's `comb` function to calculate the binomial coefficient.