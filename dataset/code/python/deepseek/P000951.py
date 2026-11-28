Sure, here is a Python code that computes the sum of Euler's Totient Function values from 1 to N.

def compute_sum_of_totients(n):
    totients = [0 for _ in range(n + 1)]
    for i in range(2, n + 1):
        if totients[i] == 0:
            for j in range(i, n + 1, i):
                totients[j] = j
    for i in range(1, n + 1):
        totients[i] = totients[i] / i * (i - 1)
    return sum(totients)

def main():
    n = int(input())
    print(compute_sum_of_totients(n))

if __name__ == "__main__":
    main()

In this code, we first initialize a list `totients` where `totients[i]` is the totient of `i`. We then iterate over all numbers `i` from 2 to `n`, and if `totients[i]` is 0 (indicating that `i` is not yet processed), we iterate over all multiples of `i` and mark them as `i`. Finally, we iterate over all numbers `i` from 1 to `n`, update `totients[i]` and return the sum of all `totients[i]`.

In the `main` function, we read the value of `n` from stdin, compute the sum of Euler's Totient Function values from 1 to `n`, and print the result.

This code uses the concept of Euler's Totient Function which is the count of positive integers less than `n` that are co-prime to `n`. It is defined as the product of all numbers `i` that are co-prime to `n`, where `i` is relatively prime to `n` (i.e., the greatest common divisor of `i` and `n` is 1).

Please note that this code has a time complexity of O(n^2). The main purpose of this code is to demonstrate the concept of the Euler's Totient Function and is not recommended for large inputs.